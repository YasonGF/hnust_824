## 栈与队列

## stack
栈是限定在表尾进行插入和删除操作的线性表
栈顶top：允许插入和删除的一端
栈底bottom：与top对应

栈是LIFO（last in， first out）的线性表

栈的操作
进栈
出栈

栈的实现
顺序存储栈
```C
#define MaxSize 50
typedef int ElemType;

typedef struct {
  ElemType data[MaxSize];
  int top;
} SqStack;
```
链式存储栈
