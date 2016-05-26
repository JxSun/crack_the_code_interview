#include <stdio.h>
#include <string.h>

#define MAX_TEST_CASE 1024

// Suppose we will not test over 1024.
int stairs[MAX_TEST_CASE] = {};

// Top-down DP
int count1(int n) {
  if (n < 0) return 0;
  else if (n == 0) return 1;
  else if (stairs[n] != -1) return stairs[n];
  else
    stairs[n] = count1(n - 1) + count1(n - 2) + count1(n - 3);
  return stairs[n];
}

// Bottom-up DP
int count2(int n) {
  stairs[0] = stairs[1] = 1;
  stairs[2] = 2;
  int i;
  for (i = 3; i <= n; i++) {
    stairs[i] = stairs[i - 1] + stairs[i - 2] + stairs[i - 3];
  }
  return stairs[n];
}

int main() {
  int i;
  for (i = 1; i <= 10; i++) {
    memset(stairs, -1, sizeof(int) * MAX_TEST_CASE);
    printf("count1(%d) = %d\n", i, count1(i));
    memset(stairs, -1, sizeof(int) * MAX_TEST_CASE);
    printf("count2(%d) = %d\n", i, count2(i));
    printf("===========\n");
  }
}
