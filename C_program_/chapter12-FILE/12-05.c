#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5
struct sysuser{
    char username[20];
    char password[8];
};

/*
zhaoxy zxy123
fengyb fyb123
lilei lilei123
lisa lisa123
iu iu123

*/

void encrypt(char *pwd);

int main(void) {
    FILE *fp;
    int i;
    struct sysuser u[SIZE], su[SIZE];
    struct sysuser *pu = u, *psu = su;
    const char *dest = "f12-5.dat";
     if ((fp = fopen(dest, "wb+")) == NULL) {
      printf("file open error!\n");
      exit(0);
    }

    for(i = 0; i < SIZE; i++, pu++) {
        printf("Enter %d th sysuser(name, password):", i);
        scanf("%s%s", pu->username, pu->password);
        encrypt(pu->password);
    }

    pu = u;
    fwrite(pu, sizeof(struct sysuser), SIZE, fp);
    rewind(fp);

    fread(psu, sizeof(struct sysuser), SIZE, fp);
    for (i = 0; i < SIZE; i++, psu++) {
      printf("[ %s\t%s ]\n", psu->username, psu->password);
    }

    if(fclose(fp)) {
        printf("can not close the file!\n");
        exit(0);
    }

    return 0;
}

void encrypt(char *pwd){
    int i;
    int len = strlen(pwd);
    for(i = 0; i < len; i++) {
        pwd[i] ^= 15;
    }
}