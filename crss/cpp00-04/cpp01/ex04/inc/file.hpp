#pragma once

#include <fstream>
#include <string>

class File {
	private:
		std::fstream m_filestream;
		std::string	m_content;
	public:
		File(std::string filename);	
		~File(void);

		void	substitute(std::string s1, std::string s2);
};
