#include <iostream>
#include <fstream>
#include "PrimeNumber.h"


int main(int argc, char ** argv) {
    PrimeNumber p;
    p.file_factorization(argv[1], argv[2]);
    PrimeNumber p1;
    std::cout << p.is_prime(11) << '\n';
    std::cout << p1.is_prime(15) << '\n';
    return 0;
}