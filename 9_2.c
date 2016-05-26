#include <stdio.h>
#include <string.h>

#define X 100
#define Y 100

int checkerboard[X][Y] = {};

// Top-down DP
int count1(int x, int y)
{
  if (x < 0 || y < 0) return 0;
  else if (x == 0 || y == 0) return 1;
  else if (checkerboard[x][y] != -1)
    return checkerboard[x][y];
  else
    checkerboard[x][y] = count1(x - 1, y) + count1(x, y - 1);
  return checkerboard[x][y];
}

// Bottom-up DP
int count2(int x, int y)
{
  int i, j;
  for (i = 0; i <= x; i++) {
    checkerboard[i][0] = 1;
  }
  for (i = 0; i <= y; i++) {
    checkerboard[0][i] = 1;
  }

  for (i = 1; i <= x; i++) {
    for (j = 1; j <= y; j++) {
      checkerboard[i][j] = checkerboard[i - 1][j] + checkerboard[i][j - 1];
    }
  }
  return checkerboard[x][y];
}

int main()
{
  int i, j;
  for (i = 2; i < 10; i++) {
    for (j = 2; j < 10; j++) {
      memset(checkerboard, -1, sizeof(int) * X * Y);
      printf("%d x %d -> %d\n", i, j, count2(i, j));
      memset(checkerboard, -1, sizeof(int) * X * Y);
      printf("%d x %d -> %d\n", i, j, count2(i, j));
    }
  }
  
  return 0;
}
