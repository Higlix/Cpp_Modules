#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_sign;
		const int			_requiredGradeSign;
		const int			_requiredGradeExec;

		Form();

	public:
		Form( std::string name, int rgs, int rge );
		Form( const Form& rhs );
		Form& operator=( const Form& rhs );
		~Form();


		std::string	getName() const;
		bool		getSign() const;
		int			getGradeSign() const;
		int			getGradeExec() const;

		void		beSigned( const Bureaucrat& rhs );
		void		signForm( const Bureaucrat& rhs );

		class GradeTooHighException : public std::exception 
		{
			public:
				const char* what() const throw()
				{
    				return ("Grade Too High");
				}
		};
		class GradeTooLowException : public std::exception 
		{
			public:
				const char* what() const throw()
				{
    				return ("Grade Too Low");
				}
		};
};

std::ostream&   operator<<( std::ostream& o, const Form& rhs );

#endif