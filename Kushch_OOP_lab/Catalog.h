#pragma once

#include "File.h"
#include <vector>


class Catalog
{
private:
	std::vector<File*> files;

	friend std::ofstream& operator<<(std::ofstream& out, Catalog& catalog);

	friend std::ifstream& operator>>(std::ifstream& in, Catalog& catalog);

public:

	Catalog() = default;

	~Catalog()
	{
		this->clear();
	}

	void add(const File& file);

	void add(File* file);

	void print() const;

	void clear();

	unsigned getSize() const;


};
