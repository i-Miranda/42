/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:53:40 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/26 17:04:26 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  std::cout << "CREATING BUREAUCRATS" << std::endl;
  Bureaucrat TestBureaucrat = Bureaucrat("Pedro", 70);
  Bureaucrat CopyBureaucrat = Bureaucrat(TestBureaucrat);
  Bureaucrat LowBureaucrat = Bureaucrat("Low", 150);
  Bureaucrat HighBureaucrat = Bureaucrat("High", 1);
  try {
    Bureaucrat NegativeBureaucrat = Bureaucrat("Negative", -100);
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cout << "\tGradeTooHighException caught: " << e.what() << std::endl;
  }

  try {
    Bureaucrat ExceptionBureaucrat = Bureaucrat("Too Low", 151);
  } catch (Bureaucrat::GradeTooLowException &e) {
    std::cout << "\tGradeTooLowException caught: " << e.what() << std::endl;
  }
  try {
    Bureaucrat ExceptionBureaucrat = Bureaucrat("Too High", 0);
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cout << "\tGradeTooHighException caught: " << e.what() << std::endl;
  }

  std::cout << std::endl;

  std::cout << "CREATING FORMS" << std::endl;
  ShrubberyCreationForm ShrubForm = ShrubberyCreationForm("Shrub");
  PresidentialPardonForm PresForm = PresidentialPardonForm("Pres");
  RobotomyRequestForm RoboForm = RobotomyRequestForm("Robo");

  std::cout << std::endl;

  std::cout << "OPERATOR << OVERLOAD" << std::endl;
  std::cout << "TestBureaucrat: " << TestBureaucrat << std::endl;
  std::cout << "CopyBureaucrat: " << CopyBureaucrat << std::endl;
  std::cout << "LowBureaucrat: " << LowBureaucrat << std::endl;
  std::cout << "HighBureaucrat: " << HighBureaucrat << std::endl;

  std::cout << std::endl;

  std::cout << ShrubForm.getName() << ": " << ShrubForm << std::endl;
  std::cout << PresForm.getName() << ": " << PresForm << std::endl;
  std::cout << RoboForm.getName() << ": " << RoboForm << std::endl;

  std::cout << std::endl;

  std::cout << "INCREMENT/DECREMENT TESTS" << std::endl;
  std::cout
      << "Incrementing TestBureaucrat. (Grade number should DECREASE by 1.)"
      << std::endl;
  TestBureaucrat.incrementGrade();
  std::cout << "TestBureaucrat: " << TestBureaucrat << std::endl;

  std::cout
      << "Decrementing TestBureaucrat. (Grade number should INCREASE by 1.)"
      << std::endl;
  TestBureaucrat.decrementGrade();
  std::cout << "TestBureaucrat: " << TestBureaucrat << std::endl;

  try {
    std::cout << "Decrementing LowBureaucrat. (Grade number should "
                 "INCREASE by 1, causing GradeTooLowException.)"
              << std::endl;
    LowBureaucrat.decrementGrade();
  } catch (Bureaucrat::GradeTooLowException &e) {
    std::cout << "\tException caught: " << e.what() << std::endl;
  }
  std::cout << "LowBureaucrat: " << LowBureaucrat << std::endl;

  try {
    std::cout << "Incrementing HighBureaucrat. (Grade number should "
                 "INCREASE by 1, causing GradeTooHighException.)"
              << std::endl;
    HighBureaucrat.incrementGrade();
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cout << "\tGradeTooHighException caught: " << e.what() << std::endl;
  }
  std::cout << "HighBureaucrat: " << HighBureaucrat << std::endl;

  std::cout << std::endl;

  std::cout << "SIGNING FORMS" << std::endl;
  std::cout << "TestBureaucrat: " << TestBureaucrat << std::endl;
  TestBureaucrat.signForm(ShrubForm);
  std::cout << ShrubForm.getName() << ": " << ShrubForm << std::endl;
  std::cout << std::endl;
  TestBureaucrat.signForm(PresForm);
  std::cout << PresForm.getName() << ": " << PresForm << std::endl;
  std::cout << std::endl;
  TestBureaucrat.signForm(RoboForm);
  std::cout << RoboForm.getName() << ": " << RoboForm << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "EXECUTING FORMS" << std::endl;
  std::cout << "TestBureaucrat: " << TestBureaucrat << std::endl;
  TestBureaucrat.executeForm(ShrubForm);
  std::cout << ShrubForm.getName() << ": " << ShrubForm << std::endl;
  std::cout << std::endl;
  TestBureaucrat.executeForm(PresForm);
  std::cout << PresForm.getName() << ": " << PresForm << std::endl;
  std::cout << std::endl;
  TestBureaucrat.executeForm(RoboForm);
  std::cout << RoboForm.getName() << ": " << RoboForm << std::endl;
  std::cout << std::endl;

  std::cout << "DESTROYING BUREAUCRATS & FORMS" << std::endl;
  return (0);
}
