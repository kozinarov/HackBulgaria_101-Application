// task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DynamicArray.h"
#include <fstream>
#include <iostream>

using namespace std;

void Read()
{
	DynamicArray<char> Pacakges;
	DynamicArray<char> tempPacakges;
	DynamicArray<char> tempLetters;
	char letter;
	//reading dependencies file
	ifstream in_dependenciesfile("dependencies.json", ios::app);
	if (in_dependenciesfile.is_open())
	{
		while (!in_dependenciesfile.eof())
		{
			in_dependenciesfile >> letter;
			if (letter == '[')
			{
				in_dependenciesfile >> letter;
				if (letter != ']')
				{
					tempPacakges.add(letter);
				}
				else
					break;
			}
		}
	}
	in_dependenciesfile.close();

	//reading all_packages file
	ifstream in_all_packagesnfile("all_packages.json", ios::app);
	if (in_all_packagesnfile.is_open())
	{
		while (!in_all_packagesnfile.eof())
		{	
			int cntlet1 = 0;
			int cntlet2 = 0;
			int cnt;
			in_all_packagesnfile >> letter;
			for (int i = 0; i < tempPacakges.size(); i++)
			{
				if (letter == tempPacakges.get(i))
				{
					cntlet1++;
					tempLetters.add(letter);
					in_all_packagesnfile >> letter;
				}
				else if (tempPacakges.get(i) == ',')
				{
					int cnti = 0;
					for (int j = i; j < tempPacakges.size(); j++)
					{
						int templet = tempLetters.get(cnti);
						if (templet == tempPacakges.get(j))
						{
							cnti++;
							cntlet2++;
						}
					}
					break;
				}
				else
					break;
			}

			//putting in if we find a match after , 
			if (cntlet1 == tempPacakges.size())
			{
				
				for (int i = 0; i < tempPacakges.size(); i++)
				{
					Pacakges.add(tempPacakges.get(i));
				}
				Pacakges.add(',');
				tempPacakges.Free();
			}

			cntlet1 = 0;
			//putting in if we find a match after , 
			if (cntlet2 == tempPacakges.size())
			{
				for (int i = 0; i < tempLetters.size(); i++)
				{
					Pacakges.add(tempLetters.get(i));
				}
				Pacakges.add(',');
				tempLetters.Free();
			}
			cntlet2 = 0;
			//reading in the beginning of every line until :
			if (letter == '/n')
			{	
				tempPacakges.Free();
				tempLetters.Free();

				in_all_packagesnfile >> letter;
				while (letter != ':')
				{
					tempPacakges.add(letter);
					in_all_packagesnfile >> letter;
				}

			}
			//reading from open brackets to closed brackets
			else if (letter == '[')
				{
					tempPacakges.Free();
					tempLetters.Free();

					in_all_packagesnfile >> letter;
					while (letter != ']')
					{
						tempPacakges.add(letter);
						in_all_packagesnfile >> letter;
					}
				}


		}
	}
	in_all_packagesnfile.close();

	//filling the file with the modules we have installed 
	ofstream installed_modules;
	installed_modules.open("installed_modules.json", ios::app);
	if (installed_modules.is_open())
	{
		for (int i = 0; i < Pacakges.size(); i++)
		{
			installed_modules << Pacakges.get(i);
		}
		
	}
	installed_modules.close();
}



int main()
{
	Read();


    return 0;
}

