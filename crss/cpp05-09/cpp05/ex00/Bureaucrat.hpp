/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:55:31 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/19 15:30:05 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
private:
  std::string const m_name;
  int m_grade;

public:
  Bureaucrat(std::string const &_name, int _grade);
  Bureaucrat(Bureaucrat const &src);
  ~Bureaucrat(void);

  Bureaucrat &operator=(Bureaucrat const &src);

  std::string const &getName(void) const;
  int getGrade(void) const;

  void incrementGrade(void);
  void decrementGrade(void);

  class GradeTooHighException : public std::exception {
  public:
    virtual char const *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual char const *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
