#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <queue>
#include <fstream>
#include <regex>
#include <cmath>
#include "Nodes.h"
#include "Edges.h"

using namespace std;

class Graph {
    private:
        Nodes nodes;
        Edges edges;
        bool directed;

        void setNodes(string str);
        void setEdges(string str);
        string getPath(string from, string to);


    public:
        Graph();
        Graph(string str);
        ~Graph();
        void set(string str);
        void print();
        void addEdge(string from, string to, double weight);
        void addNode(string nodeName);
        void removeNode(string nodeName);
        void removeEdge(string from, string to);
        map<string, double> getEdges(string node);
        void setNode(node_t node);
        node_t getNode(string nodeName);
        // path
        string dfs(string from, string to);
        string bfs(string from, string to);
        string dijkstra(string from, string to);
};


#endif 