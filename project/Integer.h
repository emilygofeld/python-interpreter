#pragma once
#include "Type.h"

class Integer : public Type
{
public:
	Integer(int value);
	~Integer();
	virtual bool isPrintable() const override;
	virtual std::string toString() const override;

	void setValue(int val);
	int getValue() const;

private:
	int _value;
};