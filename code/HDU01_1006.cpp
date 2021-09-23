/**
*   Copyright (C) 2021 All rights reserved.
*   FileName      ：HDU01_1006.cpp
*   Author        ：trswnca
*   Email         ：trswnca@yeah.net
*   Date          ：2021.07.21
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int inf = 1e9;
int n, cnt, tot, ans, k;

int ch[N * 32][2], val[N * 32], sum[N];

inline void insert(int w, int pos) {
  int x = 0;
  for (int i = 30; ~i; -- i) {
    if (!ch[x][(w >> i) & 1]) ch[x][(w >> i) & 1] = ++tot;
    x = ch[x][(w >> i) & 1];
    val[x] = val[x] ? min(val[x], pos) : pos;
  }
}

int query(int x, int w, int i) {
  if (i < 0) return val[x];
  int res = inf;
  int nxt = (w >> i) & 1;
  int below = (k >> i) & 1;
  if (ch[x][1 ^ nxt]) { // 1 way
    if (below == 1) res = min(res, query(ch[x][1 ^ nxt], w, i - 1));
    else res = min(res, val[ch[x][1 ^ nxt]]);
  } else if (below == 0) res = min(res, query(ch[x][nxt], w, i - 1));
  return res;
}

void _main() {
  for (int i = 0; i <= tot; ++ i)
    val[i] = 0, ch[i][0] = ch[i][1] = 0;
  tot = 0; val[0] = inf;
  scanf("%d %d", &n, &k);
  for (int i = 1, x; i <= n; ++ i)
    scanf("%d", &x), sum[i] = sum[i - 1] ^ x;
  int len = inf, ansl, ansr;
  for (int i = n; i; -- i) {
    insert(sum[i], i);
    int r = query(0, sum[i - 1], 30);
    if (len >= r - i + 1) {
      len = r - i + 1;
      ansl = i;
      ansr = r;
    }
    //printf("i = %d %d\n", i, r);
  }
  if (len == inf) printf("-1\n");
  else printf("%d %d\n", ansl, ansr);
}

int main() {
  int t; scanf("%d", &t);
  while (t --) _main();
}

