/**
*   Copyright (C) 2021 All rights reserved.
*   FileName      ：test.cpp
*   Author        ：trswnca
*   Email         ：trswnca@yeah.net
*   Date          ：2021.07.21
*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, t) for (int i = (int)(s); i <= (int)(t); ++ i)

inline void solve() {
#define my "HDU01_1006";
#define std "std";
  while (1) {
    printf("Accept\n");
    system("./datamaker > test.in");
    system("./HDU01_1006 < test.in > my.out");
    system("./std < test.in > ans.out");
    if (system("diff my.out ans.out")) break;
  }
}

signed main() {
  int t = 1; //cin >> t;
  while (t --) solve();
}


