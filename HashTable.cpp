#include "HashTable.h"
#include <cstring>
#include <algorithm>
#include <vector>
#include <stdio.h>

HashTable::HashTable()
{}

HashTable::~HashTable()
{}

Node::Node()
{
	this->numberCount = 0;
}

void HashTable::readFile(std::ifstream& infile)	//reads the dictionary
{
	dictionarySize = 0;
	std::string temp;
	while (std::getline(infile >> std::ws, temp))
	{
		std::hash<std::string> hashStr;
		int tempHash = hashStr(temp) % max_size;		//max_size is currently 1373
		Node tempNode;
		tempNode.numberCount = 0;
		tempNode.word = temp;
		hashTable[tempHash].emplace_back(tempNode);
		dictionarySize++;
	}
}

void HashTable::formatString(std::string& removelower)
{
	std::string ignoreChars = ".?!;";		//array of characters to be ignored includes 
	for (unsigned int count = 0; count < ignoreChars.size(); count++)		//erases .?!;
	{
		removelower.erase(std::remove(removelower.begin(), removelower.end(), ignoreChars[count]));	//for each character, erase those characters
	}
	if (isalnum(removelower[0]))
		int temp;
	else
	{
		int size = removelower.size();
		for (int count = 0; count < size - 1; count++)		//removes first char if it's not alphanumeric
		{
			removelower[count] = removelower[count + 1];
		}
	}
	if (isalnum(removelower.back()))
		int temp;
	else
	{
		removelower.pop_back();
	}


	for (int count = 0; count < removelower.size();count++)	//sets all chars to lower case
	{
		removelower[count] = tolower(removelower[count]);
	}

}

void HashTable::checkText()
{
	std::vector<std::string> misspelledWords;
	std::string checkFile;
	std::cout << "Please enter the name of the file you wish to spellcheck: " << std::endl;
	std::getline(std::cin >> std::ws, checkFile);
	std::ifstream inStream;
	inStream.open(checkFile.c_str());
	textCount = 0;
	std::string temp;
	while (inStream >> temp)
	{
		textCount++;
		formatString(temp);
		std::hash<std::string> hashStr;
		int tempHash = hashStr(temp) % max_size;
		bool present;
		for (std::list<Node>::iterator it = hashTable[tempHash].begin(); it != hashTable[tempHash].end(); it++)	//iterates the list at the hash
		{
			present = false;
			if (it->word==temp)
			{
				it->numberCount++;
				present = true;
				break;
			}
			//else
			//{
			//	misspelledWords.push_back(temp);
			//}
		}
		if (!present)
		{
			misspelledWords.push_back(temp);
		}
	}
	std::cout << "There were " << dictionarySize << " dictionary words, " << textCount << " words in file, " << misspelledWords.size() << " were misspelled." << std::endl;
	for (int count = 0; count < misspelledWords.size(); count++)
	{
		std::cout << misspelledWords[count] << std::endl;
	}


}



