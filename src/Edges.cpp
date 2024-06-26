#include "Edges.hpp"
#include <algorithm> 

using namespace std;

Edges::Edges() {
}

Edges::~Edges() {
}

void Edges::add(string from, string to, double weight){
    edges[from][to] = weight;
}

void Edges::print(){

    for(auto from : edges){
        printf("from %s to: ", from.first.c_str());

        for(auto to : from.second){
            printf("%s %f,", to.first.c_str(), to.second);
        }
        printf("\n");
    }
}

bool Edges::existNode(string name){
    return (edges.find(name) != edges.end());
}

bool Edges::existEdge(string from, string to){
    
    if(!existNode(from)) return false;

    for(auto from : edges[from]){
        if(from.first.compare(to) == 0) return true;
    } 
    
    return false;
}

void Edges::removeNode(string name){
    edges.erase(name);
}


void Edges::removeEdge(string from, string to){
    edges[from].erase(to);
    
}

map<string, double> Edges::getEdges(string node){
    return edges[node];
}
