#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAXN 101  /* 多项式最大项数，即多项式次数+1*/
#define MAXK 1e5 /* 被测函数最大重复调用次数*/
/*#define MAXSIZE 100
typedef int ElemType;*/

/*int judgerpnm(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}

int judgePrime(int num) {
    int count = 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    if (count == 0) {
        return 1;
    }
    return 0;
}

long long combination(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k > n - k) k = n - k;

    long long result = 1;
    for (int i = 1; i <= k; i++) {
        result *= (n - k + i);
        result /= i;
    }
    return result;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct point {
    int x;
    int y;
} P;

struct point creatPoint(int n1, int n2) {
    struct point p;
    p.x = n1;
    p.y = n2;
    return p;
}

void method(int *p, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}


struct book {
    int isbn;
    char bookName[20];
    double price;
};*/

//顺序表
/*typedef struct {
    ElemType *data;
    int length;
} Seqlist;

Seqlist *initList() {
    Seqlist *L = (Seqlist *) malloc(sizeof(Seqlist));
    L->data = (ElemType *) malloc(sizeof(ElemType) * MAXSIZE);
    L->length = 0;
    return L;
}

int appendElem(Seqlist *L, ElemType e) {
    if (L->length >= MAXSIZE) {
        printf("顺序表已满\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1;
} //在尾部添加元素

void listElem(Seqlist *L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int insertElem(Seqlist *L, int pos, ElemType e) {
    if (pos <= L->length) {
        for (int i = L->length; i >= pos; i--) {
            L->data[i] = L->data[i - 1];
        }
        L->data[pos - 1] = e;
        L->length++;
    }
    return 1;
}

int deleteElem(Seqlist *L, int pos, ElemType *e) {
    *e = L->data[pos - 1];
    if (pos < L->length) {
        for (int i = pos; i < L->length; i++) {
            L->data[i - 1] = L->data[i];
        }
    }
    L->length--;
    return 1;
}

int findElem(Seqlist *L, ElemType e) {
    if (L->length == 0) {
        printf("空列表\n");
        return 0;
    }

    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}*/

