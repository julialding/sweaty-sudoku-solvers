#include <iostream>
#include "Graph.cpp"
using namespace std;

int main(){
    Graph sudoku = new Graph();
    sudoku.createConnections();
    sudoku.display();
}