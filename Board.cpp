//
//  Board.cpp
//  Battleship
//
//  Created by Jake Carrico on 4/30/15.
//  Copyright (c) 2015 Jake Carrico. All rights reserved.
//

#include "Board.h"

board::board(){
    vector<vector<location> > tempBoard(10, vector<location>(10));

    for(int i=0; i<tempBoard.size(); i++){
        for(int n=0; n<tempBoard[i].size(); n++){
            tempBoard[i][n].setPoint(65+i, n+1);
        }
    }
    myBoard = tempBoard;
    vector<vector<location> > etemp(10, vector<location>(10));
    enemyBoard = etemp;
}


void board::clear(){
    vector<vector<location> > tempBoard(10, vector<location>(10));
    
    for(int i=0; i<tempBoard.size(); i++){
        for(int n=0; n<tempBoard[i].size(); n++){
            tempBoard[i][n].setPoint(65+i, n+1);
        }
    }
    myBoard = tempBoard;
}


void board::deploy(fleet f){
    vector<location> storage;
    
    for(int i=0; i<f.size(); i++){
        for(int n=0; n<f.getShip(i).size(); n++){
            storage.push_back(f.getShip(i).getLocation(n));
        }
    }
    do{
        for(int i=0; i<myBoard.size(); i++){
            for(int n=0; n<myBoard[i].size(); n++){
                if((storage[0].getx() == myBoard[i][n].getx()) &&
                (storage[0].gety() == myBoard[i][n].gety())){
                    myBoard[i][n].setIsShip(true);
                    storage.erase(storage.begin());
                }
            }
        }
    }
    while(storage.size()>0);
    
}




void board::display(){
    vector<vector<string> > myDisplay(11, vector<string> (11));
    vector<vector<string> > enemyDisplay(11, vector<string> (11));
    string cNull = "[ ]";
    string cShip = "(O)";
    string cHit = "[X]";
    string cSunk = "(*)";
    string cMiss = "[o]";
    
    //initializing board
    cout << '\t' << '\t' << "   MY SHIPS" << '\n';
    for(int i=0; i<myDisplay.size(); i++){
        for(int n=0; n<myDisplay[i].size(); n++){
            myDisplay[i][n] = cNull;
        }
    }
    
    for(int i=1; i<myDisplay.size(); i++){
        myDisplay[i][0] = 64+i;
    }
    for(int i=1; i<myDisplay.size(); i++){
        myDisplay[0][i] = to_string(i) + "  ";
    }
    myDisplay[0][0] = "  ";
    
    //editing conditions
    for(int i=1; i<myDisplay.size(); i++){
        for(int n=1; n<myDisplay[i].size(); n++){
            if(myBoard[i-1][n-1].isShip() == true){
                myDisplay[i][n] = cShip;
            }
            if(myBoard[i-1][n-1].isHit() == true){
                myDisplay[i][n] = cHit;
            }
            if(myBoard[i-1][n-1].isSunk() == true){
                myDisplay[i][n] = cSunk;
            }
            if(myBoard[i-1][n-1].isMiss() == true){
                myDisplay[i][n] = cMiss;
            }
        }
    }
    
    //outputing result
    for(int i=0; i<myDisplay.size(); i++){
        for(int n=0; n<myDisplay[i].size(); n++){
            cout << myDisplay[i][n];
        }
        cout << '\n';
    }
    
    //initializing board
    cout << '\n' << '\t' << '\t' << "  ENEMY SHIPS" << '\n';
    for(int i=0; i<enemyDisplay.size(); i++){
        for(int n=0; n<enemyDisplay[i].size(); n++){
            enemyDisplay[i][n] = cNull;
        }
    }
    
    for(int i=1; i<enemyDisplay.size(); i++){
        enemyDisplay[i][0] = 64+i;
    }
    for(int i=1; i<enemyDisplay.size(); i++){
        enemyDisplay[0][i] = to_string(i) + "  ";
    }
    enemyDisplay[0][0] = "  ";
    
    //editing conditions
    for(int i=1; i<enemyDisplay.size(); i++){
        for(int n=1; n<enemyDisplay[i].size(); n++){
            if(enemyBoard[i-1][n-1].isShip() == true){
                enemyDisplay[i][n] = cShip;
            }
            if(enemyBoard[i-1][n-1].isHit() == true){
                enemyDisplay[i][n] = cHit;
            }
            if(enemyBoard[i-1][n-1].isSunk() == true){
                enemyDisplay[i][n] = cSunk;
            }
            if(enemyBoard[i-1][n-1].isMiss() == true){
                enemyDisplay[i][n] = cMiss;
            }
        }
    }
    
    //outputing result
    for(int i=0; i<enemyDisplay.size(); i++){
        for(int n=0; n<enemyDisplay[i].size(); n++){
            cout << enemyDisplay[i][n];
        }
        cout << '\n';
    }
}

vector<vector<location> > board::getMyBoard(){
    return myBoard;
}

vector<vector<location> > board::getEnemyBoard(){
    return enemyBoard;
}
