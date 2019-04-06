#include <time.h>
#include <stdio.h>
#include <stdlib.h>

//const long SZ = 630000000L;
//const long SZ = 100000000L;
const long SZ = 100000000L;
static long res;

int main(){
	printf("hello\n");
	while(true) {
		//timespec started, ended;
		//clock_gettime(CLOCK_REALTIME, &started); 
		
		//asm volatile("cpuid");
		unsigned a,d, c;
		c = (1<<30);
		//asm volatile("rdtsc" : "=a" (a), "=d" (d));
		asm volatile("rdpmc" : "=a" (a), "=d" (d) : "c" (c));
		//asm volatile("cpuid");
		unsigned long startedC = a; 
		//unsigned long long startedC = ((unsigned long long)a) | (((unsigned long long)d)<<32);
		//printf("started: %d,%d\n", started.tv_sec, started.tv_nsec);
		//printf("startedC: %lld\n", startedC);
		
		//unsigned long long test = getCC();
		
		//long now = 1;
		//long sum = 1;
		//while (now < SZ) {
		//	sum += now;
		//	now++;
		//}
		
		//asm volatile("cpuid");
		//asm volatile("rdtsc" : "=a" (a), "=d" (d));
		//asm volatile("rdpmc" : "=a" (a), "=d" (d) : "c" (c));
		//asm volatile("cpuid");
		unsigned long endedC = a;
		//unsigned long long endedC = ((unsigned long long)a) | (((unsigned long long)d)<<32);
		
		//clock_gettime(CLOCK_REALTIME, &ended);
		
		//printf("ended: %d,%d\n", ended.tv_sec, ended.tv_nsec);
		//printf("endedC: %lld\n", endedC);
		//int diff = (ended.tv_sec - started.tv_sec)*1000 + (ended.tv_nsec - started.tv_nsec)/1000000;
		//printf("diff: %d \t\t diffC: %lld\n", diff, (endedC - startedC));
		printf("diffC: %d\n", (endedC - startedC));
	}

	return 0;
}
