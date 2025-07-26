#include "SymbolTable.h"
using namespace std;

SymbolTable::SymbolTable() {
	symbol_table.insert({ "R0","0" });
	symbol_table.insert({ "R1","1" });
	symbol_table.insert({ "R2","2" });
	symbol_table.insert({ "R3","3" });
	symbol_table.insert({ "R4","4" });
	symbol_table.insert({ "R5","5" });
	symbol_table.insert({ "R6","6" });
	symbol_table.insert({ "R7","7" });
	symbol_table.insert({ "R8","8" });
	symbol_table.insert({ "R9","9" });
	symbol_table.insert({ "R10","10" });
	symbol_table.insert({ "R11","11" });
	symbol_table.insert({ "R12","12" });
	symbol_table.insert({ "R13","13" });
	symbol_table.insert({ "R14","14" });
	symbol_table.insert({ "R15","15" });
	symbol_table.insert({ "SCREEN","16384" });
	symbol_table.insert({ "KBD","24576" });
	symbol_table.insert({ "SP","0" });
	symbol_table.insert({ "LCL","1" });
	symbol_table.insert({ "ARG","2" });
	symbol_table.insert({ "THIS","3" });
	symbol_table.insert({ "THAT","4" });
}



void SymbolTable::Insert_Label(std::string command,long addr) {
	symbol_table.insert({ command,to_string(addr) }); // set the label and the number of the next line after label
}

string SymbolTable::CodeOfSymbol(std::string command, long& value) { // set the variable with the required address 
	auto iter = symbol_table.find(command);                          // and return the decimal code of the variable or label
	if (iter == symbol_table.end()){
		if (command[0] <= '0' || command[0] >= '9')
			{
				symbol_table.insert({ command,to_string(value) });
				value += 1; // increase the adress of the next variable that we will add
				return to_string(value-1);
			}
		return command;
	}
	return iter->second;

}