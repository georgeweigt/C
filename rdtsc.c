// read intel cycle counter

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

uint64_t
rdtsc(void)
{
	union {
		uint64_t tsc;
		struct {
			uint32_t lo;
			uint32_t hi;
		};
	} u;

	asm volatile("rdtsc" : "=a" (u.lo), "=d" (u.hi));

	return u.tsc;
}

int
main()
{
	uint64_t a, b;

	a = rdtsc();
	sleep(1);
	b = rdtsc();

	printf("%g cycles\n", (float) b - a);
}
