/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:17:48 by ivmirand          #+#    #+#             */
/*   Updated: 2026/06/27 16:17:50 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &_target)
    : AForm(_target, 25, 5) {
  std::cout << "Default PresidentialPardonForm Constructor called."
            << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &src)
    : AForm(src) {
  std::cout << "Copy PresidentialPardonForm Constructor called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
  std::cout << "PresidentialPardonForm Destructor called." << std::endl;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
  std::cout << "PresidentialPardonForm Copy assignment operator called."
            << std::endl;
  if (this != &src) {
    AForm::operator=(src);
  }
  return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  AForm::execute(executor);
  std::cout << getName() << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
