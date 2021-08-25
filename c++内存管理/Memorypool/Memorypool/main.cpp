/*
*��������Դ����ڴ�ع���
*/

#include "Screen.h"
#include "Airplane.h"
#include "Foo.h"

int main() {
	//Screen�����еĵ�ַ�������һ��sizeof(Screen)
	//��������ȫ��malloc��cookie����
	cout << sizeof(Screen) << endl;
	size_t const N = 10;
	Screen* p[N];

	for (int i = 0; i < N; ++i) {
		p[i] = new Screen(i);
	}
	for (int i = 0; i < 10; i++) {
		cout << p[i] << endl;
	}
	for (int i = 0; i < N; ++i) {
		delete p[i];
	}

	cout << "********" << endl;
	
	cout << sizeof(Airplane) << endl;
	Airplane* a[N];
	for (int i = 0; i < N; ++i) {
		a[i] = new Airplane;
	}
	for (int i = 0; i < 10; ++i) {
		cout << a[i] << endl;
	}
	for (int i = 0; i < N; ++i) {
		delete a[i];
	}
	
	cout << "***********" << endl;
	cout << sizeof(long) << " " << sizeof(string) << endl;
	cout << sizeof(Foo) << endl;
	Foo* f[N];
	//cout << sizeof(f) << endl;
	for (int i = 0; i < N; ++i) {
		f[i] = new Foo(1);
	}
	for (int i = 0; i < 10; ++i) {
		cout << f[i] << endl;
	}
	for (int i = 0; i < N; ++i) {
		delete f[i];
	}
	
	return 0;
}