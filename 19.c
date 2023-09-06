#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
// Inline assembly to read the TSC
static inline uint64_t rdtsc(void) {
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    uint64_t start, end;
    int pid;

    start = rdtsc();
    pid = getpid();
    end = rdtsc();

    printf("Time taken to execute getpid: %lu cycles\n", end-start);

    return 0;
}

