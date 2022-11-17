// 有序表的增删查操作

#include <stdio.h>

#define MAXN 100

int Count = 0;

void select(int a[], int option, int value);
void input_array(int a[]);
void print_array(int a[]);
void insert(int a[], int value);
void remove(int a[], int value);
void query(int a[], int value);

int main(void) {
  int op, val, a[MAXN];

  input_array(a);
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
    select(a, op, val);
    printf("\n");
  }
  printf("thanks\n");
  return 0;
}

void select(int a[], int option, int value) {
  switch (option) {
    case 1:
      insert(a, value);
      break;
    case 2:
      remove(a, value);
      break;
    case 3:
      query(a, value);
      break;
  }
}
void input_array(int a[]) {
  printf("Input the number of array elements:");
  scanf("%d", &Count);
  printf("Input an ordered array element:");
  for (int i = 0; i < Count; i++) scanf("%d", &a[i]);
}

void print_array(int a[]) {
  printf("The ordered array a is: ");
  for (int i = 0; i < Count; i++)
    if (i == 0)
      printf("%d", a[i]);
    else
      printf(" %d", a[i]);
}
void insert(int a[], int value) {
  int i, j;
  for (i = 0; i < Count; i++)  // 1.定位
    if (value < a[i]) break;

  for (j = Count - 1; j >= i; j--)  // 2.移位
    a[j + 1] = a[j];

  a[i] = value;  // 3.插入
  Count++;       // 4.增1
  print_array(a);
}
void remove(int a[], int value) {
  int i, index = -1;
  for (i = 0; i < Count; i++)
    if (value == a[i]) {
      index = i;
      break;
    }

  if (index == -1)
    printf("Failed to find the data, deletion failed.\n");
  else
    for (i = index; i < Count - 1; i++) a[i] = a[i + 1];

  Count--;
  print_array(a);
}
void query(int a[], int value) {
  int m, l = 0, r = Count - 1;
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
