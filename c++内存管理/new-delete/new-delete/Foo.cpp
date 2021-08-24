#include "Foo.h"

void* Foo::operator new(size_t size) {
	Foo* p = (Foo*)malloc(size);
	//cout << size << endl;
	cout << "operator new..." << endl;
	return p;
}
void Foo::operator delete(void* pdead, size_t size) {
	cout << "operator delete..." << endl;
	free(pdead);
}
void Foo::operator delete[](void* pdead, size_t size) {
	free(pdead);
}
void* Foo::operator new[](size_t size) {
	Foo* p = (Foo*)malloc(size);
	return p;
}

void* Foo::operator new(size_t size, void* start) {
	cout << "placement new..." << endl;
	return start;
}
void* Foo::operator new(size_t size, long extra) {
	return malloc(size + extra);

}
void Foo::operator delete(void*, size_t) {

}
void Foo::operator delete(void*, long extra) {

}