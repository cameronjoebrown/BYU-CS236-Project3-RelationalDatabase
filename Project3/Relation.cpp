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

Relation :: ~Relation() {
    
}

string Relation :: toString() {
    //for_each(tupleSet.begin(), tupleSet.end(), ); FIX!!!
    return "";
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
