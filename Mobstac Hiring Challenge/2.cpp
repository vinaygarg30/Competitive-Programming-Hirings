/* 
Author : Vinay Garg
Description : Mobstac Hiring Challenge
Statement : Milly's Test
Milly is giving a test of algorithms course in her college. Her professor has asked a very interesting question. 
In this question , he has given a string S and each student is required to check if it is possible to change S into his / her name by deleting some of the characters of S. She will try to change S into "milly". Now your task is to print "Milly is Intelligent" ( without "" ) if she will succeed else print "Milly is not Intelligent" ( without "" ).

Input : First line of the input will contain a integer T (number of test cases).
Then for every test case there will be one line containing a string S.
Output : For every test case, print the asked answer. 
*/

#include<bits/stdc++.h>
using namespace std;
bool func(string s)
{
	char arr[5]={'m','i','l','l','y'};
	int arrC=0;

	for(long int i=0;i<s.length() && arrC<=4;i++)
		if(s[i] == arr[arrC])
			arrC++;
	if(arrC == 5)
		return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long int tc;
	cin >> tc;
	while(tc--)
	{
		string s;
		cin >> s;
		if(func(s))
			cout << "Milly is Intelligent\n";
		else
			cout << "Milly is not Intelligent\n";
	}
}
