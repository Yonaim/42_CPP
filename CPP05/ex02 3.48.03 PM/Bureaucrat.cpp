#include "Bureaucrat.hpp"
#include "AForm.hpp"

const std::string Bureaucrat::default_target = "default";

Bureaucrat::Bureaucrat() : _target(default_target), _grade(default_grade)
{
}

Bureaucrat::Bureaucrat(const std::string &target, int grade) : _target(target), _grade(grade)
{
    if (_grade < highest_grade)
        throw(GradeTooHighException());
    if (_grade > lowest_grade)
        throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &orig) : _target(orig.getName()), _grade(orig.getGrade())
{
    if (_grade < highest_grade)
        throw(GradeTooHighException());
    if (_grade > lowest_grade)
        throw(GradeTooLowException());
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &orig)
{
    if (this != &orig)
    {
        _target = orig.getName();
        _grade = orig.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName(void) const
{
    return (_target);
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
    if (_grade - 1 < highest_grade)
        throw(GradeTooHighException());
    _grade--;
}

void Bureaucrat::decrementGrade(void)
{
    if (_grade + 1 > lowest_grade)
        throw(GradeTooLowException());
    _grade++;
}

void Bureaucrat::signForm(AForm &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << _target << " signed " << form.getName() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << _target << " couldn't sign " << form.getName() << " because " << e.what() << '\n';
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << _target << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error occur while " << _target << " executed " << form.getName() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Bureaucrat: GradeTooHighException");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Bureaucrat: GradeTooLowException");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &b)
{
    return (o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".");
}
