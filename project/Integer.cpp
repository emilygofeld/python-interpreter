#include "Integer.h"


Integer::Integer(int value) : Type::Type("Integer"), _value(value)
{
}

Integer::~Integer()
{
}

bool Integer::isPrintable() const
{
    return true;
}

std::string Integer::toString() const
{
    return std::to_string(_value);
}

void Integer::setValue(int val)
{
    _value = val;
}

int Integer::getValue() const
{
    return _value;
}
