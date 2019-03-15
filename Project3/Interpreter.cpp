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
    // Store the DatalogProgram as a data member
    datalog = data;
    schemeVector = data.getSchemes();
    factVector = data.getFacts();
    ruleVector =  data.getRules();
    queryVector = data.getQueries();
    
    // Make a Relation for each scheme Predicate, and put that Relation in the Database data member
    for(int i = 0; i < schemeVector.size(); ++i){
        string schemeName = schemeVector.at(i).getID();
        vector<Parameter> schemeParams = schemeVector.at(i).getParameters();
        Scheme scheme;
        for(int j = 0; j < schemeParams.size(); ++j){
            string value = schemeParams.at(i).getValue();
            scheme.push_back(value);
        }
        Relation newRelation(schemeName, scheme);
        database.insert(pair<string, Relation>(schemeName, newRelation));
    }
    
    // Make a Tuple for each fact Predicate, and put that Tuple in the appropriate Relation in the Database
    for(int i = 0; i < schemeVector.size(); ++i){
        string factName = factVector.at(i).getID();
        vector<Parameter> factParams = factVector.at(i).getParameters();
        Tuple tuple;
        for(int j = 0; j < factParams.size(); ++j){
            string value = factParams.at(i).getValue();
            tuple.push_back(value);
        }
        (database.at(factName)).addTuple(tuple);
    }
}

Interpreter :: ~Interpreter() {
    
}

Relation Interpreter :: evalOneQuery(Predicate myQuery) {
    string queryName = myQuery.getID();
    Relation myRelation = database.at(queryName);
    vector<Parameter> paramVector = myQuery.getParameters();
    vector<int> positions;
    map<string, int> variables;
    for(int i = 0; i < paramVector.size(); ++i) {
        if(paramVector.at(i).getIsConstant() == true) {
            myRelation = myRelation.select(paramVector.at(i).getValue(), i, myRelation);
        }
        else if(paramVector.at(i).getIsConstant() == false) {
            positions.push_back(i);
            map<string, int>::iterator it = variables.find(paramVector.at(i).getValue());
            if(it != variables.end()) {
                myRelation = myRelation.select(it->second, i, myRelation);
            }
            else {
                variables.insert(pair<string, int>(paramVector.at(i).getValue(), i));
            }
            
        }
        
    }
    myRelation = myRelation.project(positions, myRelation);
    myRelation = myRelation.rename(variables, myRelation);
    return myRelation;
}

void Interpreter :: evalAllQueries() {
    for(Predicate pred : queryVector) {
        cout << pred.toString() << "? ";
        if(evalOneQuery(pred).getSet().empty()) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes(" << evalOneQuery(pred).getSet().size() << ")" << endl;
            
            cout << evalOneQuery(pred).toString();
        }
    }
}
