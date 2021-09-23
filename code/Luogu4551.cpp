/**
*   Copyright (C) 2021 All rights reserved.
*   FileName      ：Luogu4551.cpp
*   Author        ：trswnca
*   Email         ：trswnca@yeah.net
*   Date          ：2021.07.21
*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, t) for (int i = (int)(s); i <= (int)(t); ++ i)

const int N = 1e5 + 10;
int n, cnt, tot, ans;

int ch[N * 32][2], head[N];

inline void insert(int w) {
  int x = 0;
  for (int i = 30; ~i; -- i) {
    if (!ch[x][(w >> i) & 1]) ch[x][(w >> i) & 1] = ++tot;
    x = ch[x][(w >> i) & 1];
  }
}

inline void query(int w) {
  int x = 0, t = 0;
  for (int i = 30; ~i; -- i) {
    if (ch[x][1 ^ ((w >> i) & 1)]) x = ch[x][1 ^ ((w >> i) & 1)], t |= (1 << i);
    else x = ch[x][(w >> i) & 1];
  }
  if (t > ans) ans = t;
}

struct node {
  int nxt, to, w;
} e[N << 1];

inline void addline(int x, int y, int z) {
  e[++cnt] = (node){ head[x], y, z }, head[x] = cnt;
}

void dfs(int x, int fa, int pre, void (* opt)(int)) {
  opt(pre);
  for (int i = head[x], y; i; i = e[i].nxt) {
    if ((y = e[i].to) == fa) continue;
    dfs(y, x, pre ^ e[i].w, opt);
  }
}

int main() {
  scanf("%d", &n);
  for (int x, y, z, i = 2; i <= n; ++ i)
    scanf("%d %d %d", &x, &y, &z), 
    addline(x, y, z), addline(y, x, z);
  dfs(1, 0, 0, insert);
  dfs(1, 0, 0, query);
  printf("%d\n", ans);
}
