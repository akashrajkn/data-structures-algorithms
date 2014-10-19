/*
0-1 knapsack problem with dynamic programming
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max( int a, int b )
{
  return a>b?a:b;
}


int main()
{
  int n, wt, i, j;

  scanf("%d", &n);//number of items

  int w[n], v[n]; //weight and value of the items

  for( i=0; i<n; i++ )
  {
    scanf("%d %d", &v[i], &w[i]);
  }

  scanf("%d", &wt); //max weight

  int knapsack[n+1][wt+1];//matrix for dp 

  for( i=0; i<=n; i++ )
  {
    for( j=0; j<=wt; j++ )
    {
      if( i==0 || j==0 )
      {
        knapsack[i][j]= 0;
      }
      else if( w[i-1]<=j )
      {
        knapsack[i][j] = max( v[i-1]+knapsack[i-1][j-w[i-1]], knapsack[i-1][j] );
      }
      else
      {
        knapsack[i][j] = knapsack[i-1][j];
      }

    }
  }

  printf( "knapsack soln: %d\n", knapsack[n][wt] );

  return 0;
}



