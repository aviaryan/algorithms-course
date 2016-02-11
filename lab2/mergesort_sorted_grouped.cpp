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

/*
Group increasing sequences together and then merge them
*/

void mergeGrouped(int * sorted, int * arr, int size, int * groupArr, int groupCount, int grStart, int grEnd){
	if (grStart >= grEnd)
		return;
	int mid = (grStart+grEnd)/2;
	mergeGrouped(sorted, arr, size, groupArr, groupCount, grStart, mid);
	mergeGrouped(sorted, arr, size, groupArr, groupCount, mid+1, grEnd);
	// actual merging
	int endIndex = (grEnd == groupCount-1) ? size-1 : groupArr[grEnd];
	int midIndex = (mid == groupCount-1) ? size-1 : groupArr[mid];
	int i1 = (grStart==0) ? 0 : groupArr[grStart-1]+1, i2 = midIndex + 1, i;
	int startIndex = i1;
	for (i=startIndex; i<=endIndex && i1<=midIndex && i2<=endIndex; i++){
		if (sorted[i1] <= sorted[i2]){
			arr[i] = sorted[i1];
			i1++;
		} else {
			arr[i] = sorted[i2];
			i2++;
		}
	}
	// add remaining
	i1 = (i1 > midIndex) ? i2 : i1;
	while (i <= endIndex){
		arr[i] = sorted[i1];
		i++; i1++;
	}
	// copy back
	for (i=startIndex; i<=endIndex; i++){
		sorted[i] = arr[i];
		//cout << i << " - " << sorted[i] << ","; 
	}
	//cout << endl;
}

void mergeSortGrouped(int * sorted, int * arr, int size){
	int i;
	for (i=0; i<size; i++) sorted[i] = arr[i];
	int groupArr[size], gid = 0;
	bool reset = false;
	for (i=1; i<size; i++){
		if (arr[i] < arr[i-1])
			groupArr[gid++] = i-1;
	}
	mergeGrouped(sorted, arr, size, groupArr, gid, 0, gid-1);
}


int main(){
	int t, i;
	int arr[] = {1, 2, 5, 3, 6, 4, 0, 9, 8, 7};
	int sorted[10];
	mergeSortGrouped(sorted, arr, 10);

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