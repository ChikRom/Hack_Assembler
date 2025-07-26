#include "Code.h"
#include <cstdlib> 
using namespace std;

Code::Code() {
	table.insert({ "0","0101010" });
	table.insert({ "1","0111111" });
	table.insert({ "-1","0111010" });
	table.insert({ "D","0001100" });
	table.insert({ "A","0110000" });
	table.insert({ "!D","0001101" });
	table.insert({ "!A","0110001" });
	table.insert({ "-D","0001111" });
	table.insert({ "-A","0110011" });
	table.insert({ "D+1","0011111" });
	table.insert({ "A+1","0110111" });
	table.insert({ "D-1","0001110" });
	table.insert({ "A-1","0110010" });
	table.insert({ "D+A","0000010" });
	table.insert({ "D-A","0010011" });
	table.insert({ "A-D","0000111" });
	table.insert({ "D&A","0000000" });
	table.insert({ "D|A","0010101" });
	table.insert({ "M","1110000" });
	table.insert({ "!M","1110001" });
	table.insert({ "-M","1110011" });
	table.insert({ "M+1","1110111" });
	table.insert({ "M-1","1110010" });
	table.insert({ "D+M","1000010" });
	table.insert({ "D-M","1010011" });
	table.insert({ "M-D","1000111" });
	table.insert({ "D&M","1000000" });
	table.insert({ "","000" });
	table.insert({ "MD","011" });
	table.insert({ "AM","101" });
	table.insert({ "AD","110" });
	table.insert({ "AMD","111" });
	table.insert({ "JGT","001" });
	table.insert({ "JEQ","010" });
	table.insert({ "JGE","011" });
	table.insert({ "JLT","100" });
	table.insert({ "JNE","101" });
	table.insert({ "JLE","110" });
	table.insert({ "JMP","111" });

}

// We take the required instruction
// in the hash table and replace it with binary code




string Code::Comp(string command) { 
	auto iter = table.find(command); 
	if (iter != table.end()) {
		return iter->second;
	}
	return "Error";
}

string Code::Dest(string command) { 
	if (command == "M")
	{
		return "001";
	}
	if (command == "D") {
		return "010";
	}
	if (command == "A") {
		return "100";
	}
	auto iter = table.find(command);
	if (iter != table.end()) {
		return iter->second;
	}
	return "";
}



string Code::Jump(string command) {
	auto iter = table.find(command);
	if (iter != table.end()) {
		return iter->second;
	}
	return "Error";
}


string Code::Concatenation(string dest,string comp,string jump) { //we add all the results into the finished binary code
	return "111" + Comp(comp)+ Dest(dest) + Jump(jump);
}


string Code::CodeOfValue(string command) {
	string rez = "";
	long value = stoi(command);
	while (value > 0) {
		rez = to_string(value % 2) + rez;
		value = value / 2;
	}
	while (rez.length() < 16) {
		rez = "0" + rez;
	}
	return rez;
}