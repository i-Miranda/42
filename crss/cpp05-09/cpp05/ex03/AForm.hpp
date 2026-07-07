/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:55:31 by ivmirand          #+#    #+#             */
/*   Updated: 2026/06/30 17:07:18 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

#define FORM_TOO_HIGH "Bureaucrat Grade too high."
#define FORM_TOO_LOW "Bureaucrat Grade too low."
#define SIGNED "Form is signed."
#define NOT_SIGNED "Form is NOT signed."

// Forward declaration of Bureaucrat to avoid circular includes
class Bureaucrat;

class AForm {
private:
  std::string const m_name;
  const int m_sign_grade;
  const int m_exec_grade;
  bool m_signed;

public:
  AForm(std::string const &_name, int _s_grade, int _e_grade);
  AForm(const AForm &src);
  virtual ~AForm(void);

  AForm &operator=(const AForm &src);

  std::string const getName(void) const;
  int getSignGrade(void) const;
  int getExecGrade(void) const;
  bool isSigned(void) const;

  void beSigned(Bureaucrat const &bureaucrat);
  virtual void execute(Bureaucrat const &executor) const;

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class NotSignedException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
