#pragma once
#include "Type.h"

class Boolean : public Type
{
public:
	Boolean(bool value);
	~Boolean();
	virtual bool isPrintable() const override;
	virtual std::string toString() const override;

	bool getValue() const;
private:
	bool _value;
};