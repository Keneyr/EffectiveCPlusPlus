#include "Screen.h"

void* Screen::operator new(size_t size) {
	/*
	void* p = malloc(size);
	return p;
	*/
	Screen* p;
	if (!freeStore) {
		//linked list�ǿյģ���������һ���
		size_t chunk = screenChunk * size;
		freeStore = p =
			reinterpret_cast<Screen*>(new char[chunk]);
		//��һ��ηָ��ƬƬ������linked list��������
		for (; p != &freeStore[screenChunk - 1]; ++p)
			p->next = p + 1;
		p->next = 0;
	}
	p = freeStore;
	freeStore = freeStore->next;
	return p;
}
void Screen::operator delete(void* p, size_t) {
	//free();
	//��deleted object���free list
	(static_cast<Screen*>(p))->next = freeStore;
	freeStore = static_cast<Screen*>(p);
}
Screen* Screen::freeStore = 0;
const int Screen::screenChunk = 24;