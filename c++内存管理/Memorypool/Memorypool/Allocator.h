#pragma once
#include <malloc.h>
#include <iostream>
using namespace std;
class Allocator {
private:
	struct obj {
		struct obj* next; //embedded pointer
	};
public:
	Allocator() { cout << "Allocator ctor..." << endl; cout << sizeof(Allocator) << endl; }
	void* allocate(size_t);
	void deallocate(void*, size_t);
private:
	obj* freeStore = nullptr;
	const int CHUNK = 5;
};