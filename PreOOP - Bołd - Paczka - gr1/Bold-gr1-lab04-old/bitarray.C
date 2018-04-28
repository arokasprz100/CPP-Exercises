#include "bitarray.h"
#include <iostream>

void init(BitArray* toInit, unsigned rows, unsigned columns)
{
	toInit->m_rows = rows;
	toInit->m_cols = columns;
	toInit->m_bits = new char* [rows];
	for (unsigned i = 0; i<rows; ++i)
	{
		toInit->m_bits[i] = new char[columns/sizeof(char) + 1];
		for (unsigned j = 0; j<columns/sizeof(char); ++j)
			toInit->m_bits[i][j] = 0;
	}
}

unsigned rows(const BitArray * array)
{
	return array->m_rows;
}

unsigned cols(const BitArray *array)
{
	return array->m_cols;
}

void clear(BitArray* toClear)
{
	if (toClear->m_bits==nullptr)
		return;

	for (unsigned i=0; i<toClear->m_rows; ++i)
		delete [] toClear->m_bits[i];
	delete [] toClear->m_bits;
	toClear->m_bits = nullptr;
}

void set(BitArray* array, unsigned row, unsigned col, bool value)
{
	unsigned charCol = col/sizeof(char);
	unsigned charInCol = col%sizeof(char);
	//number ^= (-x ^ number) & (1UL << n);

	array->m_bits[row][charCol] ^= (-value ^ array->m_bits[row][charCol]) & (1UL << charInCol);
}

void print(const BitArray* toPrint, const char* name)
{
	std::cout<<name<<std::endl;
	for (unsigned i = 0; i<toPrint->m_rows; ++i)
	{
		for (unsigned j = 0; j<toPrint->m_cols; ++j)
		{
			for (unsigned k =0; k<sizeof(char); ++k )
			{
				bool bit = (toPrint->m_bits[i][j] >> k) & 1U;
				std::cout<<bit;
			}
		}
		std::cout<<std::endl;
	}
}

BitArray* negate(BitArray* toNegate)
{
	for (unsigned i = 0; i<toNegate->m_rows; ++i)
	{
		for (unsigned j = 0; j<toNegate->m_cols; ++j)
		{
			toNegate->m_bits[i][j] = ~toNegate->m_bits[i][j];
		}
	}

	return toNegate;
}

void xor_arrays(BitArray* result, const BitArray* lhs, const BitArray* rhs)
{
	for (unsigned i =0; i<result->m_rows; ++i)
	{
		for (unsigned j = 0; j<result->m_cols; ++j)
			result->m_bits[i][j] = lhs->m_bits[i][j] ^ rhs->m_bits[i][j];
	}
}