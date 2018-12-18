#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "time.h"

int determinant(int** mat, int size);
int** minore(int **mat, int i, int j, int dim);
void stampa_matrice(int **mat, int dim);

int main(int argc, char const *argv[])
{
  srand(time(NULL));
  const int DIM;
  printf("Scegli dimensione matrice: " );
  scanf("%d",&DIM);
  int i;
  int** mat = calloc(DIM,sizeof(int*));
  for(i=0;i<DIM;i++)
    mat[i]=calloc(DIM,sizeof(int));

  i=0;
  int x,y;
  for(x=0;x<DIM;x++)
  {
    for(y=0;y<DIM;y++)
    {
      mat[x][y]=rand()%10;
    }
  }

  stampa_matrice(mat,DIM);
  printf("%d",determinant(mat,DIM));
  return 0;
}

int determinant(int** mat, int size)
{
  if(size==1)
    return mat[0][0];
  if(size==2)
      return ((mat[0][0]*mat[1][1])-(mat[1][0]*mat[0][1]));
  int i;
  int sum=0;
  for(i=0;i<size;i++)
  {
    int** min = minore(mat,i,0,size);
    sum += (pow(-1,i+0))*mat[i][0]*determinant(min,size-1);
  }

  return sum;
}

int** minore(int **mat, int i, int j, int dim){
  int s;
  int t;
    int** min = calloc(dim-1,sizeof(int*));
    for(s=0; s<dim-1; s++)
      min[s]=calloc(dim-1,sizeof(int));
  int a=0,b=0;
  for(s=0; s<dim; s++)
  {
    b=0;
    for(t=0; t<dim; t++)
    {
      if(!(s==i || t==j))
      {
        min[a][b] = mat[s][t];
        b++;
      }
    }
    if(!(s==i || t==j))
      a++;
  }

  return min;
}

void stampa_matrice(int **mat, int dim)
{
  int i, j;
  for(i=0; i<dim; i++)
  {
    for(j=0; j<dim; j++){
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}
