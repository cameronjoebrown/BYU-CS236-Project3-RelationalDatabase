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
    for(int i = 0; i < schemeVector.size(); ++i){
        string name = schemeVector.at(i).getID();
        vector<Parameter> params = schemeVector.at(i).getParameters();
        Scheme scheme;
        for(int j = 0; j < params.size(); ++j){
            string value = params.at(i).getValue();
            scheme.push_back(value);
        }
        Relation newRelation(name, scheme);
        database.insert(pair<string, Relation>(name, newRelation));
        
    }
}

Interpreter :: ~Interpreter() {
    
}
