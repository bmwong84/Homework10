#ifndef _HASH
#define _HASH
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <array>
#include <cctype>

struct Node
{
	std::string word;
	int numberCount;		//number of times the word was found in the text
	Node();
};

class HashTable
{
private:
	static const int max_size = 1373;
	int dictionarySize = 0;
	int textCount = 0;
	//an array of linked lists containing a pair ints and strings of size max_size named hashTable
	std::array<std::list<Node>, max_size> hashTable;

public:
	HashTable::HashTable();
	HashTable::~HashTable();
	void readFile(std::ifstream& infile);
	void checkText();
	void formatString(std::string&);

};
#endif // !_HASH

