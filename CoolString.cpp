#include<stdio.h>
#include<string.h>

int main () {
	char A[1000000], B[1000000];
	int i, j, LeA, LeB, count, check;
	scanf("%s", &A);
	scanf("%s", &B);
	LeB = strlen(B);
	LeA = strlen(A) - LeB + 1;
	count = 0;	
	for (i = 0; i < LeA; i++) {
		check = 1;
		for(j = 0; j < LeB; j++) {
			if (A[j + i] != B[j])
				check = 0;			
		}
		if (check) {
			count++;
		}
	}
	printf("%d", count);
}
