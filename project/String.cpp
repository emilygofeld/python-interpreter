#include "String.h"
#include "Helper.h"

String::String(const std::string& value) : Sequence::Sequence("String"), _value(value)
{
    const char first = _value[0];
    const char last = _value[_value.length()-1];
    if ((first == '\"' && last == '\"') || (first == '\'' && last == '\''))
    {
        _value.erase(0, 1);
        _value.erase(_value.length() - 1, 1);
    }
}

String::~String()
{
}

bool String::isPrintable() const
{
    return true;
}

std::string String::toString() const
{
    if (_value.find("'") != std::string::npos)
        return "\"" + _value + "\""; 
    return "'" + _value + "'";
}

std::string String::getValue() const
{
    return _value;
}
