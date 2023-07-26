#include "BitcoinExchange.hpp"

BtcExchange::BtcExchange(const std::string &filename) : _input_filename(filename)
{
	this->_data.clear();
}

BtcExchange::BtcExchange(const BtcExchange &rhs )
{
	this->_data.clear();
	this->_data = rhs._data;
	this->_input_filename = rhs._input_filename;
}

BtcExchange& BtcExchange::operator=(const BtcExchange& rhs)
{
	if (this != &rhs)
	{
		this->_data.clear();
		this->_data = rhs._data;
		this->_input_filename = rhs._input_filename;
	}
	return (*this);
}

BtcExchange::~BtcExchange()
{
	this->_data.clear();
	this->_input_filename.clear();
}

void BtcExchange::showMapData() const
{
	std::map<std::string, double> p = _data;

    std::map<std::string, double>::iterator it = p.begin();
	std::map<std::string, double>::iterator end = p.end();
 
    for (; it != end; ++it)
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
}

void BtcExchange::readCSVFile(const std::string &filename)
{
    std::ifstream file;

	file.open(filename.c_str());
	if (file.is_open())
	{
        std::string line;

        while (std::getline(file, line))
		{
            std::stringstream ss(line);
            std::string key;
            double value;

            if (std::getline(ss, key, ',') && ss >> value)
                this->_data[key] = value;
        }
        file.close();
    }
}

double BtcExchange::compareData(std::string date, double value) const
{
	std::map<std::string, double> map = _data;

	if (date < map.begin()->first)
		return (0);
	else
	{
        std::map<std::string, double>::iterator prev = map.begin();
        std::map<std::string, double>::iterator it;

        for (it = map.begin(); it != map.end(); ++it)
		{
            if (it->first >= date || it->first == date)
			{
                if (it->first == date)
                    return (value * it->second);
                else
                    return (value * prev->second);
            }
            prev = it;
        }
    }
	return (1);
}