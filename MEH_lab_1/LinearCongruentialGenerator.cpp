#include "LinearCongruentialGenerator.h"

LinearCongruentialGenerator::LinearCongruentialGenerator(unsigned long long* a_constants, unsigned long long* init_numbers, unsigned long long numbers_count, unsigned long long c_param, unsigned long long m_param) : counter{ 0 }, m{m_param}, c{ c_param }, numbers_count{ numbers_count }, a_constants{ new unsigned long long[numbers_count]}, previous_numbers{new unsigned long long[numbers_count]}, counter_upper_bound{ numbers_count * 100000 }
{
	for (unsigned long long i = 0; i < numbers_count; i++)
	{
		this->a_constants[i] = a_constants[i];
		previous_numbers[i] = init_numbers[i];
	}
}
//default initialization parameters follow Numerical Recipies book init values for LCG
LinearCongruentialGenerator::LinearCongruentialGenerator(unsigned long long seed, unsigned long long a, unsigned long long c_param, unsigned long long m_param): counter{0}, m{m_param}, c{c_param}, numbers_count{1}, a_constants{new unsigned long long[1]}, previous_numbers{new unsigned long long[1]}, counter_upper_bound{ numbers_count * 100000 }
{
	a_constants[0] = a;
	previous_numbers[0] = seed;
}
LinearCongruentialGenerator::LinearCongruentialGenerator(unsigned long long seed) : counter{0}, m{ 4294967296ull }, c{ 1013904223ull }, numbers_count{1}, a_constants{new unsigned long long[1]}, previous_numbers{new unsigned long long[1]}, counter_upper_bound{ numbers_count * 100000 }
{
	previous_numbers[0] = seed;
	a_constants[0] = 1664525;
}
LinearCongruentialGenerator::LinearCongruentialGenerator() : counter{ 0 }, m{ 4294967296ull }, c{ 1013904223ull }, numbers_count{ 1 }, a_constants{ new unsigned long long[1] }, previous_numbers{ new unsigned long long[1] }, counter_upper_bound{numbers_count*100000}
{
	previous_numbers[0] = 43;
	a_constants[0] = 1664525;
}

LinearCongruentialGenerator::LinearCongruentialGenerator(const LinearCongruentialGenerator& other) : counter{ other.counter }, m{ other.m }, c{ other.c }, numbers_count{ other.numbers_count }, a_constants{ new unsigned long long[other.numbers_count] }, previous_numbers{ new unsigned long long[other.numbers_count] }, counter_upper_bound{ other.numbers_count * 100000 }
{
	for (int i = 0; i < numbers_count; i++)
	{
		previous_numbers[i] = other.previous_numbers[i];
		a_constants[i] = other.a_constants[i];
	}
}

LinearCongruentialGenerator::~LinearCongruentialGenerator()
{
	delete[] a_constants;
	delete[] previous_numbers;
}

void LinearCongruentialGenerator::set_seed(int pos, unsigned long long val)
{
	a_constants[pos] = val;
}	

unsigned long long LinearCongruentialGenerator::next()
{
	unsigned long long counter_reset_table[] = {0,0};
	unsigned long long x_n_plus_one = 0;
	unsigned long long current_idx = 0;
	for (unsigned long long i = 0; i < numbers_count; i++)
	{
		current_idx = (counter + i) % numbers_count;
		x_n_plus_one += a_constants[current_idx] * previous_numbers[current_idx];
	}
	x_n_plus_one += c;
	x_n_plus_one %= m;
	previous_numbers[(counter%numbers_count)] = x_n_plus_one;
	counter_reset_table[0] = counter + 1;
	counter = counter_reset_table[static_cast<unsigned int>(counter >= counter_upper_bound)];
	return x_n_plus_one;
}
