/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:38:56 by ivmirand          #+#    #+#             */
/*   Updated: 2026/04/02 13:07:17 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(void) {
	const AAnimal* dog = new Dog();
	std::cout << std::endl;

	const AAnimal* cat = new Cat();
	std::cout << std::endl;

	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl;
	
	delete dog; //should not create a leak
	std::cout << std::endl;

	delete cat;
	std::cout << std::endl;

	std::cout << "--- Deep copy test ---" << std::endl;
	std::cout << std::endl;

	Dog dog_1;
	dog_1.getBrain().setIdea("I want food", 0);
	std::cout << std::endl;

	Dog dog_2;
	dog_2.getBrain().setIdea("I want sleep", 0);
	std::cout << std::endl;

	std::cout << "dog_1 idea[0]: " << dog_1.getBrain().getIdea(0) << std::endl;
	std::cout << "dog_2 idea[0]: " << dog_2.getBrain().getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << "--- Assignment test ---" << std::endl;
	std::cout << std::endl;
	
	Cat cat_1;
	cat_1.getBrain().setIdea("I want food", 0);
	cat_1.getBrain().setIdea("I want food", 100);
	std::cout << std::endl;

	Cat cat_2;
	cat_2 = cat_1; // operator=
	cat_2.getBrain().setIdea("I want sleep", 0);
	cat_2.getBrain().setIdea("I want food", 100);
	std::cout << std::endl;

	std::cout << "cat_1 idea[0]: " << cat_1.getBrain().getIdea(0) << std::endl;
	std::cout << "cat_2 idea[0]: " << cat_2.getBrain().getIdea(0) << std::endl;
	std::cout << "cat_1 idea[1]: " << cat_1.getBrain().getIdea(1) << std::endl;
	std::cout << "cat_2 idea[1]: " << cat_2.getBrain().getIdea(1) << std::endl;
	std::cout << "cat_1 idea[100]: " << cat_1.getBrain().getIdea(100) << std::endl;
	std::cout << "cat_2 idea[100]: " << cat_2.getBrain().getIdea(100) << std::endl;
	std::cout << std::endl;

	std::cout << "--- Stack allocated Dogs and Cats Destructors test ---" << std::endl;
	std::cout << std::endl;
	return (0);
}
