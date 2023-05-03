#include "Fixed.hpp"

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    this->_fixed_point_value = 0;
}

Fixed::Fixed( const int p )
{
    // std::cout << "Int constructor called" << std::endl;
    this->_fixed_point_value = p << this->_fractional_bits;
}

Fixed::Fixed( const float p )
{
    // std::cout << "Float constructor called" << std::endl;
    this->_fixed_point_value = roundf( p * ( 1 << this->_fractional_bits ));
}

Fixed::Fixed( const Fixed &rhs )
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Fixed& Fixed::operator=( const Fixed &rhs )
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixed_point_value = rhs.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    return (this->_fixed_point_value);
}

void    Fixed::setRawBits( int const raw )
{
    this->_fixed_point_value = raw;
}

float   Fixed::toFloat( void ) const 
{
    return (static_cast<float>( this->getRawBits() )) / (1 << this->_fractional_bits);
}

int     Fixed::toInt( void ) const 
{
    return this->_fixed_point_value >> this->_fractional_bits;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return o;
}
//***********************************//
//         LOGIC OPERATIONS         //
//*********************************//

bool    Fixed::operator>( const Fixed &rhs ) const {
    return ( this->getRawBits() > rhs.getRawBits() );
}
bool    Fixed::operator<( const Fixed &rhs ) const {
    return ( this->getRawBits() < rhs.getRawBits() );
}
bool    Fixed::operator>=( const Fixed &rhs ) const {
    return ( this->getRawBits() >= rhs.getRawBits() );
}
bool    Fixed::operator<=( const Fixed &rhs ) const {
    return ( this->getRawBits() <= rhs.getRawBits() );
}
bool    Fixed::operator==( const Fixed &rhs ) const {
    return ( this->getRawBits() == rhs.getRawBits() );
}
bool    Fixed::operator!=( const Fixed &rhs ) const {
    return ( this->getRawBits() <= rhs.getRawBits() );
}

//***********************************//
//       ARITHMETIC OPERATIONS      //
//*********************************//

Fixed   Fixed::operator+( const Fixed &rhs ) const {
    return Fixed( this->toFloat() + rhs.toFloat() );
}
Fixed   Fixed::operator-( const Fixed &rhs ) const {
    return Fixed( this->toFloat() - rhs.toFloat() );
}
Fixed   Fixed::operator*( const Fixed &rhs ) const {
    return Fixed( this->toFloat() * rhs.toFloat() );
}
Fixed   Fixed::operator/( const Fixed &rhs ) const {
    return Fixed( this->toFloat() / rhs.toFloat() );
}

//------------------ Increment/Decrement operators ------------------//
Fixed&   Fixed::operator++( void ) {
    ++this->_fixed_point_value;
    return *this;
}
Fixed   Fixed::operator++( int ) {
    Fixed tmp( *this );
    tmp._fixed_point_value = this->_fixed_point_value++;
    return tmp;
}
Fixed& Fixed::operator--( void ) {
    --this->_fixed_point_value;
    return *this;
}
Fixed Fixed::operator--( int ) {
    Fixed tmp( *this );
    tmp._fixed_point_value = this->_fixed_point_value--;
    return tmp;
}

//----------------------- Max and Min ----------------------//
Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}
const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}
Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}
const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}