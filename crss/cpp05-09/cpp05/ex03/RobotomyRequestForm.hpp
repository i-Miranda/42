/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:55:31 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/13 20:32:21 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

#define R_NAME "RobotomyRequestForm"

class RobotomyRequestForm : public AForm {
private:
  std::string m_target;

public:
  RobotomyRequestForm(std::string const &_target);
  RobotomyRequestForm(RobotomyRequestForm const &src);
  virtual ~RobotomyRequestForm(void);

  RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

  void execute(Bureaucrat const &executor) const;
};

#endif
