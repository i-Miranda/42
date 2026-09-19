/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:55:31 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/19 15:29:47 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

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
