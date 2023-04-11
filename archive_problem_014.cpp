// projecteuler.net/problem=14
/*
The following iterative sequence is defined for the set of positive integers:
  n -> n/2 (n is even)
  n -> 3n + 1 (n is odd)
Using the rule above and starting with 13, we generate the following sequence:
13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?
NOTE: Once the chain starts the terms are allowed to go above one million.
*/

// Number 837,799 produces the longest chain (525 terms)

#include <iostream>

int main()
{
    unsigned long long a, nr, number_for_longest;
    int longest_length, chain_length;
    longest_length = 2;
    number_for_longest = 2;
    for (a = 3; a <= 1000000; a++)
    {
        nr = a;
        chain_length = 0;
        while (nr > 1)
        {
            if (nr % 2 == 0)
            {
                nr /= 2;
            }
            else
            {
                nr *= 3;
                nr += 1;
            }
            chain_length += 1;
        }
        chain_length += 1; //we want number of terms, not number of steps
        if (chain_length > longest_length)
        {
            longest_length = chain_length;
            number_for_longest = a;
        }
    }
    std::cout << "Number " << number_for_longest << " produces the longest chain (" << longest_length << " terms)" << std::endl;
    return 0;
}