#!/bin/bash

# コンテスト番号を引数で指定する
if [ $# -ne 1 ]; then
  echo "Usage: ./create_contest.sh <contest_number>"
  exit 1
fi

# ヘッダファイルの内容を指定する
header="#include <iostream>
#include <atcoder/all>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <set>
#define Out(x) cout << x << endl
#define Yes \"Yes\"
#define No \"No\"
#define Ans cout << ans << endl
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using ll = long long;
using P = pair<int, int>;

int main(){
  
  return 0;
}"

# コンテスト番号を取得する
contest_number=$1

# コンテスト用のフォルダを作成する
mkdir $contest_number
cd $contest_number

# a.cpp, b.cpp, ... e.cpp を作成する
for i in {a..e}; do
  echo "$header" > $i.cpp
  touch $i.cpp
  chmod 755 $i.cpp
done
