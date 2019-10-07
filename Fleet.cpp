//
//  Fleet.cpp
//  Battleship
//
//  Created by Jake Carrico on 4/30/15.
//  Copyright (c) 2015 Jake Carrico. All rights reserved.
//

#include "Fleet.h"

fleet::fleet(){
    /*
    vector<ship> tships;
    ship carrier(5);
    ship battleship(4);
    ship cruiser(3);
    ship submarine(3);
    ship destroyer(2);
    
    tships.push_back(carrier);
    tships.push_back(battleship);
    tships.push_back(cruiser);
    tships.push_back(submarine);
    tships.push_back(destroyer);
    
    fleetOfShips = tships;
     */
}

fleet::fleet(location a, char z, location b, char y, location c, char x,
             location d, char w, location e, char v){
    vector<ship> tships;
    ship carrier(5);
    carrier.changeLocation(a);
    if(z == 'v'){
        carrier.rotate();
    }
    ship battleship(4);
    battleship.changeLocation(b);
    if(y == 'v'){
        battleship.rotate();
    }
    ship cruiser(3);
    cruiser.changeLocation(c);
    if(x == 'v'){
        cruiser.rotate();
    }
    ship submarine(3);
    submarine.changeLocation(d);
    if(w == 'v'){
        submarine.rotate();
    }
    ship destroyer(2);
    destroyer.changeLocation(e);
    if(v == 'v'){
        destroyer.rotate();
    }
    
    tships.push_back(carrier);
    tships.push_back(battleship);
    tships.push_back(cruiser);
    tships.push_back(submarine);
    tships.push_back(destroyer);
    
    fleetOfShips = tships;
}

void fleet::setShip(string name, char a, int b){
    if(name == "carrier" || name == "Carrier"){
        ship carrier(5);
        fleetOfShips.push_back(carrier);
        fleetOfShips[0].changeLocation(a, b);
    }
    else if(name == "battleship" || name == "Battleship") {
        ship battleship(4);
        fleetOfShips.push_back(battleship);
        fleetOfShips[1].changeLocation(a, b);
    }
    else if(name == "cruiser" || name == "Cruiser"){
        ship cruiser(3);
        fleetOfShips.push_back(cruiser);
        fleetOfShips[2].changeLocation(a, b);
    }
    else if(name == "submarine" || name == "Submarine"){
        ship submarine(3);
        fleetOfShips.push_back(submarine);
        fleetOfShips[3].changeLocation(a, b);
    }
    else if(name == "destroyer" || name == "Destroyer"){
        ship destroyer(2);
        fleetOfShips.push_back(destroyer);
        fleetOfShips[4].changeLocation(a, b);
    }
    else cout << "ERROR: Invalid input of ship name." << '\n';
    
}

void fleet::moveShip(string name, string direction, int amount){
    int number = 5;
    if(name == "carrier" || name == "Carrier"){number = 4;}
    else if(name == "battleship" || name == "Battleship") {number = 3;}
    else if(name == "cruiser" || name == "Cruiser"){number = 2;}
    else if(name == "submarine" || name == "Submarine"){number = 1;}
    else if(name == "destroyer" || name == "Destroyer"){number = 0;}
    else cout << "ERROR: Invalid input of ship name." << '\n';
    
    bool flag = 0;
    vector<location> storage;
    vector<ship> test = fleetOfShips;
    if(direction == "up" || direction == "Up" || direction == "UP"){
        test[number].shiftUp(amount);
    }
    if(direction == "down" || direction == "Down" || direction == "DOWN"){
        test[number].shiftDown(amount);
    }
    if(direction == "left" || direction == "Left" || direction == "LEFT"){
        test[number].shiftLeft(amount);
    }
    if(direction == "right" || direction == "Right" || direction == "RIGHT"){
        test[number].shiftRight(amount);
    }
    for(int i=0; i<test.size(); i++){
        for(int n=0; n<test[i].size(); n++){
            storage.push_back(test[i].getLocation(n+1));
        }
    }
    do{
        for(int j=1; j<storage.size(); j++){
            location loc1 = storage[0];
            location loc2 = storage[j];
            if(loc1.getx() == loc2.getx() && loc1.gety() == loc2.gety()){
                flag = 1;
            }
        }
        storage.erase(storage.begin());
    }while(storage.size() > 0);
    if(flag == 1){
        cout << "ERROR: Cannot place two ships in same place." << '\n';
    }
    else fleetOfShips = test;
}

void fleet::moveShip(string name, location loc){
    int number = 5;
    if(name == "carrier" || name == "Carrier"){number = 4;}
    else if(name == "battleship" || name == "Battleship") {number = 3;}
    else if(name == "cruiser" || name == "Cruiser"){number = 2;}
    else if(name == "submarine" || name == "Submarine"){number = 1;}
    else if(name == "destroyer" || name == "Destroyer"){number = 0;}
    else cout << "ERROR: Invalid input of ship name." << '\n';
    fleetOfShips[number].changeLocation(loc);
}

void fleet::moveShip(string name, char a, int b){
    int number = 5;
    if(name == "carrier" || name == "Carrier"){number = 4;}
    else if(name == "battleship" || name == "Battleship") {number = 3;}
    else if(name == "cruiser" || name == "Cruiser"){number = 2;}
    else if(name == "submarine" || name == "Submarine"){number = 1;}
    else if(name == "destroyer" || name == "Destroyer"){number = 0;}
    else cout << "ERROR: Invalid input of ship name." << '\n';
    fleetOfShips[number].changeLocation(a, b);
}

void fleet::rotateShip(string name, int amount){
    int number = 5;
    if(name == "carrier" || name == "Carrier"){number = 0;}
    else if(name == "battleship" || name == "Battleship") {number = 1;}
    else if(name == "cruiser" || name == "Cruiser"){number = 2;}
    else if(name == "submarine" || name == "Submarine"){number = 3;}
    else if(name == "destroyer" || name == "Destroyer"){number = 4;}
    else cout << "ERROR: Invalid input of ship name." << '\n';
    for(int i=0; i<amount; i++){
        fleetOfShips[number].rotate();
    }
}

ship fleet::getShip(int n){
    return fleetOfShips[n];
}

bool fleet::isSunk(int n){
    for(int i=0; i<fleetOfShips[n-1].size(); i++){
        if(fleetOfShips[n].getLocation(i).isHit() == true){
            n++;
        }
    }
    if(n == fleetOfShips[n].size()){
        return true;
    }
    else return false;
}

int fleet:: size(){
    return fleetOfShips.size();
}

void fleet::display(){
    for(int i=0; i<fleetOfShips.size(); i++){
        fleetOfShips[i].display();
        cout << '\n';
    }
}
