#include <iostream>
#include <string>

class Zombie {
	public:
		Zombie(std::string name);
		std::string	get_name(void);
		void		set_name(std::string name);
		void		announce(void);
		~Zombie(void);
	
	private:
		std::string	m_name;
};

Zombie* zombieHorde(int N, std::string name); 
