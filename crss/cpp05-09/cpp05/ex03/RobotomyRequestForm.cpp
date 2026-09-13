/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:17:48 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/13 20:32:34 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string const &_target)
    : AForm(R_NAME, 72, 45), m_target(_target) {
  std::cout << "Default " << R_NAME << " Constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
    : AForm(src), m_target(src.m_target) {
  std::cout << "Copy " << R_NAME << " Constructor called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
  std::cout << R_NAME << " Destructor called." << std::endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &src) {
  std::cout << R_NAME << " Copy assignment operator called." << std::endl;
  if (this != &src) {
    AForm::operator=(src);
    m_target = src.m_target;
  }
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  AForm::execute(executor);
  std::cout << executor.getName() << " makes some drilling noises."
            << std::endl;
  if (std::rand() % 2 == 0)
    std::cout << m_target << " has been robotomized succesfully." << std::endl;
  else
    std::cout << m_target << "'s robotomy has failed." << std::endl;
}
