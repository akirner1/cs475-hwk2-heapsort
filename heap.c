/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author:
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Determines the index of the left child.
 *
 * @param	i	index of the parent node
 * @param	n	size of the array
 * @returns	the index of the left child
 * @returns -1 if the index is out of the array's bounds
 */
int getLeftChildIndex(int i, int n){
	int childIndex = 2 * (i + 1) - 1;
	if(childIndex >= n){
		return -1;
	}else{
		return childIndex;
	}
}


/**
 * Determines the index of the right child.
 *
 * @param	i	index of the parent node
 * @param	n	size of the array
 * @returns	the index of the right child
 * @returns -1 if the index is out of the array's bounds
 */
int getRightChildIndex(int i, int n){
	int childIndex = 2 * (i + 1);
	if(childIndex >= n){
		return -1;
	}else{
		return childIndex;
	}
}

/**
 * Given 2 indexes, returns the index that contains the smaller value
 * @param *employees a pointer to the array of employees
 * @param i1 the index of An Employee
 * @param i2 the index Another Employee to compare to
 * @returns the index of the employee with a lower salary
 */
int getSmallerIndex(Employee *employees, int i1, int i2){
	int salary1 = employees[i1].salary;
	int salary2 = employees[i2].salary;
	if(salary1 < salary2){
		return i1;
	}else{
		return i2;
	}
}


/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	// TODO - BuildHeap on the heap
	buildHeap(A, n);

	// TODO - while n > 0:
	// TODO - swap A[n-1] with A[0], since A[0] is the smallest number.
	// TODO - A[n-1] now sorted in place, so decrement n
	// TODO - Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
	while(n > 0){
		swap(&A[n-1], &A[0]);
		n--;
		for(int i = 0; i < n; i++){
			heapify(A, i, n);
		}
	}
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
	// TODO - heapify() every element from A[n/2] down-to A[0]
	for(int i = n/2; i >= 0; i--){
		heapify(A, i, n);
	}
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
	if(i >= n){
		//i is not in range, no more swaps needed
		return;
	}
	// TODO - get index of left child of element i
	// TODO - get index of right child of element i
	int leftChildIndex = getLeftChildIndex(i, n);
	int rightChildIndex = getRightChildIndex(i, n);

	// TODO - determine which child has a smaller salary. We'll call the index of this
	//		element: "smaller"
	int smaller;
	if(leftChildIndex == rightChildIndex && leftChildIndex == -1){
		//child node, no swaps needed;
		return;
	}
	if(leftChildIndex == -1){
		smaller = rightChildIndex;
	}else if(rightChildIndex == -1){
		smaller = leftChildIndex;
	}else{
		smaller = getSmallerIndex(A, leftChildIndex, rightChildIndex);
	}

	// TODO - recursively check if the salary at A[i] > the salary at A[smaller]. If it is, swap the two.
	//			Then recursively heapify A[smaller].
	if(A[i].salary > A[smaller].salary){
		swap(&A[i], &A[smaller]);
		heapify(A, smaller, n);
	}
	// TODO - Continue recursion as long as i is within range AND either right_child and left_child are still within range.
}


/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
	Employee temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	for(int i = 0; i < n; i++){
		printf("[id=%s sal=%d] ", A[i].name, A[i].salary);
	}
	printf("\n");
}
