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

class QueueStack {
	private:
		vector <int> v;

	public:
		void push(int d);
		int pop();
		void display();
		bool empty();
};

void QueueStack::push(int d){
	v.push_back(d);
}

bool QueueStack::empty(){
	return (v.size() == 0);
}

int QueueStack::pop(){
	int d;
	if (v.size() > 8){
		d = v.back();
		v.pop_back();
	} else {
		d = v.front();
		v.erase( v.begin() );
	}
	return d;
}

void QueueStack::display(){
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		printf("%d ", *it);
	printf("\n");
}


int main(){
	QueueStack qs;
	qs.push(5);
	qs.push(7);
	qs.push(9);
	qs.display();
	cout << "Deleted " << qs.pop() << endl;
	qs.push(1);
	qs.push(0);
	qs.display();

	return 0;
}