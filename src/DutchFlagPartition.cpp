#include <vector>
#include <iostream>
#include <stdint.h>

using std::vector; 
using std::cout; 
using std::endl; 

void swap(int *a, int *b) {
	int tmp = *a; 
	*a = *b; 
	*b = tmp; 
}

void print_vec(vector<int> A); 

void DutchFlagPartitionBruteForceTwoThrough(int pivot_index, vector<int>* A_ptr) {
	vector<int> &A = *A_ptr; 
	int pivot = A[pivot_index]; 
	for (vector<int>::size_type i = 0; i != A.size(); ++i) {
		for (vector<int>::size_type j = i + 1; j != A.size(); ++j) {
			if (A[j] < pivot) {
				swap(&A[i], &A[j]); 
				break; 
			}
		}
	}
	for (vector<int>::size_type i = A.size() - 1; i != UINT32_MAX && A[i] >= pivot; --i) {
		for (vector<int>::size_type j = i - 1; j != UINT32_MAX && A[j] >= pivot; --j) {
			if (A[j] > pivot) {
				swap(&A[i], &A[j]); 
				break; 
			}
		}
	}
}

void DutchFlagPartitionTwoThrough(int pivot_index, vector<int>* A_ptr) {
	vector<int> &A = *A_ptr;
	int pivot = A[pivot_index];
	int smaller = 0; 
	for (int i = 0; i != A.size(); ++i) {
		if (A[i] < pivot) 
			swap(&A[i], &A[smaller++]); 
	}

	int larger = A.size() - 1; 
	for (int i = A.size() - 1; i >= smaller; --i) {
	//for (int i = A.size() - 1; i >= 0 && A[i] >= pivot; --i) {
		if (A[i] > pivot)
			swap(&A[i], &A[larger--]); 
	}
}

void DutchFlagPartition(int pivot_index, vector<int>* A_ptr) {
	vector<int> &A = *A_ptr; 
	int pivot = A[pivot_index]; 

	int smaller = 0, equal = 0, larger = A.size() - 1; 
	while (equal <= larger) {
		if (A[equal] < pivot)
			swap(&A[equal++], &A[smaller++]);
		else if (A[equal] == pivot)
			++equal;
		else
			swap(&A[equal], &A[larger--]); 
	}
}

void test_dutch_flag_partition() {
	vector<int> A; 
	A.push_back(1); 
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);
	A.push_back(3);
	A.push_back(4);
	A.push_back(5);
	print_vec(A); 
	cout << endl; 
	DutchFlagPartition(2, &A);
	print_vec(A);
}
