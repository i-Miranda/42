/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:57:39 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/26 16:57:40 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __HUMANA_H__
#define __HUMANA_H__

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanA {
private:
  std::string m_name;
  Weapon &m_weapon;

public:
  HumanA(const std::string &name, Weapon &weapon);
  ~HumanA(void);

  void attack(void) const;
};
#endif
