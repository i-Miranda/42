/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:17:48 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/19 15:18:02 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string const &_target)
    : AForm("RobotomyRequestForm", 72, 45), m_target(_target) {
  std::cout << "Default RobotomyRequestForm Constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
    : AForm(src), m_target(src.m_target) {
  std::cout << "Copy RobotomyRequestForm Constructor called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
  std::cout << "RobotomyRequestForm Destructor called." << std::endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &src) {
  std::cout << "RobotomyRequestForm Copy assignment operator called."
            << std::endl;
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
    std::cout << m_target << " has been robotomized successfully." << std::endl;
  else
    std::cout << m_target << "'s robotomy has failed." << std::endl;
}
