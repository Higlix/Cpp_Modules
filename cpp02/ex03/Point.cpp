#include "Point.hpp"

Point::Point( void ): _x(0), _y(0) {

}

Point::Point(const float n1, const float n2): _x(n1), _y(n2) {

}

Point::Point( const Point &ref ): _x(ref._x), _y(ref._y) {
    
}

Point &Point::operator=( const Point &ref ) {
    if (this != &ref)
    {
        (Fixed ) this->_x = ref.getX();
        (Fixed ) this->_y = ref.getY();
    }
    return (*this);
}

Fixed Point::getX( void ) const {
    return this->_x;
}

Fixed Point::getY( void ) const {
    return this->_y;
}

Point::~Point()
{

}