/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:57:45 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/26 16:57:47 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __HUMANB_H__
#define __HUMANB_H__

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanB {
private:
  std::string m_name;
  Weapon *m_weapon;

public:
  HumanB(const std::string &name);
  ~HumanB(void);

  void setWeapon(Weapon &weapon);
  void attack(void) const;
};
#endif
