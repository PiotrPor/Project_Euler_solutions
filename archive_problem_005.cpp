// projecteuler.net/problem=5
/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <iostream>

int main()
{
    const unsigned long long abcdef = 20;
    unsigned long long number, the_limit, x;
    bool success;
    the_limit = 1;
    for (x = 1; x <= abcdef; x++)
    {
        the_limit *= x;
    }
    the_limit++;
    for (number = abcdef; number <= the_limit; number++)
    {
        success = true;
        for (x = 2; x <= abcdef; x++)
        {
            if (number % x != 0)
            {
                success = false;
                break;
            }
        }
        if (success)
        {
            break;
        }
    }
    std::cout << "Smallest such number is " << number << std::endl;
    return 0;
}