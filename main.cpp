//  main.cpp
//  Battleship
//  Created by Jake Carrico on 4/30/15.
//  Copyright (c) 2015 Jake Carrico. All rights reserved.

#include <iostream>
#include <vector>
#include "Location.h"
#include "Ship.h"
#include "Fleet.h"
#include "Player.h"
#include <curses.h>

void setup(fleet &f, player &p);

int main(){
    
    player p1;
    player p2;
    fleet f1;
    fleet f2;
    
    setup(f1, p1);
    setup(f2, p2);
    
    location loc;
    char a;
    int b;
    
    cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
         << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
         << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
         << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
         << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
    cout << "Player 1's Turn! (Enter to continue)";
    cin.ignore(2);
    
    while(true){
        p1.display();
        cout << "P1, Guess a location: ";
        cin >> a >> b;
        if(a < 65){
            a+=65;
        }
        p1.guess(p2, a, b);
        
        p1.display();
        
        cout << "Press enter to continue" << '\n';
        cin.ignore(2);
        cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
             << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
             << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
             << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
             << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
        cout << "Player 2's Turn! (Enter to continue)";
        cin.ignore(1);
        
        p2.display();
        cout << "P2, Guess a location: ";
        cin >> a >> b;
        if(a < 65){
            a+=65;
        }
        p2.guess(p1, a, b);
        
        p2.display();
        
        cout << "Press enter to continue" << '\n';
        cin.ignore(2);
        cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
             << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
             << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
             << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
             << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
        cout << "Player 1's Turn! (Enter to continue)";
        cin.ignore(1);
    
    }
    
    return 0;
}

void setup(fleet &f, player &p){
    cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
         << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
         << '\n' << '\n' << '\n' << '\n';
    p.display();
    
    char l, o;
    int n;
    
    cout << "Place your ships! (Enter Coordinate ex: A1)" << '\n' << '\n';
    
    
    
    cout << "Where would you like to place your Carrier? (5 ship): ";
    cin >> l >> n;
    cout << "Verticle or Horizontal? (v/h): ";
    cin >> o;
    f.setShip("Carrier", l, n);
    if(o == 'v'){
        f.rotateShip("Carrier", 1);
    }
    p.deploy(f);
    cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
         << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
         << '\n' << '\n' << '\n' << '\n';
    p.display();
    
    
    
    cout << "Where would you like to place your Battleship? (4 ship): ";
    cin >> l >> n;
    cout << "Verticle or Horizontal? (v/h): ";
    cin >> o;
    f.setShip("Battleship", l, n);
    if(o == 'v'){
        f.rotateShip("Battleship", 1);
    }
    p.deploy(f);
    cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
         << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
         << '\n' << '\n' << '\n' << '\n';
    p.display();

    
    cout << "Where would you like to place your Cruiser? (3 ship): ";
    cin >> l >> n;
    cout << "Verticle or Horizontal? (v/h): ";
    cin >> o;
    f.setShip("Cruiser", l, n);
    if(o == 'v'){
        f.rotateShip("Cruiser", 1);
    }
    p.deploy(f);
    cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
         << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
         << '\n' << '\n' << '\n' << '\n';
    p.display();

    
    cout << "Where would you like to place your Submarine? (3 ship): ";
    cin >> l >> n;
    cout << "Verticle or Horizontal? (v/h): ";
    cin >> o;
    f.setShip("Submarine", l, n);
    if(o == 'v'){
        f.rotateShip("Submarine", 1);
    }
    p.deploy(f);
    cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
         << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
         << '\n' << '\n' << '\n' << '\n';
    p.display();
    
    
    cout << "Where would you like to place your Destroyer? (2 ship): ";
    cin >> l >> n;
    cout << "Verticle or Horizontal? (v/h): ";
    cin >> o;
    f.setShip("Destroyer", l, n);
    if(o == 'v'){
        f.rotateShip("Destroyer", 1);
    }
    p.deploy(f);
    cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
         << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
         << '\n' << '\n' << '\n' << '\n';
    p.display();
}