#include "HashTable.h"


int main()
{
	HashTable checker;
	//ask user for file to check against
	std::string spellCheck;
	std::cout << "Please enter the name of the file you wish to use as a spellchecker:" << std::endl;
	std::getline(std::cin >> std::ws, spellCheck);
	std::ifstream inFile;
	inFile.open(spellCheck.c_str());
	checker.readFile(inFile);
	inFile.close();
	//ask user for file to actually check for spelling errors
	checker.checkText();
	std::cin.get();

	return 0;
}