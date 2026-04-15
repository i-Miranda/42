/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:55:31 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/01 19:28:16 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <string>
#include <iostream>
#include <exception>

#define GRADETOOHIGH "Grade value to high. Grade must be an integer between 1 and 150."
#define GRADETOOLOW "Grade value to low. Grade must be an integer between 1 and 150."

class Bureaucrat {
	private :
		std::string const m_name;
		unsigned int m_grade;
	public :
		Bureaucrat(std::string const _name, unsigned int _grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat(void);

		class GradeTooHighException : public std::exception {
			public:
				GradeTooHighException(std::string const msg);
		};

		class GradeTooLowException : public std::exception {
			public:
				GradeTooLowException(std::string const msg);
		};

		Bureaucrat& operator=(const Bureaucrat& src);
		void		operator<<(std::string const string);
		void		operator++(void);
		void		operator--(void);
		void		operator+(unsigned int increment);
		void		operator-(unsigned int decrement);

		std::string const getName(void) const;
		unsigned int 	getGrade(void) const;
};

#endif
