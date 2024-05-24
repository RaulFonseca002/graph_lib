#include "graph.h"
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

    }

    return getPath(from, to);
}
