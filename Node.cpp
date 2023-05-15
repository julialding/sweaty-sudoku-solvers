#include <iostream>
#include <list>
using namespace std;

class Node {
    public:
        int id;
        int data;
    
    Node (int index, int data) {
        id = index;
        data = data;
    }

    void setData (int data) {
        data = data;
    }

    int getID() {
        return id;
    }

    int getData() {
        return data;
    }
};