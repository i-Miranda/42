/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:55:01 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/01 19:59:55 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const _name, unsigned int _grade) :	m_name(_name), 
																		m_grade(_grade) {
	std::cout << "Default Bureaucrat Constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : m_name(src.getName()) {
	std::cout << "Copy Bureaucrat Constructor called." << std::endl;
	if (this != &src) {
		try {
			this->m_grade = src.getGrade();
		} catch (std::exception & e) {
			std::cerr << &e << std::endl;
		}
	}
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat Destructor called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	std::cout << "Copy Assignment Bureaucrat Constructor called." << std::endl;
	Bureaucrat bureaucrat = Bureaucrat(src);
	return bureaucrat;
}

void		Bureaucrat::operator<<(std::string const string) {
	std::string new_string;
	
	new_string.append(string + " " + this->getName() + ", bureaucrat grade ");
	std::cout << new_string << this->getGrade() << std::endl;
}

void		Bureaucrat::operator++(void) {
	unsigned int new_grade;

	new_grade = this->getGrade() + 1;
	if (new_grade > 150)
		throw GradeTooHighException(GRADETOOHIGH);
	if (new_grade < 1)
		throw GradeTooLowException(GRADETOOLOW);
	this->m_grade = new_grade;
}

void		Bureaucrat::operator--(void) {
	unsigned int new_grade;

	new_grade = this->getGrade() - 1;
	if (new_grade > 150)
		throw GradeTooHighException(GRADETOOHIGH);
	if (new_grade < 1)
		throw GradeTooLowException(GRADETOOLOW);
	this->m_grade = new_grade;
}

void		Bureaucrat::operator+(unsigned int increment) {
	unsigned int new_grade;

	new_grade = this->getGrade() + increment;
	if (new_grade > 150)
		throw GradeTooHighException(GRADETOOHIGH);
	if (new_grade < 1)
		throw GradeTooLowException(GRADETOOLOW);
	this->m_grade = new_grade;
}

void		Bureaucrat::operator-(unsigned int decrement) {
	unsigned int new_grade;

	new_grade = this->getGrade() + decrement;
	if (new_grade > 150)
		throw GradeTooHighException(GRADETOOHIGH);
	if (new_grade < 1)
		throw GradeTooLowException(GRADETOOLOW);
	this->m_grade = new_grade;
}

std::string const Bureaucrat::getName(void) const {
	return this->m_name;
}

unsigned int	Bureaucrat::getGrade(void) const {
	return this->m_grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string const msg) {
	std::cerr << msg << std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string const msg) {
	std::cerr << msg << std::endl;
}
