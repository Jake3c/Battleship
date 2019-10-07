//
//  Ship.cpp
//  Battleship
//
//  Created by Jake Carrico on 4/30/15.
//  Copyright (c) 2015 Jake Carrico. All rights reserved.
//

#include "Ship.h"
#include <vector>

ship::ship(int n){
    vector<location> temp(n);
    tship = temp;
    location tloc;
    for(int i=0; i<n; i++){
        tloc.setIsShip(true);
        tloc.setIsHit(false);
        tloc.setIsMiss(false);
        tloc.setIsSunk(false);
        tship[i] = tloc;
    }
    length = n;
}

void ship::setPointHit(int n){
    tship[n-1].setIsHit(true);
}
void ship::setPointSunk(int n){
    tship[n-1].setIsSunk(true);
}
void ship::setPointMiss(int n){
    tship[n-1].setIsMiss(true);
}

void ship::changeLocation(location loc){
    char a = loc.getx();
    int b = loc.gety();
    location tloc;
    for(int i=0; i<tship.size(); i++){
        tloc.setPoint(a, b+i);
        tloc.setIsShip(true);
        tship[i] = tloc;
    }
}
void ship::changeLocation(char a, int b){
    location tloc;
    if(tship[0].getx() == tship[1].getx()){
        for(int i=0; i<tship.size(); i++){
            tloc.setPoint(a, b+i);
            tloc.setIsShip(true);
            tship[i] = tloc;
        }
    }
    else if(tship[0].gety() == tship[1].gety()){
        for(int i=0; i<tship.size(); i++){
            tloc.setPoint(a+i, b);
            tloc.setIsShip(true);
            tship[i] = tloc;
        }
    }
}

void ship::rotate(){
    vector<location> test(tship.size());
    location tloc;
    if(tship[0].getx() == tship[1].getx()){
        tloc.sety(tship[0].gety());
        for(int i=0; i<tship.size(); i++){
            tloc.setx(tship[0].getx()+i);
            tloc.setIsShip(true);
            test[i] = tloc;
        }
    }
    else if(tship[0].gety() == tship[1].gety()){
        tloc.setx(tship[0].getx());
        for(int i=0; i<tship.size(); i++){
            tloc.sety(tship[0].gety()-i);
            tloc.setIsShip(true);
            test[i] = tloc;
        }
    }
    bool flag = 0;
    for(int i=0; i<tship.size(); i++){
        if(test[i].gety() < 1 || test[i].gety() > 10){flag = 1;}
        if(test[i].getx() > 75 || test[i].getx() < 65){flag = 1;}
    }
    if(flag == 0){
        for(int i=0; i<tship.size(); i++){
            tship[i] = test[i];
        }
    }
}

void ship::shiftUp(int n){
    vector<location> test(tship.size());
    location tloc;
    int flag = 0;
    for(int f=0; f<n; f++){
        test = tship;
        for(int i=0; i<tship.size(); i++){
            tloc.setPoint(tship[i].getx()-1, tship[i].gety());
            tloc.setIsShip(true);
            test[i] = tloc;
            if(tloc.getx() < 65){
                flag = 1;
            }
        }
        if(flag == 1){
            cout << "ERROR: Cannot shift up. Off board." << '\n';
        }
        else tship = test;
    }
}
void ship::shiftDown(int n){
    vector<location> test(tship.size());
    location tloc;
    int flag = 0;
    for(int f=0; f<n; f++){
        test = tship;
        for(int i=0; i<tship.size(); i++){
            tloc.setPoint(tship[i].getx()+1, tship[i].gety());
            tloc.setIsShip(true);
            test[i] = tloc;
            if(tloc.getx() > 75){
                flag = 1;
            }
        }
        if(flag == 1){
            cout << "ERROR: Cannot shift down. Off board." << '\n';
        }
        else tship = test;
    }
}
void ship::shiftLeft(int n){
    vector<location> test(tship.size());
    location tloc;
    int flag = 0;
    for(int f=0; f<n; f++){
        test = tship;
        for(int i=0; i<tship.size(); i++){
            tloc.setPoint(tship[i].getx(), tship[i].gety()-1);
            tloc.setIsShip(true);
            test[i] = tloc;
            if(tloc.gety() < 1){
                flag = 1;
            }
        }
        if(flag == 1){
            cout << "ERROR: Cannot shift left. Off board." << '\n';
        }
        else tship = test;
    }
}
void ship::shiftRight(int n){
    vector<location> test(tship.size());
    location tloc;
    int flag = 0;
    for(int f=0; f<n; f++){
        test = tship;
        for(int i=0; i<tship.size(); i++){
            tloc.setPoint(tship[i].getx(), tship[i].gety()+1);
            tloc.setIsShip(true);
            test[i] = tloc;
            if(tloc.gety() > 10){
                flag = 1;
            }
        }
        if(flag == 1){
            cout << "ERROR: Cannot shift right. Off board." << '\n';
        }
        else tship = test;
    }
}


void ship::setIsSunk(bool n){isSunk = n;}

location ship::getLocation(int n){return tship[n];}

bool ship::getIsSunk(){
    if(isSunk == true){
        return true;
    }
    int c=0;
    for(int i=0; i<this->size(); i++){
        if(this->getLocation(i).isHit() == true){
            c++;
        }
    }
    if(c == this->size()){
        isSunk = true;
        return true;
    }
    else return false;
}

int ship::size(){return tship.size();}

void ship::display(){
    for(int i=0; i<tship.size(); i++){
        tship[i].display();
    }
}