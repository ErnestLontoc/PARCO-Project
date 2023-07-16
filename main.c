// Ernest James B. Lontoc S11
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

extern long long int sdotasm(int n, long long int* vec_A, long long int* vec_B);

long long int sdot(int n, long long int* vec_A, long long int* vec_B) {
	long long int output = 0;
	int i;
	
	for (i = 0; i < n; i++)
	{
		output = output + vec_A[i] * vec_B[i];
	}
	return output;
}

int main() {
	long long int sdotC, sdotASM;
	long long int *vec_A, *vec_B;
	int i,n,j;

	printf("Input length of vector: ");
	scanf_s("%d", &n);
	printf("\n");

	vec_A = (long long int*)malloc(n * sizeof(long long int));
	vec_B = (long long int*)malloc(n * sizeof(long long int));

	for (i = 0; i < n; i++) {
		vec_A[i] = 5;
		vec_B[i] = 5;
	}

	for (j = 1; j <= 30; j++) {
		clock_t start = clock();
		sdotC = sdot(n, vec_A, vec_B);
		printf("%d. Output of C version is: %lld\n", j, sdotC);
		clock_t end = clock();
		double time_taken = ((double)(end - start)) * 1e3 / CLOCKS_PER_SEC;
		printf("C function took %f milliseconds for array size %d \n\n", time_taken, n);
	}
	

	for (j = 1; j <= 30; j++) {
		clock_t start2 = clock();
		sdotASM = sdotasm(n, vec_A, vec_B);
		printf("%d. Output of ASM version is: %lld\n", j, sdotASM);
		clock_t end2 = clock();
		double time_taken2 = ((double)(end2 - start2)) * 1e3 / CLOCKS_PER_SEC;
		printf("ASM function took %f milliseconds for array size %d \n\n", time_taken2, n);
	}
	

	return 0;
}