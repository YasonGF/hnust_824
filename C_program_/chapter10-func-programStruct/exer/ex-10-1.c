// 有序表的增删查操作

#include <stdio.h>

#define MAXN 100

// 1. 如何修改input_array()的定义，当输入数据无序或重复时，使数组a有序且无重复元素
// 2. 如何修改插入函数insert()的定义，使得重复元素不会被插入
// 3. 如果不使用全局遍历Count，如何修改程序

void select(int a[], int option, int value, int *count);
void input_array(int a[], int *count);
void print_array(int a[], int *count);
void insert(int a[], int value, int *count);
void remove(int a[], int value, int *count);
void query(int a[], int value, int *count);

int main(void) {
  int op, val, a[MAXN];
  int cnt = 0;
  input_array(a, &cnt);

  printf("[1] Insert\n");
  printf("[2] Delete\n");
  printf("[3] Query\n");
  printf("[other option] End\n");

  while (1) {
    printf("Input option:");
    scanf("%d", &op);
    if (op < 1 || op > 3) break;
    printf("Input an element:");
    scanf("%d", &val);
    select(a, op, val, &cnt);
    printf("\n");
  }
  printf("thanks\n");
  return 0;
}

void select(int a[], int option, int value, int *cnt) {
  switch (option) {
    case 1:
      insert(a, value, cnt);
      break;
    case 2:
      remove(a, value, cnt);
      break;
    case 3:
      query(a, value, cnt);
      break;
  }
}
void input_array(int a[], int *count) {
  printf("Input the number of array elements:");
  scanf("%d", count);
  printf("Input an ordered array element:");
  for (int i = 0; i < *count; i++) {
    scanf("%d", &a[i]);
    
  }
}

void print_array(int a[], int *count) {
  printf("The ordered array a is: ");
  for (int i = 0; i < *count; i++)
    if (i == 0)
      printf("%d", a[i]);
    else
      printf(" %d", a[i]);
}
void insert(int a[], int value, int *cnt) {
  int i, j;
  for (i = 0; i < *cnt; i++)  // 1.定位
    if (value < a[i]) break;

  for (j = *cnt - 1; j >= i; j--)  // 2.移位
    a[j + 1] = a[j];

  a[i] = value;  // 3.插入
  *cnt+=1;       // 4.增1
  print_array(a, cnt);
}
void remove(int a[], int value, int *cnt) {
  int i, index = -1;
  for (i = 0; i < *cnt; i++)
    if (value == a[i]) {
      index = i;
      break;
    }

  if (index == -1)
    printf("Failed to find the data, deletion failed.\n");
  else
    for (i = index; i < *cnt - 1; i++) a[i] = a[i + 1];

  *cnt-=1;
  print_array(a, cnt);
}
void query(int a[], int value, int *cnt) {
  int m, l = 0, r = *cnt - 1;
  while (l <= r) {
    m = (l + r) / 2;
    if (value == a[m]) {
      printf("The index is %d\n", m);
      return;
    } else if (value < a[m])
      r = m - 1;
    else
      l = m + 1;
  }
  printf("This element does not exist!\n");
}
