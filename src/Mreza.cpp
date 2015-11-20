//
//  Mreza.cpp
//  TTT
//
//  Created by Vid Drobnic on 11/5/15.
//  Copyright © 2015 Vid Drobnic. All rights reserved.
//

#include "Mreza.h"
#include <iostream>

void print(std::vector<std::vector<char>> mrezica) {
    for (const auto& vrstica : mrezica) {
        for (const auto& znak : vrstica) {
            std::cout << znak << " ";
        }
        
        std::cout << std::endl;
    }
}