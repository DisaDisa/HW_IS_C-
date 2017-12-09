#include "Vector.h"
#include <iostream>

using namespace std;

int main() {
	Vector <int> a(5, 3);
	a.push_back(7);
	for (int i = 0; i < 6; i++) {
		cout << a[i] << ' '; 
	}

}