#include "Point.hpp"

int main( void ) 
{
    Point a(3, 3);
    Point b(5, 6);
    Point c(7, 3);
    Point p(4, 4);

    if(bsp(a, b, c, p))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is NOT inside the triangle" << std::endl;
    return 0;
}