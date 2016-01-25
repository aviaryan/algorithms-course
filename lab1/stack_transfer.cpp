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
		string name;
		void push(int d);
		int pop();
		void display(int direction);
		bool empty();
		int top();
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

int MyStack::top(){
	return (v.size() == 0) ? 1e9 : v.back();
}


void move(MyStack * s1, MyStack * s2){
	int x;
	if (s1->top() < s2->top()){
		s2->push(x = s1->pop());
		cout << "Moved " << x << " from " << s1->name << " to " << s2->name << endl;
	} else {
		s1->push(x = s2->pop());
		cout << "Moved " << x << " from " << s2->name << " to " << s1->name << endl;
	}
}


int main(){
	MyStack smain, s1, s2;
	smain.name = "Source";
	s1.name = "Destination";
	s2.name = "Extra";

	int num, size = 5;
	if (size % 2 == 0)
		swap(s1.name, s2.name);

	cout << "Enter " << size << " numbers (in decreasing order, as in hanoi tower) : " << endl;
	for (int i = 0; i < size; i++){
		cin >> num;
		smain.push(num);
	}

	int p = pow(2,size) - 1;
	for (int i=1; i<=p; i++){
		if (i%3 == 1){
			move(&s1, &smain);
		} else if (i%3 == 2){
			move(&s2, &smain);
		} else {
			move(&s1, &s2);
		}
	}

	if (size%2 == 1)
		s1.display();
	else
		s2.display();

	return 0;
}