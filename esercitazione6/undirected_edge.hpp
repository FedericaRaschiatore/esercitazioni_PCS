#include <algorithm>
#include <iostream>
#include <tuple>

template <typename T>
class undirected_edge {
public: 
    T node_from;
    T node_to;

    // Costruttore che mi assicura che il nodo di partenza sia < di quello di arrivo
    undirected_edge(T u, T v) {
        node_from = std::min(u, v);
        node_to = std::max(u, v);
    }
    // Restituiscono i due nodi
    T from() const { return node_from; }
    T to() const { return node_to; } 

    bool operator==(const undirected_edge& other) const {
        return node_from == other.node_from && node_to == other.node_to;
    }

    bool operator<(const undirected_edge& other) const {
        return std::tie(node_from, node_to) < std::tie(other.node_from, other.node_to);
    }
    //per stampare i nodi 
    friend std::ostream& operator<<(std::ostream& os, const undirected_edge& edge) {
    os << "(" << edge.node_from << ", " << edge.node_to << ")";
    return os;
    }
};