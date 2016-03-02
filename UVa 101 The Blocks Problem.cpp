/*******************************************************/
/* UVa 101 The Blocks Problem                          */
/* Language:C                                          */
/*******************************************************/
#include<stdio.h>
#include<string.h>

int main(){
  int position[30][2];
  int block[30][30];
  int top[30];
  int n;
  char action1[10], action2[10];
  int a, b, ax, ay, bx, by;

  while( scanf( "%d", &n ) != EOF ){
    int i;
    for( i = 0 ; i < n ; i++ ){
      position[i][0] = i;
      position[i][1] = 0;
      block[i][0] = i;
      top[i] = 1;
    }
    while( scanf( "%s", action1 ) != EOF && strcmp( action1, "quit" ) ){
      scanf( "%d%s%d", &a, action2, &b );

      ax = position[a][0];
      ay = position[a][1];
      bx = position[b][0];
      by = position[b][1];

      if( ax == bx ) continue;

      if( !strcmp(action1, "move") ){
        int j;  
        for( j = ay+1 ; j < top[ax] ; j++ ){
          position[block[ax][j]][0] = block[ax][j];
          position[block[ax][j]][1] = top[block[ax][j]];
          block[block[ax][j]][top[block[ax][j]]++] = block[ax][j];
        }
        top[ax] = ay+1;
      }
      if( !strcmp(action2, "onto") ){
        int p;  
        for( p = by+1 ; p < top[bx] ; p++ ){
          position[block[bx][p]][0] = block[bx][p];
          position[block[bx][p]][1] = top[block[bx][p]];
          block[block[bx][p]][top[block[bx][p]]++] = block[bx][p];
        }
        top[bx] = by+1;
      }
      
      int k;
      for( k = ay ; k < top[ax] ; k++ ){
        position[block[ax][k]][0] = bx;
        position[block[ax][k]][1] = top[bx];
        block[bx][top[bx]++] = block[ax][k];
      }
      top[ax] = ay;
    }
    
    int q,w;
    for( q = 0 ; q < n ; q++ ){
      printf( "%d:", q );
      for( w = 0 ; w < top[q] ; w++ )
        printf( " %d", block[q][w] );
      printf( "\n" );
    }
  }

  return 0;
}
