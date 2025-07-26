// Class Parser that opens file and reads it
// It also breaks the string into the necessary elements for translation.




#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Parser {
public:
    Parser(std::string file_name);//Reading a file
    //Move to the next command in the file
    bool Has_More_Commands();//check the state of file (empty or not)
    string Read_One_Line();//read one line

    //Get the fields of the current command
    string Type_Command(std::string command); // return the type of command
    //For C-Command
    std::string Dest(std::string command); // Destination of computation
    std::string Comp(std::string command); // Some Calculation
    std::string Jump(std::string command); // Jump command
    //For A-Command
    std::string Label(std::string command); // return the value of A-Command in
                                            // decimal representation or Label (variable)
public:
    std::fstream file;//data
    std::string current_line;//line on each step of reading file
};

#endif //PARSER_H
