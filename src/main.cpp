//
//  main.cpp
//  TTT
//
//  Created by Vid Drobnic on 11/5/15.
//  Copyright © 2015 Vid Drobnic. All rights reserved.
//

#include "Mreza.hpp"
#include "Player.hpp"
#include "GameEngine.hpp"
#include <iostream>
#include <string>
#include <vector>

int main() {
    GameEngine game;
    game.setup();
    
    game.start();
    
    return 0;
}







//
//enum class STANJE {
//    Tece, Neodloceno, X, O
//};
//
//bool naredi_potezo(int index, bool na_vrsti_1, std::vector<std::vector<char>>& mreza) {
//    int x = index % 3;
//    int y = index / 3;
//    
//    if (index < 0 || index > 8 || mreza[y][x] != '_') return false;
//    
//    mreza[y][x] = "xo"[na_vrsti_1];
//    
//    return true;
//}
//
//STANJE check_igra(std::vector<std::vector<char>>& mreza) {
//    vector<char> primer = {'o', 'o', 'o'};
//    vector<char> primer2 = {'x', 'x', 'x'};
//    if (mreza[0] == primer || mreza[1] == primer || mreza[2] == primer) {
//        return STANJE::O;
//    }
//    
//    if (mreza[0] == primer2 || mreza[1] == primer2 || mreza[2] == primer2) {
//        return STANJE::X;
//    }
//    
//    if ((mreza[0][0] == 'o' && mreza[1][0] == 'o' && mreza[2][0] == 'o') ||
//        (mreza[0][1] == 'o' && mreza[1][1] == 'o' && mreza[2][1] == 'o') ||
//        (mreza[0][2] == 'o' && mreza[1][2] == 'o' && mreza[2][2] == 'o')) {
//        return STANJE::O;
//    }
//    
//    if ((mreza[0][0] == 'x' && mreza[1][0] == 'x' && mreza[2][0] == 'x') ||
//        (mreza[0][1] == 'x' && mreza[1][1] == 'x' && mreza[2][1] == 'x') ||
//        (mreza[0][2] == 'x' && mreza[1][2] == 'x' && mreza[2][2] == 'x')) {
//        return STANJE::X;
//    }
//    
//    if (mreza[0][0] == 'o' && mreza[1][1] == 'o' && mreza[2][2] == 'o') {
//        return STANJE::O;
//    }
//    
//    if (mreza[0][0] == 'x' && mreza[1][1] == 'x' && mreza[2][2] == 'x') {
//        return STANJE::X;
//    }
//    
//    if (mreza[0][2] == 'o' && mreza[1][1] == 'o' && mreza[2][0] == 'o') {
//        return STANJE::O;
//    }
//    
//    if (mreza[0][2] == 'x' && mreza[1][1] == 'x' && mreza[2][0] == 'x') {
//        return STANJE::X;
//    }
//    
//    for (const auto& vrstica : mreza) {
//        for (const auto& znak : vrstica) {
//            if (znak == '_') {
//                return STANJE::Tece;
//            }
//        }
//    }
//    
//    return STANJE::Neodloceno;
//}
//
//int main(int argc, const char * argv[]) {
//    Mreza mreza(10);
//    std::cout << mreza << std::endl;
//    return 0;
//    
//    
//    std::string ime1, ime2;
//    std::cin >> ime1 >> ime2;
//    
//    std::vector<std::vector<char>> mreza(3, std::vector<char>(3, '_'));
//    print(mreza);
//    
//    bool na_vrsti_1 = true;
//    int polje;
//    
//    while (check_igra(mreza) == STANJE::Tece) {
//        std::cout << "Na vrsti je igralec " << (na_vrsti_1 ? ime1 : ime2) << std::endl;
//        std::cin >> polje;
//        while (!naredi_potezo(polje, na_vrsti_1, mreza)) {
//            std::cout << "Na vrsti je igralec " << (na_vrsti_1 ? ime1 : ime2) << std::endl;
//            std::cin >> polje;
//        }
//        
//        print(mreza);
//        na_vrsti_1 = !na_vrsti_1;
//    }
//    
//    switch (check_igra(mreza)) {
//        case STANJE::O:
//            cout << "Zmagau je un k ma krugc! (" << ime1 << ")" << endl;
//            break;
//        case STANJE::X:
//            cout << "Zmagau je un k ma krizca! (" << ime2 << ")" << endl;
//            break;
//        case STANJE::Neodloceno:
//            cout << "Noben ni zmagu. Obadva sta luzrja!." << endl;
//            break;
//        default:
//            break;
//    }
//    
//    return 0;
//}