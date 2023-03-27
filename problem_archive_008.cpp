// projecteuler.net/problem=8
/*
The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.

73167176531330624919225119674426574742355349194934
96983520312774506326239578318016984801869478851843
85861560789112949495459501737958331952853208805511
12540698747158523863050715693290963295227443043557
66896648950445244523161731856403098711121722383113
62229893423380308135336276614282806444486645238749
30358907296290491560440772390713810515859307960866
70172427121883998797908792274921901699720888093776
65727333001053367881220235421809751254540594752243
52584907711670556013604839586446706324415722155397
53697817977846174064955149290862569321978468622482
83972241375657056057490261407972968652414535100474
82166370484403199890008895243450658541227588666881
16427171479924442928230863465674813919123162824586
17866458359124566529476545682848912883142607690042
24219022671055626321111109370544217506941658960408
07198403850962455444362981230987879927244284909188
84580156166097919133875499200524063689912560717606
05886116467109405077541002256983155200055935729725
71636269561882670428252483600823257530420752963450

Find the thirteen adjacent digits in the 1000-digit number that have the greatest product.
What is the value of this product?
*/

#include <iostream>
#include <string>
#include <fstream>

long long product_of_digits(int arr[], const int size);
void string_into_digit_array(int arr[], std::string ss, int size);
void get_subarray_of_digits(int small[], int big[], const int size_small, const int size_big, int start_pos);
void move_window_by_one(int small[], int big[], const int size_small, const int size_big, int old_start_pos);
bool is_this_among_them(int small[], int size, int x);
std::string write_about_subset(int arr[], const int size);

//================================================

int main()
{
    const int how_many_adjacent = 13;
    const int how_long_string = 1000;
    std::string string_of_digits;
    std::ifstream numfile;
    int these_digits[how_many_adjacent];
    int string_as_arr[how_long_string];
    int start_position, start_of_biggest;
    long long product, biggest_product;
    //
    numfile.open("problem_archive_008_numbers_file.txt");
    std::getline(numfile, string_of_digits);
    numfile.close();
    //
    string_into_digit_array(string_as_arr, string_of_digits, how_long_string);
    start_position = 0;
    start_of_biggest = 0;
    biggest_product = 0;
    //first
    get_subarray_of_digits(these_digits, string_as_arr, how_many_adjacent, how_long_string, start_position);
    product = product_of_digits(these_digits, how_many_adjacent);
    biggest_product = product;
    //next
    while ((start_position + how_many_adjacent) <= how_long_string)
    {
        move_window_by_one(these_digits, string_as_arr, how_many_adjacent, how_long_string, start_position);
        start_position += 1;
        //
        if (string_as_arr[start_position - 1] == 0 || is_this_among_them(these_digits,how_many_adjacent,0))
        {
            get_subarray_of_digits(these_digits, string_as_arr, how_many_adjacent, how_long_string, start_position);
            product = product_of_digits(these_digits, how_many_adjacent);
        }
        else
        {
            product /= string_as_arr[start_position - 1];
            product *= these_digits[how_many_adjacent - 1];
        }
        //
        if (product > biggest_product)
        {
            biggest_product = product;
            start_of_biggest = start_position;
        }
    }
    //
    std::cout << "Value of biggest product is " << biggest_product << std::endl;
    get_subarray_of_digits(these_digits, string_as_arr, how_many_adjacent, how_long_string, start_of_biggest);
    std::cout << write_about_subset(these_digits, how_many_adjacent) << std::endl;
    return 0;
}

//================================================

long long product_of_digits(int arr[], const int size)
{
    long long prd = 1;
    int a;
    for (a = 0; a < size; a++)
    {
        prd *= arr[a];
    }
    return prd;
}

void string_into_digit_array(int arr[], std::string ss, int size)
{
    int a;
    for (a = 0; a < size; a++)
    {
        arr[a] = (int)ss[a] - 48; // char -> ASCII_number -> number_value
    }
    return;
}

void get_subarray_of_digits(int small[], int big[], const int size_small, const int size_big, int start_pos)
{
    if ((size_small + start_pos) > size_big)
    {
        return;
    }
    int a;
    for (a = 0; a < size_small; a++)
    {
        small[a] = big[start_pos + a];
    }
    return;
}

void move_window_by_one(int small[], int big[], const int size_small, const int size_big, int old_start_pos)
{
    int a;
    for (a = 0; a < size_small - 1; a++)
    {
        small[a] = small[a + 1];
    }
    small[size_small - 1] = big[old_start_pos + size_small];
    return;
}

bool is_this_among_them(int small[], int size, int x)
{
    bool isit = false;
    int a;
    for (a = 0; a < size; a++)
    {
        if (small[a] == x)
        {
            isit = true;
            break;
        }
    }
    return isit;
}

std::string write_about_subset(int arr[], const int size)
{
    std::string desc = std::to_string(arr[0]);
    int a;
    for (a = 1; a < size; a++)
    {
        desc += "*" + std::to_string(arr[a]);
    }
    desc += " = " + std::to_string(product_of_digits(arr, size));
    return desc;
}