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

Relation :: ~Relation() {
    
}

string Relation :: toString() {
    stringstream ss;
    if(tupleSet.empty()) {
        ss << "No" << endl;
    }
    else {
        ss << "Yes(" << tupleSet.size() << ")" << endl;
        for(Tuple x : tupleSet) {
            if(x.empty()) {
                
            }
            else {
                for(int i = 0; i < x.size(); ++i) {
                    ss << "  " << scheme.at(i) << "=" << x.at(i);
                    if(i == x.size()-1) {
                        ss << endl;
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
    Relation newRelation(relation.getName(), relation.getScheme());
    for(Tuple x : relation.getSet()) {
        Tuple temp;
        for(int j = 0; j < positions.size(); j++){
            temp.push_back(x.at(positions.at(j)));
        }
        newRelation.addTuple(temp);
    }
    return newRelation;
}

Relation Relation :: rename(map<string, int> variables, Relation relation) {
    Relation newRelation(relation.getName(), relation.getSet());
    for(map<string, int>::iterator it = variables.begin(); it != variables.end(); ++it) {
        newRelation.scheme.push_back(it->first);
    }
    return newRelation;
}
