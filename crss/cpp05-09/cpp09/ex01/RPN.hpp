/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 12:59:35 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/10 11:49:09 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
private:
  std::stack<int> m_stack;

  void clear_stack(void);
  bool is_operator(char c) const;
  int perform_operation(int a, char oper, int b);

public:
  RPN(void);
  RPN(RPN const &src);
  ~RPN(void);

  RPN &operator=(RPN const &src);

  int calculate(std::string const &input);
};

#endif
