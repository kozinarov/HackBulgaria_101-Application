// task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include "DynamicArray.h"
#include <string>

using namespace std;

char table[100][100];
int cntWords = 0;

int testHorizontal(int jPosition, int hor)
{
	if (jPosition<0 || jPosition >= hor)
	{
		return 0;
	}
}

int testVertical(int iPosition, int ver)
{
	if (iPosition<0 || iPosition >= ver)
	{
		return 0;
	}
}

int testAcross(int jPosition, int iPosition, int hor, int ver)
{
	if (iPosition < 0|| iPosition >= ver)
	{
		return 0;
	}
}

bool timesCheck(int cnt, int len)
{
	
	if (cnt == len)
	{
		return 1;
	}
	else
		return 0;
}


int checkrows(int lines, int columns)
{
		
	DynamicArray<char> Word;
	
	string string;
	int cnt = 0;
	cout << "Enter word you want to find: ";
	getline(cin, string);
	getline(cin, string);
	for (int i = 0; i < string.length(); i++)
	{

		Word.insertAtBeggining(string[i]);
		
	}
	
	int numFind = 0;
	int len = Word.size();
	
	for (int i = 0; i<lines; i++)
	{
		for (int j = 0; j<columns; j++)
		{
			if (Word.get(0) == table[i][j])
			{
				cnt = 0;
				//Horizontal left to right
				for (int k = 0; k < len; k++)
				{
					testHorizontal(j, columns);

					if (table[i][j + k] == Word.get(k))
					{
						cnt++;
					}
					
					numFind += timesCheck(cnt, len);
				}

				cnt = 0;
				//Horizontal right to left
				for (int k = 0; k < len; k++)
				{
					testHorizontal(j, columns);

					if (table[i][j - k] == Word.get(k))
					{
						cnt++;
					}

					numFind += timesCheck(cnt, len);
				}

				cnt = 0;
				//Vertical up to bottom
				for (int k = 0; k < len; k++)
				{
					testVertical(i, lines);

					if (table[i + k][j] == Word.get(k))
					{
						cnt++;
					}

					numFind += timesCheck(cnt, len);
				}
				cnt = 0;
				//Vertical bottom to up
				for (int k = 0; k < len; k++)
				{
					testVertical(i, lines);

					if (table[i - k][j] == Word.get(k))
					{
						cnt++;
					}

					numFind += timesCheck(cnt, len);
				}

				cnt = 0;
				//Across down and right
				for (int k = 0; k < len; k++)
				{
					testAcross(j, i, columns, lines);

					if (table[i + k][j + k] == Word.get(k))
					{
						cnt++;
					}

					numFind += timesCheck(cnt, len);
				}
				cnt = 0;
				//Across up and right
				for (int k = 0; k<len; k++)
				{
					testAcross(j, i, columns, lines);

					if (table[i - k][j + k] == Word.get(k))
					{
						cnt++;
					}

					numFind += timesCheck(cnt, len);
				}
				cnt = 0;
				//Across up and left
				for (int k = 0; k < len; k++)
				{
					testAcross(j, i, columns, lines);

					if (table[i - k][j - k] == Word.get(k))
					{
						cnt++;
					}

					numFind += timesCheck(cnt, len);
				}
				cnt = 0;
				//Across down and left
				for (int k = 0; k<len; k++)
				{
					testAcross(j, i, columns, lines);

					if (table[i + k][j - k] == Word.get(k))
					{
						cnt++;
					}

					numFind += timesCheck(cnt, len);
				}
			}
		}
	}
	return numFind;
}




int main()
{
	int lines, columns;
	char letter;

	cout << "Enter Lines: ";
	cin >> lines;
	cout << "Enter Columns: ";
	cin >> columns;

	cout << "Enter table: " << endl;
	for (int i = 0; i<lines; i++)
	{
		for (int j = 0; j<columns; j++)
		{
			cin >> letter;
			table[i][j] = letter;
		}
	}
	
	cout << "Word is found " << checkrows(lines, columns) <<" times." << endl;
	return 0;
}
