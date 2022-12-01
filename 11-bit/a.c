// 模拟实现strstr函数
#include <assert.h>
#include <stdio.h>
#include <string.h>

char *my_strstr(const char *str1, const char *str2);
int index_bf(const char *s, int slen, const char *t, int tlen);

int main(void) {
  char pstr1[] = "abbbcdef";
  char pstr2[] = "bcd";
  //   char *ans = my_strstr(pstr1, pstr2);

  int ans = index_bf(pstr1, strlen(pstr1), pstr2, strlen(pstr2));
  ans = ans == -1 ? 0 : ans;
  printf("index = %d\n", ans);
  puts(pstr1+ans);

  return 0;
}

char *my_strstr(const char *str1, const char *str2) {
  assert(str1 && str2);
  const char *s1 = NULL;  // s1指向主串
  const char *s2 = NULL;  // s2指向子串
  const char *cp = str1;  // 记录回溯时主串从哪里开始比较

  if (*str2 == '\0') return (char *)str1;

  while (*cp) {
    s1 = cp;
    s2 = str2;
    while (*s1 && *s2 && (*s1 == *s2)) {
      s1++;
      s2++;
    }
    if (*s2 == '\0') return (char *)cp;
    cp++;
  }
  return NULL;
}

int index_bf(const char *s, int slen, const char *t, int tlen) {
  int i = 0, j = 0;
  while (i < slen && j < tlen) {
    if (*(s + i) == *(t + j)) {
      i++;
      ++j;
    } else {
      i = i - j + 1;
      j = 0;
    }
  }
  if (j >= tlen) return i - tlen;
  return -1;
}