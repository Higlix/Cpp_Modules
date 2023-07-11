#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("CRAT_DEFAULT"), _grade(10)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (this->_grade < 1) 
		throw(Bureaucrat::GradeTooHighException());
	if (this->_grade > 150)
		throw(Bureaucrat::GradeTooLowException());
}

Bureaucrat::~Bureaucrat() {/**/}


std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int			Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void		Bureaucrat::gradePlus()
{
	if (this->_grade - 1 < 1)
		throw(Bureaucrat::GradeTooHighException());
	this->_grade--;
}

void		Bureaucrat::gradeMinus()
{
	if (this->_grade + 1 > 150)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade++;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& ref )
{
	if (this != &ref)
	{
		this->_grade = ref._grade;
	}
	return (*this);
}

void    Bureaucrat::signForm( AForm& AForm )
{
    try
	{
        AForm.beSigned( *this );
        std::cout << *this << " signed " << AForm.getName() << std::endl;
    } 
	catch(AForm::GradeTooLowException &e)
	{
        std::cout << _name << " coulnd't sign " << AForm.getName() << " because " << e.what() << std::endl;
    }
}

void		Bureaucrat::executeForm( const AForm &form ) const
{
    try
	{
        form.execute( *this );
	}
	catch ( std::exception& e )
	{
        std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs )
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}