#include <iostream>
#include <list>
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
    void createConnections(){
        for (int i = 1; i<= 81; i++){
            for (int j = (i/9)*9+1; j<=(i/9)*9+9; j++){
                addEdge(i-1,j);
            }
            for (int j = 1; j<=81;j++){
                if (i%9 == j%9){
                    addEdge(i-1,j);
                }
            }
            for (int j = 1; j<=81;j++){
                if (i/27 == j/27 && ((i%9)-1)/3==((j%9)-1)/3){
                    addEdge(i-1,j);
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