#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string const mName;
	int mGrade;

public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
    
	std::string const getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();
	void signForm(Form &form) const;
	void executeForm(Form const &form);

	class GradeTooHighException : public std::exception
	{ 
		public:
			const char* what(void) const throw ();
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what(void) const throw ();
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
