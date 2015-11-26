//
//  GameEngine.hpp
//  TTT
//
//  Created by Vid Drobnic on 11/26/15.
//  Copyright © 2015 Vid Drobnic. All rights reserved.
//

#ifndef GameEngine_hpp
#define GameEngine_hpp

#include "Mreza.hpp"
#include "Player.hpp"
#include <iostream>

enum class STANJE {
    Tece, Neodloceno, Player1, Player2
};

class GameEngine {
    Player player1, player2;
    Mreza grid;
    bool running = true;

    STANJE checkGame();
    bool narediPotezo(Player, int);
public:
    void setup();
    void start();
};

#endif /* GameEngine_hpp */
