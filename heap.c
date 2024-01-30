/*
 * heapsort.c
 *
 *  Created on: 1/29/24
 *      Author: Branson Jones
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	buildHeap(A, n);
	while(n > 0){
		swap(&A[0], &A[n-1]);
		n--;
		heapify(A, 0, n-1);
	}

	// TODO - while n > 0:
	// TODO - swap A[n-1] with A[0], since A[0] is the smallest number.
	// TODO - A[n-1] now sorted in place, so decrement n
	// TODO - Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
	for(int i = (int)n/2; i >=0; i--)
		heapify(A, i, n);
	printList(A, n);
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{
	int leftChild = 2*(i+1)-1;
	int rightChild = 2*(i+1);
	int smaller;
	//set index to 0 if child index is out of bounds
	//0 means false
	if(leftChild >= n)
		leftChild = 0;
	if(rightChild >= n)
		rightChild = 0;
	//determine index of smaller
	if(!leftChild){
		smaller = -1;
	} else if(leftChild && !rightChild){
		smaller = leftChild;
	} else if(rightChild && A[leftChild].salary > A[rightChild].salary){
		smaller = leftChild;
	} else {
		smaller = rightChild;
	}
	//check if swaps are necessary, and execute them if so
	if(smaller != -1 && A[i].salary > A[smaller].salary){
		swap(&A[i], &A[smaller]);
		//recurse
		heapify(&A[smaller], smaller, n);
	}
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
	Employee tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

/**
 * Outputs a string representation of the array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	for(int i = 0; i < n; i++)
		printf("[id=%s sal=%d] ", A[i].name, A[i].salary);
}
