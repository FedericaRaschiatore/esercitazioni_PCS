#include <iostream>
#include <list>
#include <set>
#include <map>
#include <tuple>
#include <unordered_map>
#include <algorithm>
#include "undirected_edge.hpp"

template <typename T>
class undirected_graph {
public:
    std::unordered_map<T, std::list<T>> adj_list;  //lista dei nodi adiacenti

    std::set<undirected_edge<T>> unique_edges; //lista degli archi senza doppioni, infatti i set non ammettono duplicati

    std::map<T, int> node_degrees; //qui map ha come chiave il nodo e come valore il grado del nodo 

    // Costruttore di default
    undirected_graph()=default;

    // Costruttore di copia
    undirected_graph(const undirected_graph& other) {
        adj_list = other.adj_list;
        unique_edges = other.unique_edges;
        node_degrees = other.node_degrees;
    }

    std::list<T> neighbours(T node) const {
        typename std::unordered_map<T, std::list<T>>::const_iterator it = adj_list.find(node);
        if (it != adj_list.end()) {   //cioè se il nodo viene trovato nella mappa:
            return it->second; // return il secondo elemento della tupla, cioè nella mia mappa la lista dei nodi adiacenti
        }
        return std::list<T>(); // se il nodo non viene trovato nella mappa restituisce nulla
    }

    void add_edge(T u, T v) {
        undirected_edge<T> new_edge(u, v);

        std::pair<typename std::set<undirected_edge<T>>::iterator, bool> result = unique_edges.insert(new_edge);

        if (result.second) { //se bool=true allora aggiorniamo lista dei nodi adiacenti e anche il grado 
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
            
            node_degrees[u]++;
            node_degrees[v]++;
        }
    }

    std::set<undirected_edge<T>> all_edges() const {  //avevamo già creato la lista degli archi unique_edges
        return unique_edges;
    }

    std::set<T> all_nodes() const {  // uso un set così i nodi non avranno doppioni
        std::set<T> nodes;
        for (const std::pair<const T, int>& p : node_degrees) {  //scorre la mappa node_degrees creata prima e inserisce nel set nodes ogni nodo
            nodes.insert(p.first);
        }
        return nodes;
    }

    int edge_number(const undirected_edge<T>& edge) const {

    typename std::set<undirected_edge<T>>::const_iterator it = unique_edges.find(edge); //cerchiamo l'arco nel set unique_edges con un iteratore

    if (it == unique_edges.end()) {   //se non lo troviamo return -1
        return -1;
    }
    return static_cast<int>(std::distance(unique_edges.begin(), it)); //se lo trova restituiamo la distanza tra il primo arco nel set e la posizione dell'iteratore it
    }



    undirected_edge<T> edge_at(int index) const {  //il numero lo salviamo come index

        typename std::set<undirected_edge<T>>::const_iterator it = unique_edges.begin(); //inizializziamo l'iteratore sull'inizio del set
        it = std::next(it, index); //l'iteratore avanza di index passi
        return *it; //restituisce il valore contenuto nel posto it
    }

    undirected_graph<T> operator-(const undirected_graph<T>& other) const {

        undirected_graph<T> result; //grafo che rappresenterà il risultato
        for (typename std::set<undirected_edge<T>>::const_iterator it = this->unique_edges.begin(); //iteratore it sull'inizio di unique_edges
            it != this->unique_edges.end(); ++it) {
            
            const undirected_edge<T>& e = *it; //estraiamo l'arco puntato da it e lo chiamiamo e

            // 3. Verifichiamo se l'arco 'e' NON è presente nel grafo 'other' (G')
            // Se la ricerca nel set di G' arriva alla fine (end), l'arco non esiste in G'
            if (other.unique_edges.find(e) == other.unique_edges.end()) {  

                result.add_edge(e.from(), e.to()); //verifichiamo che l'arco sia in uno e non nel'altro e lo inseriamo nel grafo result
            }
        }
        return result;
    }
};





