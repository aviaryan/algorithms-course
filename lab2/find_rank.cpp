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
 * finds the number of elements smaller than 'till' in the sorted segment of array
 * @param  arr   array pointer
 * @param  start start index
 * @param  end   end idx
 * @param  till  Element to find rank of
 * @return       answer
 */
int findTill(int * arr, int start, int end, int till){
	int mid;
	while (start <= end){
		mid = (start+end)/2;
		if (arr[mid] < till){
			start = mid+1;
		} else if (arr[mid] > till) {
			end = mid-1;
		} else {
			return mid-1; // items before that
		}
	}
	return end;
}

int solve(int * arr, int size, int k, int item){
	int rank = (findTill(arr, 0, k-1, item)-0+1) + (findTill(arr, k+1, size-1, item)-(k+1)+1);
	if (item != arr[k]) // not the min element
		rank++;
	return rank + 1; // include the element itself
}

int main(){
	int t, i;
	int arr [] = {2, 6, 8, 10, 1, 3, 7, 9, 11, 12};
	int size = sizeof(arr)/sizeof(int);

	int k = 4;

	for (i=0; i<size; i++){ // find ranks of all elements
		int item = arr[i];
		int rank = solve(arr, size, k, item);
		cout << "Rank of " << item << " is " << rank << endl;
	}

	return 0;
}