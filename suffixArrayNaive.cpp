// suffix array naive implementation.....

#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<iterator>
#include<set>
#include<map>
#include<iostream>
#include<sstream>
#include<deque>
#include<cmath>
#include<memory.h>
#include<algorithm>
#include<utility>

using namespace std;

int main()
{
  string s;
  map<string, int> m;
  vector<string> v;

  cin>> s;

  int len = s.size();
  
  for( int i=0; i<len; ++i )
  {
    m[s.substr(i)] = i;
  }

  for( map<string, int>::it = m.begin(); it!=m.end(); it++ )
  {
    v.push_back( it->first );
  }

  return 0;
}