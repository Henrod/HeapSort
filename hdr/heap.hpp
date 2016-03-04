#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>

class Heap {
	public:
		Heap();
		Heap(const Heap& heap);
		void insert(const int data);
		void remove(const int data);
		int  getMin() const;
		int  getMax() const;
		void sort();
		void print() const;
		const std::vector<int> getHeap() const;
		void heapsort();
		unsigned int size() const;
	private:
		void sink(unsigned int k, const unsigned int size);
		void swim(int k);
		void exch(int i, int j);
		std::vector<int> mHeap;
};

#endif //HEAP_HPP
