/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:40:24 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/19 16:59:37 by ivmirand         ###   ########.fr       */
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

AForm *Intern::makeShrubbery(std::string const &target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomy(std::string const &target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidential(std::string const &target) {
  return new PresidentialPardonForm(target);
}

Intern::Intern(void) {
  std::cout << "Default Intern Constructor called." << std::endl;
}

Intern::Intern(Intern const &src) {
  std::cout << "Copy Intern Constructor called." << std::endl;
  *this = src;
}

Intern &Intern::operator=(Intern const &src) {
  std::cout << "Copy assignment operator called." << std::endl;
  (void)src;
  return *this;
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
    if (form == names[i]) {
      AForm *created = (this->*creators[i])(form_target);
      std::cout << "Intern creates " << form_type << std::endl;
      return created;
    }
  }
  std::cout << "Intern couldn't create " << form_type
            << ". The form type is unknown." << std::endl;

  return NULL;
}