//单向链表和环
/*typedef struct node {
    ElemType data;
    struct node *next;
} Node;

Node *initList() {
    Node *head = (Node *) malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

int insertHead(Node *L, ElemType e) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
}

Node *get_tail(Node *L) {
    Node *p = L;
    while (p->next != NULL) {
        p = p->next;
    }
    return p;
}

Node *insertTail(Node *tail, ElemType e) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->data = e;
    tail->next = p;
    p->next = NULL;
    return p;
}

int insertNode(Node *L, int pos, ElemType e) {
    //用来保存插入位置的前驱节点
    Node *p = L;
    int i = 0;

    while (i < pos - 1) {
        p = p->next;
        i++;
        if (p == NULL) {
            return 0;
        }
    } //这里将头节点视作索引0,Pos指的是数据中的位置(不包括头节点),但是循环是从0开始的
    //所以从0到pos-1需要经过pos-1次操作(指p=p->next)才能到达第pos-1个节点的位置
    //此时p的储的是pos-1这个节点的地址,所以p->next是第pos个节点的地址
    //q是要插入的新节点
    Node *q = (Node *) malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

int delNode(Node *L, int pos) {
    Node *p = L;
    int i = 0;
    while (i < pos - 1) {
        p = p->next;
        i++;
        if (p == NULL) {
            return 0;
        }
    }
    if (p->next == NULL) {
        return 0;
    }
    Node *q = p->next; //q指向要删除的节点
    p->next = q->next; //让要删除的节点的前驱指向删除节点的后继
    free(q); //释放要删除节点的内存空间
    return 1;
}

int listLength(Node *L) {
    Node *p = L;
    int len = 0;
    while (p != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

void freeList(Node *L) {
    Node *p = L->next;
    Node *q;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

int findNodeFS(Node *L, int k) {
    Node *fast = L->next;
    Node *slow = L->next;
    for (int i = 0; i < k; i++) {
        fast = fast->next;
    }
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    printf("倒数第%d个节点值是:%d\n", k, slow->data);
    return 1;
}

Node *findIntersectionNode(Node *L1, Node *L2) {
    if (L1 == NULL || L2 == NULL) {
        return NULL;
    }
    Node *p = L1;
    int len1 = listLength(L1);
    int len2 = listLength(L2);
    int max = len1 > len2 ? len1 : len2;
    int min = len1 < len2 ? len1 : len2;
    int step = max - min;
    Node *fast = len1 > len2 ? L1 : L2;
    Node *slow = len1 > len2 ? L2 : L1;
    for (int i = 0; i < step; i++) {
        fast = fast->next;
    }
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

void removeNode(Node *L, int n) {
    Node *p = L;
    int index;
    int *q = (int *) malloc(sizeof(int) * (n + 1));

    for (int i = 0; i < n + 1; i++) {
        *(q + i) = 0;
    }

    while (p->next != NULL) {
        index = abs(p->next->data);
        if (*(q + index) == 0) {
            *(q + index) = 0;
            p = p->next;
        } else {
            Node *temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    }
    free(q);
}

Node *reverseList(Node *head) {
    Node *first = NULL;
    Node *second = head->next;
    Node *third = NULL;

    while (second != NULL) {
        //用于反转指针
        third = second->next;
        second->next = first;

        //用于移动指针
        first = second;
        second = third;
    }
    Node *hd = initList();
    hd->next = first;
    return hd;
}

int delMidNode(Node *head) {
    Node *slow = head;
    Node *fast = head->next;
    while (fast->next != NULL && fast != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *temp = slow->next;
    slow->next = temp->next;
    free(temp);
    return 1;
}

void reOrderList(Node *head) {
    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *first = NULL;
    Node *second = slow->next;
    slow->next = NULL; //将链表拆成2部分
    Node *third = NULL;

    while (second != NULL) {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }

    Node *p1 = head->next;
    Node *q1 = first;
    Node *p2, *q2;
    while (p1 != NULL && q1 != NULL) {
        p2 = p1->next;
        q2 = q1->next;

        p1->next = q1;
        q1->next = p2;

        p1 = p2;
        q1 = q2;
    }
}

int isCircle(Node *head) {
    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            return 1;
        }
    }
    return 0;
}

Node *findEntry(Node *head) {
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            Node *p = fast;
            int count = 1;
            while (p->next != slow) {
                p = p->next;
                count++;
            }
            slow = head;
            fast = head;
            for (int i = 0; i < count; i++) {
                fast = fast->next;
            }
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
}

void listNode(Node *L) {
    Node *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


clock_t start, end;
/* clock_t 是 clock()函数返回的变量类型#1#
double duration;

double f1(int n, double a[], double x) {
    int i;
    double p = a[0];
    for (i = 1; i < n; i++)
        p += (a[i] * pow(x, i));
    return p;
} //时间复杂度:O(n^2)

double f2(int n, double a[], double x) {
    int i;
    double p = a[0];
    for (i = n; i > 0; i--)
        p = a[i - 1] + x * p;
    return p;
} //时间复杂度:O(n)

void run(double (*f)(int n, double *, double), double a[], int func_n) {
    int i;
    start = clock();
    for (i = 0; i < MAXK; i++)
        f(MAXN - 1, a, 1.1);
    end = clock();
    duration = ((double) (end - start)) / CLK_TCK;
    printf("ticks%d=%f\n", func_n, (double) (end - start));
    printf("duration%d=%6.2e\n", func_n, duration);
}*/

