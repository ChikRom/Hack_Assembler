#include "Parser.h"


Parser::Parser(std::string file_name) {
	file.open(file_name);
	if (!file.is_open()) {
		std::cerr << "Error: Cannot open file " << file_name << std::endl;
	}
}


bool Parser::Has_More_Commands() {
	return !file.eof();
}



string Parser::Read_One_Line() { //read one line and erase the comments and spaces from it
	getline(file, current_line);
	if (current_line.find("//")) {
		current_line = current_line.substr(0, current_line.find("//"));
	}
	current_line.erase(remove(current_line.begin(), current_line.end(), ' '), current_line.end());
	return current_line;
}


string Parser::Type_Command(string command) {
	if (command[0] == '(') { //  (***) - Label, D = M+1 - C-Commmand, @32 - A-Command
		return "Label";
	}
	else if (command[0] == '@')
	{
		return "A-Command";
	}
	return "C-Command";
}


string Parser::Dest(string command){
	command.erase(0, command.find_first_not_of(" \t")); // delete tabulation
	if (command.find("=") == string::npos) { // if there is a "=" then there is assignment
		return "";
	}
	return command.substr(0, command.find("="));
}


string Parser::Comp(string command) { // calculation comes after the assignment
	string dest_line = Dest(command); // if there isn't an assignment then immediately calculation
	int beg = dest_line.length() + 1;
	int end = 0;
	if (dest_line == "")
	{
		beg = 0;
	}
	if (command.find(";")) {
		end = command.find(";"); 
	}
	else
	{
		end = command.find(" ");
	}
	return command.substr(beg, end);
}

string Parser::Jump(string command) { // Jump comes after calculation right after the ";" symbol
	string comp_line = Dest(command)+Comp(command);
	int beg = comp_line.length() + 1;
	return command.substr(beg);
}

string Parser::Label(string command) { // ingore "@" symbol
	return command.substr(1);
}