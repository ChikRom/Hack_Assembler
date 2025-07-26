#include <iostream>
#include "Parser.h"
#include "SymbolTable.h"
#include "Code.h"
#include <fstream>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cerr << "Error!";
		return 1;
	}
	Parser file(argv[1]);// initialize and name opened file
	long instr_counter = 0;// number of instructions
	long variable_addr = 16;// address for variables
	string line;// Read line at each step
	Code translator;// Object from Class Code
	SymbolTable sym_tab;// Object from Class Code
	string name = argv[1];
	name = name.substr(0, name.find(".")+1) + "hack";//Change the extension of output file
	ofstream output(name);
	bool flag=1;// flag to implement line breaks
	while (file.Has_More_Commands()) { //Reading the file for the first time
		line = file.Read_One_Line();
		if (line.empty() || line.substr(0, 2) == "//") {
			continue; // ignore comments and empty lines
		}
		if (file.Type_Command(line) == "Label") { // if our line is a transition label we add this instruction to the SymbolTable 
			sym_tab.Insert_Label(line.substr(1,line.find(")")-1),instr_counter);
		}
		if (file.Type_Command(line) != "Label") {// We count the total number of commands without
			instr_counter += 1;                  // transition labels and unnecessary lines
		}
	}
	instr_counter = 0;
	Parser file_1(argv[1]);
	while(file_1.Has_More_Commands()) { // Reading the file for the second time and translate lines to binary code
		line = file_1.Read_One_Line();
		if (line.empty() || line.substr(0, 2) == "//") { // ignore comments and empty lines
			continue;
		}
		if (!flag && file_1.Type_Command(line)!="Label") { //if line isn't a Label - line break
			output << "\n";
		}

		if (file_1.Type_Command(line) == "C-Command") { // translation for C-Commands
			output<<translator.Concatenation(file_1.Dest(line), file_1.Comp(line), file_1.Jump(line));
		}

		else if (file_1.Type_Command(line) == "A-Command") { // translation for A-Commands
			output<<translator.CodeOfValue(sym_tab.CodeOfSymbol(file_1.Label(line), variable_addr));
		}

		if (file_1.Type_Command(line) != "Label") { // We count the total number of commands without
			instr_counter += 1;                     // transition labels and unnecessary lines
		}
		flag = 0;
	}
	instr_counter -= 1; // The total number of lines

	return 0;
}