#include "ScalarConverter.hpp"

void	unKnownInput()
{
	std::cout << "char = " << "Unknown Input" << std::endl;
	std::cout << "int = " << "Unknown Input" << std::endl;
	std::cout << "float = " << "Unknown Input" << std::endl;
	std::cout << "double = " << "Unknown Input" << std::endl;
}

void	convertToChar(long int a, bool isImpossible)
{
	std::cout << "char: ";
	if (isImpossible == true)
		std::cout << "Impossible";
	else if (a < 0 || a > 127)
		std::cout << "Out of limit";
	else if (a > 32 && a < 127)
	{
		char chr = a;
		std::cout << "\'" << chr << "\'";
	}
	else
		std::cout << "Non Displayable";
	std::cout << std::endl;
}

void	convertToInt(long int value, bool isImpossible)
{
	std::cout << "int: ";
	if (isImpossible == true)
		std::cout << "Impossible";
	else if (!(value > INT_MIN && value < INT_MAX))
		std::cout << "Out of limit";
	else if (value > INT_MIN && value < INT_MAX)
		std::cout << value;
	std::cout << std::endl;
}

void	convertToFloat(float value, bool valueDecimalPoint, bool isImpossible)
{
	std::cout << "float: ";
	std::cout << value;
	if (valueDecimalPoint == false && !isImpossible)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void	convertToDouble(double value, bool valueDecimalPoint, bool isImpossible)
{
	std::cout << "double: ";
	std::cout << value;
	if (valueDecimalPoint == false && !isImpossible)
		std::cout << ".0";
	std::cout << std::endl;
}

bool	checkImpossibles(std::string value)
{
	if (!value.compare("nanf") || !value.compare("nan")
		|| !value.compare("+inf") || !value.compare("-inf")
		|| !value.compare("+inff") || !value.compare("-inff"))
		return (true);
	return (false);
}

bool	checkInput(std::string value)
{
	int input_size = static_cast<int>(value.length());
	int decimal_count = 0;
	int f_count = 0;

	if (!value.compare("nanf") || !value.compare("nan")
		|| !value.compare("+inf") || !value.compare("-inf")
		|| !value.compare("+inff") || !value.compare("-inff"))
		return (true);

	for (int i = 0; i < input_size; i++)
	{
		if (!(value[i] >= 48 && value[i] <= 57) && value[i] != '.')
		{
			if (value[i] == 'f' && i + 1 == input_size)
				return (true);
			else
				return (false);
		}
		if (value[i] == '.' && (!value[i + 1] || value[i + 1] == 'f'))
			return (false);
		if (value[i] == 'f')
			f_count++;
		if (value[i] == '.')
			decimal_count++;
	}
	if (f_count > 1 || decimal_count > 1)
		return (false);
	return (true);
}

bool	checkDecimalPoint(std::string value)
{
	int input_size = static_cast<int>(value.length());
	
	for (int i = 0; i < input_size; i++)
	{
		if (value[i] == '.')
		{
			i++;
			for (int j = i; j < input_size; j++)
			{
				if (value[j] != '0' && value[j] != 'f')
					return (true);
			}
			return (false);
		}
	}
	return (false);
}

void	ScalarConverter::convert(std::string value)
{
	if (checkInput(value) == false)
	{
		unKnownInput();
		return ;
	}
	
	const char *val = value.c_str();

	bool intImpossible = checkImpossibles(value);
	bool valueDecimalPoint = checkDecimalPoint(value);

	long int charValue = atoi(val);
	long int intValue = atol(val);

	float floatValue = atof(val);
	double doubleValue = strtod(val, NULL);

	convertToChar(charValue, intImpossible);
	convertToInt(intValue, intImpossible);
	convertToFloat(floatValue, valueDecimalPoint, intImpossible);
	convertToDouble(doubleValue, valueDecimalPoint, intImpossible);
}

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& rhs)
{
	(void )rhs;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	(void )rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{

}