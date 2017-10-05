#pragma once

#include <set>
#include <cstdlib>
#include <vector>
#include <list>

template <typename T>
struct StatisticMultiset {

	StatisticMultiset();

	//add number to set
	void AddNum(T const &num);
	void AddNum(std::multiset<T> const &numbers);
	void AddNum(std::vector<T> const &numbers);
	void AddNum(std::list<T> const &numbers);
	void AddNum(StatisticMultiset<T> const &numbers);
	void AddNumsFromFile(char const * const filename);
	
	//returns max value of set
	T GetMax() const;

	//return min value of set
	T GetMin() const;

	//returns average of set
	float GetAvg() const;

	//returns quantity of elements
	size_t GetSize() const;

	//returns quantity of elements which less that argument
	size_t GetCountUnder(float const &threshold) const;

	//returns quantity of elements which larger that argument
	size_t GetCountAbove(float const &threshold) const;
	

private:
	std::multiset <T> data;
	T sum;
};

#include "StatisticMultiset.cpp"	

