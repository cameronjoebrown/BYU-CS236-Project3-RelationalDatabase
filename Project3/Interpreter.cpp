//
//  Interpreter.cpp
//  Project3
//
//  Created by Cam on 3/5/19.
//  Copyright © 2019 Cam. All rights reserved.
//

#include "Interpreter.h"

Interpreter :: Interpreter() {

}

Interpreter :: Interpreter(DatalogProgram data) {
    datalog = data;
    schemeVector = data.getSchemes();
    factVector = data.getFacts();
    ruleVector =  data.getRules();
    queryVector = data.getQueries();
//    Database(schemeVector, factVector);
}

Interpreter :: ~Interpreter() {
    
}
