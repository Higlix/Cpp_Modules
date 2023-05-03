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

};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif