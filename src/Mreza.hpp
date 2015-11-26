//
//  Mreza.h
//  TTT
//
//  Created by Vid Drobnic on 11/5/15.
//  Copyright © 2015 Vid Drobnic. All rights reserved.
//

#ifndef Mreza_h
#define Mreza_h

#include <vector>
#include <iostream>

class Mreza {
    std::vector<char> mreza;
    int size;
public:
    Mreza(int);
    Mreza();
    void setSize(int);
    bool setField(int, char);
    char getField(int);
    int getSize();
    bool checkWin(char);
    bool isFull();
    
    friend std::ostream& operator<<(std::ostream& os, const Mreza& mreza);
};

std::ostream& operator<<(std::ostream& os, const Mreza& mreza);


#endif /* Mreza_h */
