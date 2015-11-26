//
//  GameEngine.cpp
//  TTT
//
//  Created by Vid Drobnic on 11/26/15.
//  Copyright © 2015 Vid Drobnic. All rights reserved.
//

#include "GameEngine.hpp"

void GameEngine::setup() {
    std::cout << "Velikost mreze: ";
    int size;
    std::cin >> size;
    
    grid = Mreza(size);
    
    std::string name;
    char symbol;
    std::cout << std::endl <<  "Ime prvega igralca: ";
    std::cin >> name;
    std::cout << "Znak za prvega igralca: ";
    std::cin >> symbol;
    
    player1.name = name;
    player1.symbol = symbol;
    
    std::cout << std::endl <<  "Ime drugega igralca: ";
    std::cin >> name;
    std::cout << "Znak za drugega igralca: ";
    std::cin >> symbol;
    
    player2.name = name;
    player2.symbol = symbol;
}

void GameEngine::start() {
    bool turnFlag = true;
    while (checkGame() == STANJE::Tece) {
        std::cout << grid << std::endl;
        std::cout << "Na vrsti je igralec " << (turnFlag ? player1.name : player2.name) << ": ";
        int index;
        std::cin >> index;
        
        while (!narediPotezo((turnFlag ? player1 : player2), index)) {
            std::cout << "Na vrsti je igralec " << (turnFlag ? player1.name : player2.name) << ": ";
            std::cin >> index;
        }
        
        turnFlag = !turnFlag;
    }
    
    switch (checkGame()) {
        case STANJE::Player1:
            std::cout << "Zmagovalec je " << player1.name << "!" << std::endl;
            break;
        case STANJE::Player2:
            std::cout << "Zmagovalec je " << player2.name << "!" << std::endl;
            break;
        case STANJE::Neodloceno:
            std::cout << "Neodloceno!" << std::endl;
            break;
        default:
            break;
    }
}

bool GameEngine::narediPotezo(Player player, int index) {
    return grid.setField(index, player.symbol);
}

STANJE GameEngine::checkGame() {
    if (grid.checkWin(player1.symbol)) {
        return STANJE::Player1;
    } else if (grid.checkWin(player2.symbol)) {
        return STANJE::Player2;
    } else if (grid.isFull()) {
        return STANJE::Neodloceno;
    }
    
    return STANJE::Tece;
}