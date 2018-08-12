//
//  main.cpp
//  HW2
//
//  Created by Brian Yao on 7/27/18.
//  Copyright © 2018 Brian Yao. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

// Returns the product of two positive integers, m and n, using only repeated addition.
int mult(unsigned int m, unsigned int n) // works
{
    if( m == 0)
        return 0;
    int result = mult(m-1, n);
    return(n + result);
}

// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.
//
// Pseudocode Example:
//    countDigit(18838, 8) -> 3
//    countDigit(55555, 3) -> 0
//    countDigit(0, 0) -> 0 or 1 (either is fine)
//
int countDigit(int num, int digit) // works
{
    int count = 0;
    if(num < 10){
        if (num == digit)
            return 1;
        else
            return 0;
    }
    int hello = countDigit(num / 10, digit);
    if(num % 10 == digit)
        count++;
    return hello + count;
}

// Returns a string where the same characters next each other in
// string n are separated by "**"
//
//    Pseudocode Example:
//    pairStars("goodbye") => "go**odbye"
//    pairStars("yyuu")    => "y**yu**u"
//    pairStars("aaaa")    => "a**a**a**a"
//
string pairStars(string n) // works
{
    
    if(n == "")
        return "";
    if(n.length() == 1)
        return n;
    
    string c = n.substr(0,1);
    string k = pairStars(n.substr(1,n.length()-1));
    string o = k.substr(0,1);
    if (c == o)
        return(c+"**"+k);
    else
        return(c + k);
}

// str contains a single pair of brackets, return a new string
// made of only the brackets and whatever those brackets contain
//
//  Pseudocode Example:
//     subBrackets("abc[ghj]789") => "[ghj]"
//     subBrackets("[x]7")        => "[x]"
//     subBrackets ("4agh[y]")    => "[y]"
//
string subBrackets(string str) //works
{
    //return "*";  // This is incorrect.
    if(str == "")
        return "";
    if(str.substr(0,1) == "]")
        return "]";
    
    string c = str.substr(0,1);
    string k = subBrackets(str.substr(1,str.length()-1));
    
    if(k.find("["))
        return c+k;
    else
        return k;
}


bool pathExists(string maze[], int nRows, int nCols,int sr, int sc, int er, int ec) // tested and works
// Return true if there is a path from (sr,sc) to (er,ec) through the maze; return false otherwise
{
    // check bounds
    if(er < 0 || er > nRows)
        return false;
    if(ec < 0 || ec > nCols)
        return false;
    if(sr > nRows || sr < 0)
        return false;
    if(sc > nCols || sc < 0)
        return false;
    
    bool bar = false;
    
    /* just for debugging purposes
    for( int i = 0; i < nRows; i++)
        cout << maze[i] << endl;
     */
    
    if(sr == er && sc == ec){
        return true;
    }
    maze[sr][sc] = 'o';
    if(maze[sr][sc + 1] == '.'){
        bar = pathExists(maze, nRows, nCols, sr, sc+1, er, ec);
        if (bar == true)
            return bar; // make sure bar is not getting reset to false
    }
    if(maze[sr + 1][sc] == '.'){
        bar = pathExists(maze, nRows, nCols, sr+1, sc, er, ec);
        if (bar == true)
            return bar;
    }
    if(maze[sr - 1][sc] == '.'){
        bar = pathExists(maze, nRows, nCols, sr-1, sc, er, ec);
        if (bar == true)
            return bar;
    }
    if(maze[sr][sc - 1] == '.'){
        bar = pathExists(maze, nRows, nCols, sr, sc-1, er, ec);
        if (bar == true)
            return bar;
    }
    return bar;
}


/*
int main() {
    string maze[10] = {
        "XXXXXXXXXX", //0
        "X.......@X", //1
        "XX@X@@.XXX", //2
        "X..X.X...X", //3
        "X..X...@.X", //4
        "X....XXX.X", //5
        "X@X....XXX", //6
        "X..XX.XX.X", //7
        "X...X....X", //8
        "XXXXXXXXXX"  //9
    };
    if (pathExists(maze, 10, 10, 6, 4, 1, 1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
    return 0; }
 */


// Return true if the sum of any combination of elements in the
// array a equals the value of the target.
//
//  Pseudocode Example:
//     comboSum([2, 4, 8], 3, 10) => true
//     comboSum([2, 4, 8], 3, 12) => true
//     comboSum([2, 4, 8], 3, 11) => false
//     comboSum([], 0, 0)         => true
//

bool comboSum(const int a[], int size, int target)
{
    //return false;  // This is not always correct
    if(target == 0)
        return true;
    if(target != 0 && size == 0)
        return false;
    
    bool answer = comboSum(a, size-1, target) || comboSum(a, size-1, target -a[size -1]);
    return answer;
}

/*
 int main() {
 
     cout << mult(7,3) << endl; // test mult
     cout << countDigit(18838,8) << endl; // test countDigit
     cout << subBrackets("4agh[y]") << endl;
     cout << pairStars("goodye") << endl;
     
     const int a[4] = {4,4,4,4};
     cout << comboSum(a, 4, 12) << endl;
 }
*/


