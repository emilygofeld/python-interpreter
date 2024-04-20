#include "Void.h"

Void::Void() : Type::Type("Void")
{
}

Void::~Void()
{
}

bool Void::isPrintable() const
{
    return false;
}

std::string Void::toString() const
{
    return "";
}
