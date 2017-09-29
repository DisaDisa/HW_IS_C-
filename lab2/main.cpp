#include "StatisticMultiset.h"
#include <iostream>
#include <set>
#include <vector>
#include <list>

int main() {
	StatisticMultiset<int> s;	
	s.AddNum(5);
	s.AddNum(10);
	std::vector<int> v = {1, 2, 3};
	std::multiset<int> ss = {7, 15};
	std::list<int> l = {10, 20};
	s.AddNum(v);
	s.AddNum(ss);
	s.AddNum(l);
	StatisticMultiset<int> s2;
	std::vector<int> v2 = {25, 22};
	s2.AddNum(v2);
	s.AddNum(s2);
	s.AddNumsFromFile("input.txt");
	std::cout << "min " << s.GetMin() << '\n';
	std::cout << "max " << s.GetMax() << '\n';
	std::cout << "avg " << s.GetAvg() << '\n';
	std::cout << "less 7.5 " << s.GetCountUnder(7.5) << '\n';
	std::cout << "larger 7.5 " << s.GetCountAbove(7.5) << '\n';
	std::cout << "less 10 " << s.GetCountUnder(10) << '\n';
	std::cout << "larger 10 " << s.GetCountAbove(10) << '\n';
}	