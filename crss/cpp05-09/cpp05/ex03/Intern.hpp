/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:40:30 by ivmirand          #+#    #+#             */
/*   Updated: 2026/07/04 13:40:31 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class Intern {
private:
  Intern(const Intern &src);

  Intern &operator=(const Intern &src);

public:
  Intern(void);
  ~Intern(void);

  AForm *makeForm(std::string const &form_type, std::string const &form_target);
};
