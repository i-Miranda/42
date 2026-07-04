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

int main(void) {
  std::cout << "CREATING BUREAUCRATS" << std::endl;
  Bureaucrat TestBureaucrat = Bureaucrat("Pedro", 11);
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

  std::cout << "OPERATOR << OVERLOAD" << std::endl;
  std::cout << "TestBureaucrat: " << TestBureaucrat << std::endl;
  std::cout << "CopyBureaucrat: " << CopyBureaucrat << std::endl;
  std::cout << "LowBureaucrat: " << LowBureaucrat << std::endl;
  std::cout << "HighBureaucrat: " << HighBureaucrat << std::endl;

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
    std::cout << "\tGradeTooLowException caught: " << e.what() << std::endl;
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

  std::cout << "DESTROYING BUREAUCRATS" << std::endl;
  return (0);
}
