/*
  problem: ford fulkerson method for finding maximal flow of the graph
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


int max(int a, int b)
{
  return a>b ? a : b;
}

#define MAXNUM 100


ll n;                               //number of vertices
ll adjMatrix[MAXNUM][MAXNUM];       //graph in adjacency matrix representation
ll residualAdjMat[MAXNUM][MAXNUM];  //residual graph
ll parentNode[MAXNUM];              //parent of each vertex
ll visited[MAXNUM];

void fordFulkerson();
ll augmentPathExists();
void stMinCut();
void depthTraversal(ll);



int main()
{
  printf("enter the numeber of vertices\n");

  getInt(n); //n is the number of vertices

  printf("enter the adjacency matrix\n");

  rep(i, n)
  {
    rep(j, n)
    {
      getInt(adjMatrix[i][j]);  //enter the matrix
    }
  }

  /*
    fordFulkerson()
      initial flow is 0
      while there is an augmenting path from source to sink
        add this path-flow to max-flow
      return flow
  */

  fordFulkerson();

  stMinCut();

  return OfTheKing;
}


void fordFulkerson()
{
  //fill values in adjacency matrix
  rep(i, n)
  {
    rep(j, n)
    {
      residualAdjMat[i][j] = adjMatrix[i][j];
    }
  }

  ll maxFlow = 0;                   //initialize with 0

  while( augmentPathExists() )
  {
    ll cfp = INT_MAX;               //path flow

    for(ll i = n-1; i!=0; i=parentNode[i])
    {
      ll j = parentNode[i];
      cfp = min(cfp, residualAdjMat[j][i]);  //finding the minimum path flow 
    }

    //update residual graph capacities
    for(ll i=n-1; i!=0; i=parentNode[i])
    {
      ll j = parentNode[i];          //get the parent node 

      residualAdjMat[i][j] += cfp;   // i,j is forward edge in the adj mat representation
      residualAdjMat[j][i] -= cfp;   // j,i is the reverse edge in the adj mat represetation
    }

    maxFlow += cfp;
  }

  printf("max flow is %lld\n", maxFlow);;
  cout<<endl;
}


/* this function uses dfs to find if there is a path from source to sink */
ll augmentPathExists()
{
  //ll visited[n];  //visited array to keep track of the visited nodes

  memset(visited, 0, MAXNUM*sizeof(ll));

  stack<long long> s;  //stack for dfs
  s.push(0);           //initialization - mark the 0th vertex as visited
  visited[0] = 1;
  parentNode[0] = -1;

  //depth first search
  while(!s.empty())
  {
    ll ver = s.top();
    s.pop();

    rep(i, n)
    {
      if( visited[i]==0 && residualAdjMat[ver][i]>0 )
      {
        s.push(i);
        parentNode[i]= ver;
        visited[i] = 1;
      }
    }
  }

  return (visited[n-1]==1);
}


void stMinCut()
{
  //traverse all nodes from s upto some unreachable one

  /*
    dfs at each non zero value j>i in 

  */
  memset(visited, 0, MAXNUM*sizeof(ll));

  depthTraversal(0);

  rep(i, n)
  {
    rep(j,n)
    {
      if(visited[i] && !visited[j] && adjMatrix[i][j])
      {
        printf("[ %lld, %lld ]\n", i, j);
      }
    }
  }

}


void depthTraversal(ll s)
{
  visited[s] = 1;

  rep(i, n)
  {
    if(residualAdjMat[s][i] && !visited[i])
    {
      depthTraversal(i);
    }
  }
}
