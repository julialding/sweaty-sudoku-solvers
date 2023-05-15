#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Graph {
    public:
    int V; //Number of vertices: Will be 81;
    list<int>*adj;
    Graph(){
        V = 81;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w){
        adj[v].push_back(w);
    }
    bool contains(int v, int w) {
      for (int i : adj[v]) {
        if (i==w) {
          return true;
        }
      }
      return false;
    }
    void createConnections(){
        for (int i = 1; i<= 81; i++){
            for (int j = ((i-1)/9)*9+1; j<=((i-1)/9)*9+9; j++){
                if (!contains(i-1,j) && i!=j) { addEdge(i-1,j); }
            }
            for (int j = 1; j<=81;j++){
                if (i%9 == j%9){
                    if (!contains(i-1,j)&& i!=j) { addEdge(i-1,j); }
                }
            }
            for (int j = 1; j<=81;j++){
                if ((i-1)/27 == (j-1)/27 && ((i-1)%9)/3==((j-1)%9)/3){
                   if (!contains(i-1,j)&& i!=j) { addEdge(i-1,j); }
                }
            }
        }
        
    }

    

    void display(){
        for (int v = 0; v<V;v++){
            std::cout<<"vertex v: "<<v+1<<" - ";
            for (int n : adj[v]) {
                std::cout<<n<<", ";
            }
            std::cout<< std::endl;
        }
    }

};