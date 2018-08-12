//
//  Arena.h
//  Project 1
//
//  Created by Brian Yao on 7/2/18.
//  Copyright © 2018 Brian Yao. All rights reserved.
//

#ifndef Arena_h
#define Arena_h
#include <iostream>
#include "globals.h"
#include "Past.h"

using namespace std;

class Player;
class Robot;

class Arena
{
public:
    // Constructor/destructor
    Arena(int nRows, int nCols);
    ~Arena();
    
    // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    int     robotCount() const;
    int     nRobotsAt(int r, int c) const;
    void    display(string msg) const;
    
    // Mutators
    bool   addRobot(int r, int c);
    bool   addPlayer(int r, int c);
    void   damageRobotAt(int r, int c);
    bool   moveRobots();
    
    // Past
    Past& thePast();
    
private:
    int     m_rows;
    int     m_cols;
    Player* m_player;
    Robot*  m_robots[MAXROBOTS];
    int     m_nRobots;
    
    // Past
    Past m_Past;
};

#endif /* Arena_h */