//双向链表
/*typedef struct node {
    ElemType data;
    struct node *next, *prev;
} Node;

Node *initNode() {
    Node *head = (Node *) malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

int insertHead(Node *L, ElemType e) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    p->prev = L;
    if (L->next != NULL) {
        L->next->prev = p;
    }
    L->next = p;
    return 1;
}

Node *findTail(Node *L) {
    Node *tail = L;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    return tail;
}

Node *insertTail(Node *L, ElemType e) {
    Node *p = (Node *) malloc(sizeof(Node));
    Node *tail = L;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    p->data = e;
    p->next = NULL;
    p->prev = tail;
    tail->next = p;
    return p;
}

int insertNode(Node *L, ElemType e, int pos) {
    Node *p = L;
    for (int i = 0; i < pos - 1; i++) {
        p = p->next;
        if (p == NULL) {
            return 0;
        }
    }
    Node *q = (Node *) malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    q->prev = p;
    p->next->prev = q;
    p->next = q;
    return 1;
}

int deleteNode(Node *L, int pos) {
    Node *p = L;
    for (int i = 0; i < pos - 1; i++) {
        p = p->next;
        if (p == NULL) {
            return 0;
        }
    }
    if (p->next == NULL) {
        return 0;
    }
    Node *q = p->next;
    p->next=q->next;
    q->next->prev=p;
    free(q);
    return 1;
}

void showList(Node *L) {
    Node *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}*/

//栈
/*typedef struct {
    ElemType data[MAXSIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}*/

/*typedef struct {
    ElemType *data;
    int top; //栈顶的数组下标
} Stack;

Stack *initStack() {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->data = (ElemType *) malloc(sizeof(ElemType) * MAXSIZE);
    s->top = -1;
    return s;
}

int isEmpty(Stack *s) {
    if (s->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int push(Stack *s, ElemType e) {
    if (s->top >= MAXSIZE - 1) {
        printf("满了\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}

int pop(Stack *s, ElemType *e) {
    if (s->top == -1) {
        printf("空的\n");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}

int getTop(Stack *s, ElemType *e) {
    if (s->top == -1) {
        printf("空的\n");
        return 0;
    }
    *e = s->data[s->top];
    return 1;
}*/

/*typedef struct stack {
    ElemType data;
    struct stack *next;
} Stack;

Stack *initStack() {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->data = 0;
    s->next = NULL;
    return s;
}

//判断栈是否为空
int isEmpty(Stack *s) {
    return s->next == NULL;
}

int push(Stack *s, ElemType e) {
    Stack *p = (Stack *) malloc(sizeof(Stack));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return 1;
}

int pop(Stack *s, ElemType *e) {
    if (s->next == NULL) {
        printf("空的\n");
        return 0;
    }
    *e = s->next->data;
    Stack *p = s->next;
    s->next = p->next;
    free(p);
    return 1;
}

int getTop(Stack *s, ElemType *e) {
    if (s->next == NULL) {
        printf("空的\n");
        return 0;
    }
    *e = s->next->data;
    return 1;
}*/

//队列
/*typedef struct {
    ElemType data[MAXSIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *Q) {
    Q->front = 0;
    Q->rear = 0;
}

int isEmpty(Queue *Q) {
    if (Q->front == Q->rear) {
        printf("空的\n");
        return 1;
    } else {
        return 0;
    }
}

ElemType deQueue(Queue *Q) {
    if (Q->front == Q->rear) {
        printf("空的\n");
        return 0;
    }
    ElemType e = Q->data[Q->front];
    Q->front++;
    return e;
}

int queueFull(Queue *Q) {
    if (Q->front > 0) {
        int step = Q->front;
        for (int i = Q->front; i <= Q->rear; i++) {
            Q->data[i - step] = Q->data[i];
        }
        Q->front = 0;
        Q->rear -= step;
        return 1;
    } else {
        printf("真的满了\n");
        return 0;
    }
}

int eQueue(Queue *Q, ElemType e) {
    if (Q->rear >= MAXSIZE) {
        if (!queueFull(Q)) {
            return 0;
        }
    }
    Q->data[Q->rear] = e;
    Q->rear++;
    return 1;
}

int getHead(Queue *Q,ElemType *e) {
    if (Q->front==Q->rear) {
        printf("满的\n");
        return 0;
    }
    *e=Q->data[Q->front];
    return 1;
}*/

