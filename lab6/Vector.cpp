#include <iostream>


//Constructors
template <typename T>
Vector<T>::Vector() : size(0), capacity(0), data_(nullptr) {}

template <typename T>
Vector<T>::Vector(size_t sz) : size(sz), capacity(sz), data_(nullptr){}

template <typename T>
Vector<T>::Vector(size_t sz, T const &a) : size(sz), capacity(sz), data_(new T[sz]) {
	for (std::size_t i = 0; i < sz; i++) 
		data_[i] = a;
}


//Destructor
template <typename T>
Vector<T>::~Vector() {
	delete [] data_;
}


//Getters
template <typename T>
T & Vector<T>::operator[](std::size_t i) {
	return data_[i];
}

template <typename T>
T const & Vector<T>::operator[](std::size_t i) const {
	return data_[i];
}

template <typename T>
T & Vector<T>::at(std::size_t i) {
	if (i >= size)
		std::cerr << "out of range\n";
	return data_[i];
}

template <typename T>
T const & Vector<T>::at(std::size_t i) const {
	if (i >= size) 
		std::cerr << "out of range\n";
	return data_[i];
}

template <typename T>
void Vector<T>::resize(std::size_t sz) {
	if (sz > capacity) {
		add_size(sz);
	}
	size = sz;
}

template <typename T>
void Vector<T>::resize(std::size_t sz, T const &n) {
	if (sz > capacity) {
		add_size(sz);
		for (std::size_t i = size; i < sz; i++) 
			data_[i] = n;
	}
	size = sz;
}

template <typename T>
void Vector<T>::reserve(std::size_t sz) {
	if (sz > capacity) {
		add_size(sz);
	}
}

template <typename T>
void Vector<T>::add_size(std::size_t sz) {
	T * new_data = new T[sz];
	capacity = sz;
	for (std::size_t i = 0; i < size; i++) 
		new_data[i] = data_[i];
	delete[] data_;
	data_ = new_data;
}

template <typename T>
Vector<T>::Vector(Vector const &a): size(a.size), capacity(a.capacity), data_(new T[capacity]) {
	for (std::size_t i = 0; i < size; i++) 
		data_[i] = a.data_[i];
}

template <typename T>
Vector<T> & Vector<T>::operator=(Vector const &a) {
	if (this != &a) {
		delete[] data_;
		size = a.size;
		capacity = a.capacity;
		data_ = new T[capacity];
		for (std::size_t i = 0; i < size; i++)
			data_[i] = a.data_[i];
	}
	return *this;
}

template <typename T>
void Vector<T>::push_back(T const &val) {
	if (size == capacity) reserve(2 * capacity);
	data_[size++] = val;
}

template <typename T>
void Vector<T>::push_back(T && val) {
	if (size == capacity) reserve(2 * capacity);
	data_[size++] = std::move(val);
}

template <typename T>
void Vector<T>::swap(Vector &v) {
	std::swap(size, v.size);
	std::swap(capacity, v.capacity);
	std::swap(data_, v.data_);
}

template <typename T>
Vector<T>::Vector(Vector && v) {
	data_ = nullptr;
	size = 0;
	capacity = 0;
	swap(v);
}

template <typename T>
Vector<T> & Vector<T>::operator=(Vector && v) {
	swap(v);
	return *this;
}

template <typename T>
std::size_t Vector<T>::length() const {
	return size;
}

