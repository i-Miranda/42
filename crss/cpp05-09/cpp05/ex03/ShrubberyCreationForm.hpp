/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:55:31 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/19 15:32:29 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
private:
  std::string m_target;

public:
  ShrubberyCreationForm(std::string const &_target);
  ShrubberyCreationForm(ShrubberyCreationForm const &src);
  virtual ~ShrubberyCreationForm(void);

  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

  void execute(Bureaucrat const &executor) const;

  class CreationException : public std::exception {
  public:
    virtual char const *what() const throw();
  };
};

#endif
