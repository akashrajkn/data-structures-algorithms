/*
0-1 knapsack problem with recursion
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max( int a, int b )
{
  return a>b?a:b;
}


int knapsack( int w[], int v[], int wt, int n )
{
  if( wt==0 || n==0 )// base case
  {
    return 0;
  }

  if( w[n-1]> wt )
  {
    return knapsack( w, v, wt, n-1 );
  }
  else
  {
    return max( v[n-1]+knapsack(w, v, wt-w[n-1], n-1 ), knapsack( w, v, wt, n-1 ) );
  }
}


int main()
{
  int n, wt, i;

  scanf("%d", &n);//number of items

  int w[n], v[n]; //weight and value of the items

  for( i=0; i<n; i++ )
  {
    scanf("%d %d", &v[i], &w[i]);
  }

  scanf("%d", &wt); //max weight

  printf( "knapsack soln: %d\n", knapsack( w, v, wt, n ) );

  return 0;
}



