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
		printf("Salary: ");
		scanf("%d", &e.salary);
		A[i] = e;
	}

	heapSort(A, MAX_EMPLOYEES);
	printList(A, MAX_EMPLOYEES);
	
	return 0;
}
