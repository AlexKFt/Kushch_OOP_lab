
#include "File.h"
#include "Catalog.h"

using namespace std;



void printMenu()
{
	cout << "1: Add new file to catalog\n"
		<< "2: Show all file from catalog\n"
		<< "3: Read list of files from file stream\n"
		<< "4: Save catalog to file\n"
		<< "5: Clear catalog\n\n";
}


string getFileName()
{
	cout << "Enter file name: \n";
	string fileName;
	getline(cin, fileName);
	return fileName;
}



int main()
{
	int commandIndex{ -1 };

	Catalog mainCatalog;


	while (commandIndex != 0)
	{
		printMenu();
		cout << "Enter command index (from 1 to 5) \nEnter 0 to exit: ";
		try {
			cin >> commandIndex;
			cin.clear();
			cin.ignore(10, '\n');
		}
		catch (...)
		{
			commandIndex = -1;
		}

		switch (commandIndex)
		{
		case 0:
			break;
		case 1:
		{
			File* f = new File();
			cin >> *f;
			mainCatalog.add(f);
			break;
		}
		case 2:
		{
			mainCatalog.print();
			break;
		}
		case 3:
		{
			string fileName{ getFileName() };
			ifstream fin{ fileName, ios::in };
			if (fin.is_open())
			{
				fin >> mainCatalog;
				cout << "Catalog was loadede from file\n";
			}
			fin.close();
			break;
		}
		case 4:
		{
			string fileName{ getFileName() };
			ofstream fout{ fileName, ios::out };
			if (fout.is_open())
			{
				fout << mainCatalog;
				cout << "Catalog was written to file\n";
			}
			fout.close();
			break;
		}
		case 5:
		{
			mainCatalog.clear();
			cout << "Catalog is empty\n";
		}
		default:
		{
			cout << "You have entered a wrong index\n";
		}
		if (!cin)
		{
			commandIndex = -1;
			cout << "You have entered a wrong index\n";
		}
		}
	}

}