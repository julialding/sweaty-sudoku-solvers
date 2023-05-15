// https://medium.com/code-science/sudoku-solver-graph-coloring-8f1b4df47072

#include <iostream>
#include "SudokuBoard.cpp"
using namespace std;

int main(){
    //Graph * sudoku = new Graph();
    //sudoku->createConnections();
    //sudoku->display();

    cout << endl << "PRINT BOARD" << endl << endl;
    SudokuBoard *s = new SudokuBoard();
    s->printBoard();
    s->getMappedMatrix();
    s->solveGraphColoring();
    s->printBoard();
}