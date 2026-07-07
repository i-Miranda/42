/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:40:24 by ivmirand          #+#    #+#             */
/*   Updated: 2026/07/04 13:40:25 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cctype>

static std::string str_to_lower(std::string const &str) {
  std::string new_str;
  new_str.reserve(str.length());
  for (size_t i = 0; i < str.length(); i++) {
    new_str.push_back(
        static_cast<char>(std::tolower(static_cast<unsigned char>(str[i]))));
  }
  return (new_str);
}

Intern::Intern(void) {
  std::cout << "Default Intern Constructor called." << std::endl;
}

Intern::~Intern(void) { std::cout << "Intern Destructor called." << std::endl; }

AForm *Intern::makeForm(std::string const &form_type,
                        std::string const &form_target) {
  AForm *form;
  std::string form_to_lower = str_to_lower(form_type);

  if (form_to_lower == "shrubbery creation")
    form = new ShrubberyCreationForm(form_target);
  else if (form_to_lower == "presidential pardon")
    form = new PresidentialPardonForm(form_target);
  else if (form_to_lower == "robotomy request")
    form = new RobotomyRequestForm(form_target);
  else
    form = NULL;
  return form;
}
