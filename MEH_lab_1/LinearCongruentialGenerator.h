#pragma once
class LinearCongruentialGenerator
{
private:
	unsigned long long* a_constants, * previous_numbers, c, m, numbers_count, counter, counter_upper_bound;
public: 
	LinearCongruentialGenerator(unsigned long long* a_constants, unsigned long long* init_numbers, unsigned long long numbers_count, unsigned long long c_param, unsigned long long m_param);
	LinearCongruentialGenerator(unsigned long long seed, unsigned long long a, unsigned long long c_param, unsigned long long m_param);
	LinearCongruentialGenerator(unsigned long long seed);
	LinearCongruentialGenerator();
	void set_seed(int pos, unsigned long long val);
	LinearCongruentialGenerator(const LinearCongruentialGenerator& other);
	~LinearCongruentialGenerator();
	inline unsigned long long get_m_param() { return m; }
	inline unsigned long long get_a_multipliers_count() { return numbers_count; }
	unsigned long long next();
};

