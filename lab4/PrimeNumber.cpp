//
// Created by disa on 05.11.17.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "PrimeNumber.h"


std::vectorgint> PrimeNumber::min_prime;
std::vector<int> PrimeNumber::primes;


PrimeNumber::PrimeNumber() {
    min_prime.resize(size_ + 1, 0);
    for (int i = 2; i <= (int)size_; i++) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
            primes.push_back(i);
        }
        for (size_t j = 0; j < primes.size() && primes[j] <= min_prime[i] && i * primes[j] <= (int)size_; j++)
            min_prime[i * primes[j]] = primes[j];
    }
}

std::vector <int> PrimeNumber::factorization(int const n) const {
    std::vector <int> ans;
    int now = n;
    for (int i = 0; i < (int)primes.size() && now > size_; i++) {
        while (now % primes[i] == 0) {
            ans.push_back(primes[i]);
            now /= primes[i];
        }
    }
    while(now > 1 && now <= size_) {
        ans.push_back(min_prime[now]);
        now /= min_prime[now];
    }
    for (int i = 2; i * i <= now; i++) {
        while (now % i == 0) {
            ans.push_back(i);
            now /= i;
        }
    }
    if (now > 1) ans.push_back(now);
    return std::move(ans);
}



void PrimeNumber::file_factorization(char const * const filename_in, char const * const filename_out) const {
    std::ifstream in(filename_in);
    std::ofstream out(filename_out);
    if (!in.good() || !out.good()) {
        std::cerr << "File IO error while opening\n";
    }
    int num;
    while (in >> num) {
        std::vector <int> ans = factorization(num);
        out << num << " = ";
        for (size_t i = 0; i < ans.size(); i++) {
            out << ans[i] << ' ';
            if (i + 1 < ans.size())
                out << "* ";
        }
        out << '\n';
    }
    in.close();
    out.close();
}

bool PrimeNumber::is_prime(int const n) const {
    return min_prime[n] == n;
}














