#include "operations.h"
#include <stdexcept>
double sum(double a, double b)
{
    return a + b;
}

double sub(double a, double b)
{
    return a - b;
}

double mult(double a, double b)
{
    return a * b;
}

double divi(double a, double b)
{
    if (b == 0)
        throw std::invalid_argument("Division by zero is not allowed");
    return a / b;
}
