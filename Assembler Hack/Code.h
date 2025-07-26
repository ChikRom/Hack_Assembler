//Class Code that translate mnemonic commands from Class Parser to binary code


#ifndef CODE_H
#define CODE_H
#include <iostream>
#include <string>
#include <unordered_map>

class Code {
public:
	Code(); // Hash Table for storage all possible instruction parts and their binary representations
	// For C-Command
	std::string Comp(std::string command); // translate part of calculation
	std::string Dest(std::string command); // translate part of destination
	std::string Jump(std::string command); // translate part of jump
	std::string Concatenation(std::string dest, std::string comp, std::string jump); // ready C-Command in binary representation
	// For C-Command

	// For A-Command
	std::string CodeOfValue(std::string command); // translate decimal to binary for A-Command
public:
	std::unordered_map<std::string, std::string> table; // built-in symbols table
};



#endif