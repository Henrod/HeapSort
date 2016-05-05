#include <math.h>
#include <iostream>
#include "heap.hpp"

using namespace std;

Heap::Heap() {
	std::cout<< "__DEBUG__" << std::endl;
	mHeap.push_back(-1);
}

Heap::Heap(const Heap& heap) {
	for (const auto& x : heap.getHeap())
		mHeap.push_back(x);
}

const std::vector<int> Heap::getHeap() const {
	return mHeap;
}

void Heap::insert(const int data){
	mHeap.push_back(data);
}

void Heap::remove(const int data){
	for (unsigned int i = 1; i < mHeap.size(); ++i) {
		if (data == mHeap[i]) {
				exch(i, mHeap.size() - 1);
				mHeap.pop_back();
				sink(i, mHeap.size());
				break;
		}
	}
}

int  Heap::getMin() const {
	Heap aux_heap = Heap(*this);
	aux_heap.heapsort();
	return aux_heap.getHeap()[1];
}

int  Heap::getMax() const {
	Heap aux_heap = Heap(*this);
	aux_heap.sort();
	return aux_heap.getHeap()[1];
}


void Heap::exch(int i, int j) {
	int tmp = mHeap[i];
	mHeap[i] = mHeap[j];
	mHeap[j] = tmp;
}


void Heap::print() const {
	for (unsigned int i = 1; i < mHeap.size(); ++i) {
		cout << mHeap[i] << " ";
	}
	cout << endl << endl;
}

unsigned int Heap::size() const {
	return mHeap.size();
}

void Heap::heapsort() {
	int N = mHeap.size() - 1;
	sort();

	while (N > 1) {
		exch(1, N--);
		sink(1, N);
	}
}

void Heap::sink(unsigned int k, const unsigned int size) {
	while (2*k <= size) {
		unsigned int j = 2*k; //Son, k is Parent
		if (j + 1 < size && mHeap[j] < mHeap[j+1]) ++j;
		if (mHeap[k] > mHeap[j]) break;
		exch(j, k);
		k = j;
	}
}
void Heap::sort() {
	unsigned int N = mHeap.size();
	for (unsigned int k = N/2; k >= 1; --k) {
		sink(k, N);
	}
}
