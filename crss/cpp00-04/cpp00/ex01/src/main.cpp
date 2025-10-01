/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:15:28 by ivmirand          #+#    #+#             */
/*   Updated: 2025/10/01 22:34:31 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

static std::string	_get_command_input(void) {
	std::string input;
	std::string input_to_upper;
	int			input_len;

	std::cout << "Options:" << std::endl;
	std::cout << "\t ADD: ";
	std::cout << "save a new contact" << std::endl;
	std::cout << "\t SEARCH: ";
	std::cout << "display a specific contact" << std::endl;
	std::cout << "\t EXIT: ";
	std::cout << "exit the program" << std::endl;
	std::cout << "Please input a command: ";
	
	std::getline(std::cin, input);
	if (std::cin.eof()) {
		std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
		std::exit(0);
	}
	
	input_len = input.length();
	input_to_upper.reserve(input_len);
	for (int i = 0; i < input_len; i++)
		input_to_upper.push_back(static_cast<char>(std::toupper(input[i])));
	return (input_to_upper);
}

int	main(void) {
	PhoneBook	phonebook;
	std::string	command;
	bool		is_running;

	phonebook = PhoneBook();
	is_running = true;
	std::cout << "------ Crappy Awesome 80s Phonebook ------" << std::endl;
	while (is_running) {
		command = std::string();
		command = _get_command_input();
			if(command == "ADD")
				phonebook.add();
			else if (command == "SEARCH")
				phonebook.search();
			else if (command == "EXIT")
				is_running = false;
			else
				std::cout << "Incorrect command please enter from the following options:" << std::endl;
	}
	return (0);
}
