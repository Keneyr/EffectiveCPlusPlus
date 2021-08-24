/**
* ����operator new / operator delete����
*/
#include <iostream>
#include "Foo.h"
using namespace std;

int main() {
	cout << sizeof(int) << " " << sizeof(long) << " " << sizeof(string) << " " << sizeof(size_t)<< endl;
	cout << sizeof(Foo) << endl;
	//ʹ�����ص�operator new �� delete
	Foo* p = new Foo(7);
	delete p;

	cout << endl;

	//ʹ��ȫ��operator new �� delete
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