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
Improved Queue Implementation
*/
class MyQueue {
	private:
		vector <int> v;

	public:
		void enqueue(int d);
		int dequeue();
		void display();
		bool empty();
		int front();
		int rear();
};

void MyQueue::enqueue(int d){
	v.push_back(d);
}

int MyQueue::dequeue(){
	int d = v.front();
	v.erase( v.begin() );
	return d;
}

void MyQueue::display(){
	// if (direction == 1)
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
			printf("%d ", *it);
		printf("\n");
	// else
	// 	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	// 		printf("%d ", *it);
}

bool MyQueue::empty(){
	return (v.size() == 0);
}

int MyQueue::front(){
	return v.front();
}

int MyQueue::rear(){
	return v.back();
}



int main(){

	MyQueue qmain, q1;
	int num, i, last, last_sorted;
	
	printf("Enter 10 numbers : \n");
	for (i = 0; i < 5; i++){
		scanf("%d", &num);
		qmain.enqueue(num);
	}

	int ct = 1;
	q1.enqueue( qmain.dequeue() );

	while (!qmain.empty()){
		last = qmain.dequeue();
		for (i=0; i<ct; i++){
			if (q1.front() > last && last != 999999){
				q1.enqueue(last);
				last = 999999;
			}
			q1.enqueue(q1.dequeue());
		}
		ct++;
	}
	q1.display();
}