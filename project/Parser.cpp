#include "Parser.h"
#include "IndentationException.h"
#include <iostream>
#include <string>
//------------------------
#include "SyntaxException.h"
#include "NameErrorException.h"
#include "Integer.h"
#include "Boolean.h"
#include "String.h"
#include "Void.h"
//------------------------

std::unordered_map<std::string, Type*> Parser::_variables;

Type* Parser::parseString(std::string& str)
{
	if (str.length() > 0)
	{
		if (str.rfind(" ", 0) == 0 || str.rfind("\t", 0) == 0)
			throw IndentationException();

		Helper::rtrim(str);

		Type* type = getVariableValue(str); // checking if var exists already
		if (type != nullptr)
			return type;

		type = getType(str); // checking if var is a valid type
		if (type != nullptr)
			return type;
	}
	if (makeAssignment(str))
	{
		Void* voidVal = new Void();
		voidVal->setIsTemp(true);
		return voidVal;
	}
	throw SyntaxException();
}

Type* Parser::getType(std::string& str)
{
	Helper::trim(str);
	if (Helper::isInteger(str))
	{
		Helper::removeLeadingZeros(str);
		Integer* val = new Integer(stoi(str));
		val->setIsTemp(true);
		return val;
	}
	if (Helper::isBoolean(str))
	{
		bool ctorValue = (str == "False") ? false : true;
		Boolean* val = new Boolean(ctorValue);
		val->setIsTemp(true);
		return val;
	}
	if (Helper::isString(str))
	{ 
		String* val = new String(str);
		val->setIsTemp(true);
		return val;
	}
	if (isLegalVarName(str))
		throw NameErrorException();
	return nullptr;
}


bool Parser::isLegalVarName(std::string& str)
{
	if (Helper::isDigit(str[0]))
		return false;

	for (auto chr : str)
	{
		if (!(Helper::isLetter(chr) || Helper::isUnderscore(chr) || Helper::isDigit(chr)))
			return false;
	}
	return true;
}

bool Parser::makeAssignment(std::string& str)
{
	unsigned int found = str.find("="); 

	if (found == std::string::npos) // if '=' char not found
		return false;
	//if (str.find("=", found + 1)) // if there are more than one '=' char
	//	return false;
	if (found == 0 || found == str.length()-1) // if '=' is in the beggining or end of str
		return false;

	std::string subStrBeg = str.substr(0, found);
	std::string subStrEnd = str.substr(found + 1, str.length() - 1);
	String strCheck1(subStrBeg);
	String strCheck2(subStrEnd);
	if (!(Helper::isString(strCheck1.toString()) && Helper::isString(strCheck2.toString())))
		return false;

	Helper::trim(subStrBeg);
	Helper::trim(subStrEnd);

	if (!isLegalVarName(subStrBeg)) // if illegal var name
		throw NameErrorException();

	if (_variables.find(subStrEnd) != _variables.end()) 
		if (copyVar(subStrBeg, subStrEnd))
			return true;

	if (_variables.find(subStrBeg) != _variables.end()) 
	{
		if (_variables[subStrBeg] != nullptr)
			delete _variables[subStrBeg]; // deleting previous type if value exists
	}
		
	Type* type = getType(subStrEnd);
	if (type == nullptr) // if illegal value name
		throw SyntaxException();

	type->setIsTemp(false);
	_variables[subStrBeg] = type;
	return true;
}


bool Parser::copyVar(std::string& var, std::string& varToCopy)
{

	Type* type = _variables.at(varToCopy);

	if (type->getType() == "Integer")
	{
		if (_variables.find(var) != _variables.end())  // deleting previous type if value exists
			delete _variables.at(var);

		Integer* newVal = new Integer(atoi(type->toString().c_str()));
		return true;
	}
	if (type->getType() == "Boolean")
	{
		if (_variables.find(var) != _variables.end())  // deleting previous type if value exists
			delete _variables.at(var);

		Boolean* newVal = new Boolean((type->toString() == "False") ? false : true);
		return true;
	}
	if (type->getType() == "String")
	{
		if (_variables.find(var) != _variables.end())  // deleting previous type if value exists
			delete _variables.at(var);

		std::string strToCopy = type->toString();
		strToCopy.erase(0, 1);
		strToCopy.erase(strToCopy.length() - 1, 1);
		String* newVal = new String(strToCopy);
		return true;
	}

	return false;
}


Type* Parser::getVariableValue(std::string& str)
{
	if (_variables.find(str) != _variables.end())
		return _variables.at(str);
	return nullptr;
}


void Parser::cleanVars()
{
	for (auto var : _variables)
	{
		delete var.second;
	}
}

