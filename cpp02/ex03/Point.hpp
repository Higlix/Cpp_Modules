#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point {

private:
    const Fixed _x;
    const Fixed _y;

public:
    Point();
    Point( const float n1, const float n2 );
    Point( const Point &ref );
    Point& operator=( const Point &ref );
    ~Point();

    Fixed getX( void ) const;
    Fixed getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif