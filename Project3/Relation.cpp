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

Relation :: ~Relation() {
    
}

string Relation :: toString() {
    stringstream ss;
    for(Tuple x : tupleSet) {
        for(int i = 0; i < x.size(); ++i) {
            ss << scheme.at(i) << "=" << x.at(i);
            if(i == x.size()-1) {
                ss << endl;
            }
            else {
                ss << ", ";
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

Relation Relation :: select(string constant, int index, Relation newRelation) {
    newRelation.tupleSet.clear();
    for(set<Tuple> :: iterator i = tupleSet.begin(); i != tupleSet.end(); i++){
        if(i->at(index) == constant) {
            newRelation.addTuple(*i);
        }
    }
    return newRelation;
}

Relation Relation :: select(int index1, int index2, Relation newRelation) {
    newRelation.tupleSet.clear();
    for(set<Tuple> :: iterator i = tupleSet.begin(); i != tupleSet.end(); i++){
        if(i->at(index1) == i->at(index2)) {
            newRelation.addTuple(*i);
        }
    }
    return newRelation;
}

Relation Relation :: project(vector<int> positions, Relation newRelation) {
    newRelation.tupleSet.clear();
    for(set<Tuple> :: iterator i = tupleSet.begin(); i != tupleSet.end(); i++) {
        Tuple temp;
        for(int j = 0; j < positions.size(); j++){
            int firstOccurrence =  positions.at(j);
            string instance = i->at(firstOccurrence);
            temp.push_back(instance);
        }
        newRelation.addTuple(temp);
    }
    return newRelation;
}

Relation Relation :: rename(map<string, int> variables, Relation newRelation) {
    for(map<string, int>::iterator it = variables.begin(); it != variables.end(); ++it) {
        for(int i = 0; i < scheme.size(); ++i) {
            if(it->second == i) {
                scheme.at(i) = it->first;
            }
        }
        
    }
    return newRelation;
}
