/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:55:01 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/01 19:59:55 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string const _name, int _grade)
    : m_name(_name), m_grade(_grade) {
  std::cout << "Default Bureaucrat Constructor called." << std::endl;
  if (_grade < 1)
    throw Bureaucrat::GradeTooHighException();
  if (_grade > 150)
    throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : m_name(src.getName()) {
  std::cout << "Copy Bureaucrat Constructor called." << std::endl;
  if (this != &src) {
    this->m_grade = src.getGrade();
  }
}

Bureaucrat::~Bureaucrat(void) {
  std::cout << "Bureaucrat Destructor called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
  std::cout << "Copy assignment operator called." << std::endl;
  if (this != &src) {
    this->m_grade = src.getGrade();
  }
  return *this;
}

std::string const Bureaucrat::getName(void) const { return m_name; }

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
    std::cout << getName() << " signed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << getName() << " couldn't sign " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return BUREAUCRAT_TOO_HIGH;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return BUREAUCRAT_TOO_LOW;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return out;
}
