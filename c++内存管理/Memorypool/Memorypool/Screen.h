#pragma once

#include <iostream>
using namespace std;

class Screen {
public:
	Screen(int _id) : id(_id){}
	int get();

	void* operator new(size_t size);
	void operator delete(void*, size_t);

private:
	Screen* next;
	int id;

	static Screen* freeStore;
	static const int screenChunk;
};