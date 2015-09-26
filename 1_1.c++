#include <iostream> // endl, istream, ostream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

using namespace std;

/*string reverse(string s)
{
	string rev = "";
	int j = 0;
	for (int i = s.length()-1; i >= 0; --i)
	{
		rev += s[i];
	}
	return rev;
}

int main()
{
	string s;
	cin >> s;

	string rev = reverse(s);
	cout<<rev<<endl;
}*/

int check(string s)
{
	string rev = "";
	int j = 0;
	rev[j] = s[j];
	for (int i = 1; i < s.length(); ++i)
	{
		for(int j = 0; j < rev.length(); j++)
		{
			if(rev[j] == s[i])
				return -1;
		}
		rev += s[i];
	}
		return 1;
}
//Runtime: O(n^2)

bool check_opt(string s)
{
	int hashtable[256];
	//bool charSet[256]; 
	for(int i = 0; i< s.length(); ++i)
	{
		int counter = s[i];
		//if(charSet[counter] == true)
		if(hashtable[counter] == 1)
			return false;
		else
			hashtable[counter] = 1;
			//charSet[counter] = true;
	}
	return true;
}
//Runtime: O(n)

int main()
{
	string s;
	cin >> s;

	int c = check(s);
	bool b = check_opt(s);
	cout<<"b:"<<b<<endl;
	if(c == 1)
		cout<<"Truly unique\n";
	else
		cout<<"oops\n";
}