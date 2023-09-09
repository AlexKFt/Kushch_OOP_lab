#include "Catalog.h"

void Catalog::add(const File& file)
{
	File* f = new File{ file };
	files.push_back(f);
}

void Catalog::add(File* file)
{
	if (file)
	{
		files.push_back(file);
		file = nullptr;
	}
}

void Catalog::print() const
{
	for (auto f : files)
	{
		std::cout << *f << std::endl;
	}
}

void Catalog::clear()
{
	for (auto f : files)
	{
		if (f)
			delete f;
	}
	files.clear();
}

unsigned Catalog::getSize() const
{
	return files.size();
}

std::ofstream& operator<<(std::ofstream& out, Catalog& catalog)
{
	out << catalog.getSize() << std::endl;
	for (auto& f : catalog.files)
	{
		out << *f;
	}
	return out;
}

std::ifstream& operator>>(std::ifstream& in, Catalog& catalog)
{
	catalog.clear();

	unsigned size;
	in >> size >> std::ws;
	for (unsigned i{}; i < size; ++i)
	{
		File* f = new File();
		in >> *f;
		catalog.add(f);
	}
	return in;
}