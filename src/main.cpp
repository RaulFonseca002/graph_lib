#include "graph.h"

int main(int argc, char const *argv[])
{
    Graph graph;
    string inputString;
    fstream inputFile("input.txt");

    while (getline(inputFile, inputString)) {
        graph.set(inputString);
    }

    printf("%s\n", graph.dijkstra("a", "f").c_str());
    return 0;
}
