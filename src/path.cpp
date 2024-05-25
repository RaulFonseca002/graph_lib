#include "graph.hpp"
using namespace std;

struct pathingNode {
    string name;
    double totalWeight;
    string from;

    pathingNode(string name, double weight) : name(name), totalWeight(weight) {}

    bool operator < (const pathingNode& other) const {
        return totalWeight > other.totalWeight;
    }
};

string Graph::dfs(string from, string to) {
    return "";
}

string Graph::bfs(string from, string to) {
    return "";
}

struct compareWeight {
    bool operator()(node_t n1, node_t n2) {
        return n1.weight > n2.weight;
    }
};

void setNodesVector(vector<node_t> *vec, string startNode, double startingVal){
    
    for(int n = 0; n < vec->size(); n++){
        vec->at(n).weight = (vec->at(n).name.compare(startNode) == 0) ? 0 : startingVal;
    }
}

void setWeights(vector<node_t> *nodeVector, string to, double edgeWeight, node_t from){

    for(node_t &n : *nodeVector){

        if(n.name.compare(to) == 0 && (n.weight > (from.weight + edgeWeight))){
            n.weight = from.weight + edgeWeight;
            n.cameFrom = from.name;
            return;
        }

    }
}

string Graph::dijkstra(string from, string to) {

    node_t node;
    vector<node_t> nodesHeap = nodes.getNodesVector();
    map<string, double> currentEdges;

    setNodesVector(&nodesHeap, from, HUGE_VAL);
    make_heap(nodesHeap.begin(), nodesHeap.end(), compareWeight());

    node = nodesHeap.front();
    nodesHeap.erase(nodesHeap.begin());

    while(!nodesHeap.empty() || (node.name.compare(to) == 0)){

        setNode(node);

        for(auto it : getEdges(node.name)){
            setWeights(&nodesHeap, it.first, it.second, node);
        }
        
        make_heap(nodesHeap.begin(), nodesHeap.end(), compareWeight());

        node = nodesHeap.front();
        nodesHeap.erase(nodesHeap.begin());

        if(node.weight == HUGE_VAL) {
            return "no path from " + from + " to " + to;
        }
    }

    return getPath(from, to);
}

string Graph::dijkstra(vector<string> from, vector<string> to){

    string resp;

    addNode("startingNode");
    addNode("terminalNode");

    for(int c = 0; c < from.size(); c++){
        addEdge("startingNode", from[c], 1);
    }

    for(int c = 0; c < to.size(); c++){
        addEdge(to[c], "terminalNode", 1);
    }

    resp = dijkstra("startingNode", "terminalNode");

    removeNode("startingNode");
    removeNode("terminalNode");


    resp = resp.substr(strlen("startingNode->"), (resp.length() - (strlen("->terminalNode") + strlen("startingNode->"))));
    return resp;
}

string Graph::dijkstra(vector<string> from, string to){

    vector<string> t;
    t.push_back(to);

    return dijkstra(from, t);
}

string Graph::dijkstra(string from, vector<string> to){

    vector<string> s;
    s.push_back(from);

    return dijkstra(s, to);
}