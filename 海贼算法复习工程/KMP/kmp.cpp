/*
    最优：O(n+m)
    最差：O(nm)
    平均：O(n+m)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST(func, a, b) { \
    printf("%s(%s, %s) = %d\n", #func, a, b, func(a, b)); \
} \

int KMP(char *str, char *pat) {
    int *next = (int *)malloc(sizeof(int) * strlen(pat));
    next[0] = -1;
    // 建立next数组的过程，可看成模板串的自我匹配过程
    // next[i]记录的可以理解为最长公共前后缀的最后一个字符的下标
    for (int i = 1; pat[i]; i++) {
        int j = next[i - 1];
        while (j != -1 && pat[j + 1] != pat[i]) j = next[j];
        if (pat[j + 1] == pat[i]) next[i] = j + 1;
        else next[i] = -1;
    }
    // j + 1 为下一个要匹配的位置
    // 个人理解：因为当发生失配时，内层while循环找到了最后一个能匹配的位置（或者-1），j+1即为下一个要匹配的
    int i = 0, j = -1;
    while (str[i]) {
        while (j != -1 && str[i] != pat[j + 1]) j = next[j];
        if (str[i] == pat[j + 1]) {
            j++;
        }
        i++;
        if (pat[j + 1] == 0) return i - strlen(pat);
    }
    return -1;
}

int main(){
   char str[100], pattern[100];
   while (scanf("%s%s", str, pattern) != EOF) {
       TEST(KMP, str, pattern);
   }
   
   return 0;
}
