#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V; //Number of vertices: Will be 81;
    list<int>*adj;
    Graph(){
        V = 81;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w){
        adj[v].push_back(w)
    }
    void display(){
        for (int v = 0; v<V;v++){
            std::cout<<"vertex v: "<<v<<" - ";
            for (int n : adj[v]) {
                std::cout<<n<<", ";
            }
            std::cout<< std::endl;
        }
    }

};