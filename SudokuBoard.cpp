using namespace std;
#include <iostream>
#include <array> 
#include "Graph.cpp"

 class SudokuBoard {
  public:
    int sb[9][9] = {{0,4,3,0,0,0,0,0,8}, 
              {0,0,7,8,5,1,9,0,3}, 
              {0,0,8,4,0,0,0,0,2}, 
              {0,7,4,6,8,0,0,0,1}, 
              {0,6,1,0,3,0,8,9,0}, 
              {0,3,5,0,1,0,0,0,0}, 
              {0,0,0,0,6,0,7,2,0}, 
              {0,5,2,1,9,0,3,0,0}, 
              {0,8,6,0,4,0,0,1,9}};
    Graph * myG;
    int color[81];
    int givenIDs[81];
// hard code example sudoku for now
//SudokuBoard() {
   
//}
  SudokuBoard(){
    myG = new Graph();
  }
  void getMappedMatrix(){
    myG->createConnections();
    myG->display();
  }

  void initializeGraphColoring() {
    // ids of the cells given and can't be changed
    int count = 0;
    int givenIndex = 0;
    for (int i = 0; i < 9; i++) {
       for (int j=0; j<9; j++) {
          if (sb[i][j]!=0) {
            color[count] = sb[i][j];
            givenIDs[count] = count;
            givenIndex++;
          }
          else {
            givenIDs[count] = -1;
          }
         count++;
       }
    }
  }

  bool isNeighbor(int v, int i){
    for (int n:myG->adj[v]){
      if (i == n){
        return true;
      }
    }
    return false;
  }

  bool isSafeToColor(int v, int c){
    bool inGiven = (givenIDs[v] != -1);
    if (inGiven){ return false;}
    for (int i = 0;i<81;i++){
      if (color[i]==c && isNeighbor(v,i+1)){return false;}
    }
    return true;
  }

  bool graphColorUtility(int v) {
    if (v >= 82){
      return true;
    }
    bool inGiven = (givenIDs[v]!= -1);
    for (int c = 1; c<= 9;c++){
      if (isSafeToColor(v,c)){
        color[v] = c;
        givenIDs[v] = v;
        sb[v/9][v%9] = color[v];
        if (graphColorUtility(v+1)){return true;}
      }
      if (!inGiven){
        color[v] = 0;
      }
    }
    return false;
  }

  bool solveGraphColoring() {
    initializeGraphColoring();
    int count = 0;
    for (int i=0; i<9; i++){
      for (int k=0; k<9; k++){
        graphColorUtility(count);
        count++;
      }
    }
    return true;
  }

  
  void printBoard() {
     for (int r=0; r<9; r++) {
       for (int c=0; c<9; c++) {
         cout << sb[r][c] <<" ";
       }
       cout << endl;
     }
   }
 };