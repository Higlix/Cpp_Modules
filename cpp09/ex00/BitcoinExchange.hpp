#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>

# include <algorithm>
# include <map>
# include <string>

# include <fstream>
# include <unistd.h>
# include <sstream>


# define FILE_VALID 1
# define FILE_INVALID -1

class BtcExchange
{
	private:
		std::map<std::string, double>	_data;
		std::string						_input_filename;

		BtcExchange();

	public:
		BtcExchange( const std::string &filename );
		BtcExchange( const BtcExchange &rhs );
		BtcExchange& operator=( const BtcExchange &rhs );
		~BtcExchange();

		void	readCSVFile( const std::string &csv );

		void	showMapData() const;

		double	compareData(std::string date, double value) const;


};

#endif