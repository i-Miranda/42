/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:17:48 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/19 16:29:33 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string const &_name, int _s_grade, int _e_grade)
    : m_name(_name), m_sign_grade(_s_grade), m_exec_grade(_e_grade),
      m_signed(false) {
  std::cout << "Default Form Constructor called." << std::endl;
  if (_s_grade < 1 || _e_grade < 1)
    throw AForm::GradeTooHighException();
  if (_s_grade > 150 || _e_grade > 150)
    throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &src)
    : m_name(src.m_name), m_sign_grade(src.m_sign_grade),
      m_exec_grade(src.m_exec_grade), m_signed(src.m_signed) {
  std::cout << "Copy Form Constructor called." << std::endl;
}

AForm::~AForm(void) { std::cout << "Form Destructor called." << std::endl; }

AForm &AForm::operator=(AForm const &src) {
  std::cout << "Copy assignment operator called." << std::endl;
  if (this != &src) {
    m_signed = src.m_signed;
  }
  return *this;
}

std::string const &AForm::getName(void) const { return m_name; }

int AForm::getSignGrade(void) const { return m_sign_grade; }

int AForm::getExecGrade(void) const { return m_exec_grade; }

bool AForm::isSigned(void) const { return m_signed; }

void AForm::beSigned(Bureaucrat const &bureaucrat) {
  if (bureaucrat.getGrade() > m_sign_grade)
    throw AForm::GradeTooLowException();
  m_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const {
  if (!m_signed)
    throw AForm::NotSignedException();
  else if (executor.getGrade() > m_exec_grade)
    throw AForm::GradeTooLowException();
}

char const *AForm::GradeTooHighException::what() const throw() {
  return "Grade too high. Grade must be an integer between 1 and 150.";
}

char const *AForm::GradeTooLowException::what() const throw() {
  return "Grade too low. Grade must be an integer between 1 and 150.";
}

char const *AForm::NotSignedException::what() const throw() {
  return "Form is NOT signed.";
}

std::ostream &operator<<(std::ostream &out, AForm const &form) {
  out << form.getName() << ",\n\tgrade required to sign " << form.getSignGrade()
      << "\n\tgrade required to execute " << form.getExecGrade() << "\n\t";
  if (form.isSigned()) {
    out << "Form is signed.";
  } else {
    out << "Form is NOT signed.";
  }
  return out;
}
