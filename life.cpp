// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header!

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "grid.h"
#include "gwindow.h"
#include "simpio.h"
#include "lifegui.h"
using namespace std;

Grid<char> SetInitialDish (ifstream &in, Grid <char> &InitialDish);
void SetPattern(Grid <char> &InitialDish);


int main() {

    ifstream in;

    string s = getLine("Enter initial file name: ");
    in.open(s);

    if (in.is_open()){

        cout << "The file has successfully been opened." << endl;
    }

    if (in.fail()){

        cerr << "Failed to open file";
    }

    //Set up initial dish
    Grid <char> InitialDish;
    cout << SetInitialDish(in, InitialDish) << endl;

    //Define how the pattern according to which it moves
    SetPattern(InitialDish);

    return 0;
}

Grid<char> SetInitialDish (ifstream &in, Grid <char> &InitialDish){



    string temp;
    int a;
    int b;
    getline(in, temp);
    a = stringToInteger(temp);
    getline(in, temp);
    b = stringToInteger(temp);
    cout << "row = " << a << endl << "column = " << b << endl;
    InitialDish.resize(a, b);

    int count = 0;

    while(true){
        string line;
        getline(in, line);

        for (int i = 0; i < line.length(); i++){
            char ch;
            ch = line[i];
            InitialDish.set(count, i, ch);
        }
        count++;

        if (in.fail()){
            break;
        }

        if (count >= InitialDish.numRows()){
            break;
        }
    }

    in.clear();  //Do I need to clear the getline function?
    in.close();

    if (!in.is_open()){

        cout << "Done reading file. File has been closed." << endl;
    }

    return InitialDish;
}


void SetPattern(Grid <char> &InitialDish){

    Grid <char> TempGrid;
    TempGrid.resize(InitialDish.numRows(), InitialDish.numCols());

    //0 or 1 neighbors

    for (int row = 1; row < (InitialDish.numRows() - 1); row ++){
        for (int col = 1; col < (InitialDish.numCols() - 1); col ++){

            //這裡有問題，為什麼有兩個 NumOfNeighbors
            int NumOfNeighbors;

            if (InitialDish[row][col] == 'X'){
                int NumOfNeighbors = -1;

            } else {
                int NumOfNeighbors = 0;
            }

            for (int r = -1; r < 2; r++){

                for (int c = -1; c < 2; c++){

                    //Check Boundary
                    //if (InitialDish.inBounds((row + r), (col + c))){

                    if (InitialDish[row +r][col + c] == 'X'){

                        NumOfNeighbors ++;
                    }
                }
            }

            //Insert here
            if (NumOfNeighbors == 0 || NumOfNeighbors == 1){
                //Zero or one neighbors, empty in the next generation
                TempGrid.set(row, col, '-');

            }

            if (NumOfNeighbors == 2){
                //Two neighbors, stable
                if (InitialDish[row][col] == '-'){
                    TempGrid.set(row, col, '-');
                }
                if (InitialDish[row][col] == 'X'){

                    TempGrid.set(row, col, 'X');
                }
            }

            if (NumOfNeighbors == 3){
                TempGrid.set(row, col, 'X');
            }

            if (NumOfNeighbors > 3){
                TempGrid.set(row, col, '-');
            }

            else {

                TempGrid.set(row, col, '-');
            }
        }
        // }

    }


    cout << TempGrid << endl;

}
