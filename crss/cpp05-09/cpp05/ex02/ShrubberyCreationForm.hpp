/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:55:31 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/13 18:40:05 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

#define S_NAME "ShrubberyCreationForm"

class ShrubberyCreationForm : public AForm {
private:
  std::string m_target;

public:
  ShrubberyCreationForm(std::string const &_target);
  ShrubberyCreationForm(ShrubberyCreationForm const &src);
  virtual ~ShrubberyCreationForm(void);

  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

  void execute(Bureaucrat const &executor) const;
};

#endif
