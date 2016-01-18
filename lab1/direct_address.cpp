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


void display_table(int * arr, int size){
	printf("---------------\n");
	for (int i = 0; i <= size; i++){
		if (arr[i] != 0)
			printf("%d => %d\n", i, arr[i]);
	}
	printf("----------------");
}

int main(){
	int hash_table[11] = {0};

	int in = 0, data1, data2;
	do {
		printf("\n1 - Insert\n2- Delete\n3 - Display\n\n");
		scanf("%d", &in);
		if (in == 1){
			printf("Insert at (key) : ");
			scanf("%d", &data1);
			printf("Insert (value) : ");
			scanf("%d", &data2);
			hash_table[data1] = data2;
		} else if (in == 2){
			printf("Key to delete : ");
			scanf("%d", &data1);
			hash_table[data1] = 0;
		} else if (in == 3){
			display_table(hash_table, 10);
		}
	} while (in > 0);
	return 0;
}
