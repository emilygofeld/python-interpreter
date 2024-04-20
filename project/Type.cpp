#include "Type.h"


Type::Type(const std::string& type) :_isTemp(false), _type(type)
{
}

Type::~Type()
{
}

bool Type::getIsTemp() const
{
    return _isTemp;
}

void Type::setIsTemp(bool newIsTemp)
{
    _isTemp = newIsTemp;
}

std::string Type::getType() const
{
    return _type;
}
