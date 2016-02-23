#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


class heap {
	private:
		int arr[100];
		int status;

	public:
		heap();
		void insert(int);
		void print();
		void heapsort();
		void build(int * in, int sz);
		void rebuildHeap();

	private:
		void heapify(int);
};

heap::heap(){
	status = 0;
	fill_n(arr, 100, 0);
	return;
}

/**
 * build heap from input array
 * @param in input array pointer
 * @param sz size of in array
 */
void heap::build(int * in, int sz){
	status = sz;
	for (int i = 1; i <= sz; i++)
		arr[i] = in[i-1];
	rebuildHeap();
}

/**
 * restore the heap sequence
 */
void heap::rebuildHeap(){
	for (int i = status / 2; i > 0; i--)
		heapify(i);
}

void heap::heapify(int p){
	if (!p) return;

	int l = p*2, r = p*2 + 1, mx = p;

	if (l<=status)
		if (arr[l] > arr[p]) mx = l;
	if (r<=status)
		if (arr[r] > arr[mx]) mx = r;

	if (mx != p){
		swap(arr[p], arr[mx]);
		heapify(mx);
	}
}

void heap::insert(int k){
	arr[++status] = k;
	heapify(status/2);
}

void heap::print(){
	for (int i=1; i<=status; i++) printf("%d ", arr[i]);
	printf("\n");
}

/**
 * sort using heapsort. The heap is now destroyed. Use rebuildHeap() to restore the heap sequence.
 */
void heap::heapsort(){
	int szBk = status;
	for (int i = status; i > 1; i--){
		swap(arr[i], arr[1]);
		status--;
		heapify(1);
	}
	status = szBk;
}


int main(){
	int t, i;
	ios_base::sync_with_stdio(0);
	
	heap mh;
	int arr[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
	int n = sizeof(arr)/sizeof(int);
	mh.build(arr, n);
	mh.print();
	mh.heapsort();
	mh.print();
	// correct 16  14  10  8  7  9  3  2  4  1
	return 0;
}