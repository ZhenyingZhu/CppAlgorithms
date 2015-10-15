#include <vector>
#include <iostream>

using std::vector; 
using std::cout; 
using std::endl; 

void swap(int *a, int *b) {
	int tmp = *a; 
	*a = *b; 
	*b = tmp; 
}

void print_vec(vector<int> A); 

void DutchFlagPartitionTwoThrough(int pivot_index, vector<int>* A_ptr) {
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

	for (vector<int>::size_type i = A.size() - 1; i >= 0 && A[i] >= pivot; --i) {
		for (vector<int>::size_type j = i - 1; j >= 0 && A[j] >= pivot; --j) {
			if (A[j] > pivot) {
				swap(&A[i], &A[j]); 
				break; 
			}
		}
	}
}

void test_dutch_flag_partition() {
	vector<int> A; 
	A.push_back(1); 
	A.push_back(3);
	A.push_back(2);
	A.push_back(5);
	A.push_back(4);
	A.push_back(3);
	A.push_back(4);
	print_vec(A); 
	cout << endl; 
	DutchFlagPartitionTwoThrough(1, &A); 
	print_vec(A);
}