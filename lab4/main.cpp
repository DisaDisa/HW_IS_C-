#include <iostream>
#include <fstream>
#include "PrimeNumber.h"


int main(int argc, char ** argv) {
    std::cerr << "input filename: " << argv[1] << '\n';
    std::cerr << "output filename: " << argv[2] << '\n';
    std::ifstream in;
    in.open(argv[1]);
    std::ofstream out;
    out.open(argv[2]);
    if (!in.good() || !out.good()) {
        std::cerr << "File IO error while opening\n";
    }
    int num;
    PrimeNumber p;
    while (in >> num) {
        std::cerr << num << '\n';
        std::vector <int> *ans = p.factorization(num);
        out << num << " = ";
        for (size_t i = 0; i < ans->size(); i++) {
            out << (*ans)[i] << ' ';
            if (i + 1 < ans->size())
                out << "* ";
        }
        out << '\n';
    }
    in.close();
    out.close();
    return 0;
}