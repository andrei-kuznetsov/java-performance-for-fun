#include <time.h>
#include <stdio.h>
#include <stdlib.h>

//const long SZ = 630000000L;
const long SZ = 100000000L;
//const long SZ = 3000000L;
static long res;

long calcArithmeticProgression(long sz) {
	long now = 1;
	long sum = 1;
	while (now < sz) {
		sum += now;
		now++;
	}
	return sum;
}

int main(){
	while(true) {
		timespec started, ended;
		clock_gettime(CLOCK_REALTIME, &started); 
		
		//printf("started: %d,%d\n", started.tv_sec, started.tv_nsec);
		res = calcArithmeticProgression(SZ);
		clock_gettime(CLOCK_REALTIME, &ended);
		
		//printf("ended: %d,%d\n", ended.tv_sec, ended.tv_nsec);
		int diff = (ended.tv_sec - started.tv_sec)*1000 + (ended.tv_nsec - started.tv_nsec)/1000000;
		printf("diff: %d\n", diff);
	}

	return 0;
}
