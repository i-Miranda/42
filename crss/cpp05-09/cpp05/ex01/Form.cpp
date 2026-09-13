/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:17:48 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/13 13:34:27 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string const &_name, int _s_grade, int _e_grade)
    : m_name(_name), m_sign_grade(_s_grade), m_exec_grade(_e_grade),
      m_signed(false) {
  std::cout << "Default Form Constructor called." << std::endl;
  if (_s_grade < 1 || _e_grade < 1)
    throw Form::GradeTooHighException();
  if (_s_grade > 150 || _e_grade > 150)
    throw Form::GradeTooLowException();
}

Form::Form(Form const &src)
    : m_name(src.m_name), m_sign_grade(src.m_sign_grade),
      m_exec_grade(src.m_exec_grade), m_signed(src.m_signed) {
  std::cout << "Copy Form Constructor called." << std::endl;
}

Form::~Form(void) { std::cout << "Form Destructor called." << std::endl; }

Form &Form::operator=(Form const &src) {
  std::cout << "Copy assignment operator called." << std::endl;
  if (this != &src) {
    m_signed = src.m_signed;
  }
  return *this;
}

std::string const &Form::getName(void) const { return m_name; }
int Form::getSignGrade(void) const { return m_sign_grade; }
int Form::getExecGrade(void) const { return m_exec_grade; }
bool Form::isSigned(void) const { return m_signed; }

void Form::beSigned(Bureaucrat const &bureaucrat) {
  if (bureaucrat.getGrade() > m_sign_grade)
    throw Form::GradeTooLowException();
  m_signed = true;
}

char const *Form::GradeTooHighException::what() const throw() {
  return FORM_TOO_HIGH;
}

char const *Form::GradeTooLowException::what() const throw() {
  return FORM_TOO_LOW;
}

std::ostream &operator<<(std::ostream &out, Form const &form) {
  out << form.getName() << ",\n\tgrade required to sign " << form.getSignGrade()
      << "\n\tgrade required to execute " << form.getExecGrade() << "\n\t";
  if (form.isSigned()) {
    out << SIGNED;
  } else {
    out << NOT_SIGNED;
  }
  return out;
}
