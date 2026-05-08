#include "undirected_graph.hpp"
#include <iostream>

int main() {
    undirected_graph<int> g;
    g.add_edge(1, 2);
    
    std::cout << "Archi nel grafo: ";
    for (const auto& e : g.all_edges()) {
        std::cout << e << " ";
    }
    
    return 0;
}