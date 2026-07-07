/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:17:48 by ivmirand          #+#    #+#             */
/*   Updated: 2026/06/27 16:17:50 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string const &_target)
    : AForm(_target, 72, 45) {
  std::cout << "Default RobotomyRequestForm Constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src) {
  std::cout << "Copy RobotomyRequestForm Constructor called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
  std::cout << "RobotomyRequestForm Destructor called." << std::endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
  std::cout << "RobotomyRequestForm Copy assignment operator called."
            << std::endl;
  if (this != &src) {
    AForm::operator=(src);
  }
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  AForm::execute(executor);
  std::cout << executor.getName() << " makes some drilling noises."
            << std::endl;
  if (std::rand() % 2 == 0)
    std::cout << executor.getName() << " has been robotomized succesfully."
              << std::endl;
  else
    std::cout << executor.getName() << "'s robotomy has failed." << std::endl;
}