//循环队列
/*typedef struct {
    ElemType *data;
    int front;
    int rear;
} Queue;

Queue *initQueue() {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->data = (ElemType *) malloc(sizeof(ElemType) * MAXSIZE);
    q->front = 0;
    q->rear = 0;
    return q;
}

int equeue(Queue *Q, ElemType e) {
    if ((Q->rear + 1) % MAXSIZE == Q->front) {
        printf("满了\n");
        return 0;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1;
}

int dequeue(Queue *Q, ElemType *e) {
    if (Q->front == Q->rear) {
        printf("空的\n");
        return 0;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}

int getHead(Queue *Q,ElemType *e) {
    if (Q->front==Q->rear) {
        printf("空的\n");
        return 0;
    }
    *e=Q->data[Q->front];
    return 1;
}*/

/*队列的链式结构
typedef struct QueueNode {
    ElemType data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} Queue;

Queue *initQueue() {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    QueueNode *node = (QueueNode *) malloc(sizeof(QueueNode));
    node->data = 0;
    node->next = NULL;
    q->front = node;
    q->rear = node;
    return q;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void equeue(Queue *q, ElemType e) {
    QueueNode *node = (QueueNode *) malloc(sizeof(QueueNode));
    node->data = e;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
}

int dequeue(Queue *q, ElemType *e) {
    QueueNode *node = q->front->next;
    *e = node->data;
    q->front->next = node->next;
    if (q->rear == node) {
        q->rear = q->front;
    }
    free(node);
    return 1;
}

ElemType getFront(Queue *q) {
    if (isEmpty(q)) {
        printf("空的\n");
        return 0;
    }
    return q->front->next->data;
}*/

/*//递归
int fun(int n) {
    if (n == 1) return 1;
    else return fun(n - 1) + n;
}

int Fibonacci(int n) {
    if (n == 1 || n == 2) return 1;
    else return Fibonacci(n - 1) + Fibonacci(n - 2);
}*/

/*//枚举
typedef enum weekday {
    mon = 1, tue, wed, thu, fri, sat, sun
} weekday;

typedef enum bool {
    false, true
} bool;

typedef enum {
    LEFT_PARE, RIGHT_PARE,
    ADD, SUB, MUL, DIV, MOD,
    EOS, NUM
} contentType;

char expr[] = "x/(i-j)*y";

contentType getToken(char *symbol, int *index) {
    *symbol = expr[*index];
    *index = *index + 1;
    switch (*symbol) {
        case'(':
            return LEFT_PARE;
        case ')':
            return RIGHT_PARE;
        case '+':
            return ADD;
        case '-':
            return SUB;
        case '*':
            return MUL;
        case '/':
            return DIV;
        case '%':
            return MOD;
        case '\0':
            return EOS;
        default:
            return NUM;
    }
}

int evil(Stack *s) {
    char symbol;
    int op1, op2;
    int index = 0;
    contentType token;
    token = getToken(&symbol, &index);
    ElemType result;
    while (token != EOS) {
        if (token == NUM) {
            push(s, symbol - '0');
        } else {
            pop(s, &op2);
            pop(s, &op1);

            switch (token) {
                case ADD:
                    push(s, op1 + op2);
                    break;
                case SUB:
                    push(s, op1 - op2);
                    break;
                case MUL:
                    push(s, op1 * op2);
                    break;
                case DIV:
                    push(s, op1 / op2);
                    break;
                case MOD:
                    push(s, op1 % op2);
                    break;
                default:
                    break;
            }
        }
        token = getToken(&symbol, &index);
    }
    pop(s, &result);
    printf("%d\n", result);
    return 1;
}

int print_token(contentType token) {
    switch (token) {
        case ADD:
            printf("+");
            break;
        case SUB:
            printf("-");
            break;
        case MUL:
            printf("*");
            break;
        case DIV:
            printf("/");
            break;
        case MOD:
            printf("%%");
            break;
        default:
            return 0;
    }
    return 1;
}

void postfix(Stack *s) {
    int in_stack[] = {0, 19, 12, 12, 13, 13, 13, 0};
    int out_stack[] = {20, 19, 12, 12, 13, 13, 13, 0};

    contentType token;
    int index = 0;
    push(s, EOS);
    char symbol;
    ElemType e;
    token = getToken(&symbol, &index);

    while (token != EOS) {
        if (token == NUM) {
            printf("%c", symbol);
        } else if (token == RIGHT_PARE) {
            while (s->data[s->top] != LEFT_PARE) {
                pop(s, &e);
                print_token(e);
            }
            pop(s, &e);
        } else {
            while (in_stack[s->data[s->top]] >= out_stack[token]) {
                pop(s, &e);
                print_token(e);
            }
            push(s, token);
        }
        token = getToken(&symbol, &index);
    }
    while (!isEmpty(s)) {
        pop(s,&e);
        print_token(e);
    }
}*/

