#ifndef EDGES_HPP
#define EDGES_HPP

#include <string>
#include <map>
#include <vector>

using namespace std;
class Edges {
private:
    map<string, map<string, double>> edges;

public:
    Edges();
    ~Edges();
    void add(string from, string to, double weight);
    void print();
    bool existNode(string nodeName);
    bool existEdge(string from, string to);
    void removeNode(string name);
    void removeEdge(string from, string to);
    map<string, double> getEdges(string node);
};

#endif
