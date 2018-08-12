//
//  Game.h
//  Project 1
//
//  Created by Brian Yao on 7/3/18.
//  Copyright © 2018 Brian Yao. All rights reserved.
//

#ifndef Game_h
#define Game_h

class Arena;

class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nRobots);
    ~Game();
    
    // Mutators
    void play();
    
private:
    Arena* m_arena;
};

#endif /* Game_h */
