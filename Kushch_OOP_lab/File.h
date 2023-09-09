#pragma once
#include <iostream>
#include <fstream>
#include<string>



class File
{
private:
	std::string name;
	std::string AccessMode;
	std::string description;
	unsigned size;


	friend std::istream& operator>>(std::istream& in, File& file);

	friend std::ostream& operator<<(std::ostream& out, File& file);

	friend std::ifstream& operator>>(std::ifstream& in, File& file);

	friend std::ofstream& operator<<(std::ofstream& out, File& file);
public:
	File() = default;

	File(const std::string& name, const std::string& AccessMode, std::string& desc) : name{ name }, AccessMode{ AccessMode }, description{desc}
	{
		size = sizeof(name) + sizeof(AccessMode) + sizeof(desc);
	}
	~File()
	{
	}

	std::string getName() const;

	std::string getAccessMode() const;

	std::string getDesription() const;

	int getSize() const;
};
