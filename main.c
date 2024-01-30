#include <stdio.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 5

int main(int argc, char *argv[])
{
	Employee A[MAX_EMPLOYEES];
	for(int i = 0; i < MAX_EMPLOYEES; i++){
		Employee e;
		printf("\n\nName: ");
        scanf("%s", e.name);
		if(e.name[MAX_NAME_LEN] != '\0'){
			printf("Error: Name exceeds maximum allowed length. Terminating!\n");
			return 0;
		}
		printf("Salary: ");
		if(scanf("%d", &e.salary) != 1){
			e.salary = 0;
			int c;
			while ((c = getchar()) != '\n' && c != EOF) { }
		}
		A[i] = e;
	}

	heapSort(A, MAX_EMPLOYEES);
	printList(A, MAX_EMPLOYEES);
	
	return 0;
}
