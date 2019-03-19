//
//  Relation.h
//  Project3
//
//  Created by Cam on 3/5/19.
//  Copyright © 2019 Cam. All rights reserved.
//

#ifndef Relation_h
#define Relation_h

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include "Tuple.h"
#include "Scheme.h"


using namespace std;

class Relation {
public:
    Relation();
    Relation(string n, Scheme s);
    Relation(string n, set<Tuple> s);
    ~Relation();
    
    string toString();
    
    void addTuple(Tuple t);
    
    string getName();
    Scheme getScheme();
    set<Tuple> getSet();
    
    Relation select(string constant, int index, Relation relation);
    Relation select(int index1, int index2, Relation relation);
    Relation project(vector<int> positions, Relation relation);
    Relation rename(map<string, int> variables, Relation relation);
private:
    string name; // Name of Scheme
    Scheme scheme; // Scheme is one vector of attributes
    set<Tuple> tupleSet; // These are Facts
};

#endif /* Relation_h */
