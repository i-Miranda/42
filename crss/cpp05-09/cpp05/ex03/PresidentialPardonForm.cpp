/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:17:48 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/19 15:29:19 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &_target)
    : AForm("PresidentialPardonForm", 25, 5), m_target(_target) {
  std::cout << "Default PresidentialPardonForm Constructor called."
            << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &src)
    : AForm(src), m_target(src.m_target) {
  std::cout << "Copy PresidentialPardonForm Constructor called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
  std::cout << "PresidentialPardonForm Destructor called." << std::endl;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &src) {
  std::cout << "PresidentialPardonForm Copy assignment operator called."
            << std::endl;
  if (this != &src) {
    AForm::operator=(src);
    m_target = src.m_target;
  }
  return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  AForm::execute(executor);
  std::cout << m_target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
