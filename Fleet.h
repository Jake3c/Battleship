//
//  Fleet.h
//  Battleship
//
//  Created by Jake Carrico on 4/30/15.
//  Copyright (c) 2015 Jake Carrico. All rights reserved.
//

#ifndef __Battleship__Fleet__
#define __Battleship__Fleet__

#include <iostream>
#include "Location.h"
#include "Ship.h"

using namespace std;

class fleet{
    
private:
    vector<ship> fleetOfShips;
    bool isGameOver;
    
public:
    fleet();
    fleet(location a, char z, location b, char y, location c, char x,
          location d, char w, location e, char v);
    
    void setShip(string name, char a, int b);
    void moveShip(string name, string direction, int amount);
    void moveShip(string name, location loc);
    void moveShip(string name, char a, int b);
    void rotateShip(string name, int amount);
    
    ship getShip(int n);
    int size();
    bool isSunk(int n);
    
    void display();
    
};

#endif /* defined(__Battleship__Fleet__) */
