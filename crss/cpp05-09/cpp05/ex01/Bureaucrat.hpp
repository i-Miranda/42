/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:55:31 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/01 19:28:16 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

#define BUREAUCRAT_TOO_HIGH                                                    \
  "Grade too high. Grade must be an integer between 1 and 150."
#define BUREAUCRAT_TOO_LOW                                                     \
  "Grade too low. Grade must be an integer between 1 and 150."

// Forward declaration of Form to avoid circular includes
class Form;

class Bureaucrat {
private:
  std::string const m_name;
  int m_grade;

public:
  Bureaucrat(std::string const _name, int _grade);
  Bureaucrat(const Bureaucrat &src);
  ~Bureaucrat(void);

  Bureaucrat &operator=(const Bureaucrat &src);

  std::string const getName(void) const;
  int getGrade(void) const;

  void incrementGrade(void);
  void decrementGrade(void);
  void signForm(Form &form);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureacrat);

#endif
