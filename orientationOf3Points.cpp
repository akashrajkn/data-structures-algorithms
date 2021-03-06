/*
	C++ program to find orientation of 3 points in 2d plane
*/

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
#include<climits>
#include<list>
#include<bitset>
#include<fstream>

using namespace std;

#define OfTheKing 0
#define rep(i,n) for(long long i=0; i<n; ++i)
#define gRep(i,p,n) for(long long i=p; i<n; ++i)
#define MP make_pair
#define all(c) c.begin(),c.end()
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define PB push_back
#define PF push_front
//#define g_u getchar_unlocked() //if windows use getchar()
//#define p_u(x) putchar_unlocked(x) //if windows use putchar()
#define p_u(x) putchar(x) 
#define g_u getchar()

typedef pair<long long, long long> pii;
typedef long long ll;


//fast input function
inline void getInt(ll &n)
{
  n = 0;
  ll ch = g_u;
  ll sign = 1;
  while (ch < '0' || ch > '9')
  {
    if (ch == '-')
    {
      sign = -1;
    }
    ch = g_u;
  }
  while (ch >= '0' && ch <= '9')
  {
    n = (n << 3) + (n << 1) + ch - '0';
    ch = g_u;
  }
  n *= sign;
}

struct point
{
  ll x, y;
};


int main()
{
  ll tempx, tempy;
  point p[3];

  //input 3 points from the user
  rep(i,3)
  {
    getInt(tempx);
    getInt(tempy);

    p[i].x = tempx;
    p[i].y = tempy;
  }


  // slope of the line p1p2 - slope of the line p2p3
  ll val = (p[1].y - p[0].y)*(p[2].x - p[1].x) - (p[1].x - p[0].x)*(p[2].y - p[1].y);

  if(val == 0)
  {
    printf("collinear\n");
  }
  else if(val > 0)    
  {
    printf("clockwise\n");
  }
  else
  {
    printf("counter-clockwise\n");
  }


  return OfTheKing;
}
