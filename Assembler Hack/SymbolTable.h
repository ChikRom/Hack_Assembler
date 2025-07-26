//Class SymbolTable for storage the Labels and variables in the hash table


#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <iostream>
#include <string>
#include <unordered_map>
class SymbolTable{
public:
	SymbolTable(); // built-in instructions from developers the Hack language
	std::string CodeOfSymbol(std::string command,long& value); // return the decimal code of variable or label
	void Insert_Label(std::string command, long addr); //insert Label during first read file

public:
	std::unordered_map <std::string, std::string> symbol_table; // hash table for storage built-in instructions, labels and variables
};


#endif