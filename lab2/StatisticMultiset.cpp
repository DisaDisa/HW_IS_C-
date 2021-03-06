#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <fstream>
#include <string>


template <typename T>
StatisticMultiset<T>::StatisticMultiset() : sum(0) {}


template <typename T>
void StatisticMultiset<T>::AddNum(T const &num) {
	data.insert(num);
	sum += num;
}


template <typename T>
void StatisticMultiset<T>::AddNum(std::multiset<T> const &numbers) {
	for (auto &i : numbers) {
		data.insert(i);
		sum += i;
	}
}
	

template <typename T>
void StatisticMultiset<T>::AddNum(std::vector<T> const &numbers) {
	for (auto &i : numbers) {
		data.insert(i);
		sum += i;
	}
}


template <typename T>
void StatisticMultiset<T>::AddNum(std::list<T> const &numbers) {
	for (auto &i : numbers) {
		data.insert(i);
		sum += i;
	}
}

template <typename T>
void StatisticMultiset<T>::AddNum(StatisticMultiset<T> const &numbers) {
	if (this != &numbers) {
		AddNum(numbers.data);
	} else {
		for (auto i = numbers.data.begin(); i != numbers.data.end(); i++) {
			data.insert(*i);
			sum += *i;
			i++; // 
		}
	}	
}

template <typename T>
void StatisticMultiset<T>::AddNumsFromFile(char const * const filename) {
	std::ifstream in(filename);
	if (!in.good())
		std::cerr << "File IO error while opening\n";
	T now;
	while(in >> now) { 
		AddNum(now);
		sum += now;
	}	
}	
	


template <typename T>
T StatisticMultiset<T>::GetMin() const {
	return *data.begin();
}	

template <typename T>
T StatisticMultiset<T>::GetMax() const {
	return *data.rbegin();
}	

template <typename T>
size_t StatisticMultiset<T>::GetSize() const {
	return data.size();
}	
	
template <typename T>
float StatisticMultiset<T>::GetAvg() const {
	if (GetSize() == 0) 
		std::cerr << "No elements is StatisticMultiset\n";
	return (float)sum / GetSize();
}	

template <typename T>
size_t StatisticMultiset<T>::GetCountUnder(float const &threshold) const {
	size_t ans = 0;
	for (auto i = data.begin(); i != data.end() && *i < threshold; i++) ++ans;
	return ans;	 
}	

template <typename T>
size_t StatisticMultiset<T>::GetCountAbove(float const &threshold) const {
	size_t ans = 0;
	for (auto i = data.rbegin(); i != data.rend() && *i > threshold; i++) ++ans;
	return ans;
}	
                                                             
	
