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


    while (true){
        string s = getLine("Grid input file name? ");
        in.open(s);

        if (in.is_open()){
            break;
        }
        if (in.fail()){

            cout << "Unable to open that file.  Try again." << endl;
        }
    }
    //Set up initial dish
    Grid <char> InitialDish;

    InitialDish = SetInitialDish(in, InitialDish);
    //Print the grid in a prettier way

    for (int RowOfInitialDish = 0; RowOfInitialDish < InitialDish.numRows(); RowOfInitialDish ++){

        for (int ColOfInitialDish = 0; ColOfInitialDish < InitialDish.numCols(); ColOfInitialDish ++){

            if (InitialDish[RowOfInitialDish][ColOfInitialDish] == 'X'){
                cout << InitialDish[RowOfInitialDish][ColOfInitialDish];
            } else {
                cout << InitialDish[RowOfInitialDish][ColOfInitialDish];
            }

        }
        cout << endl;

    }

    while (true){

        string s2 = getLine("a)nimate, t)ick, q)uit? ");

        if (s2 == "q"){

            cout << "Have a nice Life!";
            break;

        } else if (s2 == "t"){

            SetPattern(InitialDish);

        } else if (s2 == "a") {

            string frames;

            while (true){

                frames = getLine("How many frames? ");

                if (stringIsInteger(frames)){
                    break;
                }
                cout << "Illegal integer format. Try again." << endl;
            }

            int Frames = stringToInteger(frames);
            for (int count = 0; count <= Frames; count ++){

                clearConsole();
                SetPattern(InitialDish);
                pause(50);

            }

        } else {
            cout << "Invalid choice; please try again." << endl;
        }

    }
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

    return InitialDish;
}


void SetPattern(Grid <char> &InitialDish){

    Grid <char> TempGrid;
    TempGrid.resize(InitialDish.numRows(), InitialDish.numCols());

    for (int row = 0; row < (InitialDish.numRows()); row ++){
        for (int col = 0; col < (InitialDish.numCols()); col ++){

            int NumOfNeighbors;

            if (InitialDish[row][col] == 'X'){
                NumOfNeighbors = -1;

            } else {
                NumOfNeighbors = 0;
            }

            for (int r = -1; r < 2; r++){

                for (int c = -1; c < 2; c++){

                    if (InitialDish.inBounds((row + r), (col + c)) &&
                            InitialDish[row +r][col + c] == 'X'){

                        NumOfNeighbors ++;
                    }
                }
            }

            if (NumOfNeighbors == 0 || NumOfNeighbors == 1){
                //Zero or one neighbors, empty in the next generation
                TempGrid.set(row, col, '-');

            }

            else if (NumOfNeighbors == 2){
                //Two neighbors, stable
                TempGrid.set(row, col, InitialDish[row][col]);
            }

            else if (NumOfNeighbors == 3){
                TempGrid.set(row, col, 'X');
            }

            else if (NumOfNeighbors > 3){
                TempGrid.set(row, col, '-');
            }

            else {

                TempGrid.set(row, col, '-');
            }
        }

    }


    InitialDish =TempGrid;

    for (int RowOfInitialDish = 0; RowOfInitialDish < InitialDish.numRows(); RowOfInitialDish ++){

        for (int ColOfInitialDish = 0; ColOfInitialDish < InitialDish.numCols(); ColOfInitialDish ++){

            if (InitialDish[RowOfInitialDish][ColOfInitialDish] == 'X'){
                cout << InitialDish[RowOfInitialDish][ColOfInitialDish];
            } else {
                cout << InitialDish[RowOfInitialDish][ColOfInitialDish];
            }

        }
        cout << endl;

    }

}
