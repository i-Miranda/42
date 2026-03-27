/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:57:51 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/26 16:57:52 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <string>

class Weapon {
private:
  std::string m_type;

public:
  Weapon(const std::string &type);
  ~Weapon(void);

  const std::string &getType(void) const;
  void setType(const std::string &type);
};
#endif
