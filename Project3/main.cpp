//
//  main.cpp
//  Project 1
//
//  Created by Cam on 1/22/2019.
//  Copyright © 2019 Cameron Brown. All rights reserved.
//

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Scanner.h"
#include "Parser.h"
#include "Interpreter.h"

using namespace std;

int main(int argc, char* argv[]){
    string fileName = argv[1];
    Scanner myScanner(fileName);
    myScanner.scan();
    vector<Token> tokenVector = myScanner.getVector();
    Parser myParser(tokenVector);
    myParser.parse();
    DatalogProgram data = myParser.getData();
    Interpreter myInterpreter(data);
    
    return 0;
}
