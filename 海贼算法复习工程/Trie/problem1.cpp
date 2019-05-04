/*
    字典树：单词查找，字符串排序
    例题1：计蒜客：Trie树的复习--不同子串的个数
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#define NUM 26
#define BASE 'a'

struct Node {
    int key;
    struct Node *next[NUM];
};
int ans = 0;
Node *newNode() {
    ans++;
    Node *node = (Node *)malloc(sizeof(Node));          // 也可以直接使用calloc，不必手写循环
    for (int i = 0; i < NUM; i++) {
        node->next[i] = NULL;
    }
    node->key = 0;
    return node;
}
// 插入不改变根节点，因此不需要返回值
void insert(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        char c = str[i] - BASE;
        if (p->next[c] == NULL) {
            p->next[c] = newNode();
        }
        p = p->next[c];
    }
    p->key = 1;
}
int search(Node *root, char *str) {
    if (root == NULL) return 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int c = str[i] - BASE;
        if (p->next[c] == NULL) return 0;
        p = p->next[c]; 
    }
    return p->key;                  // 注意这里不能直接返回1，要看这个是否独立成词
} 
int main(){
    char s[100005], sub[100005];
    scanf("%s", s);
    int len = strlen(s);
    Node *root = newNode();
    for (int i = 0; i < len; i++) {
        // 将从i到len长度的子串（即后缀）插入字典树
        strncpy(sub, s + i, len - i);
        sub[len - i] = 0;
        insert(root, sub);
    }
    printf("%d\n", ans - 1);        // 减去根节点
    return 0;
}
