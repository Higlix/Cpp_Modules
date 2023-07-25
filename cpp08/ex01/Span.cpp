#include "Span.hpp"

Span::Span()
{
	_size = 0;
}

Span::Span( unsigned int N )
{
	_size = N;
}

Span::Span( const Span& rhs)
{
	this->_size = rhs._size;

	for (size_t i = 0; i < rhs._array.size(); i++)
		this->_array.push_back(rhs._array[i]);
}

Span&	Span::operator=( const Span& rhs )
{
	if (this != &rhs)
	{
		this->_array.clear();
		this->_size = rhs._size;
		for (size_t i = 0; i < rhs._array.size(); i++)
			this->_array.push_back(rhs._array[i]);
	}
	return (*this);
}

Span::~Span() {/**/}

void	Span::addNumber(int number)
{
	if (this->_array.size() + 1 <= this->_size)
		this->_array.push_back(number);
	else
		throw (ArrayAtMax());
}

int Span::shortestSpan() const
{
    if (_array.size() <= 1)
        throw (SpanNotFound());

    std::vector<int> sortedNumbers = _array;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int shortest = sortedNumbers[1] - sortedNumbers[0];
    for (size_t i = 2; i < sortedNumbers.size(); i++)
    {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < shortest)
            shortest = span;
    }
    return shortest;
}

int Span::longestSpan() const
{
    if (_array.size() <= 1)
        throw (SpanNotFound());

    int min = *std::min_element(_array.begin(), _array.end());
    int max = *std::max_element(_array.begin(), _array.end());
    return max - min;
}