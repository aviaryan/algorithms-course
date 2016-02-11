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
* Struct Hash Cell
*/
struct HashCell {
	int key;
	int val;
	bool deleted;
	bool isempty;
};
typedef struct HashCell HashCell;

/* 
* Hash Table with Probing
*/
class HashTableProbing {
private:
	int SIZE;
	HashCell * arr;
	int searchId(int key);
public:
	HashTableProbing(int size = 10);
	void insert(int key, int value);
	int remove(int key);
	int search(int key);
	void display();
};

/**
 * Insert key,value in Hash Table
 * @param key   Key of item
 * @param value Value of item
 */
void HashTableProbing::insert(int key, int value){
	int hInd = key % SIZE;
	int initial = hInd;
	while (arr[hInd].isempty == false){
		hInd = (hInd+1)%SIZE;
		if (hInd == initial){
			printf("Table full");
			return;
		}
	}
	arr[hInd].key = key;
	arr[hInd].val = value;
	arr[hInd].isempty = false;
	arr[hInd].deleted = false;
}

int HashTableProbing::searchId(int key){
	int hInd = key % SIZE;
	int initial = hInd;
	do {
		if (arr[hInd].isempty == false && arr[hInd].key == key)
			return hInd;
		else if (arr[hInd].isempty == true && arr[hInd].deleted == false)
			return -1;
		else
			hInd = (hInd+1)%SIZE;
	} while (hInd != initial);
	return -1;
}

int HashTableProbing::search(int key){
	int id = searchId(key);
	if (id == -1){
		printf("No key like that exists\n");
		return -1;
	} else
		return arr[id].val;
}

int HashTableProbing::remove(int key){
	int id = searchId(key);
	if (id == -1){
		printf("No key like that exists\n");
		return -1;
	} else {
		arr[id].isempty = true;
		arr[id].deleted = true;
		return arr[id].val;
	}
}

HashTableProbing::HashTableProbing(int size){
	arr = (HashCell *) malloc(sizeof(HashCell) * size);
	SIZE = size;
	for (int i=0; i<size; i++){
		arr[i].isempty = true;
		arr[i].deleted = false;
	}
}

void HashTableProbing::display(){
	for (int i = 0; i < SIZE; i++)
		if (arr[i].isempty == false)
			printf("Index %d has %d => %d\n", i, arr[i].key, arr[i].val);
}



int main(){
	HashTableProbing ht(7);
	
	int in = 0, data1, data2;
	do {
		printf("1 - Insert\n2- Delete\n3 - Display\n4 - Search\n");
		scanf("%d", &in);
		if (in == 1){
			printf("Insert at (key) : ");
			scanf("%d", &data1);
			printf("Insert  (value) : ");
			scanf("%d", &data2);
			ht.insert(data1, data2);
		} else if (in == 2){
			printf("Key to delete : ");
			scanf("%d", &data1);
			data2 = ht.remove(data1);
			printf("removed value %d at key %d\n", data2, data1);
		} else if (in == 3){
			ht.display();
		} else if (in == 4){
			printf("Key to search : ");
			scanf("%d", &data1);
			data2 = ht.search(data1);
			printf("Found value %d at key %d\n", data2, data1);
		}
	} while (in > 0);


	return 0;
}