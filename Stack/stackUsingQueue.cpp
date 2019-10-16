#include<iostream>
#include<queue>
using namespace std;

int currentSize;
queue<int> q1,q2;

void push(int data)
{
	q2.push(data);
	currentSize++;

	while(!q1.empty())
	{
		q2.push(q1.front());
		q1.pop();
	}

	queue<int> q = q1;
	q1 = q2;
	q2 = q;
}

void pop()
{
	if(q1.empty())
		return;
	q1.pop();
	currentSize--;
}


int main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	printf("Total Elements : %d\n", currentSize);
	printf("Top Element : %d\n",q1.front());
	pop();
	printf("Top Element : %d\n",q1.front());
	pop();
	printf("Top Element : %d\n",q1.front());
	pop();
}