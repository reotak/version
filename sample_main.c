#include<stdio.h>

/* TO_STRINGでマクロを受け取った場合、文字列化(#)するとマクロ名を文字列化してしまう
 * そのため、一度別なマクロを呼び出して値を渡す必要がある
 * このマクロは、その展開を行った後で文字列化するためのマクロ */
#define __TO_STRING_HELPER(s) #s

/* マクロ名ではなく、マクロの値を文字列化するマクロ */
#define TO_STRING(var) __TO_STRING_HELPER(var) 

int main(void) {
#if defined(GIT_BRANCH)
    printf("GIT_BRANCH: %s\n", TO_STRING(GIT_BRANCH));
#endif

#if defined(GIT_REVISION)
    printf("GIT_REVISION: %s\n", TO_STRING(GIT_REVISION));
#else
    printf("GIT REVISION is unset\n");
#endif

#if defined(GIT_MODIFICATIONS)
    printf("GIT_MODIFICATIONS: %s\n", TO_STRING(GIT_MODIFICATIONS));
#endif

    return 0;
}

