#include "Type.h"
#include "InterpreterException.h"
#include "Parser.h"
#include <iostream>

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "Emily"


int main(int argc,char **argv)
{
	std::cout << WELCOME << YOUR_NAME << std::endl;

	std::string input_string = "";
	Type* type;
	// get new command from user

	
	while (input_string != "quit()")
	{
		try
		{
			// get new command from user
			std::cout << ">>> ";
			std::getline(std::cin, input_string);

			// parsing command
			type = Parser::parseString(input_string);
			if (type != nullptr && type->isPrintable())
			{
				std::cout << type->toString() << std::endl;
				if (type->getIsTemp())
				{
					delete type;
					type = nullptr;
				}
			}
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	Parser::cleanVars();

	return 0;
}
