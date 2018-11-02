#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <cassert>
#include <algorithm>

extern "C" {
#include "qsort.h"
}

struct Node {
    int id;
    char s[12];

    bool operator<(const Node &other) const {
        return id < other.id;
    }
};

int compare_Node(const void *a, const void *b) {
    return ((const Node *)a)->id - ((const Node *)b)->id;
}

int compare_int(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
test:
    size_t seed = time(NULL) ^ clock();
    printf("%lu\n", seed);
    srand(seed);
    int n = rand() % 400000 + 1;
    scanf("%d", &n);

    // int range = rand() % 1000 + 1;

    int a[n];
    // for (int i = 0; i < n; i++) a[i] = rand() % range;
    for (int i = 0; i < n; i++) a[i] = rand();
    // for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    // for (int i = 0; i < n; i++) printf("%d\n", a[i]);

    // _qsort(a, n, sizeof(int), compare_int);
    qsort(a, n, sizeof(int), compare_int);
    // std::sort(a, a + n);

    // for (int i = 0; i < n; i++) printf("%d%c", a[i], " \n"[i == n - 1]);
    assert(std::is_sorted(a, a + n));

    puts("AC");
    // goto test;
}
