#include "IllegalBalanceException.h"

const char * IllegalBalanceException::what() const noexcept{
    return "Illegal Balance Exception";
}