#include <iostream>
#include <fstream>

std::string sed_convert( std::string filename )
{
	std::string str;
	std::fstream hel;
	char *buffer;
	int count;

	hel.open(filename, std::ios::in);
	hel.seekg(0, hel.end);
	count = hel.tellg();
	hel.seekg(0, hel.beg);
	buffer = new char [count];
	hel.read(buffer, count);
	str.append(buffer);
	hel.close();
	delete[] buffer;
	return (str);
}

void	sed_do( std::string& str, std::string s1, std:: string s2 )
{
	int i = 0;
	while (str[i])
	{
		if (!str.compare(i, s1.length(), s1))
		{
			str.erase(i, s1.length());
			str.insert(i, s2);
		}
		i++;
	}
}

void	sed_wfile( std::string& str, std::string fn )
{
	std::fstream hel;

	fn.append(".replace");
	hel.open(fn, std::ios::out);
	hel << str;
	hel.close();
}

void	sed_is_for_losers( std::string fn, std::string s1, std::string s2 )
{
	std::string str;
	std::string& ref = str;

	str = sed_convert(fn);
	sed_do(ref, s1, s2);
	sed_wfile(ref, fn);
}

int main( int argc, char **argv )
{
	if (argc == 4)
		sed_is_for_losers(argv[1], argv[2], argv[3]);
	else if (argc < 4)
		std::cout << "ERROR NOT ENOUGH ARGUMENTS" << std::endl;	
	else
		std::cout << "ERROR TOO MANY ARGUMENTS" << std::endl;	
	return (0);
}