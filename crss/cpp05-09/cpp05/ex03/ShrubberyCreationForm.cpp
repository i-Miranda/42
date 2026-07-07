/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:17:48 by ivmirand          #+#    #+#             */
/*   Updated: 2026/06/27 16:17:50 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &_target)
    : AForm(_target, 145, 137) {
  std::cout << "Default ShrubberyCreationForm Constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src) {
  std::cout << "Copy ShrubberyCreationForm Constructor called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
  std::cout << "ShrubberyCreationForm Destructor called." << std::endl;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
  std::cout << "ShrubberyCreationForm Copy assignment operator called."
            << std::endl;
  if (this != &src) {
    AForm::operator=(src);
  }
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  std::ofstream file;
  std::string target;

  AForm::execute(executor);
  target = getName() + "_shrubbery";
  file.open(target.c_str(), std::ios_base::out);
  file << "         ºº                       \n"
       << "     º ººªº                       \n"
       << "      oºº\\ º        xxx          \n"
       << "        ªºªoºº  ª ªªªªoºº         \n"
       << "  ºo   º ºaºª ºº Oºº ºº  v        \n"
       << " ºº º ªººoº// º oª   a  ___,      \n"
       << " ªx\\ ºoºªoºªº a º/ºx//V_/ªººº    \n"
       << "  a ºaX ºXº/ /º ºXoªººº__oo/ O    \n"
       << "   ºoºªoºªºxY ºXxº___//O  oºoªª   \n"
       << "     \\ººXºX_º ___/X Vo º         \n"
       << "      ªYXºXXV_/                   \n"
       << "        /X,/Y                     \n"
       << "       /XX'                       \n"
       << "      KXX'                        \n"
       << "     |XXXXXn                      \n"
       << "    /nXXXAXXuvn                   \n"
       << ",ww/vWwwAwwvwvWu\\Wwvw,vvvwuvWww,.\n";
  file.close();
}
