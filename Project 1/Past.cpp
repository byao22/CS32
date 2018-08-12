//
//  Past.cpp
//  Project 1
//
//  Created by Brian Yao on 7/3/18.
//  Copyright © 2018 Brian Yao. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Past.h"
#include "globals.h"
using namespace std;

Past::Past(int nRows, int nCols)    // initialize Past
:m_rows(nRows), m_cols(nCols)
{
    int r, c;
    for (r = 1; r <= m_rows; r++)
        for (c = 1; c <= m_cols; c++)
            m_arenaPast[r - 1][c - 1] = 0;
}

bool Past::markIt(int r, int c)    // move at (r,c)
{
    if (r <= 0 || c <= 0 || r > m_rows || c > m_cols)
        return false;
    else {
    m_arenaPast[r - 1][c - 1]++;    // mark location if within bounds
    return true;
    }
}

void Past::printThePast() const    // print all past moves
{
    clearScreen();
    
    int r, c;
    char printThePast[MAXROWS][MAXCOLS];
    for (r = 1; r <= m_rows; r++)
        for (c = 1; c <= m_cols; c++)
        {
            int count = m_arenaPast[r - 1][c - 1];
            if (count == 0)
                printThePast[r - 1][c - 1] = '.';
            else if (count >= 26)
                printThePast[r - 1][c - 1] = 'Z';
            else
                printThePast[r - 1][c - 1] = 64 + count; // notation for all letters
        }
    for (r = 1; r <= m_rows; r++)
    {
        for (c = 1; c <= m_cols; c++)
            cout << printThePast[r - 1][c - 1];   
        cout << endl;
    }
    cout << endl;
}
