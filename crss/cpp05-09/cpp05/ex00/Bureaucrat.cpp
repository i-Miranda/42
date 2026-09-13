/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:55:01 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/13 12:43:41 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

char const *Bureaucrat::GradeTooHighException::what() const throw() {
  return TOO_HIGH;
}

char const *Bureaucrat::GradeTooLowException::what() const throw() {
  return TOO_LOW;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return out;
}
