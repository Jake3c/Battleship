//
//  Player.h
//  Battleship
//
//  Created by Jake Carrico on 5/1/15.
//  Copyright (c) 2015 Jake Carrico. All rights reserved.
//

#ifndef __Battleship__Player__
#define __Battleship__Player__

#include <iostream>
#include "Location.h"
#include "Ship.h"
#include "Fleet.h"
#include "Board.h"

using namespace std;

class player{
    
private:
    vector<vector<location> > myBoard;
    vector<vector<location> > enemyBoard;
    
public:
    player();
    
    void deploy(fleet f);
    void clear();
    
    void display();
    
    void guess(player &p2, char a, int b);
    
    vector <vector<location> > & getMyBoard();
    vector <vector<location> > & getEnemyBoard();
    
};


#endif /* defined(__Battleship__Player__) */
