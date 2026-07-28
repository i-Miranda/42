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
  static const std::string names[3] = {"shrubbery creation", "robotomy request",
                                       "presidential pardon"};
  static const FormCreator creators[3] = {
      &Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential};

  std::string form = str_to_lower(form_type);

  for (int i = 0; i < 3; ++i) {
    if (form == names[i])
      return (this->*creators[i])(form_target);
  }

  return NULL;
}
