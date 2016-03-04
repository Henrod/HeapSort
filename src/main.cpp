#include <iostream>
#include "heap.hpp"

using namespace std;

int main() {
	Heap heap;
	cout << "i (insert), r (remove), s (sort), m (get min), x (stop), h (heapsort), M (get max): " << endl;
	char cmd;

	while (true) {
		cout << "cmd> ";
		cin >> cmd;
		int value;

		switch(cmd) {
			case 'i':
				cout << "\tvalue> ";
				cin >> value;
				heap.insert(value);
				break;
			case 'r':
				cout << "\tvalue> ";
				cin >> value;
				heap.remove(value);
				break;
			case 's':
				heap.sort();
				break;
			case 'm':
				cout << "\tMin value: " << heap.getMin() << endl;
				break;
			case 'M':
				cout << "\tMax value: " << heap.getMax() << endl;
				break;
			case 'h':
				heap.heapsort();
				break;
		}
		if (cmd == 'x') break;
		heap.print();
	}
}
