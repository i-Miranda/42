/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:17:48 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/19 15:20:30 by ivmirand         ###   ########.fr       */
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
    file << "         ºº                       " << std::endl
         << "     º ººªº                       " << std::endl
         << "      oºº\\ º        xxx          " << std::endl
         << "        ªºªoºº  ª ªªªªoºº         " << std::endl
         << "  ºo   º ºaºª ºº Oºº ºº  v        " << std::endl
         << " ºº º ªººoº// º oª   a  ___,      " << std::endl
         << " ªx\\ ºoºªoºªº a º/ºx//V_/ªººº    " << std::endl
         << "  a ºaX ºXº/ /º ºXoªººº__oo/ O    " << std::endl
         << "   ºoºªoºªºxY ºXxº___//O  oºoªª   " << std::endl
         << "     \\ººXºX_º ___/X Vo º         " << std::endl
         << "      ªYXºXXV_/                   " << std::endl
         << "        /X,/Y                     " << std::endl
         << "       /XX'                       " << std::endl
         << "      KXX'                        " << std::endl
         << "     |XXXXXn                      " << std::endl
         << "    /nXXXAXXuvn                   " << std::endl
         << ",ww/vWwwAwwvwvWu\\Wwvw,vvvwuvWww,." << std::endl;
  } else {
    throw ShrubberyCreationForm::CreationException();
  }
  file.close();
}

char const *ShrubberyCreationForm::CreationException::what() const throw() {
  return "Shrubbery file not created";
}
