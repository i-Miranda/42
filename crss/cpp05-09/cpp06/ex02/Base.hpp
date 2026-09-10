/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:45:52 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/07 13:45:59 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
  virtual ~Base();
};

Base *generate(void);

void identify(Base *p);

void identify(Base &p);

#endif
