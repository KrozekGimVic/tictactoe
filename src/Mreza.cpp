//
//  Mreza.cpp
//  TTT
//
//  Created by Vid Drobnic on 11/5/15.
//  Copyright © 2015 Vid Drobnic. All rights reserved.
//

#include "Mreza.hpp"
#include <iostream>

Mreza::Mreza(int size_): size(size_) {
    for (int i = 0 ; i < size_ * size_; i++) {
        mreza.push_back('_');
    }
}

Mreza::Mreza(): size(0) {}

void Mreza::setSize(int size_) {
    size = size_;
    for (int i = 0 ; i < size_ * size_; i++) {
        mreza.push_back('_');
    }
}

int Mreza::getSize() {
    return size;
}

char Mreza::getField(int index) {
    return mreza[index];
}

bool Mreza::setField(int index, char symbol) {
    if (index < 0 || index >= size * size || mreza[index] != '_') {
        return false;
    }
    
    mreza[index] = symbol;
    return true;
}

bool Mreza::checkWin(char symbol) {
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size - 2; ++x) {
            int startIndex = y * size + x;
            if (mreza[startIndex] == symbol && mreza[startIndex + 1] == symbol && mreza[startIndex + 2] == symbol) {
                return true;
            }
        }
    }
    
    for (int column = 0; column < size; ++column) {
        for (int y = 0; y < size - 2; ++y) {
            int startIndex = y * size + column;
            if (mreza[startIndex] == symbol && mreza[startIndex + size] == symbol && mreza[startIndex + 2 * size] == symbol) {
                return true;
            }
        }
    }
    
    for (int i = 0; i < size * size; ++i) {
        if (i - size < 0 || i + size >= size * size || i % size == 0 || i + 1 % size == 0) {
            continue;
        }
        
        
        int lu = i - size - 1;
        int ru = i - size + 1;
        int ld = i + size - 1;
        int rd = i + size + 1;
        
        if (mreza[lu] == symbol && mreza[i] == symbol && mreza[rd] == symbol) {
            return true;
        }
        
        if (mreza[ru] == symbol && mreza[i] == symbol && mreza[ld] == symbol) {
            return true;
        }
    }
    
    return false;
}

bool Mreza::isFull() {
    for (char i : mreza) {
        if (i == '_') {
            return false;
        }
    }
    
    return true;
}

std::ostream& operator<<(std::ostream& os, const Mreza& mreza) {
    for (int i = 0; i < mreza.mreza.size(); ++i) {
        if (i % mreza.size == 0) {
            os << std::endl;
        }
        os << mreza.mreza[i] << " ";
    }
    
    return os;
}