#include "graph.hpp"

int main(int argc, char const *argv[])
{
    Graph graph;
    string inputString;
    fstream inputFile("input.txt");
    vector<string> s;
    vector<string> t;

    while (getline(inputFile, inputString)) {
        graph.set(inputString);
    }

    s.push_back("s");
    s.push_back("z");
    
    t.push_back("t");
    t.push_back("p");

    printf("%s\n", graph.dijkstra(s,t).c_str());
    printf("%s\n", graph.dijkstra("e","a").c_str());

    return 0;
}
