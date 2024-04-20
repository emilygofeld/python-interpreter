#include "NameErrorException.h"

const char* NameErrorException::what() const noexcept
{
    return "Name Error: Name undefined";
}
