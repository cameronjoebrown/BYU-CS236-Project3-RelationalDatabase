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
    for(int i = 0; i < (int)schemeVector.size(); ++i){
        string schemeName = schemeVector.at(i).getID();
        vector<Parameter> schemeParams = schemeVector.at(i).getParameters();
        Scheme scheme;
        for(int j = 0; j < (int)schemeParams.size(); ++j){
            string value = schemeParams.at(j).getValue();
            scheme.push_back(value);
        }
        Relation newRelation(schemeName, scheme);
        database.insert(pair<string, Relation>(schemeName, newRelation));
    }
    
    // Make a Tuple for each fact Predicate, and put that Tuple in the appropriate Relation in the Database
    for(int i = 0; i < (int)factVector.size(); ++i){
        string factName = factVector.at(i).getID();
        vector<Parameter> factParams = factVector.at(i).getParameters();
        Tuple tuple;
        for(int j = 0; j < (int)factParams.size(); ++j){
            string value = factParams.at(j).getValue();
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
    vector<Parameter> queryParams = myQuery.getParameters();
    vector<int> positions;
    map<string, int> variables;
    for(int i = 0; i < (int)queryParams.size(); i++) {
        if((queryParams.at(i).getIsConstant()) == true) {
            myRelation = myRelation.select(queryParams.at(i).getValue(), i, myRelation);
        }
        else {
            map<string, int> :: iterator duplicate = variables.find(queryParams.at(i).getValue());
            if(duplicate == variables.end()) {
                positions.push_back(i);
                variables.insert(pair<string, int>(queryParams.at(i).getValue(), i));
            }
            else {
                myRelation = myRelation.select(duplicate->second, i, myRelation);
            }
        }
        
    }
    myRelation = myRelation.project(positions, myRelation);
    myRelation = myRelation.rename(variables, myRelation);
    
    variables.clear();
    return myRelation;
}

void Interpreter :: evalAllQueries() {
    for(int i = 0; i < (int)queryVector.size(); ++i) {
        Relation newRelation = evalOneQuery(queryVector.at(i));
        cout << queryVector.at(i).toString() << "? " << newRelation.toString();
        if(i != (int)queryVector.size()-1) {
            cout << endl;
        }
    }
}
