//
//  Board.h
//  Battleship
//
//  Created by Jake Carrico on 4/30/15.
//  Copyright (c) 2015 Jake Carrico. All rights reserved.
//

#ifndef __Battleship__Board__
#define __Battleship__Board__

#include <iostream>
#include "Location.h"
#include "Ship.h"
#include "Fleet.h"

using namespace std;

class board{
    
private:
    vector<vector<location> > myBoard;
    vector<vector<location> > enemyBoard;
    
public:
    board();
    
    void deploy(fleet f);
    void clear();
    
    void display();
    
    vector<vector<location> > getMyBoard();
    vector<vector<location> > getEnemyBoard();
    
};

#endif /* defined(__Battleship__Board__) */
