#pragma once

class Airplane {
private:
	struct AirplaneRep {
		unsigned long miles;
		char type;
	};
private:
	union {
		AirplaneRep rep;
		Airplane* next;
	};
public:
	unsigned long getMiles();
	char getType();
	void set(unsigned long m, char t);
public:
	static void* operator new(size_t size);
	static void operator delete(void* deadObject, size_t size);
private:
	static const int BLOCK_SIZE;
	static Airplane* headOfFreeList;
};