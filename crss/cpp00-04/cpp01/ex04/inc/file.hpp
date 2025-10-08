#pragma once

#include <fstream>
#include <string>

class File {
	private:
		std::fstream m_filestream;
	public:
		File(const char* filename);	
		~File(void);

		void	find(std::string string);
		void	replace(std::string s1, std::string s2);
};
