#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("AForm_DEFAULT"), _requiredGradeSign(1), _requiredGradeExec(1)
{
	this->_sign = false;
}

AForm::AForm( std::string name, int rgs, int rge ) : 
_name(name), _requiredGradeSign(rgs), _requiredGradeExec(rge)
{
	this->_sign = false;
}

AForm::AForm( const AForm& rhs ) :
_name(rhs._name), 
_requiredGradeSign(rhs._requiredGradeSign),
_requiredGradeExec(rhs._requiredGradeExec)
{
	this->_sign = false;
}

AForm& AForm::operator=( const AForm& rhs )
{
	if (this != &rhs)
	{
		this->_sign = rhs._sign;
	}
	return (*this);
}

AForm::~AForm() {/**/}


std::string	AForm::getName() const
{
	return (this->_name);
}

bool		AForm::getSign() const
{
	return (this->_sign);
}

int			AForm::getGradeSign() const
{
	return (this->_requiredGradeSign);
}

int			AForm::getGradeExec() const
{
	return (this->_requiredGradeExec);
}

void		AForm::beSigned( const Bureaucrat& rhs )
{
	if (rhs.getGrade() <= this->_requiredGradeSign)
		this->_sign = true;
	else
		throw(AForm::GradeTooLowException());
}
std::ostream&   operator<<( std::ostream& o, const AForm& rhs )
{
    o << "------------- AForm Info -------------" << std::endl;
    o << "AForm name: " << rhs.getName() << std::endl
      << "Grade to sign: " << rhs.getGradeSign() << std::endl
      << "Grade to execute: " << rhs.getGradeExec();
    return (o);
}