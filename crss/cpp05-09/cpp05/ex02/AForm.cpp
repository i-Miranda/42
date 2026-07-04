/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:17:48 by ivmirand          #+#    #+#             */
/*   Updated: 2026/06/27 16:17:50 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string const _name, int _s_grade, int _e_grade)
    : m_name(_name), m_sign_grade(_s_grade), m_exec_grade(_e_grade),
      m_signed(false) {
  std::cout << "Default Form Constructor called." << std::endl;
  if (_s_grade < 1 || _e_grade < 1)
    throw Bureaucrat::GradeTooHighException();
  if (_s_grade > 150 || _e_grade > 150)
    throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(const AForm &src)
    : m_name(src.getName()), m_sign_grade(src.getSignGrade()),
      m_exec_grade(src.getExecGrade()), m_signed(src.isSigned()) {
  std::cout << "Copy Form Constructor called." << std::endl;
}

AForm::~AForm(void) { std::cout << "Form Destructor called." << std::endl; }

AForm &AForm::operator=(const AForm &src) {
  std::cout << "Copy assignment operator called." << std::endl;
  if (this != &src) {
    m_signed = src.isSigned();
  }
  return *this;
}

std::string const AForm::getName(void) const { return m_name; }

int AForm::getSignGrade(void) const { return m_sign_grade; }

int AForm::getExecGrade(void) const { return m_exec_grade; }

bool AForm::isSigned(void) const { return m_signed; }

void AForm::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > getSignGrade())
    throw AForm::GradeTooLowException();
  m_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const {
  if (!isSigned())
    throw AForm::NotSignedException();
  else if (executor.getGrade() > getExecGrade())
    throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
  return FORM_TOO_HIGH;
}

const char *AForm::GradeTooLowException::what() const throw() {
  return FORM_TOO_LOW;
}

const char *AForm::NotSignedException::what() const throw() {
  return NOT_SIGNED;
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
  out << form.getName() << ",\n\tgrade required to sign " << form.getSignGrade()
      << "\n\tgrade required to execute " << form.getExecGrade() << "\n\t";
  if (form.isSigned()) {
    out << SIGNED;
  } else {
    out << NOT_SIGNED;
  }
  return out;
}
