#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <numeric>
#include <vector>
int main(int argc, const char* argv[]) {
    if (argc<2) {
        std::cerr << "Errore, devi passare nome file" << std::endl;
        return 1;
    }
    std ::string filename= argv[1];
    std ::ifstream ifs(filename);
    std:: string riga;
    if (ifs.is_open()) {
        while(std::getline(ifs,riga)) {
            std::stringstream ss(riga);
            std::string citta;
            double temp_00, temp_06, temp_12, temp_18;
            if (ss >> citta >> temp_00 >> temp_06 >> temp_12 >> temp_18) {
                std::vector<double> temp={temp_00,temp_06,temp_12,temp_18};
                double somma= std::accumulate(temp.begin(),temp.end(),0.0);
                double media=somma/4.0;
                std:: cout<<citta<<" "<< media<< std::endl;
            }
        }
    }
}