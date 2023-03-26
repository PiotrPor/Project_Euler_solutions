// projecteuler.net/problem=3
/*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*/

#include <iostream>
#include <vector>

bool is_it_prime_number(long long num);

int main()
{
    const long long given_number = 600851475143;
    std::vector<long long> prime_factors;
    long long a;
    long long half = given_number / (long long)2;
    for (a = 0; a <= half; a++)
    {
        if (given_number % a == 0)
        {
            if (is_it_prime_number(a))
            {
                prime_factors.push_back(a);
            }
        }
    }
    long long largest = prime_factors.back();
    std::cout << "Largest prime factor of " << given_number << " is " << largest << std::endl;
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