#include <algorithm>
#include <iostream>
#include <string>

#define MAX_SIZE 255

using namespace std;

typedef struct {
  char data[MAX_SIZE + 1];
  int length;  // 串的当前长度
} SString;

// brute_force算法，最好O(n), 最坏O(M*n)
int index_bf(SString &s, SString &t);

int main(void) {
  SString s = {
      //   "aaaaab",6,
      "abbbcdef",
      8,
  };
  SString t = {
      //   "aaab",4,
      "bbc",
      3,
  };
  cout << index_bf(s, t);
  return 0;
}

int index_bf(SString &s, SString &t) {
  int i = 1, j = 1;
  while (i <= s.length && j <= t.length) {
    if (s.data[i] == t.data[j]) {
      ++i;
      ++j;
    } else {
      i = i - j + 2;
      j = 1;
    }
  }
  if (j >= t.length)
    return i - t.length;
  else
    return 0;
}
