/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:40:30 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/19 15:40:16 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
private:
  typedef AForm *(Intern::*FormCreator)(std::string const &);

  AForm *makeShrubbery(std::string const &target);
  AForm *makeRobotomy(std::string const &target);
  AForm *makePresidential(std::string const &target);

public:
  Intern(void);
  Intern(Intern const &src);
  Intern &operator=(Intern const &src);
  ~Intern(void);

  AForm *makeForm(std::string const &form_type, std::string const &form_target);
};

#endif
