// projecteuler.net/problem=1
/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <iostream>

int main()
{
    const int limit = 1000;
    int n3 = 3;
    int n5 = 5;
    int big_sum = 0;
    do {
        big_sum += n3;
        n3 += 3;
    } while (n3 < limit);
    do {
        if (!(n5 % 3 == 0))
        {
            big_sum += n5;
        }
        n5 += 5;
    } while (n5 < limit);
    std::cout << "Sum of multiples: " << big_sum << std::endl;
    return 0;
}
