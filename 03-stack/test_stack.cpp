#include <iostream>

#include "stack_link_tmp.cpp"
// #include "stack_link_tmp2.cpp"
// #include "stack_template1.cpp"
// #include "stack_template2.cpp"

using namespace std;

int main(void) {
  LiStack s;
  init(s);

  push(s, 1);
  push(s, 2);
  push(s, 3);

  

  return 0;
}