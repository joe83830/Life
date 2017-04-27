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

Grid<char> SetInitialDish (ifstream &in);
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
    cout << SetInitialDish(in) << endl;
    SetPattern(InitialDish);

    return 0;
}

Grid<char> SetInitialDish (ifstream &in){

    Grid <char> InitialDish;

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
    TempGrid.resize(5,5); //Replace with a, b

    //0 or 1 neighbors

    for (int row = 0; row < InitialDish.numRows(); row ++){
        for (int col = 0; col < InitialDish.numCols(); col ++){

            for (int r = 0; r < 3; r++){

                for (int c = 0; c < 3; c++){

                    int NumOfNeighbors = 0;

                    if (InitialDish[row + (r-1)][col + (c-1)] == 'X'){

                        NumOfNeighbors ++;
                        NumOfNeighbors -= 1;
                    }
                    if (NumOfNeighbors = 1 || 2){
                        //Zero or one neighbors, empty in the next generation
                        TempGrid.set(row, col, '-');

                    }

                    if (NumOfNeighbors = 3){
                        //Two neighbors, stable
                        if (InitialDish[row][col] == '-'){
                            TempGrid.set(row, col, '-');
                        }
                        if (InitialDish[row][col] == 'X'){

                            TempGrid.set(row, col, 'X');
                        }
                    }

                    if (NumOfNeighbors = 4){
                        TempGrid.set(row, col, 'X');
                    }

                    if (NumOfNeighbors > 4){
                        TempGrid.set(row, col, '-');
                    }





                }
            }
        }

    }

}
