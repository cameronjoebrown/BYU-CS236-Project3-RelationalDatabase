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
#include "Parser.h"

using namespace std;

int main(int argc, char* argv[]){
    string fileName = argv[1];
    Parser myParser(fileName);
    myParser.parse();
    
    return 0;
}
