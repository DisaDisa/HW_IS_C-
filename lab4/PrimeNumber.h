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
    std::vector <int> factorization(int const) const;

    //factorization of numbers in file
    void file_factorization(char const * const filename_in, char const * const filename_out) const;

    //check that int argument is prime
    bool is_prime(int const) const;


private:
    static size_t const size_ = (int)1e7;
    static std::vector <int> min_prime;
    static std::vector <int> primes;
};

