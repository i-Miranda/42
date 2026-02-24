/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:27:03 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/13 12:57:33 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "file.hpp"

static std::string trim(const std::string &str)
{
	size_t start = str.find_first_not_of(" \t\n");
	if (start == std::string::npos)
		return ("");
	size_t end = str.find_last_not_of(" \t\n");
	if (end == std::string::npos)
		return ("");
	return (str.substr(start, end + 1));
}

int main(int argc, char *argv[])
{
	std::string filename;
	std::string s1;
	std::string s2;
	File	*file;

	if (argc != 4)
		return (std::cerr << "Wrong arg count: " << argc - 1 << ". Must be three args." << std::endl, 1);
	filename = trim(argv[1]);
	s1 = trim(argv[2]);
	s2 = trim(argv[3]);

	std::cout << filename << ", " << s1 << ", " << s2 << "\n";
	
	file = new File(filename);
	file->substitute(s1, s2);
	delete file;
	return (0);
}
