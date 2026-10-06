/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 12:59:35 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/06 13:16:44 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
private:
  std::stack<int> m_stack;

public:
  RPN(void);
  RPN(std::string const &input);
  RPN(RPN const &src);
  ~RPN(void);

  RPN &operator=(RPN const &src);
};

#endif
