// projecteuler.net/problem=6
/*
The sum of the squares of the first ten natural numbers is
 1^2 + 2^2 + 3^2 +...+ 10^2 = 385
The square of the sum of the first ten natural numbers is
 (1+2+3+...+10)^2 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025-385=2640
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include <iostream>
#include <cmath>

double triangular_number(double x);

int main()
{
    double sum_of_squares, square_of_sum, difference, a;
    const double upper_limit = 100;
    sum_of_squares = 0;
    for (a = 1; a <= upper_limit; a++)
    {
        sum_of_squares += pow(a, 2);
    }
    square_of_sum = pow(triangular_number(upper_limit), 2);
    difference = square_of_sum - sum_of_squares;
    std::cout << "For the first " << upper_limit << " numbers the diference is " << difference << std::endl;
    return 0;
}

double triangular_number(double x)
{
    return (x * (x + 1)) / (double)2;
}