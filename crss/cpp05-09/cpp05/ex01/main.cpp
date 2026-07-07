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

static void exceptionMessage(std::exception const &e,
                             std::string const &e_name) {
  std::cout << "\t" << e_name << " caught : " << e.what() << std::endl;
}

int main(void) {
  std::cout << "CREATING BUREAUCRATS" << std::endl;

  Bureaucrat TestBureaucrat = Bureaucrat("Pedro", 11);
  Bureaucrat CopyBureaucrat = Bureaucrat(TestBureaucrat);
  Bureaucrat LowRankBureaucrat = Bureaucrat("LowRankBureaucrat", 150);
  Bureaucrat HighRankBureaucrat = Bureaucrat("HighRankBureaucrat", 1);

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

  std::cout << "CREATING FORMS" << std::endl;
  Form TestForm = Form("Basic", 11, 11);
  Form CopyForm = Form(TestForm);
  Form LowReqForm = Form("LowReqForm", 150, 150);
  Form HighReqForm = Form("HighReqForm", 1, 1);

  try {
    Form NegativeForm = Form("Negative", -100, -100);
  } catch (Form::GradeTooHighException const &e) {
    exceptionMessage(e, "Form::GradeTooHighException");
  }
  try {
    Form ExceptionForm = Form("Too Low", 151, 151);
  } catch (Form::GradeTooLowException const &e) {
    exceptionMessage(e, "Form::GradeTooLowException");
  }
  try {
    Form ExceptionForm = Form("Too High", 0, 0);
  } catch (Form::GradeTooHighException const &e) {
    exceptionMessage(e, "Form::GradeTooHighException");
  }

  std::cout << std::endl;

  std::cout << "OPERATOR << OVERLOAD" << std::endl;

  std::cout << TestBureaucrat << std::endl;
  std::cout << CopyBureaucrat << std::endl;
  std::cout << LowRankBureaucrat << std::endl;
  std::cout << HighRankBureaucrat << std::endl;

  std::cout << std::endl;

  std::cout << TestForm << std::endl;
  std::cout << CopyForm << std::endl;
  std::cout << LowReqForm << std::endl;
  std::cout << HighReqForm << std::endl;

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
        << "Decrementing " << LowRankBureaucrat
        << " (Grade number should DECREASE by 1, causing GradeTooLowException.)"
        << std::endl;
    LowRankBureaucrat.decrementGrade();
  } catch (Bureaucrat::GradeTooLowException const &e) {
    exceptionMessage(e, "Bureaucrat::GradeTooLowException");
  }
  std::cout << LowRankBureaucrat << std::endl;

  try {
    std::cout << "Incrementing " << HighRankBureaucrat
              << " (Grade number should INCREASE by 1, causing "
                 "GradeTooHighException.)"
              << std::endl;
    HighRankBureaucrat.incrementGrade();
  } catch (Bureaucrat::GradeTooHighException const &e) {
    exceptionMessage(e, "Bureaucrat::GradeTooHighException");
  }
  std::cout << HighRankBureaucrat << std::endl;

  std::cout << std::endl;

  std::cout << "SIGNING FORMS" << std::endl;

  std::cout << TestBureaucrat << std::endl;
  TestBureaucrat.signForm(TestForm);
  std::cout << TestForm << std::endl;
  std::cout << std::endl;
  std::cout << CopyBureaucrat << std::endl;
  CopyBureaucrat.signForm(CopyForm);
  std::cout << CopyForm << std::endl;
  std::cout << std::endl;
  std::cout << HighRankBureaucrat << std::endl;
  HighRankBureaucrat.signForm(LowReqForm);
  std::cout << LowReqForm << std::endl;
  std::cout << std::endl;
  std::cout << LowRankBureaucrat << std::endl;
  LowRankBureaucrat.signForm(HighReqForm);
  std::cout << HighReqForm << std::endl;
  std::cout << std::endl;

  std::cout << "DESTROYING BUREAUCRATS & FORMS" << std::endl;
  return (0);
}
