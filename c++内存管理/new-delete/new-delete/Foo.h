#pragma once
#include <iostream>
using namespace std;
class Foo {
public:
	int id;
	long data;
	string str;
public:
	Foo() : id(0) { cout << "default ctor. this = " << this << " id = " << id << endl; }
	Foo(int _id) : id(_id) { cout << "ctor. this = " << this << " id = " << id << endl; }
	~Foo() { cout << "dtor. this = " << this << " id = " << id << endl; }

	static void* operator new (size_t size);
	static void operator delete(void* pdead, size_t size);

	static void* operator new[](size_t size);
	static void operator delete[](void* pdead, size_t size);

	static void* operator new(size_t size,void* start); //placement new
	static void* operator new(size_t size, long extra); //placement new

	static void operator delete(void*, size_t);
	static void operator delete(void*, long extra); //basc_string实现中用到了这个

};
