// Show that $ r! = \frac{1}{2^r} \sum_{j=0}^r binom{r}{j} (2j - 1)!! (2r - 2j - 1)!! $

// See Feynman and Hibbs problem 9-7

#include <stdio.h>
#include <stdint.h>

uint64_t
factorial(int n)
{
	int i;
	uint64_t t = 1;
	for (i = 2; i <= n; i++)
		t *= i;
	return t;
}

uint64_t
choose(int n, int k)
{
	return factorial(n) / factorial(k) / factorial(n - k);
}

uint64_t
dbl_factorial(int n)
{
	int i;
	uint64_t t = 1;
	for (i = 3; i <= n; i += 2)
		t *= i;
	return t;
}

int
main()
{
	int j, r;
	uint64_t t;
	for (r = 0; r <= 16; r++) {
		t = 0;
		for (j = 0; j <= r; j++)
			t += choose(r, j) * dbl_factorial(2 * j - 1) * dbl_factorial(2 * (r - j) - 1);
		t = t / (1 << r);
		printf("%2d %15lld %d\n", r, t, t == factorial(r));
	}
}
