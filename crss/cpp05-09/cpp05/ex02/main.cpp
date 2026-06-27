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
#include "Form.hpp"

int main(void) {
  std::cout << "CREATING BUREAUCRATS" << std::endl;
  Bureaucrat TestBureaucrat = Bureaucrat("Pedro", 11);
  Bureaucrat CopyBureaucrat = Bureaucrat(TestBureaucrat);
  Bureaucrat LowBureaucrat = Bureaucrat("Low", 150);
  Bureaucrat HighBureaucrat = Bureaucrat("High", 1);
  try {
    Bureaucrat NegativeBureaucrat = Bureaucrat("Negative", -100);
  } catch (std::exception &e) {
    std::cout << "\tException caught: " << e.what() << std::endl;
  }

  try {
    Bureaucrat ExceptionBureaucrat = Bureaucrat("Too Low", 151);
  } catch (std::exception &e) {
    std::cout << "\tException caught: " << e.what() << std::endl;
  }
  try {
    Bureaucrat ExceptionBureaucrat = Bureaucrat("Too High", 0);
  } catch (std::exception &e) {
    std::cout << "\tException caught: " << e.what() << std::endl;
  }

  std::cout << std::endl;

  std::cout << "CREATING FORMS" << std::endl;
  Form TestForm = Form("Basic", 11, 11);
  Form CopyForm = Form(TestForm);
  Form LowForm = Form("Low", 150, 150);
  Form HighForm = Form("High", 1, 1);
  try {
    Form NegativeForm = Form("Negative", -100, -100);
  } catch (std::exception &e) {
    std::cout << "\tException caught: " << e.what() << std::endl;
  }

  try {
    Form ExceptionForm = Form("Too Low", 151, 151);
  } catch (std::exception &e) {
    std::cout << "\tException caught: " << e.what() << std::endl;
  }
  try {
    Form ExceptionForm = Form("Too High", 0, 0);
  } catch (std::exception &e) {
    std::cout << "\tException caught: " << e.what() << std::endl;
  }

  std::cout << std::endl;

  std::cout << "OPERATOR << OVERLOAD" << std::endl;
  std::cout << "TestBureaucrat: " << TestBureaucrat << std::endl;
  std::cout << "CopyBureaucrat: " << CopyBureaucrat << std::endl;
  std::cout << "LowBureaucrat: " << LowBureaucrat << std::endl;
  std::cout << "HighBureaucrat: " << HighBureaucrat << std::endl;

  std::cout << std::endl;

  std::cout << "TestForm: " << TestForm << std::endl;
  std::cout << "CopyForm: " << CopyForm << std::endl;
  std::cout << "LowForm: " << LowForm << std::endl;
  std::cout << "HighForm: " << HighForm << std::endl;

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
  } catch (std::exception &e) {
    std::cout << "\tException caught: " << e.what() << std::endl;
  }
  std::cout << "LowBureaucrat: " << LowBureaucrat << std::endl;

  try {
    std::cout << "Incrementing HighBureaucrat. (Grade number should "
                 "INCREASE by 1, causing GradeTooHighException.)"
              << std::endl;
    HighBureaucrat.incrementGrade();
  } catch (std::exception &e) {
    std::cout << "\tException caught: " << e.what() << std::endl;
  }
  std::cout << "HighBureaucrat: " << HighBureaucrat << std::endl;

  std::cout << std::endl;

  std::cout << "SIGNING FORMS" << std::endl;
  std::cout << "TestBureaucrat: " << TestBureaucrat << std::endl;
  TestBureaucrat.signForm(TestForm);
  std::cout << "TestForm: " << TestForm << std::endl;
  std::cout << std::endl;
  std::cout << "CopyBureaucrat: " << CopyBureaucrat << std::endl;
  CopyBureaucrat.signForm(CopyForm);
  std::cout << "CopyForm: " << CopyForm << std::endl;
  std::cout << std::endl;
  std::cout << "HighBureaucrat: " << HighBureaucrat << std::endl;
  HighBureaucrat.signForm(LowForm);
  std::cout << "LowForm: " << LowForm << std::endl;
  std::cout << std::endl;
  std::cout << "LowBureaucrat: " << LowBureaucrat << std::endl;
  LowBureaucrat.signForm(HighForm);
  std::cout << "HighForm: " << HighForm << std::endl;
  std::cout << std::endl;

  std::cout << "DESTROYING BUREAUCRATS & FORMS" << std::endl;
  return (0);
}
