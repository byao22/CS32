//
//  Player.h
//  Project 1
//
//  Created by Brian Yao on 7/2/18.
//  Copyright © 2018 Brian Yao. All rights reserved.
//

#ifndef Player_h
#define Player_h
#include <iostream>

using namespace std;

class Arena;

class Player
{
public:
    // Constructor
    Player(Arena *ap, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    int  age() const;
    bool isDead() const;
    
    // Mutators
    string takeComputerChosenTurn(); // Why does this need std::string instead of just string
    void   stand();
    void   move(int dir);
    bool   shoot(int dir);
    void   setDead();
    
private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_age;
    bool   m_dead;
    
    int    computeDanger(int r, int c) const;
};


#endif /* Player_h */
