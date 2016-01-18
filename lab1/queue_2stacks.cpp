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
Improved Stack Implementation
*/
class MyStack {
	private:
		vector <int> v;

	public:
		void push(int d);
		int pop();
		void display(int direction);
		bool empty();
};

void MyStack::push(int d){
	v.push_back(d);
}

int MyStack::pop(){
	int d = v.back();
	v.pop_back();
	return d;
}

void MyStack::display(int direction = 1){
	if (direction == 1)
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
			printf("%d ", *it);
	else
		for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
			printf("%d ", *it);
}

bool MyStack::empty(){
	return (v.size() == 0);
}


/*
Queue using 2 stacks
*/
class MyQueue {
	private:
		MyStack s1;
		MyStack s2;

	public:
		void enqueue(int data);
		int dequeue();
		void display();
};

void MyQueue::enqueue(int data){
	s1.push(data);
}

int MyQueue::dequeue(){
	if (s2.empty())
		while (!s1.empty())
			s2.push(s1.pop());
	return s2.pop();
}

void MyQueue::display(){
	printf("\n");
	s2.display(0);
	s1.display(1);
	printf("\n");
}



int main(){
	MyQueue q;
	
	int in = 0, data1;
	do {
		printf("\n1 - enqueue\n2- dequeue\n3 - Display\n\n");
		scanf("%d", &in);
		if (in == 1){
			printf("Insert : ");
			scanf("%d", &data1);
			q.enqueue(data1);
		} else if (in == 2){
			data1 = q.dequeue();
			printf("dequeued %d\n", data1);
		} else if (in == 3){
			q.display();
		}
	} while (in > 0);
	return 0;
}