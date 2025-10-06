/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 22:30:06 by ivmirand          #+#    #+#             */
/*   Updated: 2025/09/29 13:29:10 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstring>
#include <string>

static std::string str_to_caps(char *str)
{
	std::string	new_str;

	new_str.reserve(std::strlen(str));
	for (size_t i = 0; str[i]; i++)
	{
		new_str.push_back(static_cast<char>(
					std::toupper(static_cast<unsigned char>(str[i]))));
	}
	return (new_str);
}

int	main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
		std::cout << str_to_caps(argv[i]);
	std::cout << std::endl;
	return (0);
}
