//
//  Location.h
//  Battleship
//
//  Created by Jake Carrico on 4/30/15.
//  Copyright (c) 2015 Jake Carrico. All rights reserved.
//

#ifndef __Battleship__Location__
#define __Battleship__Location__

#include <iostream>

using namespace std;

class location{
    
private:
    char x;
    int y;
    bool shipvalue;
    bool hitvalue;
    bool sunkvalue;
    bool missvalue;
    
public:
    location();
    location(char a, int b);
    
    void setPoint(char a, int b);
    void setx(char a);
    void sety(int b);
    void setIsShip(bool a);
    void setIsHit(bool a);
    void setIsSunk(bool a);
    void setIsMiss(bool a);
    
    char getx();
    int gety();
        
    bool isShip();
    bool isHit();
    bool isSunk();
    bool isMiss();
    
    void display();
};


#endif /* defined(__Battleship__Location__) */
