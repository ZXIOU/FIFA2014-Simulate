#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <windows.h>
using namespace std;

void show()
{
	ofstream out("simulationLog.txt");
	cout <<"	     	  	   欢迎使用FIFA2014实时直播"<<endl << endl << endl;
	cout << "   			            /-----. " << endl;
	cout << "   			           /-------. " << endl;
	cout << "   			          |---------| "<< endl;
	cout << "   			          ||||  2014 "<< endl;
	cout << "   			           |||    / "<< endl;
	cout << "   			             ||||/ "<< endl;
	cout << "   			             |||| "<< endl;
	cout << "   			            /||||| " << endl;
	cout << "   			           /||||||| "<< endl;
	cout << "   			          /||||||||| "<< endl << endl;

	out <<"	     	  	   欢迎使用FIFA2014实时直播"<< endl << endl << endl;
	out << "   			            /-----. " << endl;
	out << "   			           /-------. " << endl;
	out << "   			          |---------| "<< endl;
	out << "   			          ||||  2014 "<< endl;
	out << "   			           |||    / "<< endl;
	out << "   			             ||||/ "<< endl;
	out << "   			             |||| "<< endl;
	out << "   			            /||||| " << endl;
	out << "   			           /||||||| "<< endl;
	out << "   			          /||||||||| "<< endl << endl;
}

int main()
{
	ifstream in;
	ofstream out("simulationLog.txt", ios::app);
	system("fifa.exe");
	show();

	cout << "Below are the 32 teams participate in the competition:" << endl;
	out << "Below are the 32 teams participate in the competition:" << endl;
	in.open("team32.txt");
	for(string str;getline(in, str);)
	{
		cout <<str <<endl;
		out <<str <<endl;
	}
	in.close();
	cout << endl;
	out << endl;
	system("pause");

	in.open("schedule16.txt");
	for(string str;getline(in, str);)
	{
		cout << str << endl;
		out << str << endl;
	}
	in.close();
	cout << endl;
	out << endl;

	in.open("Result16.txt");
	for(string str;getline(in, str);)
	{
		cout << str << endl;
		out << str << endl;
	}
	in.close();
	system("pause");

	in.open("team16.txt");
	for(string str;getline(in, str);)
	{
		cout << str << endl;
		out << str << endl;
	}
	in.close();
	cout << endl;
	out << endl;

	in.open("schedule8.txt");
	for(string str;getline(in, str);)
	{
		cout << str << endl;
		out << str << endl;
	}
	in.close();
	cout << endl;
	out << endl;

	in.open("Result8.txt");
	for(string str;getline(in, str);)
	{
		cout << str << endl;
		out << str << endl;
	}
	in.close();
	cout << endl;
	out << endl;
	system("pause");

	in.open("team8.txt");
	for(string str;getline(in, str);)
	{
		cout << str << endl;
		out << str << endl;
	}
	in.close();
	cout << endl;
	out << endl;

	in.open("schedule4.txt");
	for(string str;getline(in, str);)
	{
		cout << str << endl;
		out << str << endl;
	}
	in.close();
	cout << endl;
	out << endl;

	in.open("Result4.txt");
	for(string str;getline(in, str);)
	{
		cout << str<<endl;
		out << str<<endl;
	}
	in.close();
	system("pause");

	in.open("team4.txt");
	for(string str;getline(in, str);)
	{
		cout << str<<endl;
		out << str<<endl;
	}
	in.close();
	cout << endl;
	out << endl;

	in.open("schedule2.txt");
	for(string str;getline(in, str);)
	{
		cout << str<<endl;
		out << str<<endl;
	}
	in.close();
	cout << endl;
	out << endl;

	in.open("Result2.txt");
	for(string str;getline(in, str);)
	{
		cout << str<<endl;
		out << str<<endl;
	}
	in.close();
	cout << endl;
	out << endl;
	system("pause");

	in.open("team(finals).txt");
	for(string str;getline(in, str);)
	{
		cout << str<<endl;
		out << str<<endl;
	}
	in.close();

	in.open("schedule(finals).txt");
	for(string str;getline(in, str);)
	{
		cout << str<<endl;
		out << str<<endl;
	}
	in.close();
	cout << endl;
	out << endl;

	in.open("Result(finals).txt");
	for(string str;getline(in, str);)
	{
		cout << str<<endl;
		out << str<<endl;
	}
	in.close();
	system("pause");

	in.open("topTenTeam.txt");
	for(string str;getline(in, str);)
	{
		cout << str<<endl;
		out << str<<endl;
	}
	in.close();
	cout << endl;
	out << endl;
	system("pause");

	in.open("finalStastics.txt");
	for(string str;getline(in, str);)
	{
		cout << str<<endl;
		out << str<<endl;
	}
	in.close();
	system("pause");

	return 0;
}
