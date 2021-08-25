#include "Airplane.h"

Airplane* Airplane::headOfFreeList;
const int Airplane::BLOCK_SIZE = 512;

void* Airplane::operator new(size_t size) {
	if (size != sizeof(Airplane))
		return ::operator new (size);
	
	Airplane* p = headOfFreeList;
	if (p) {
		headOfFreeList = p->next;
	}
	else {
		Airplane* newBlock = static_cast<Airplane*>(::operator new(sizeof(Airplane) * BLOCK_SIZE));
		for (int i = 1; i < BLOCK_SIZE - 1; ++i) {
			newBlock[i].next = &newBlock[i+1];
		}
		newBlock[BLOCK_SIZE - 1].next = 0;
		p = newBlock;
		headOfFreeList = &newBlock[1];
	}
	return p;
}
void Airplane::operator delete(void* deadObject, size_t size) {
	if (deadObject == 0) return;
	if (size != sizeof(Airplane)) {
		::operator delete(deadObject);
		return;
	}
	Airplane* carcass = static_cast<Airplane*>(deadObject);
	carcass->next = headOfFreeList;
	headOfFreeList = carcass;
}