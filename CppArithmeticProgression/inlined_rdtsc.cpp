#include <time.h>
#include <stdio.h>
#include <stdlib.h>

//const long SZ = 630000000L;
//const long SZ = 100000000L;
const long SZ = 100000000L;
static long res;

int main(){
	while(true) {
		unsigned a, d;
		// use rdtscp instead of rdtsc in order to set out-of-order execution barrier.
		asm volatile("rdtscp" : "=a" (a), "=d" (d));
		
		unsigned long long startedC = ((unsigned long long)a) | (((unsigned long long)d)<<32);
		//printf("startedC: %lld\n", startedC);
		
		long now = 1;
		long sum = 1;
		while (now < SZ) {
			sum += now;
			now++;
		}
		
		asm volatile("rdtscp" : "=a" (a), "=d" (d));
		unsigned long long endedC = ((unsigned long long)a) | (((unsigned long long)d)<<32);
		
		//printf("endedC: %lld\n", endedC);
		printf("diffC: %d\n", (endedC - startedC));
	}

	return 0;
}