typedef char ElemType;

typedef struct TreeNode {
    ElemType data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

typedef TreeNode *BiTree; //二叉树指针

char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;

void creatTree(BiTree *T) {
    ElemType ch;
    ch = str[idx++];
    if (ch == '#') {
        *T = NULL;
    } else {
        *T = (TreeNode *) malloc(sizeof(TreeNode));
        (*T)->data = ch;
        creatTree(&(*T)->lchild);
        creatTree(&(*T)->rchild);
    }
}

//二叉树的遍历:
//1.前序遍历
void preOrder(BiTree T) {
    if (T == NULL) {
        return;
    }
    printf("%c ", T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
}

//2.中序遍历
void inOrder(BiTree T) {
    if (T==NULL) {
        return ;
    }
    inOrder(T->lchild);
    printf("%c ",T->data);
    inOrder(T->rchild);
}

//3.后序遍历
void postOrder(BiTree T) {
    if (T==NULL) {
        return;
    }
    postOrder(T->lchild);
    postOrder(T->rchild);
    printf("%c ",T->data);
}


int main(void) {
    /*
int a, b;
scanf_s("%d %d", &a, &b);
int count = 0;
for (int i = a; i <= b; i++) {
    int flag = judgerpnm(i);
    if (flag == 1) {
        count++;
    }
}
printf("%d\n", count);
for (int i = a; i <= b; i++) {
    int flag = judgerpnm(i);
    if (flag == 1) {
        printf("%d ", i);
    }
}
*/

    /*
int num;
scanf_s("%d", &num);
int flag = judgePrime(num);
if (flag == 1) {
    printf("%d是质数", num);
}
else {
    printf("%d不是质数", num);
}
*/

    /*int n;
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<n;i++) {
        int flag=judgePrime(arr[i]);
        if (flag==1) {
            printf("%d ",arr[i]);
        }
    }*/

    /*int num;
    scanf("%d", &num);
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            int j = num / i;
            if (judgePrime(i) == 1 && judgePrime(j) == 1 && i < j) {
                printf("%d\n", j);
            }
        }
    }*/

    /*int n;
    scanf("%d", &n);
    int length = 1;
    for (int i = 0; i < n; i++) {
        length = length * 2;
    }
    //printf("%d\n",length);
    for (int i = 1; i <= length; i++) {
        for (int j = 1; j <= length - i; j++) {
            printf("0 ");
        }

        for (int k = 1; k <= i; k++) {
            int num=combination(i-1,k-1);
            if (num % 2 == 0) {
                printf("0 ");
            } else {
                printf("1 ");
            }
        }
        printf("\n");
    }
    return 0;*/

    /*int n;
    scanf("%d", &n);
    int arr[n];
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d:%p\n",arr[i],&arr[i]);
    }*/

    /*int a, b;
    scanf("%d %d", &a, &b);
    int arr[10] = {0};
    int temp;
    for (int i = a; i <= b; i++) {
        temp=i;
        while ( temp> 0) {
            arr[temp%10]++;
            temp/=10;
        }
    }

    for (int j = 0; j < 10; j++) {
        printf("%d:%d\n", j,arr[j]);
    }*/

    /*int a = 5;
    printf("%zu\n", sizeof(a)); //4
    printf("%zu\n", sizeof(3.14)); //8
    printf("%zu\n", sizeof(int)); //4
    int *p = &a;
    printf("%p\n", p);
    printf("%p\n", &a);
    printf("%d\n", *p);
    printf("%d\n", a);
    printf("%p\n", &p);
    *p = 100;
    printf("%d\n", a);*/

    /*int n1=5;
    int n2=10;
    int *p1=&n1;
    int *p2=&n2;
    printf("%d %d\n",n1,n2);
    swap(p1,p2);
    printf("%d %d\n",n1,n2);

    int a[]={15,22,67,43,87};
    int *p;
    p=a;//p存储的是数组的首地址

    printf("%p\n",p);
    printf("%p\n",a);
    printf("%p\n",&a[0]);
    printf("%d\n",*p);
    printf("\n");

    for (int i=0;i<sizeof(a)/sizeof(a[0]);i++) {
        printf("%d %d\n",a[i],*(p+i));
    }
    //给指针加上一个整数,实际上加的是这个整数和指针数据类型对应字节数的乘积
    //比如这里看似每次加1,实则每次加4,4是int的字节数*/

    /*struct point p;
    p = creatPoint(10, 20);

    struct point *pp;
    pp = &p;
    (*pp).x = 5;
    pp->y = 10; //结构体指针
    printf("x=%d,y=%d\n", p.x, p.y);
    printf("x=%d,y=%d\n", pp->x, pp->y);

    P p1;
    p1.x = 2;
    p1.y = 3;*/

    /*int *p1 = malloc(100); //申请一个连续的长度100字节的空间
    int *p2 = malloc(100 * sizeof(int));
    printf("%p\n", p2);
    printf("%d\n", *p1);

    //赋值
    for (int i = 0; i < 10; i++) {
        //*(p2 + i) = (i + 1) * 10;
        p2[i] = (i + 1) * 10;
        //i[p2]=(i+1)*10;
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(p2 + i));
    }*/

    /*int *p3 = calloc(10, sizeof(int));
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(p3 + i));
    }*/

    /*int *p = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        p[i] = (i + 1) * 10;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
    int *pp = realloc(p, 20 * sizeof(int));
    for (int i=0;i<20;i++) {
        printf("%d ",pp[i]);
    }
    printf("\n");
    for (int i = 10; i < 20; i++) {
        pp[i] = (i + 1) * 20;
    }
    for (int i = 0; i < 20; i++) {
        printf("%d ", pp[i]);
    }
    free(pp);
    free(p);*/

    /*char* s=malloc(10);
    strcpy(s,"cat");
    printf("%s\n",s);
    free(s);

    int* arr=(int*)malloc(5*sizeof(int));
    for (int i=0;i<5;i++) {
        arr[i]=i;
    }

    for (int i=0;i<5;i++) {
        printf("%d ",arr[i]);
    }
    free(arr);

    P *p=(P*)malloc(sizeof(P));
    p->x=1;
    p->y=2;
    printf("%d\n",p->x);
    printf("%d\n",p->y);
    free(p);*/

    //算法分析
    /*int n;
    int x = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= j; k++) {
                x++;
            }
        }
    }
    printf("%d\n", x);*
    /*数据结构
    1.线性表:分成 列表和链表
    定义:由n个数据特性相同的元素构成的有限序列(n个相同数据类型的)
    类似于数组,但是数组的长度是固定的,而列表的长度是可变的
    顺序表:用一组连续的内存单元依次存储线性表的各个元素
    也就是说逻辑上相邻的元素,物理存储空间也是连续的*/

    //顺序表的基本操作
    /*Seqlist *list1 = initList();
    printf("初始化成功,目前长度占用%d\n", list1->length);
    printf("目前占用内存%zu字节\n", sizeof(list1->data));
    appendElem(list1, 88);
    appendElem(list1, 45);
    appendElem(list1, 43);
    appendElem(list1, 17);
    listElem(list1);;
    insertElem(list1, 1, 18888);
    listElem(list1);;
    ElemType delData;
    deleteElem(list1, 2, &delData);
    printf("被删除的数据是:%d\n", delData);
    listElem(list1);
    printf("%d\n", findElem(list1, 43));
    free(list1);*/

    //头插法
    /*Node *list = initList();
    insertHead(list, 10);
    insertHead(list, 20);
    insertHead(list, 30);
    //头插法的顺序和排列的顺序是反的
    //并且这里的头节点不存数据,头插法是从头节点后面存入数据的
    listNode(list);
    insertNode(list, 2, 15);
    listNode(list);
    delNode(list, 2);
    listNode(list);
    printf("%d\n", listLength(list));
    freeList(list);
    printf("%d\n", listLength(list));*/

    //尾插法
    /*Node *list = initList();
    Node *tail = get_tail(list);
    tail = insertTail(tail, 10);
    tail = insertTail(tail, 20);
    tail = insertTail(tail, 30);
    tail = insertTail(tail, 40);
    tail = insertTail(tail, 50);
    tail = insertTail(tail, 60);
    tail = insertTail(tail, 70);
    listNode(list);
    findNodeFS(list, 3);*/

    //删除链表中所有值为e的节点
    /*Node *list = initList();
    Node *tail = get_tail(list);
    tail = insertTail(tail, 21);
    tail = insertTail(tail, -15);
    tail = insertTail(tail, -15);
    tail = insertTail(tail, 7);
    tail = insertTail(tail, 15);
    listNode(list);
    removeNode(list,21);
    listNode(list->next);*/

    //反转链表
    /*Node *list = initList();;
    Node *tail = get_tail(list);
    tail = insertTail(tail, 10);
    tail = insertTail(tail, 20);
    tail = insertTail(tail, 30);
    tail = insertTail(tail, 40);
    tail = insertTail(tail, 50);
    tail = insertTail(tail, 60);
    tail = insertTail(tail, 80);
    listNode(list);
    Node *reverse = reverseList(list);
    listNode(reverse);*/

    //重新排序链表
    /*Node *list = initList();
    Node *tail = get_tail(list);
    tail = insertTail(tail, 10);
    tail = insertTail(tail, 20);
    tail = insertTail(tail, 30);
    tail = insertTail(tail, 40);
    tail = insertTail(tail, 50);
    tail = insertTail(tail, 60);
    tail = insertTail(tail, 70);
    tail = insertTail(tail, 80);
    listNode(list);
    reOrderList(list);
    listNode(list);*/

    //判断是否有环
    /*Node *list = initList();
    Node *tail = get_tail(list);
    tail = insertTail(tail, 1);
    tail = insertTail(tail, 2);
    tail = insertTail(tail, 3);
    Node *three = tail;
    tail = insertTail(tail, 4);
    tail = insertTail(tail, 5);
    tail = insertTail(tail, 6);
    tail = insertTail(tail, 7);
    tail = insertTail(tail, 8);
    tail->next = three;
    if (isCircle(list)) {
        printf("有环");
    }
    else {
        printf("没环");
    }*/

    //找到环的入口
    /*Node *list = initList();
    Node *tail = get_tail(list);
    tail = insertTail(tail, 1);
    tail = insertTail(tail, 2);
    tail = insertTail(tail, 3);
    Node *three = tail;
    tail = insertTail(tail, 4);
    tail = insertTail(tail, 5);
    tail = insertTail(tail, 6);
    tail = insertTail(tail, 7);
    tail = insertTail(tail, 8);
    tail->next = three;
    Node *entry=findEntry(list);
    printf("%d\n",entry->data);*/

    /*int i;
    double a[MAXN]; /* 存储多项式的系数 #1#
    a[0]=1;
    for(i=1;i<MAXN;i++)
        a[i]=(double)(1.0/i);
    run(f1,a,1);
    run(f2,a,2);*/

    //双向链表
    /*Node *list1 = initNode();
    insertHead(list1, 10);
    insertHead(list1, 20);
    insertHead(list1, 30);
    insertHead(list1, 40);
    showList(list1);
    Node *tail = findTail(list1);
    insertTail(list1, 50);
    insertTail(list1, 60);
    insertTail(list1, 70);
    showList(list1);
    insertNode(list1, 100, 4);
    showList(list1);
    deleteNode(list1,2);
    showList(list1);*/

    /*栈和队列
    栈(stack):限定仅在表尾进行插入和删除操作的线性表(先进后出)
    尾端:栈顶
    头端:栈底
    操作:进栈(插入),出栈(删除最后插入的元素)*/

    /*Stack *s = initStack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    ElemType e;
    pop(s, &e);
    printf("删去的元素是:%d\n", e);

    getTop(s, &e);
    printf("栈顶元素是:%d\n", e);*/

    /*Stack *s = initStack();
    push(s, 10);
    push(s, 20);
    push(s, 30);

    ElemType e;
    pop(s, &e);
    printf("%d\n", e);

    getTop(s, &e);
    printf("%d\n", e);
    */

    /*队列(queue)先进先出first in first out(FIFO)
    允许插入的一端称为队尾(rear),允许删除的一端称为队头(front)
    Queue q;
    initQueue(&q);
    eQueue(&q,10);
    eQueue(&q,20);
    eQueue(&q,30);
    eQueue(&q,40);
    eQueue(&q,50);

    printf("%d\n",deQueue(&q));
    printf("%d\n",deQueue(&q));
    ElemType e;
    getHead(&q,&e);
    printf("%d\n",e);

    Queue *q=initQueue();

    equeue(q,10);
    equeue(q,20);
    equeue(q,30);
    equeue(q,40);
    equeue(q,50);

    ElemType e;
    dequeue(q,&e);
    printf("%d\n",e);
    dequeue(q,&e);
    printf("%d\n",e);

    getHead(q,&e);
    printf("%d\n",e);

    Queue *q=initQueue();
    equeue(q,10);
    equeue(q,20);
    equeue(q,30);
    equeue(q,40);
    equeue(q,50);
    ElemType e;
    dequeue(q,&e);
    printf("出队%d\n",e);
    dequeue(q,&e);
    printf("出队%d\n",e);
    printf("%d\n",getFront(q));*/

    //printf("%d\n",Fibonacci(30));

    /*enum weekday a;
    a = mon;
    weekday b;
    b = tue;
    printf("%d\n", a);
    printf("%d\n", b);*/

    /*Stack *s = initStack();
    evil(s);*/

    /*Stack *s = initStack();
    printf("%s\n", expr);
    postfix(s);*/

    /*二叉树:根节点有2个子树,每个节点的最大的度为2
    分类:
    1.满二叉树:
    深度为k,则其节点个数为2^(k-1),也就是说这棵树是完全填满的

    2.完全二叉树:
    没有左子树,不能有右子树,
    上一层没有铺满,不能有下一层

    性质:
    具有n个节点的完全二叉树的深度为log2(n)+1(向下取整)

    如果对一颗有n个节点的完全二叉树的节点按层序编号,则对任意节点i(1<=i<=n)有:
    1.如果i=1,则节点i是根节点,无双亲
    2.如果i>1,则其双亲节点的编号为i/2(向下取整)
    3.如果2i<=n,则节点i有左子树,其左子树的编号为2i
    4.如果2i>n,则节点i无左子树
    5.如果2i+1<=n,则节点i有右子树,其右子树的编号为2i+1
    6.如果2i+1>n,则节点i无右子树
     */
    BiTree T;
    creatTree(&T);
    preOrder(T);
    printf("\n");
    inOrder(T);
    printf("\n");
    postOrder(T);
    printf("\n");

    return 0;
}
