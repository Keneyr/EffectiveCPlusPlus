#include "Allocator.h"

void* Allocator::allocate(size_t size) {
	obj* p;
	if (!freeStore) {
		size_t chunk = CHUNK * size;
		freeStore = p = (obj*)malloc(chunk);

		for (int i = 0; i < (CHUNK - 1); ++i) {
			p->next = (obj*)((char*)p + size);
			p = p->next;
		}
		p->next = nullptr;
	}
	p = freeStore;
	freeStore = freeStore->next;
	return p;

}
void Allocator::deallocate(void* p, size_t) {
	((obj*)p)->next = freeStore;
	freeStore = (obj*)p;
}