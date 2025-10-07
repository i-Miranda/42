#include <string>
#include <iostream>

int	main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "The string's address is: " << &str << std::endl;
	std::cout << "The address held by the string pointer is: " << stringPTR << std::endl;
	std::cout << "The address held by the string reference is: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "The string's content is: " << str << std::endl;
	std::cout << "The content pointed to by the string pointer is: " << *stringPTR << std::endl;
	std::cout << "The content pointed to by the string reference is: " << stringREF << std::endl;

	return (0);
}
