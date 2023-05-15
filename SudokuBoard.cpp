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
            givenIDs[givenIndex] = count;
            givenIndex++;
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
    bool inGiven = false;
    for (int i = 0; i<81;i++){
      if (v == givenIDs[i]){inGiven = true;}
    }
    if (inGiven && color[v] == c){return true;}
    else if(inGiven){return false;}

    for (int i = 0;i<81;i++){
      if (color[i]==c && isNeighbor(v,i)){return false;}
    }
    return false;
  }

  bool graphColorUtility(int v) {
    if (v >= 82){
      return true;
    }
    bool inGiven = false;
    for (int i = 0;i<81;i++){
      if (v==givenIDs[i]){inGiven = true;}
    }
    for (int c = 1; c<= 10;c++){
      if (isSafeToColor(v,c)==true){
        color[v] = c;
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
    if (graphColorUtility(1) == false) {
      return false;
    }
    int count = 0;
    for (int i=0; i<9; i++){
      for (int k=0; k<9; k++){
        sb[i][k] = color[count];
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