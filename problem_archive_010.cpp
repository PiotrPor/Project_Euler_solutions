// projecteuler.net/problem=10
/*
The sum of the primes below 10 is 2+3+5+7=17.
Find the sum of all the primes below two million.
*/

#include <iostream>

bool is_it_prime_number(long long number);

int main()
{
    const long long TwoMillion = 2000000;
    long long nr, sum;
    sum = 0;
    for (nr = 2; nr < TwoMillion; nr++)
    {
        if (is_it_prime_number(nr))
        {
            sum += nr;
        }
    }
    std::cout << "Sum of primes below " << TwoMillion << " is: " << sum << std::endl;
    return 0;
}

bool is_it_prime_number(long long number)
{
    bool isit = true;
    long long a;
    if (number > 3)
    {
        for (a = 2; (a * a) <= number; a++)
        {
            if (number % a == 0)
            {
                isit = false;
                break;
            }
        }
    }
    return isit;
}