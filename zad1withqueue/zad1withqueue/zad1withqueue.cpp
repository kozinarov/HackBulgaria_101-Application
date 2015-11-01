// zad1withqueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include<iostream>

#include<cstdlib>
#include<string>
#include"Queue.h"
using namespace std;



int main() {

	Queue<char> queue;
	
	int x, y;
	int cnt = 0;
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;
	cout << "Starting point (" << x << ", " << y << ")" << endl;
	string direct;
	cout << "Enter the directions: ";
	getline(cin, direct);
	getline(cin, direct);

	for (int i = 0; i < direct.length(); i++)
	{
		queue.enqueue(direct[i]);
	}
	
	for (int i = 0; i < direct.length(); i++)
	{	
		char bottom = queue.dequeue();
		if (bottom == '~')
		{
			cnt++;
			continue;
		}
		//Checking directions for even times of ~
		if (cnt % 2 == 0)
		{
			
			switch (bottom)
			{
			case '>':
				x++;
				break;
			case '<':
				x--;
				break;
			case '^':
				y--;
				break;
			case 'v':
				y++;
				break;

			default:
				cout << "You have entered wrong symbols" << endl;
				cout << "v ifa" << endl;
				break;
			}
			
		}
		//Checking directions for odd times of ~
		else
		{
			switch (bottom)
			{
			case '>':
				x--;
				break;
			case '<':
				x++;
				break;
			case '^':
				y++;
				break;
			case 'v':
				y--;
				break;

			default:
				cout << "You have entered wrong symbols" << endl;
				cout << "v else" << endl;
				break;
			}

		}
	}

	cout << "(" << x << ", " << y << ")" << endl;

	

	return 0;

}
