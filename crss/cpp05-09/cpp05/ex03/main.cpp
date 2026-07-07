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
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

static void exceptionMessage(std::exception const &e,
                             std::string const &e_name) {
  std::cout << "\t" << e_name << " caught : " << e.what() << std::endl;
}

int main(void) {
  // Generating random seed from current time
  std::srand(std::time(NULL));

  std::cout << "CREATING BUREAUCRATS" << std::endl;

  Bureaucrat TestBureaucrat = Bureaucrat("Pedro", 11);
  Bureaucrat CopyBureaucrat = Bureaucrat(TestBureaucrat);
  Bureaucrat MinRankBureaucrat = Bureaucrat("MinRankBureaucrat", 150);
  Bureaucrat MaxRankBureaucrat = Bureaucrat("MaxRankBureaucrat", 1);

  Bureaucrat ShrubLowRankSignBureaucrat =
      Bureaucrat("ShrubLowRankSignBureaucrat", 146);
  Bureaucrat ShrubLowRankExecBureaucrat =
      Bureaucrat("ShrubLowRankExecBureaucrat", 145);
  Bureaucrat ShrubHighRankExecBureaucrat =
      Bureaucrat("ShrubHighRankExecBureaucrat", 137);
  Bureaucrat PresLowRankSignBureaucrat =
      Bureaucrat("PresLowRankSignBureaucrat", 26);
  Bureaucrat PresLowRankExecBureaucrat =
      Bureaucrat("PresLowRankExecBureaucrat", 25);
  Bureaucrat PresHighRankExecBureaucrat =
      Bureaucrat("PresHighRankExecBureaucrat", 5);
  Bureaucrat RoboLowRankSignBureaucrat =
      Bureaucrat("RoboLowRankSignBureaucrat", 76);
  Bureaucrat RoboLowRankExecBureaucrat =
      Bureaucrat("RoboLowRankExecBureaucrat", 72);
  Bureaucrat RoboHighRankExecBureaucrat =
      Bureaucrat("RoboHighRankExecBureaucrat", 45);

  try {
    Bureaucrat NegativeBureaucrat = Bureaucrat("Negative", -100);
  } catch (Bureaucrat::GradeTooHighException const &e) {
    std::cout << "\tGradeTooHighException caught: " << e.what() << std::endl;
  }

  try {
    Bureaucrat ExceptionBureaucrat = Bureaucrat("Too Low", 151);
  } catch (Bureaucrat::GradeTooLowException const &e) {
    std::cout << "\tGradeTooLowException caught: " << e.what() << std::endl;
  }
  try {
    Bureaucrat ExceptionBureaucrat = Bureaucrat("Too High", 0);
  } catch (Bureaucrat::GradeTooHighException const &e) {
    std::cout << "\tGradeTooHighException caught: " << e.what() << std::endl;
  }

  std::cout << std::endl;

  std::cout << "CREATING INTERN" << std::endl;
  Intern TestIntern;

  std::cout << std::endl;

  std::cout << "CREATING FORMS" << std::endl;
  AForm *ShrubForm = TestIntern.makeForm("shrubbery creation", "Shrub");
  AForm *PresForm = TestIntern.makeForm("presidential pardon", "Pres");
  AForm *RoboForm = TestIntern.makeForm("robotomy request", "Robo");

  std::cout << std::endl;

  std::cout << "OPERATOR << OVERLOAD" << std::endl;

  std::cout << TestBureaucrat << std::endl;
  std::cout << CopyBureaucrat << std::endl;

  std::cout << ShrubLowRankSignBureaucrat << std::endl;
  std::cout << ShrubLowRankExecBureaucrat << std::endl;
  std::cout << ShrubHighRankExecBureaucrat << std::endl;

  std::cout << PresLowRankSignBureaucrat << std::endl;
  std::cout << PresLowRankExecBureaucrat << std::endl;
  std::cout << PresHighRankExecBureaucrat << std::endl;

  std::cout << RoboLowRankSignBureaucrat << std::endl;
  std::cout << RoboLowRankExecBureaucrat << std::endl;
  std::cout << RoboHighRankExecBureaucrat << std::endl;

  std::cout << std::endl;

  std::cout << *ShrubForm << std::endl;
  std::cout << *PresForm << std::endl;
  std::cout << *RoboForm << std::endl;

  std::cout << std::endl;

  std::cout << "INCREMENT/DECREMENT TESTS" << std::endl;

  std::cout << "Incrementing " << TestBureaucrat
            << " (Grade number should DECREASE by 1.)" << std::endl;
  TestBureaucrat.incrementGrade();
  std::cout << TestBureaucrat << std::endl;

  std::cout << "Decrementing " << TestBureaucrat
            << " (Grade number should INCREASE by 1.)" << std::endl;
  TestBureaucrat.decrementGrade();
  std::cout << TestBureaucrat << std::endl;

  try {
    std::cout
        << "Decrementing " << MinRankBureaucrat
        << " (Grade number should DECREASE by 1, causing GradeTooLowException.)"
        << std::endl;
    MinRankBureaucrat.decrementGrade();
  } catch (Bureaucrat::GradeTooLowException const &e) {
    exceptionMessage(e, "Bureaucrat::GradeTooLowException");
  }
  std::cout << MinRankBureaucrat << std::endl;

  try {
    std::cout << "Incrementing " << MaxRankBureaucrat
              << " (Grade number should INCREASE by 1, causing "
                 "GradeTooHighException.)"
              << std::endl;
    MaxRankBureaucrat.incrementGrade();
  } catch (Bureaucrat::GradeTooHighException const &e) {
    exceptionMessage(e, "Bureaucrat::GradeTooHighException");
  }
  std::cout << MaxRankBureaucrat << std::endl;

  std::cout << std::endl;

  std::cout << "SIGNING FORMS" << std::endl;
  std::cout << "Signing ShrubberyCreationForm" << std::endl;
  std::cout << ShrubLowRankSignBureaucrat << std::endl;
  ShrubLowRankSignBureaucrat.signForm(*ShrubForm);
  std::cout << *ShrubForm << std::endl;
  std::cout << std::endl;
  std::cout << ShrubLowRankExecBureaucrat << std::endl;
  ShrubLowRankExecBureaucrat.signForm(*ShrubForm);
  std::cout << *ShrubForm << std::endl;
  std::cout << std::endl;
  std::cout << "Signing PresidentialPardonForm" << std::endl;
  std::cout << PresLowRankSignBureaucrat << std::endl;
  PresLowRankSignBureaucrat.signForm(*PresForm);
  std::cout << *PresForm << std::endl;
  std::cout << std::endl;
  std::cout << PresLowRankExecBureaucrat << std::endl;
  PresLowRankExecBureaucrat.signForm(*PresForm);
  std::cout << *PresForm << std::endl;
  std::cout << std::endl;
  std::cout << "Signing RobotomyRequestForm" << std::endl;
  std::cout << RoboLowRankSignBureaucrat << std::endl;
  RoboLowRankSignBureaucrat.signForm(*RoboForm);
  std::cout << *RoboForm << std::endl;
  std::cout << std::endl;
  std::cout << RoboLowRankExecBureaucrat << std::endl;
  RoboLowRankExecBureaucrat.signForm(*RoboForm);
  std::cout << *RoboForm << std::endl;
  std::cout << std::endl;

  std::cout << "EXECUTING FORMS" << std::endl;
  std::cout << "Executing ShrubberyCreationForm" << std::endl;
  std::cout << ShrubLowRankExecBureaucrat << std::endl;
  ShrubLowRankExecBureaucrat.executeForm(*ShrubForm);
  std::cout << *ShrubForm << std::endl;
  std::cout << std::endl;
  std::cout << ShrubHighRankExecBureaucrat << std::endl;
  ShrubHighRankExecBureaucrat.executeForm(*ShrubForm);
  std::cout << *ShrubForm << std::endl;
  std::cout << std::endl;
  std::cout << "Executing PresidentialPardonForm" << std::endl;
  std::cout << PresLowRankExecBureaucrat << std::endl;
  PresLowRankExecBureaucrat.executeForm(*PresForm);
  std::cout << *PresForm << std::endl;
  std::cout << std::endl;
  std::cout << PresHighRankExecBureaucrat << std::endl;
  PresHighRankExecBureaucrat.executeForm(*PresForm);
  std::cout << *PresForm << std::endl;
  std::cout << std::endl;
  std::cout << "Signing RobotomyRequestForm" << std::endl;
  std::cout << RoboLowRankExecBureaucrat << std::endl;
  RoboLowRankSignBureaucrat.signForm(*RoboForm);
  std::cout << *RoboForm << std::endl;
  std::cout << std::endl;
  std::cout << RoboHighRankExecBureaucrat << std::endl;
  RoboHighRankExecBureaucrat.signForm(*RoboForm);
  std::cout << *RoboForm << std::endl;
  std::cout << std::endl;

  std::cout << "DESTROYING BUREAUCRATS & FORMS" << std::endl;
  delete ShrubForm;
  delete PresForm;
  delete RoboForm;
  return (0);
}
