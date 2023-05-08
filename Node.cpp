#include <iostream>
#include <list>
using namespace std;

class Node {
    public:
        int id;
        int data;
    
    Node (index, data) {
        id = index;
        data = data;
    }

    // include weight arg for sudoku implementation
    void addNeighbor(this, neighbor, weight = 0) {
        // if the neighbor's id is not already in connectedTo
        if (neighbor.id) {
            this.connectedTo[neighbor.id] = weight;
        }
    }

    void setData (data) {
        data = data;
    }

    <list> getConnections(int e) {
        return connectedTo[e]; // return the indices
    }

    int getID() {
        return id;
    }

    int getData() {
        return data;
    }

    // int getWeight
}