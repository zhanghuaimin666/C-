#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAXN 101  /* ����ʽ���������������ʽ����+1*/
#define MAXK 1e5 /* ���⺯������ظ����ô���*/
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

//˳���
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
        printf("˳�������\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1;
} //��β�����Ԫ��

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
        printf("���б�\n");
        return 0;
    }

    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}*/

//��������ͻ�
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
    //�����������λ�õ�ǰ���ڵ�
    Node *p = L;
    int i = 0;

    while (i < pos - 1) {
        p = p->next;
        i++;
        if (p == NULL) {
            return 0;
        }
    } //���ｫͷ�ڵ���������0,Posָ���������е�λ��(������ͷ�ڵ�),����ѭ���Ǵ�0��ʼ��
    //���Դ�0��pos-1��Ҫ����pos-1�β���(ָp=p->next)���ܵ����pos-1���ڵ��λ��
    //��ʱp�Ĵ�����pos-1����ڵ�ĵ�ַ,����p->next�ǵ�pos���ڵ�ĵ�ַ
    //q��Ҫ������½ڵ�
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
    Node *q = p->next; //qָ��Ҫɾ���Ľڵ�
    p->next = q->next; //��Ҫɾ���Ľڵ��ǰ��ָ��ɾ���ڵ�ĺ��
    free(q); //�ͷ�Ҫɾ���ڵ���ڴ�ռ�
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
    printf("������%d���ڵ�ֵ��:%d\n", k, slow->data);
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
        //���ڷ�תָ��
        third = second->next;
        second->next = first;

        //�����ƶ�ָ��
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
    slow->next = NULL; //��������2����
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
/* clock_t �� clock()�������صı�������#1#
double duration;

double f1(int n, double a[], double x) {
    int i;
    double p = a[0];
    for (i = 1; i < n; i++)
        p += (a[i] * pow(x, i));
    return p;
} //ʱ�临�Ӷ�:O(n^2)

double f2(int n, double a[], double x) {
    int i;
    double p = a[0];
    for (i = n; i > 0; i--)
        p = a[i - 1] + x * p;
    return p;
} //ʱ�临�Ӷ�:O(n)

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

//˫������
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

//ջ
/*typedef struct {
    ElemType data[MAXSIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}*/

/*typedef struct {
    ElemType *data;
    int top; //ջ���������±�
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
        printf("����\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}

int pop(Stack *s, ElemType *e) {
    if (s->top == -1) {
        printf("�յ�\n");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}

int getTop(Stack *s, ElemType *e) {
    if (s->top == -1) {
        printf("�յ�\n");
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

//�ж�ջ�Ƿ�Ϊ��
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
        printf("�յ�\n");
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
        printf("�յ�\n");
        return 0;
    }
    *e = s->next->data;
    return 1;
}*/

//����
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
        printf("�յ�\n");
        return 1;
    } else {
        return 0;
    }
}

ElemType deQueue(Queue *Q) {
    if (Q->front == Q->rear) {
        printf("�յ�\n");
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
        printf("�������\n");
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
        printf("����\n");
        return 0;
    }
    *e=Q->data[Q->front];
    return 1;
}*/

//ѭ������
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
        printf("����\n");
        return 0;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1;
}

