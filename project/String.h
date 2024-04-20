#pragma once
#include "Sequence.h"

class String : public Sequence
{
public:
	String(const std::string& value);
	~String();
	virtual bool isPrintable() const override;
	virtual std::string toString() const override;

	std::string getValue() const;

private:
	std::string _value;
};