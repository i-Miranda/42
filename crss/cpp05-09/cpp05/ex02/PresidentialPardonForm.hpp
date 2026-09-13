/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:55:31 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/13 18:41:17 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

#define P_NAME "PresidentialPardonForm"

class PresidentialPardonForm : public AForm {
private:
  std::string m_target;

public:
  PresidentialPardonForm(std::string const &_target);
  PresidentialPardonForm(PresidentialPardonForm const &src);
  virtual ~PresidentialPardonForm(void);

  PresidentialPardonForm &operator=(PresidentialPardonForm const &src);

  void execute(Bureaucrat const &executor) const;
};

#endif
