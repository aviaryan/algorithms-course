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
Hash Table class
*/
class HashTable {
private:
	const static int SIZE = 5;
	map <int,int> ht[SIZE];

public:
	void insert(int key, int value);
	void remove(int key);
	void display();
};

void HashTable::insert(int key, int value){
	int hashIndex = key % SIZE;
	ht[hashIndex].insert( make_pair(key, value) );
}

void HashTable::remove(int key){
	int hashIndex = key % SIZE;
	ht[hashIndex].erase(key);
}

void HashTable::display(){
	for (int i = 0; i<SIZE; i++){
		if (ht[i].size() == 0) continue;
		printf("Data at index %d of Hash Table\n", i);
		for (map<int,int>::iterator miit = ht[i].begin(); miit != ht[i].end(); miit++){
			printf("%d ==> %d\n", miit->first, miit->second);
		}
	}
	printf("\n");
}


int main(){
	int t, i;
	HashTable ht;

	int in = 0, data1, data2;
	do {
		printf("1 - Insert\n2- Delete\n3 - Display\n");
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
			ht.remove(data1);
		} else if (in == 3){
			ht.display();
		}
	} while (in > 0);

	return 0;
}