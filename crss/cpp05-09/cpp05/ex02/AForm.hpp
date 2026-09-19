/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:55:31 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/19 16:28:48 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

// Forward declaration of Bureaucrat to avoid circular includes
class Bureaucrat;

class AForm {
private:
  std::string const m_name;
  int const m_sign_grade;
  int const m_exec_grade;
  bool m_signed;

public:
  AForm(std::string const &_name, int _s_grade, int _e_grade);
  AForm(AForm const &src);
  virtual ~AForm(void);

  AForm &operator=(AForm const &src);

  std::string const &getName(void) const;
  int getSignGrade(void) const;
  int getExecGrade(void) const;
  bool isSigned(void) const;

  void beSigned(Bureaucrat const &bureaucrat);
  virtual void execute(Bureaucrat const &executor) const = 0;

  class GradeTooHighException : public std::exception {
  public:
    virtual char const *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual char const *what() const throw();
  };

  class NotSignedException : public std::exception {
  public:
    virtual char const *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif
