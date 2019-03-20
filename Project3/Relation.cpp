//
//  Relation.cpp
//  Project3
//
//  Created by Cam on 3/5/19.
//  Copyright © 2019 Cam. All rights reserved.
//

#include "Relation.h"

Relation :: Relation() {
    
}

Relation :: Relation(string n, Scheme s) {
    name = n;
    scheme = s;
}

Relation :: Relation(string n, set<Tuple> s) {
    name = n;
    tupleSet = s;
}

Relation :: Relation(string n) {
    name = n;
}

Relation :: ~Relation() {
    
}

string Relation :: toString() {
    stringstream ss;
    if(tupleSet.empty()) {
        ss << "No";
    }
    else {
        ss << "Yes(" << tupleSet.size() << ")";
        for(Tuple x : tupleSet) {
            if(x.empty()) {
                
            }
            else {
                ss << endl << "  ";
                for(int i = 0; i < (int)x.size(); ++i) {
                    ss << scheme.at(i) << "=" << x.at(i);
                    if(i == (int)x.size()-1) {
                        
                    }
                    else {
                        ss << ", ";
                    }
                }
            }
            
        }
    }
    return ss.str();
}

void Relation :: addTuple(Tuple t) {
    tupleSet.insert(t);
}


string Relation :: getName() {
    return name;
}

Scheme Relation :: getScheme() {
    return scheme;
}

set<Tuple> Relation :: getSet() {
    return tupleSet;
}

Relation Relation :: select(string constant, int index, Relation relation) {
    Relation newRelation(relation.getName(), relation.getScheme());
    for(Tuple x : relation.getSet()) {
        if(x.at(index) == constant) {
            newRelation.addTuple(x);
        }
    }
    return newRelation;
}

Relation Relation :: select(int index1, int index2, Relation relation) {
    Relation newRelation(relation.getName(), relation.getScheme());
    for(Tuple x : relation.getSet()) {
        if(x.at(index1) == x.at(index2)) {
            newRelation.addTuple(x);
        }
    }
    return newRelation;
}

Relation Relation :: project(vector<int> positions, Relation relation) {
    Relation newRelation(relation.getName());
    for(Tuple x : relation.getSet()) {
        Tuple temp;
        for(int j = 0; j < (int)positions.size(); j++){
            temp.push_back(x.at(positions.at(j)));
            scheme.push_back(relation.scheme.at(j));
        }
        newRelation.addTuple(temp);
    }
    return newRelation;
}

Relation Relation :: rename(vector<string> variables, Relation relation) {
    Relation newRelation(relation.getName(), relation.getSet());
    for(int i = 0; i < (int)variables.size(); i++) {
        newRelation.scheme.push_back(variables.at(i));
    }
    return newRelation;
}
