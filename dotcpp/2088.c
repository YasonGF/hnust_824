/*
快速幂

给定A, B, P，求(A^B) mod P。

输入共一行。
第一行有三个数，N, M, P。

输出共一行，表示所求。
*/

#include <stdio.h>

long long qsm(int a, int n);                          // 快速幂求a的n次方
long long qsm_mod_p(long a, long n, unsigned int p);  // 快速幂求a的n次方取模p

int q_m(long long, long long, int);

int main(void) {
  //
  long long a, b;
  int p;
  scanf("%lld %lld %d", &a, &b, &p);

  //   long long ans = qsm(a, b);
  //   printf("%lld\n", ans % p);

  long long ans = qsm_mod_p(a, b, p);
  printf("%lld\n", ans);

  return 0;
}

long long qsm(int a, int n) {
  long long ans = 1;
  while (n) {
    if (n % 2) ans = ans * a;
    a = a * a;
    n /= 2;
  }
  return ans;
}

long long qsm_mod_p(long a, long n, unsigned int p) {
  a = a % p;
  long long ans = 1;
  while (n) {
    if (n & 1)  // 等价于n%2
      ans = (ans * a) % p;
    a = (a * a) % p;
    n >>= 1;  // 等价于n/=2
  }
  return ans % p;
}

int q_m(long long a, long long n, int p) {
  if (n == 0LL) return 1;
  long long m = q_m(a % p, n / 2, p);
  return m % p * m % p * ((1 + (a - 1) * (n % 2))) % p;
}