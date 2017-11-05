//
// Created by disa on 05.11.17.
//

#include <iostream>
#include "PrimeNumber.h"


PrimeNumber::PrimeNumber() : neerest_prime(size_ + 1, 0) {
    for (int i = 2; i <= (int)size_; i++) {
        if (neerest_prime[i] == 0) {
            neerest_prime[i] = i;
            primes.push_back(i);
        }
        for (size_t j = 0; j < primes.size() && primes[j] <= neerest_prime[i]
                           && i * primes[j] <= (int)size_; j++)
            neerest_prime[i * primes[j]] = primes[j];
    }
}

std::vector <int> * PrimeNumber::factorization(int const n) const {
    std::vector <int> *ans = new std::vector <int>;
    int now = n;
    for (int i = 0; i < (int)primes.size() && now > size_; i++) {
        while (now % primes[i] == 0) {
            ans->push_back(primes[i]);
            now /= primes[i];
        }
    }
    while(now > 1 && now <= size_) {
        ans->push_back(neerest_prime[now]);
        now /= neerest_prime[now];
    }
    for (int i = 2; i * i <= now; i++) {
        while (now % i == 0) {
            ans->push_back(i);
            now /= i;
        }
    }
    if (now > 1) ans->push_back(now);
    return ans;
}