#include "BitcoinExchange.hpp"


int validateFile(const std::string &filename)
{
	if ((access( filename.c_str(), F_OK ) != -1) == FILE_VALID)
		return (FILE_VALID);
	std::cout << "Error: file not found." << std::endl;
	return (FILE_INVALID);
}

int validateArgsCount(int argc, char **argv, std::string &filename)
{
	if (argc < 2)
	{
		std::cout << "Error: no file was given." << std::endl;
		return (FILE_INVALID);
	}
	if (argc > 2)
	{
		std::cout << "Error: too many files given." << std::endl;
		return (FILE_INVALID);
	}
	std::string newFile(argv[1]);
	filename = newFile;
	return (FILE_VALID);
}

int main(int argc, char **argv)
{
	std::string filename;

	if (validateArgsCount(argc, argv, filename) == FILE_INVALID)
		return (-1);
	if (validateFile(filename) == FILE_INVALID)
		return (-1);
	
	try
	{
		BtcExchange btc(filename);

		btc.readCSVFile("data.csv");
		//btc.showMapData();
		
		std::ifstream input;
		std::string line;

		input.open(filename.c_str());
		while (std::getline(input, line))
		{
			double dVal;
			std::string date;
			std::string value;

			std::istringstream line_stream(line);
			if (std::getline(line_stream, date, '|') && std::getline(line_stream, value))
			{
				date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));
				date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
				value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));
				value.erase(value.find_last_not_of(" \t\n\r\f\v") + 1);
				if (date.length() != 10 || date[4] != '-' || date[7] != '-')
					continue ;
				try
				{
					dVal = strtod(value.c_str(), NULL);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					continue ;
				}
				if (dVal < 0)
				{
					std::cerr << "Error: not a positive number. " << std::endl;
                	continue;
				}
				if (dVal > 1000)
				{
					std::cerr << "Error: too large a number. " << std::endl;
                	continue;
				}
			}
			else
			{
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}
			std::cout << date << " => " << value << " = " << btc.compareData(date, dVal)<< std::endl;
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}



#ifdef LEAK
    system("leaks exec");
#endif

	return (0);
}