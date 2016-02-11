#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

/**
 * Performs Merge Operation
 * @param sorted sorted array pointer
 * @param arr    original array pointer
 * @param start  array index to start from
 * @param end    array index to end at
 */
void mergeOp(int * sorted, int * arr, int start, int end){
	if (start >= end)
		return;
	int mid = (start+end)/2;
	mergeOp(sorted, arr, start, mid);
	mergeOp(sorted, arr, mid+1, end);
	// actual merging
	int i1 = start, i2 = mid+1, i;
	for (i=start; i<=end && i1<=mid && i2<=end; i++){
		if (sorted[i1] <= sorted[i2]){
			arr[i] = sorted[i1];
			i1++;
		} else {
			arr[i] = sorted[i2];
			i2++;
		}
	}
	// add remaining
	i1 = (i1 > mid) ? i2 : i1;
	while (i <= end){
		arr[i] = sorted[i1];
		i++; i1++;
	}
	// copy back
	for (i=start; i<=end; i++){
		sorted[i] = arr[i];
	}
}

/**
 * Performs Merge Sort over array
 * @param sorted pointer of sorted array
 * @param arr    pointer of real array
 * @param size   size of array
 */
void mergeSort(int * sorted, int * arr, int size){
	for (int i=0; i<size; i++) sorted[i] = arr[i];
	mergeOp(sorted, arr, 0, size-1);
}


int main(){
	int t, i;
	int arr[] = {1, 5, 3, 2, 6, 4, 0, 9, 8, 7};
	int sorted[10];
	mergeSort(sorted, arr, 10);

	for (i=0; i<10; i++)
		cout << sorted[i] << ",";

	return 0;
}
/*
1 5 3
1 5
3
1 3 
*/