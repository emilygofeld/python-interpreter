#pragma once
#include "InterpreterException.h"
#include "Type.h"
#include "Helper.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>


class Parser
{
public:
	static Type* parseString(std::string& str);
	static Type* getType(std::string& str);
	static void cleanVars();

	static std::unordered_map<std::string, Type*> _variables;

private:
	static bool isLegalVarName(std::string& str);
	static bool makeAssignment(std::string& str);
	static bool copyVar(std::string& var, std::string& varToCopy);
	static Type* getVariableValue(std::string& str);
};
