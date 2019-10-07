//
//  Ship.h
//  Battleship
//
//  Created by Jake Carrico on 4/30/15.
//  Copyright (c) 2015 Jake Carrico. All rights reserved.
//

#ifndef __Battleship__Ship__
#define __Battleship__Ship__

#include <iostream>
#include "Location.h"
#include <vector>

using namespace std;

class ship{
    
private:
    vector<location> tship;
    int length;
    bool isSunk;
    
public:
    ship(int n);
    
    void setPointHit(int n);
    void setPointSunk(int n);
    void setPointMiss(int n);
    
    void changeLocation(location loc);
    void changeLocation(char a, int b);
    void rotate();
    void shiftUp(int n=1);
    void shiftDown(int n=1);
    void shiftLeft(int n=1);
    void shiftRight(int n=1);
    
    void setIsSunk(bool n);
    
    bool getIsSunk();
    location getLocation(int n);
    int size();
    
    void display();
    
};


#endif /* defined(__Battleship__Ship__) */
