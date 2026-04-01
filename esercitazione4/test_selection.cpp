#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib> // Per rand() e srand()
#include <ctime>   // Per time()
#include "timecounter.h"

template<typename T>
bool is_sorted(const std::vector<T>& vec){
    if (vec.size()<2) {
        return true;
    }
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i]<vec[i-1]){
            return false;
        }
    }
    return true;
}


template<typename T>
void selection_sort(std::vector<T>& vec){
    if (vec.size()<2) return;
    for (size_t i=0; i<vec.size()-1; ++i) {
        size_t min=i;
        for (size_t j=i+1; j<vec.size(); ++j){
            if (vec[j]<vec[min]) {
                min=j;
            }
        }
        T temp=vec[i];
        vec[i]=vec[min];
        vec[min]=temp;
    }
}

int main() {
    srand(time(0));
    timecounter timer; 
    double tempo_totale = 0;
    double tempo_totale_sort=0;

    for (int i = 0; i < 100; ++i) {
        // Dimensione casuale tra 10 e 100
        int dimensione = rand() % 91 + 10; 
        std::vector<int> v;

        // Riempire con numeri tra -1000 e 1000
        for (int j = 0; j < dimensione; ++j) {
            int valore = rand() % 2001 - 1000; 
            v.push_back(valore);
        }

        timer.tic();
        // Ordiniamo il vettore
        selection_sort(v);
        tempo_totale += timer.toc();

        timer.tic();
        std::sort( v.begin(), v.end() );
        tempo_totale_sort += timer.toc();


        // Verifichiamo se e' ordinato
        if (!is_sorted(v)) std::cout << "Errore nel test"<< "!\n";
    }
    std::cout << "Tempo totale per 100 ordinamenti: " << tempo_totale << " secondi\n";
    std::cout << "Tempo totale per 100 ordinamenti usando sort: " << tempo_totale_sort << " secondi\n";
    
    std::vector<std::string> parole = {
        "zaino", "quadro", "mela", "barca", "gatto", 
        "cane", "fuoco", "ciao", "libro", "erba"
    };

    selection_sort(parole);

    if (is_sorted(parole)) {
        std::cout << "Test stringhe: SUPERATO!\n";
    } else {
        std::cout << "Test stringhe: FALLITO!\n";
    }

    return 0;
}