int dequeue(Queue *Q, ElemType *e) {
    if (Q->front == Q->rear) {
        printf("�յ�\n");
        return 0;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}

int getHead(Queue *Q,ElemType *e) {
    if (Q->front==Q->rear) {
        printf("�յ�\n");
        return 0;
    }
    *e=Q->data[Q->front];
    return 1;
}*/

/*���е���ʽ�ṹ
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
        printf("�յ�\n");
        return 0;
    }
    return q->front->next->data;
}*/

/*//�ݹ�
int fun(int n) {
    if (n == 1) return 1;
    else return fun(n - 1) + n;
}

int Fibonacci(int n) {
    if (n == 1 || n == 2) return 1;
    else return Fibonacci(n - 1) + Fibonacci(n - 2);
}*/

/*//ö��
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

typedef TreeNode *BiTree; //������ָ��

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

//�������ı���:
//1.ǰ�����
void preOrder(BiTree T) {
    if (T == NULL) {
        return;
    }
    printf("%c ", T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
}

//2.�������
void inOrder(BiTree T) {
    if (T==NULL) {
        return ;
    }
    inOrder(T->lchild);
    printf("%c ",T->data);
    inOrder(T->rchild);
}

//3.�������
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
    printf("%d������", num);
}
else {
    printf("%d��������", num);
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
    p=a;//p�洢����������׵�ַ

    printf("%p\n",p);
    printf("%p\n",a);
    printf("%p\n",&a[0]);
    printf("%d\n",*p);
    printf("\n");

    for (int i=0;i<sizeof(a)/sizeof(a[0]);i++) {
        printf("%d %d\n",a[i],*(p+i));
    }
    //��ָ�����һ������,ʵ���ϼӵ������������ָ���������Ͷ�Ӧ�ֽ����ĳ˻�
    //�������￴��ÿ�μ�1,ʵ��ÿ�μ�4,4��int���ֽ���*/

    /*struct point p;
    p = creatPoint(10, 20);

    struct point *pp;
    pp = &p;
    (*pp).x = 5;
    pp->y = 10; //�ṹ��ָ��
    printf("x=%d,y=%d\n", p.x, p.y);
    printf("x=%d,y=%d\n", pp->x, pp->y);

    P p1;
    p1.x = 2;
    p1.y = 3;*/

    /*int *p1 = malloc(100); //����һ�������ĳ���100�ֽڵĿռ�
    int *p2 = malloc(100 * sizeof(int));
    printf("%p\n", p2);
    printf("%d\n", *p1);

    //��ֵ
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

    //�㷨����
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
    /*���ݽṹ
    1.���Ա�:�ֳ� �б������
    ����:��n������������ͬ��Ԫ�ع��ɵ���������(n����ͬ�������͵�)
    ����������,��������ĳ����ǹ̶���,���б�ĳ����ǿɱ��
    ˳���:��һ���������ڴ浥Ԫ���δ洢���Ա�ĸ���Ԫ��
    Ҳ����˵�߼������ڵ�Ԫ��,����洢�ռ�Ҳ��������*/

    //˳���Ļ�������
    /*Seqlist *list1 = initList();
    printf("��ʼ���ɹ�,Ŀǰ����ռ��%d\n", list1->length);
    printf("Ŀǰռ���ڴ�%zu�ֽ�\n", sizeof(list1->data));
    appendElem(list1, 88);
    appendElem(list1, 45);
    appendElem(list1, 43);
    appendElem(list1, 17);
    listElem(list1);;
    insertElem(list1, 1, 18888);
    listElem(list1);;
    ElemType delData;
    deleteElem(list1, 2, &delData);
    printf("��ɾ����������:%d\n", delData);
    listElem(list1);
    printf("%d\n", findElem(list1, 43));
    free(list1);*/

    //ͷ�巨
    /*Node *list = initList();
    insertHead(list, 10);
    insertHead(list, 20);
    insertHead(list, 30);
    //ͷ�巨��˳������е�˳���Ƿ���
    //���������ͷ�ڵ㲻������,ͷ�巨�Ǵ�ͷ�ڵ����������ݵ�
    listNode(list);
    insertNode(list, 2, 15);
    listNode(list);
    delNode(list, 2);
    listNode(list);
    printf("%d\n", listLength(list));
    freeList(list);
    printf("%d\n", listLength(list));*/

    //β�巨
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

    //ɾ������������ֵΪe�Ľڵ�
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

    //��ת����
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

    //������������
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

    //�ж��Ƿ��л�
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
        printf("�л�");
    }
    else {
        printf("û��");
    }*/

    //�ҵ��������
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
    double a[MAXN]; /* �洢����ʽ��ϵ�� #1#
    a[0]=1;
    for(i=1;i<MAXN;i++)
        a[i]=(double)(1.0/i);
    run(f1,a,1);
    run(f2,a,2);*/

    //˫������
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

    /*ջ�Ͷ���
    ջ(stack):�޶����ڱ�β���в����ɾ�����������Ա�(�Ƚ����)
    β��:ջ��
    ͷ��:ջ��
    ����:��ջ(����),��ջ(ɾ���������Ԫ��)*/

    /*Stack *s = initStack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    ElemType e;
    pop(s, &e);
    printf("ɾȥ��Ԫ����:%d\n", e);

    getTop(s, &e);
    printf("ջ��Ԫ����:%d\n", e);*/

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

    /*����(queue)�Ƚ��ȳ�first in first out(FIFO)
    ��������һ�˳�Ϊ��β(rear),����ɾ����һ�˳�Ϊ��ͷ(front)
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
    printf("����%d\n",e);
    dequeue(q,&e);
    printf("����%d\n",e);
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

    /*������:���ڵ���2������,ÿ���ڵ�����Ķ�Ϊ2
    ����:
    1.��������:
    ���Ϊk,����ڵ����Ϊ2^(k-1),Ҳ����˵���������ȫ������

    2.��ȫ������:
    û��������,������������,
    ��һ��û������,��������һ��

    ����:
    ����n���ڵ����ȫ�����������Ϊlog2(n)+1(����ȡ��)

    �����һ����n���ڵ����ȫ�������Ľڵ㰴������,�������ڵ�i(1<=i<=n)��:
    1.���i=1,��ڵ�i�Ǹ��ڵ�,��˫��
    2.���i>1,����˫�׽ڵ�ı��Ϊi/2(����ȡ��)
    3.���2i<=n,��ڵ�i��������,���������ı��Ϊ2i
    4.���2i>n,��ڵ�i��������
    5.���2i+1<=n,��ڵ�i��������,���������ı��Ϊ2i+1
    6.���2i+1>n,��ڵ�i��������
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
