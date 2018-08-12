//
//  Past.h
//  Project 1
//
//  Created by Brian Yao on 7/3/18.
//  Copyright © 2018 Brian Yao. All rights reserved.
//

#ifndef Past_h
#define Past_h
#include "globals.h"

class Past
{
public:
    Past(int nRows, int nCols);
    bool markIt(int r, int c);
    void printThePast() const;
    
private:
    int m_rows;
    int m_cols;
    int m_arenaPast[MAXROWS][MAXCOLS];   
};

#endif /* Past_h */
