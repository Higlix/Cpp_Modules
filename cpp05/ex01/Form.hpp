#ifndef AForm_HPP
# define AForm_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_sign;
		const int			_requiredGradeSign;
		const int			_requiredGradeExec;

		AForm();

	public:
		AForm( std::string name, int rgs, int rge );
		AForm( const AForm& rhs );
		AForm& operator=( const AForm& rhs );
		~AForm();


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

std::ostream&   operator<<( std::ostream& o, const AForm& rhs );

#endif