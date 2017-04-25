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

void SetInitialDish(ifstream &in);
int CountLines(ifstream &in);

int main() {

//Open the file

    ifstream in;

    string s = getLine("Enter initial file name: ");
    in.open(s);

//Test if the file opens successfully

    if (in.fail()){

        cerr << "Failed to open file";
    }

    cout << "NumLines = " << CountLines(in);

//Stuff the info in the file into a Grid
    SetInitialDish(in);

    return 0;
}

//Just to test if file is successfully opened
int CountLines(ifstream &in){

    int count = 0;
    while(true){

        string line;
        getline(in, line);


        if (in.fail()){
           break;
        }

        count++;
    }
    return count;

}
/////////////////////////////////////////////


void SetInitialDish(ifstream &in){     //Why can't I pass in a Grid as a parameter?

    Grid <char> EmptyDish;


}
