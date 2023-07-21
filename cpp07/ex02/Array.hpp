#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array( void ) : _array(new T()), _size(0) {/**/};
		Array( unsigned int n ) : _array(new T[n]), _size(n) {/**/};

		Array( const Array& rhs ) : _array(new T[rhs._size]), _size(rhs._size)
		{
			for ( size_t i = 0; i < _size; i++)
				_array[i] = rhs._array[i];
		};

		Array& operator=( const Array& rhs )
		{
			if ( this != &rhs )
			{
				delete [] _array;
				_array = new T[rhs.size()];
				_size = rhs._size;
				for ( size_t i = 0; i < _size; i++ )
					_array[i] = rhs._array[i];
			}
        	return (*this);
    	}

		T& operator[]( unsigned int i ) const 
		{
			if ( i >= _size )
				throw (OutOfBoundsException());
			return (_array[i]);
		}

		unsigned int  size( void ) const { return _size; }

		~Array( void ) { delete [] _array; }

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw() { return "Index is out of bound";}
		};
};

template < typename T >
std::ostream& operator<<( std::ostream& out, const Array<T>& arr )
{
    for ( size_t i = 0; i < arr.size(); i++ )
        out << arr[i] << " ";
    return (out);
}

#endif