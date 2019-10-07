//
//  Location.cpp
//  Battleship
//
//  Created by Jake Carrico on 4/30/15.
//  Copyright (c) 2015 Jake Carrico. All rights reserved.
//

#include "Location.h"

location::location(){
    shipvalue = false;
    hitvalue = false;
    sunkvalue = false;
    missvalue = false;
}

location::location(char a, int b){
    if(a > 90){
        a = a-32;
    }
    x = a;
    y = b;
    shipvalue = false;
    hitvalue = false;
    sunkvalue = false;
    missvalue = false;
}

void location::setPoint(char a, int b){
    if(a > 90){
        a = a-32;
    }
    x = a;
    y = b;
    shipvalue = false;
}

void location::setIsShip(bool a){shipvalue = a;}
void location::setIsHit(bool a){hitvalue = a;}
void location::setIsSunk(bool a){sunkvalue = a;}
void location::setIsMiss(bool a){missvalue = a;}

void location::setx(char a){x = a;}
void location::sety(int b){y = b;}

char location::getx(){return x;}
int location::gety(){return y;}

bool location::isShip(){return shipvalue;}
bool location::isHit(){return hitvalue;}
bool location::isSunk(){return sunkvalue;}
bool location::isMiss(){return missvalue;}

void location::display(){
    cout << "(" << x << "," << y << ")";
}