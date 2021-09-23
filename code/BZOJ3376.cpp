#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 10;
int fa[N], top[N], d[N];
int n, p, x, y; char s[2];

int find(int x) {
  if (fa[x] == x) return x;
  int y = find(fa[x]);
  d[x] += d[fa[x]];
  return fa[x] = y;
}

int main() {
  for (int i = 1; i < N; ++ i)
    fa[i] = top[i] = i;
  scanf("%d", &p);
  while (p --) {
    scanf("%s", s);
    if (*s == 'M') {
      scanf("%d %d", &x, &y);
      int xx = find(x), yy = top[find(y)];
      top[find(yy)] = top[xx];
      fa[xx] = yy; d[xx] = 1;
    } else {
      scanf("%d", &x); find(x);
      printf("%d\n", d[x]);
    }
  }
}
