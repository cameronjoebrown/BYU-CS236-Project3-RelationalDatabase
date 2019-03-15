//
//  Tuple.cpp
//  Project3
//
//  Created by Cam on 3/5/19.
//  Copyright © 2019 Cam. All rights reserved.
//

#include "Tuple.h"

Tuple :: Tuple() {
    
}

Tuple :: ~Tuple() {
    
}

string Tuple :: toString() {
    stringstream ss;
    for(int i = 0; i < this->size(); ++i) {
        ss << this->at(i);
    }
    return ss.str();
}
