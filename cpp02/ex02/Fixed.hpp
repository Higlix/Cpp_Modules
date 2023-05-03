#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

private:
	int					_fixed_point_value;
	static const int	_fractional_bits = 8;

public:
	Fixed();
    Fixed( const Fixed &rhs );
    Fixed( const int p );
    Fixed( const float p );
    Fixed& operator=( const Fixed &rhs );
    ~Fixed();

    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;

    bool    operator>( const Fixed &rhs ) const ;
    bool    operator<( const Fixed &rhs ) const ;
    bool    operator>=( const Fixed &rhs ) const ;
    bool    operator<=( const Fixed &rhs ) const ;
    bool    operator==( const Fixed &rhs ) const ;
    bool    operator!=( const Fixed &rhs ) const ;
    
    Fixed   operator+( const Fixed &rhs ) const ;
    Fixed   operator-( const Fixed &rhs ) const ;
    Fixed   operator*( const Fixed &rhs ) const ;
    Fixed   operator/( const Fixed &rhs ) const ;

    Fixed&  operator++( void ); // prefix
    Fixed   operator++( int ); // postfix
    Fixed&  operator--( void ); // prefix
    Fixed   operator--( int ); // postfix

    static Fixed& min( Fixed &a, Fixed &b );
    static const Fixed& min( const Fixed &a, const Fixed &b );
    static Fixed& max( Fixed &a, Fixed &b );
    static const Fixed& max( const Fixed &a, const Fixed &b );
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif