// projecteuler.net/problem=15
/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
How many such routes are there through a 20×20 grid?
*/

#include <iostream>

const int maxX = 2;
const int maxY = -2;
int route_quantity;

// option 1: move to the right
// option 2: move down
void make_next_move(int x, int y, int option);

int main()
{
    route_quantity = 0;
    make_next_move(0, 0, 1);
    make_next_move(0, 0, 2);
    std::cout << "There are " << route_quantity << " possible routes" << std::endl;
    return 0;
}

void make_next_move(int x, int y, int option)
{
    if (option == 1)
    {
        if (x < maxX)
        {
            route_quantity++;
            make_next_move(x + 1, y, 1);
            make_next_move(x + 1, y, 2);
        }
    }
    if (option == 2)
    {
        if (y > maxY)
        {
            route_quantity++;
            make_next_move(x, y - 1, 1);
            make_next_move(x, y - 1, 2);
        }
    }
    return;
}