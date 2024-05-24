#ifndef NODES_H
#define NODES_H

#include <string>
#include <map>
#include <vector>

using namespace std;

struct node_t {
    string name;
    int inDegree, outDegree;
    double weight;
    string cameFrom;

    node_t() : name(""), inDegree(0), outDegree(0), weight(0) {}
    node_t(string name) : name(name), inDegree(0), outDegree(0), weight(0) {}
};

class Nodes {

    private:
        map<string, node_t> nodes;

    public:
        Nodes();
        ~Nodes();
        void print();
        node_t getNode(string name);
        void add(string name);
        bool exists(string name);
        void remove(string nodeName);
        void addDegree(string nodeName, int inDegree, int outDegree);
        vector<node_t> getNodesVector ();
        void setNode(node_t node);
};


#endif
