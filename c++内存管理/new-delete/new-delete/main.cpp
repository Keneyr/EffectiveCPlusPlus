/**
* 重载operator new / operator delete测试
*/
#include <iostream>
#include "Foo.h"
using namespace std;

int main() {
	cout << sizeof(int) << " " << sizeof(long) << " " << sizeof(string) << " " << sizeof(size_t)<< endl;
	cout << sizeof(Foo) << endl;
	//使用重载的operator new 及 delete
	Foo* p = new Foo(7);
	delete p;

	cout << endl;

	//使用全局operator new 及 delete
	Foo* gp = ::new Foo(8);
	::delete gp;

	cout << endl;

	cout << "***********" << endl;
	//placement new
	Foo start;
	Foo* p1 = new Foo;

	cout << endl;

	Foo* p2 = new(&start)Foo;

	return 0;
}