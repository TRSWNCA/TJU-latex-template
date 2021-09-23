/**
*   Copyright (C) 2021 All rights reserved.
*   FileName      ：datamaker.cpp
*   Author        ：trswnca
*   Email         ：trswnca@yeah.net
*   Date          ：2021.07.21
*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, t) for (int i = (int)(s); i <= (int)(t); ++ i)

signed main() {
  printf("1\n");
  int n = 10;
  int k = rand() % 10;
  printf("%d %d\n", n, k);
  for (int i = 1; i <= n; ++ i)
    printf("%d ", rand() % 10);
}


