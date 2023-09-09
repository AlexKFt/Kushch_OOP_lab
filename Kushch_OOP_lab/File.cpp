#include "File.h"

std::istream& operator>>(std::istream& in, File& file)
{
	std::cout << "Enter file name: " << std::endl;
	getline(in, file.name);

	std::cout << "Enter Access mode: " << std::endl;
	getline(in, file.AccessMode);

	file.size = sizeof(file.name) + sizeof(file.AccessMode);
	return in;
}

std::ostream& operator<<(std::ostream& out, File& file)
{
	out << "File name: " << file.name << std::endl
		<< "Access mode: " << file.AccessMode << std::endl
		<< "Size: " << file.size << " Bytes" << std::endl;

	return out;
}

std::ifstream& operator>>(std::ifstream& in, File& file)
{
	std::getline(in, file.name);
	std::getline(in, file.AccessMode);
	in >> file.size >> std::ws;
	return in;
}

std::ofstream& operator<<(std::ofstream& out, File& file)
{
	out << file.name << std::endl
		<< file.AccessMode << std::endl
		<< file.size << std::endl;
	return out;
}

std::string File::getName() const
{
	return name;
}

std::string File::getAccessMode() const
{
	return AccessMode;
}

int File::getSize() const
{
	return size;
}