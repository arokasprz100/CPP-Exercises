#ifndef bitarray_h
#define bitarray_h

struct BitArray
{
	char ** m_bits;
	unsigned m_rows;
	unsigned m_cols;
};


void init(BitArray* toInit, unsigned rows, unsigned columns);

unsigned rows(const BitArray * array);

unsigned cols(const BitArray *array);

void clear(BitArray* toClear);

void set(BitArray* array, unsigned row, unsigned col, bool value);

void print(const BitArray* toPrint, const char* name);

BitArray* negate(BitArray* toNegate);

void xor_arrays(BitArray* result, const BitArray* lhs, const BitArray* rhs);

#endif