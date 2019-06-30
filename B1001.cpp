//
// Created by Kelper on 6/30/2019.
//
/**
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805325918486528
 * 1001 害死人不偿命的 (3n+1) 猜想 (15 分)
 */
#include <stdio.h>
int main() {

    int n;
    int step = 0;
    scanf("%d", &n);
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = (3 * n + 1) / 2;
        }
        step ++;
    }
    printf("%d", step);
    return 0;
}