#pragma once
#include <iostream>
#include <fstream>
#include<string>



class File
{
private:
	std::string name;
	unsigned size;
	std::string AccessMode;
	char* content{ nullptr };


	friend std::istream& operator>>(std::istream& in, File& file);

	friend std::ostream& operator<<(std::ostream& out, File& file);

	friend std::ifstream& operator>>(std::ifstream& in, File& file);

	friend std::ofstream& operator<<(std::ofstream& out, File& file);
public:
	File() = default;

	File(const std::string& name, const std::string& AccessMode) : name{ name }, AccessMode{ AccessMode }
	{
		size = sizeof(name) + sizeof(AccessMode);
	}
	~File()
	{
	}

	std::string getName() const;

	std::string getAccessMode() const;

	int getSize() const;

	/*File(const File&);

	File& operator=(const File&);

	File(File&& f) noexcept;

	File& operator=(File&&) noexcept;*/
};
