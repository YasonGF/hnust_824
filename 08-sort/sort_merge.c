#include <stdio.h>

#define N 100010
int a[N];
int b[N];

void merge_sort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

int main(void) {
  //
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  ;

  merge_sort(a, 1, n);

  for (int i = 1; i <= n; i++) printf("%d ", a[i]);

  return 0;
}

void merge_sort(int a[], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    merge_sort(a, low, mid);
    merge_sort(a, mid + 1, high);
    merge(a, low, mid, high);
  }
}

void merge(int a[], int low, int mid, int high) {
  int i, j, k;
  for (k = low; k <= high; k++) b[k] = a[k];
  for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    if (b[i] <= b[j])
      a[k] = b[i++];
    else
      a[k] = b[j++];
  while (i <= mid) a[k++] = b[i++];
  while (j <= high) a[k++] = b[j++];
}