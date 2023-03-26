// projecteuler.net/problem=4
/*
A palindromic number reads the same both ways.
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <string>

bool is_it_palindrome(unsigned int nn);

int main()
{
    unsigned int a, b, tested;
    unsigned int array_about_results[] = {0,0,0};
    for (a = 100; a < 1000; a++)
    {
        for (b = a; b < 1000; b++)
        {
            tested = a * b;
            if (is_it_palindrome(tested))
            {
                if (tested > array_about_results[2])
                {
                    array_about_results[0] = a;
                    array_about_results[1] = b;
                    array_about_results[2] = tested;
                }
            }
        }
    }
    std::cout << "Largest such palindrome is " << array_about_results[2] << "=";
    std::cout << array_about_results[0] << "*" << array_about_results[1] << std::endl;
    return 0;
}

bool is_it_palindrome(unsigned int nn)
{
    bool isit = false;
    std::string checked, reversed;
    int a;
    unsigned int size;
    checked = std::to_string(nn);
    size = checked.size();
    for (a = size-1; a>=0; a--)
    {
        reversed.push_back(checked[a]);
    }
    if (checked.compare(reversed) == 0)
    {
        isit = true;
    }
    return isit;
}