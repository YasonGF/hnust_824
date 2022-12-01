#include <algorithm>
#include <iostream>
#include <string>

#define CHUNK_SIZE 80

using namespace std;

typedef struct Chunk {
  char data[CHUNK_SIZE];
  struct Chunk *next;
} Chunk;

typedef struct {
  Chunk *head, *tail;
  int curlen;
} LString;

int main(void) { return 0; }