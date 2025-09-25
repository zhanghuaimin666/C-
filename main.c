#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAXN 101  /* 多项式最大项数，即多项式次数+1*/
#define MAXK 1e5 /* 被测函数最大重复调用次数*/


int judgerpnm(int year) {
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

#define MAXSIZE 100
typedef int ElemType;

struct book {
    int isbn;
    char bookName[20];
    double price;
};

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

typedef struct node {
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

void listNode(Node *L) {
    Node *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

clock_t start,end;
/* clock_t 是 clock()函数返回的变量类型*/
double duration;

double f1(int n,double a[],double x){
    int i;
    double p=a[0];
    for(i=1;i<n;i++)
        p+=(a[i]*pow(x,i));
    return p;
}//时间复杂度:O(n^2)

double f2(int n,double a[],double x){
    int i;
    double p=a[0];
    for(i=n;i>0;i--)
        p=a[i-1]+x*p;
    return p;
}//时间复杂度:O(n)

void run(double(*f)(int n,double *,double ),double a[],int func_n){
    int i;
    start = clock();
    for(i=0;i<MAXK;i++)
        f(MAXN-1,a,1.1);
    end = clock();
    duration = ((double)(end-start))/CLK_TCK;
    printf("ticks%d=%f\n",func_n,(double)(end-start));
    printf("duration%d=%6.2e\n",func_n,duration);
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
    printf("%d\n", x);*/

    /*数据结构
    1.线性表:分成 列表和链表
    定义:由n个数据特性相同的元素构成的有限序列(n个相同数据类型的)
    类似于数组,但是数组的长度是固定的,而列表的长度是可变的
    顺序表:用一组连续的内存单元依次存储线性表的各个元素
    也就是说逻辑上相邻的元素,物理存储空间也是连续的*/

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
    listNode(reverse);*/;

    /*int i;
    double a[MAXN]; /* 存储多项式的系数 #1#
    a[0]=1;
    for(i=1;i<MAXN;i++)
        a[i]=(double)(1.0/i);
    run(f1,a,1);
    run(f2,a,2);*/

    printf("Hello world");

    return 0;
}
