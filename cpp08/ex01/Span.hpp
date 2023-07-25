#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

# include <vector>
# include <algorithm>

class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_array;

		Span();

	public:
		Span( unsigned int N );
		Span( const Span &rhs);
		Span& operator=( const Span &rhs );
		~Span();

		void	addNumber(int number);

		int shortestSpan() const;
		int longestSpan() const;

		class ArrayAtMax : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("ArrayAtCapacity");
				}
		};

		class SpanNotFound : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("SpanNotFound");
				}
		};
};

#endif