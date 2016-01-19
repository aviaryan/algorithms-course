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
	printf("\n");
}

bool MyStack::empty(){
	return (v.size() == 0);
}

int MyStack::top(){
	return v.back();
}



int main(){
	MyStack smain, s1, s2;
	int num, last;
	printf("Enter 5 numbers : \n");
	for (int i = 0; i < 5; i++){
		scanf("%d", &num);
		smain.push(num);
	}

	s1.push(smain.pop());
	int flag;
	while (!smain.empty()){
		flag = 0;
		last = smain.pop();
		while (!s1.empty()){
			if (s1.top() < last){
				s1.push(last);
				flag = 1;
				break;
			} else {
				s2.push(s1.pop());
			}
		}
		if (flag == 0)
			s1.push(last);
		while (!s2.empty())
			s1.push(s2.pop());
	}
	s1.display();

	return 0;
}