#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sysuser {
  char username[20];
  char password[8];
};

void encrypt(char *pwd);  // 对每个字符ASCII码的低四位取反，高四位保持不变
void encrypt2(char *pwd); // 凯撒密码加密

int main(void) {
  FILE *fp;
  int i;
  struct sysuser su;

  if ((fp = fopen("f12-2.txt", "w")) == NULL) {
    printf("FILE OPEN ERROR!\n");
    exit(0);
  }

  for (i = 1; i <= 5; i++) {
    printf("Enter %d th sysuser(name, password):", i);
    scanf("%s%s", su.username, su.password);

    encrypt(su.password);
    fprintf(fp, "%s %s\n", su.username, su.password);
  }

  if (fclose(fp)) {
    printf("cant close the file!\n");
    exit(0);
  }

  return 0;
}

void encrypt(char *pwd) {
  // 对每个字符ASCII码的低四位取反，高四位保持不变

  int len = strlen(pwd);
  int i;
  for (i = 0; i < len; i++) {
    *(pwd + i) = pwd[i] ^ 15;
  }
}