#include <stdio.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 5

int main(int argc, char *argv[])
{
	Employee A[MAX_EMPLOYEES];
	for(int i = 0; i < MAX_EMPLOYEES; i++){
		char str[MAX_NAME_LEN];
		int money = 0;
		Employee e;
		printf("\n\nName: ");
        scanf("%s", str);
		printf("Salary: ");
		scanf("%d", &money);
		
		e.name[MAX_NAME_LEN] = *str;
		e.salary = money;
		A[i] = e;
	}

	heapSort(A, MAX_EMPLOYEES);
	printList(A, MAX_EMPLOYEES);
	
	return 0;
}
