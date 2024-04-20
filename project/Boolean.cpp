#include "Boolean.h"


Boolean::Boolean(bool value) : Type::Type("Boolean"), _value(value)
{
}

Boolean::~Boolean()
{
}

bool Boolean::isPrintable() const
{
    return true;
}

std::string Boolean::toString() const
{
    return (!_value? "False" : "True");
}

bool Boolean::getValue() const
{
    return _value;
}
