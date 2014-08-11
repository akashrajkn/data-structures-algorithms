//trie Data Structure

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct trieNode
{
  int value;
  struct trieNode *children[26];
};

typedef struct trieNode list;
int count;

void search( list *p, char a[] );
void insert( list **node, char key[] );

int main()
{
  char key[][8] =   { "one", "two", "three", "four", "five", "six" };
  list *root, *q;
  int i, size;

  size = sizeof(key) / sizeof(key[0]);

  //initialize
  root = malloc(sizeof(list));
  q = root;

  for( i=0; i<size; i++ )
  {
    insert( &q, key[i] );
  }

  search(root, "three");

  return 0;
}

void insert( list **node, char key[] )
{
  int len, i, index, j;
  list *temp;

  temp = *node;
  len = strlen(key);

  count++;

  for( i=0; i<len; i++ )
  {
    index = key[i] - 'a';
    if( !(temp-> children[index]) )
    {
      temp->children[index] = malloc(sizeof(list));
      for(j=0; j<26; j++)
      {
        temp->children[index]->children[j] = NULL;
      }
    }
    temp = temp->children[index];
  }

  temp->value = count;
}

void search(list *p, char a[])
{
  int len, i, index;

  len = strlen(a);

  for( i=0; i<len; i++ )
  {
    index = a[i] - 'a';
    if( p->children[index] != NULL )
    {
      printf( "%c %c\n", a[0], (index+'a') );
      p = p->children[index];
    }
    else
    {
      printf("not found\n");
      break;
    }
  }
}




