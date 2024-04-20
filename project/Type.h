#pragma once
#include <iostream>
#include <string>

class Type
{
public:
	Type(const std::string& type);
	virtual ~Type();

	bool getIsTemp() const;
	void setIsTemp(bool newIsTemp);

	std::string getType() const;

	virtual bool isPrintable() const = 0;
	virtual std::string toString() const = 0;

private:
	bool _isTemp;
	std::string _type;
};
