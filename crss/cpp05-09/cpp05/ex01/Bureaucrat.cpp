/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:55:01 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/19 16:19:44 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string const &_name, int _grade)
    : m_name(_name), m_grade(_grade) {
  std::cout << "Default Bureaucrat Constructor called." << std::endl;
  if (_grade < 1)
    throw Bureaucrat::GradeTooHighException();
  if (_grade > 150)
    throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
    : m_name(src.m_name), m_grade(src.m_grade) {
  std::cout << "Copy Bureaucrat Constructor called." << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
  std::cout << "Bureaucrat Destructor called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {
  std::cout << "Copy assignment operator called." << std::endl;
  if (this != &src) {
    m_grade = src.m_grade;
  }
  return *this;
}

std::string const &Bureaucrat::getName(void) const { return m_name; }

int Bureaucrat::getGrade(void) const { return m_grade; }

void Bureaucrat::incrementGrade() {
  if (m_grade <= 1)
    throw Bureaucrat::GradeTooHighException();
  m_grade--;
}

void Bureaucrat::decrementGrade() {
  if (m_grade >= 150)
    throw Bureaucrat::GradeTooLowException();
  m_grade++;
}

void Bureaucrat::signForm(Form &form) {
  try {
    form.beSigned(*this);
    std::cout << m_name << " signed " << form.getName() << std::endl;
  } catch (Form::GradeTooLowException const &e) {
    std::cout << m_name << " couldn't sign " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

char const *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade too high. Grade must be an integer between 1 and 150.";
}

char const *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade too low. Grade must be an integer between 1 and 150.";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
      << ".";
  return out;
}
