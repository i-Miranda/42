/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:17:48 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/19 15:27:02 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &_target)
    : AForm("ShrubberyCreationForm", 145, 137), m_target(_target) {
  std::cout << "Default ShrubberyCreationForm Constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
    : AForm(src), m_target(src.m_target) {
  std::cout << "Copy ShrubberyCreationForm Constructor called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
  std::cout << "ShrubberyCreationForm Destructor called." << std::endl;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) {
  std::cout << "ShrubberyCreationForm Copy assignment operator called."
            << std::endl;
  if (this != &src) {
    AForm::operator=(src);
    m_target = src.m_target;
  }
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  std::ofstream file;
  std::string target;

  AForm::execute(executor);
  target = m_target + "_shrubbery";
  file.open(target.c_str(), std::ios_base::out);
  if (!file.fail()) {
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
  } else {
    throw ShrubberyCreationForm::CreationException();
  }
  file.close();
}

char const *ShrubberyCreationForm::CreationException::what() const throw() {
  return "Shrubbery file not created";
}
