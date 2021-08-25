#pragma once
#include <string>
#include "Allocator.h"
class Foo {
public:
	long L;
	string str;
	static Allocator myAlloc;
public:
	Foo(long l) :L(l) { cout << "Foo ctor..." << endl; }
	static void* operator new(size_t size) {
		return myAlloc.allocate(size);
	}
	static void operator delete(void* pdead, size_t size) {
		return myAlloc.deallocate(pdead, size);
	}
};
Allocator Foo::myAlloc;