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

static void exceptionMessage(std::exception const &e,
                             std::string const &e_name) {
  std::cout << "\t" << e_name << " caught : " << e.what() << std::endl;
}

int main(void) {
  std::cout << "CREATING BUREAUCRATS" << std::endl;

  Bureaucrat TestBureaucrat = Bureaucrat("Pedro", 11);
  Bureaucrat CopyBureaucrat = Bureaucrat(TestBureaucrat);
  Bureaucrat MinRankBureaucrat = Bureaucrat("MinRankBureaucrat", 150);
  Bureaucrat MaxRankBureaucrat = Bureaucrat("MaxRankBureaucrat", 1);

  try {
    Bureaucrat NegativeBureaucrat = Bureaucrat("Negative", -100);
  } catch (Bureaucrat::GradeTooHighException const &e) {
    exceptionMessage(e, "Bureaucrat::GradeTooHighException");
  }
  try {
    Bureaucrat ExceptionBureaucrat = Bureaucrat("Too Low", 151);
  } catch (Bureaucrat::GradeTooLowException const &e) {
    exceptionMessage(e, "Bureaucrat::GradeTooLowException");
  }
  try {
    Bureaucrat ExceptionBureaucrat = Bureaucrat("Too High", 0);
  } catch (Bureaucrat::GradeTooHighException const &e) {
    exceptionMessage(e, "Bureaucrat::GradeTooHighException");
    std::cout << "\tGradeTooHighException caught: " << e.what() << std::endl;
  }

  std::cout << std::endl;

  std::cout << "OPERATOR << OVERLOAD" << std::endl;

  std::cout << TestBureaucrat << std::endl;
  std::cout << CopyBureaucrat << std::endl;
  std::cout << MinRankBureaucrat << std::endl;
  std::cout << MaxRankBureaucrat << std::endl;

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

  std::cout << "DESTROYING BUREAUCRATS" << std::endl;
  return (0);
}
