/*
    AC自动机：多模匹配
    即加了失败指针的字典树，字典树+KMP的思想
        当前节点t有fail指针，其fail指针所指向的节点和t所代表的字符是相同的。
        因为t匹配成功后，我们需要去匹配t->child，发现失配，那么就从t->fail这个节点开始再次去进行匹配
    逐层建立失败指针（广度优先搜索）
    例题：给出n个单词，再给出一段文章，找出有多少个单词出现过
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#define NUM 26
#define BASE 'a'

typedef struct Node {
    int flag;
    struct Node *next[NUM];
    struct Node *fail;
} Node;
typedef struct Queue {
    Node **data;
    int head, tail, size;
} Queue;
Queue *init_queue(int n) {
    Queue *q = (Queue *)calloc(sizeof(Queue), 1);
    q->data = (Node **)malloc(sizeof(Node *) * n);
    q->head = q->tail = 0;
    return q;
}
Node *front(Queue *q) {
    return q->data[q->head];
}
void push(Queue *q, Node *node) {
    q->data[q->tail++] = node;
    return ;
}
int empty(Queue *q) {
    return q->head == q->tail;
}
void pop(Queue *q) {
    if (empty(q)) return ;
    q->head++;
    return ;
}
Node *newNode() {
    // Node *p = (Node *)calloc(sizeof(Node), 1);       // 可以直接这样
    Node *node = (Node *)malloc(sizeof(Node));          // 也可以直接使用calloc，不必手写循环
    for (int i = 0; i < NUM; i++) {
        node->next[i] = NULL;
    }
    node->fail = NULL;
    node->flag = 0;
    return node;
}
// 为了构建建立失败指针，返回int来统计字典树中的节点个数
int insert(Node *root, char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        char c = str[i] - BASE;
        if (p->next[c] == NULL) {
            p->next[c] = newNode();
            cnt++;
        }
        p = p->next[c];
    }
    p->flag = 1;
    return cnt;
}
void build_ac(Node *root, int n) {
    Queue *q = init_queue(n + 5);
    root->fail = NULL;
    push(q, root);                      // 开始时先将root入队
    while (!empty(q)) {                 // 站在父节点（建立好了失败指针）去建立子节点的失败指针
        Node *now_node = front(q);
        pop(q);
        for (int i = 0; i < NUM; i++) {
            // 当没有第i个孩子时，无法为其建立失败指针，跳过
            if (now_node->next[i] == NULL) continue;
            Node *p = now_node->fail;
            // 当p非空并且没有第i个孩子时
            while (p && p->next[i] == NULL) p = p->fail;        
            // p有第i个孩子或者p为空
            if (p == NULL) now_node->next[i]->fail = root;
            else now_node->next[i]->fail = p->next[i];
            push(q, now_node->next[i]);
        }
    }
}
int match(Node *root, char *str) {
    // 用来在字典树上匹配的指针
    Node *p = root;
    int cnt = 0;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BASE;
        // 匹配字符str[i]
        while (p && p->next[ind] == NULL) p = p->fail;
        if (p == NULL) p = root;
        else p = p->next[ind];
        Node *q = p;
        // 顺着链走，统计所有匹配到的单词
        while (q) cnt += q->flag, q = q->fail;
    }
    return cnt;
}
int main(){
    Node *root = newNode();
    int n, cnt = 0;                     // 记录字典树有多少节点，用来确定队列大小
    char str[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);               // 读入模式串
        cnt += insert(root, str);
    }
    build_ac(root, cnt);                // 建立失败指针
    scanf("%s", str);                   // 读入文本串
    printf("match word cnt: %d\n",match(root, str));
    return 0;
}
