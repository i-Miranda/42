/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:53:40 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/13 00:58:43 by ivmirand         ###   ########.fr       */
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

  std::cout << std::endl;

  std::cout << "TESTING BUREAUCRAT EXCEPTIONS DURING CREATION" << std::endl;
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
  }

  std::cout << std::endl;

  std::cout << "OPERATOR << OVERLOAD" << std::endl;

  std::cout << TestBureaucrat << std::endl;
  std::cout << CopyBureaucrat << std::endl;
  std::cout << MinRankBureaucrat << std::endl;
  std::cout << MaxRankBureaucrat << std::endl;

  std::cout << std::endl;

  std::cout << "INCREMENT/DECREMENT TESTS" << std::endl;

  std::cout << INCREMENT << TestBureaucrat << DECREASE << ".)" << std::endl;
  TestBureaucrat.incrementGrade();
  std::cout << TestBureaucrat << std::endl;

  std::cout << DECREMENT << TestBureaucrat << INCREASE ".)" << std::endl;
  TestBureaucrat.decrementGrade();
  std::cout << TestBureaucrat << std::endl;

  std::cout << std::endl;

  std::cout << "INCREMENT/DECREMENT EXCEPTION TESTS" << std::endl;
  try {
    std::cout << DECREMENT << MinRankBureaucrat << INCREASE
              << ", causing GradeTooLowException.)" << std::endl;
    MinRankBureaucrat.decrementGrade();
  } catch (Bureaucrat::GradeTooLowException const &e) {
    exceptionMessage(e, "Bureaucrat::GradeTooLowException");
  }
  std::cout << MinRankBureaucrat << std::endl;

  try {
    std::cout << INCREMENT << MaxRankBureaucrat << DECREASE
              << ", causing GradeTooHighException.)" << std::endl;
    MaxRankBureaucrat.incrementGrade();
  } catch (Bureaucrat::GradeTooHighException const &e) {
    exceptionMessage(e, "Bureaucrat::GradeTooHighException");
  }
  std::cout << MaxRankBureaucrat << std::endl;

  std::cout << std::endl;

  std::cout << "DESTROYING BUREAUCRATS" << std::endl;
  return (0);
}
