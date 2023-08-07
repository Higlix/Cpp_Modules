#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Form_DEFAULT"), _requiredGradeSign(1), _requiredGradeExec(1)
{
	this->_sign = false;
}

Form::Form( std::string name, int rgs, int rge ) : 
_name(name),
_requiredGradeSign(rgs),
_requiredGradeExec(rge)
{
	this->_sign = false;
}

Form::Form( const Form& rhs ) :
_name(rhs._name), 
_requiredGradeSign(rhs._requiredGradeSign),
_requiredGradeExec(rhs._requiredGradeExec)
{
	this->_sign = false;
}

Form& Form::operator=( const Form& rhs )
{
	if (this != &rhs)
	{
		this->_sign = rhs._sign;
	}
	return (*this);
}

Form::~Form() {/**/}


std::string	Form::getName() const
{
	return (this->_name);
}

bool		Form::getSign() const
{
	return (this->_sign);
}

int			Form::getGradeSign() const
{
	return (this->_requiredGradeSign);
}

int			Form::getGradeExec() const
{
	return (this->_requiredGradeExec);
}

void		Form::beSigned( const Bureaucrat& rhs )
{
	if (rhs.getGrade() <= this->_requiredGradeSign)
		this->_sign = true;
	else
		throw(Form::GradeTooLowException());
}
std::ostream&   operator<<( std::ostream& o, const Form& rhs )
{
    o << "------------- Form Info -------------" << std::endl;
    o << "Form name: " << rhs.getName() << std::endl
      << "Grade to sign: " << rhs.getGradeSign() << std::endl
      << "Grade to execute: " << rhs.getGradeExec();
    return (o);
}