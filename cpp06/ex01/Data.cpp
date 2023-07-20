#include "Data.hpp"

Data::Data() : _name("DataIsMyCat") {/* */}

Data::Data(const Data& data) : _name(data._name) {/* */}

Data& Data::operator=(const Data& data)
{
	if (this != &data)
		this->_name = data._name;
	return (*this);
}

Data::~Data() {/* */}

std::string Data::getName() const { return (this->_name); }