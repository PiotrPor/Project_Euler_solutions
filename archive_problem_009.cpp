// projecteuler.net/problem=9
/*
A Pythagorean triplet is a set of three natural numbers, a<b<c, for which
a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <iostream>

int main()
{
    int a, b, c, a2, b2, c2;
    const int limit = 1000;
    bool found = false;
    for (a = 1; a < limit; a++)
    {
        for (b = a; b < limit; b++)
        {
            c = limit - (a + b);
            if (c > 0)
            {
                a2 = a * a;
                b2 = b * b;
                c2 = c * c;
                if ((a2 + b2) == c2)
                {
                    found = true;
                    break;
                }
            }
        }
        if (found) { break; }
    }
    if (found)
    {
        std::cout << "This triplet is " << a << ", " << b << ", " << c << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }
    return 0;
}
