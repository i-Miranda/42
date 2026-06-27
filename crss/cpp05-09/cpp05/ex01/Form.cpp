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

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string const _name, int _s_grade, int _e_grade)
    : m_name(_name), m_sign_grade(_s_grade), m_exec_grade(_e_grade),
      m_signed(false) {
  std::cout << "Default Form Constructor called." << std::endl;
  if (_s_grade < 1 || _e_grade < 1)
    throw Bureaucrat::GradeTooHighException();
  if (_s_grade > 150 || _e_grade > 150)
    throw Bureaucrat::GradeTooLowException();
}

Form::Form(const Form &src)
    : m_name(src.getName()), m_sign_grade(src.getSignGrade()),
      m_exec_grade(src.getExecGrade()), m_signed(src.isSigned()) {
  std::cout << "Copy Form Constructor called." << std::endl;
}
Form::~Form(void) { std::cout << "Form Destructor called." << std::endl; }

Form &Form::operator=(const Form &src) {
  std::cout << "Copy assignment operator called." << std::endl;
  if (this != &src) {
    m_signed = src.isSigned();
  }
  return *this;
}

std::string const Form::getName(void) const { return m_name; }
int Form::getSignGrade(void) const { return m_sign_grade; }
int Form::getExecGrade(void) const { return m_exec_grade; }
bool Form::isSigned(void) const { return m_signed; }

void Form::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > getSignGrade())
    throw Form::GradeTooLowException();
  m_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return FORM_TOO_HIGH;
}

const char *Form::GradeTooLowException::what() const throw() {
  return FORM_TOO_LOW;
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
  if (form.isSigned()) {
    out << form.getName() << ", grade required to sign " << form.getSignGrade()
        << "\n grade required to execute " << form.getExecGrade() << "\n"
        << SIGNED;
  } else {
    out << form.getName() << ", grade required to sign " << form.getSignGrade()
        << "\n grade required to execute " << form.getExecGrade() << "\n"
        << NOT_SIGNED;
  }
  return out;
}
