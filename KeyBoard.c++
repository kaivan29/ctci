#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include <map>
#include <stdlib.h> //to use abs. abs is declared in stdlib.h instead of math.h

using namespace std;

	string values[3] =
	{ "QWERTYUIOP",
      "ASDFGHJKL;",
      "ZXCVBNM,./"};

int dist( const pair<int,int>& a, const pair<int,int>& b)
{
//	cout<<a.first<<a.second;
	int sum = abs(a.first - b.first) + abs(a.second - b.second);
	return sum; 
}

int main()
{	
	map < char, pair <int, int> > qwerty;

    for (int i = 0; i < 3; ++i)
	{
	    for (int j = 0; j < 10; ++j)
	    {
	        //qwerty.insert(pair< char, pair<int,int> > (values[i][j], make_pair(i,j)));
	        qwerty[values[i][j]] = make_pair(i,j);
	    }
	}

//TRAVERSED THROUGH THE WHOLE MAP

/*	map < char, pair <int, int> > :: iterator p;
	p = qwerty.begin();
	while(p!=qwerty.end())
	{
		cout<<p->first<<" ";
		pair<int, int> q = p -> second;
		cout<<q.first<<","<<q.second<<endl;
		++p;
	}*/

	cout<<"Enter the number of test cases: ";
	int tests;
	cin>>tests;

	while(tests>0)
	{
		string s;
		cin>>s;

		int sum = 0;
		for(int i = 0; i < s.size() - 1; ++i)
		{
			sum = sum + dist(qwerty[s[i]], qwerty[s[i+1]]);
			//MAP[KEY_VALUE] = MAPPED_VALUE
			//IN OUR CASE MAP[CHAR] = PAIR<INT , INT>;
		}
		cout<<sum<<endl;
		--tests;
	}	
}


//PREVIOUS TRY
/*class Key
{
private:
	int row;
	int column;
	char alpha;
public:
	int get_row(){return row;}
	int get_column(){return column;}
	char get_alpha(){return alpha;}
	Key()
	{
		row = 0;
		column = 0;
		alpha = ' ';
	}
	Key(int i, int j, char a)
	{
		row = i;
		column = j;
		alpha = a;
	}
};

// -------------
// cache defined
// -------------

#define CACHE

#ifdef CACHE
Key k[3][10];//lazy cache
#endif

int main()
{
	char letter[3][10] = {{'Q','W','E','R','T','Y','U','I','O','P'},{'A','S','D','F','G','H','J','K','L',';'},{'Z','X','C','V','B','N','M',',','.','/'}};
	
	#ifdef CACHE
	       for (int i = 0; i < 3; ++i)
	       {
	       	for (int j = 0; j < 10; ++j)
	       	{
	       		Key key(i,j,letter[i][j]);
	       		k[i][j] = key;
	       	}
	       }
	#endif

	cout<<"Enter the number of test cases: ";
	int tests;
	cin>>tests;

	while(tests>0)
	{
		string input;
		cin>>input;

		for(int i = 0; i<input.size(); ++i)
		{
			
		}
		--tests;
	}

}*/