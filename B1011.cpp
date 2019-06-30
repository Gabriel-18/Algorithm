//
// Created by Kelper on 6/30/2019.
//
/**
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805312417021952
 * 1011 A+B 和 C (15 分)
 */
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    long long a, b, c;
    int i = 1;
    while (n --) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a + b > c) {
            printf("Case #%d: true\n", i);
        } else {
            printf("Case #%d: false\n", i);
        }
        i++;
    }
    return 0;
}