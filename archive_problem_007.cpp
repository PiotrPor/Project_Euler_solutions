// projecteuler.net/problem=7
/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?
*/

// 10,001 -> 104,743

#include <iostream>

bool is_it_prime_number(long long num);

int main()
{
    const unsigned int which_prime = 10001;
    unsigned int how_many = 0;
    long long xyz = 1;
    bool keep_going = true;
    do {
        if (how_many == UINT32_MAX) 
        { break; }
        xyz += 1;
        if (is_it_prime_number(xyz))
        {
            how_many += 1;
        }
        if (how_many == which_prime)
        {
            keep_going = false;
        }
    } while (keep_going);
    if (!keep_going)
    {
        std::cout << "That prime number is " << xyz << std::endl;
    }
    else
    {
        std::cout << "Search prime number is too big (bigger than " << UINT32_MAX << ")" << std::endl;
    }
    return 0;
}

bool is_it_prime_number(long long num)
{
    bool verdict = true;
    long long a;
    for (a = 2; (a * a) <= num; a++)
    {
        if (num % a == 0 && num != a)
        {
            verdict = false;
            break;
        }
    }
    return verdict;
}