/*
    字典树：单词查找，字符串排序，词频统计等
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#define NUM 26                      // 若是含大小写字母或者其他字符，按情况调整即可
#define BASE 'a'

struct Node {
    int key;                        // 是否独立成词
    struct Node *next[NUM];         // 26个小写字母，26条边
};
int ans = 0;
Node *newNode() {
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
void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < NUM; i++) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}
int main(){
    Node *root = newNode();
    char str[100];
    int op;
    while (scanf("%d%s", &op, str) != EOF) {
        switch (op) {
            case 1: {
                printf("insert %s to trie\n", str);
                insert(root, str);
            } break;
            case 2: {
                printf("search %s from trie = %d\n", str, search(root, str));
            } break;
        }
    }
    return 0;
}
