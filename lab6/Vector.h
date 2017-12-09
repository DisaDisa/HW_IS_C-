//
// Created by disa on 09.12.17.
//

#pragma once


#include <cstddef>
#include <utility>


template <typename T>
struct Vector {
    Vector();
    Vector(std::size_t);
    Vector(std::size_t, T const &);

    ~Vector();

    T & operator[](std::size_t);
    T const & operator[](std::size_t) const;

    T & at(std::size_t);
    T const & at(std::size_t) const;

    void resize(std::size_t);
    void resize(std::size_t, T const &);

    void reserve(std::size_t);

    Vector(Vector const &);
    Vector<T> & operator=(Vector const &);

    void push_back(T const &);
    void push_back(T &&);

    Vector (Vector &&);
    Vector & operator=(Vector &&);

    void swap(Vector &);

    std::size_t length() const;

private:

    void add_size(std::size_t);

    std::size_t capacity, size;
    T* data_;

};

#include "Vector.cpp"
