//
// Created by disa on 05.11.17.
//

#pragma once

#include <cstddef>
#include <vector>


struct PrimeNumber {
    //generate array neerest_prime
    PrimeNumber();

    //returns vector <int> with primes
    std::vector <int> * factorization(int const) const;


private:
    static size_t const size_ = (int)1e7;
    std::vector <int> neerest_prime;
    std::vector <int> primes;
};

