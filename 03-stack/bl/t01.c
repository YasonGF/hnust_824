// Q 是一个队列，S 是一个空栈，编写算法使得队列中元素逆置
#include "t01_circular_queue.c"
#include "t01_seq_stack.c"

int main(void) {  //
    SQueue queue ;
    queue_init(&queue);

    en_queue(&queue, 1);
    en_queue(&queue, 2);
    en_queue(&queue, 3);
    en_queue(&queue, 4);
    en_queue(&queue, 5);

    Seqstack stack;
    stack_init(&stack);

    // 队列中元素逆置algorithm
    int x;
    while(!is_empty_queue(&queue)) {
        de_queue(&queue, &x);
        push(&stack, x);
    }

    while(!stack_empty(&stack)) {
        pop(&stack, & x);
        en_queue(&queue, x);
    }





  return 0;
}
