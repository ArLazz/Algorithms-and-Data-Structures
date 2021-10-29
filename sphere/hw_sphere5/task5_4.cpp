#include <stdio.h>
#include <stdlib.h>

struct t_n {
    struct t_n *left;
    struct t_n *right;
};

void insert(struct t_n *n, unsigned x) {
    for (unsigned m = (1u << (8*sizeof(unsigned int) - 1)); m != 0; m >>= 1) {
        if ((m & x) == 0) {
            if (n->left == NULL) {
                n->left = (struct t_n *) malloc(sizeof(struct t_n));
                (n->left)->left = NULL;
                (n->left)->right = NULL;
            }
            n = n->left;
        } else {
            if (n->right == NULL) {
                n->right = (struct t_n *) malloc(sizeof(struct t_n));
                (n->right)->left = NULL;
                (n->right)->right = NULL;
            }
            n = n->right;
        }
    }
}

unsigned d1(struct t_n *n, unsigned x, unsigned m) {
    if (((m & x) == 0) && (n->left != NULL)) {
        int d = d1(n->left, x, m >> 1);
        if ((d == 1) && (n->right == NULL)) {
            free(n);
            return 1;
        } else {
            if (d) {
                n->left = NULL;
            }
            return 0;
        }
    } else if (((m & x) > 0) && (n->right != NULL)) {
        int d = d1(n->right, x, m >> 1);
        if ((d == 1) && (n->left == NULL)) {
            free(n);
            return 1;
        } else {
            if (d) {
                n->right = NULL;
            }
            return 0;
        }
    } else {
        if ((n->left == NULL) && (n->right == NULL)) {
            free(n);
            return 1;
        } else {
            return 0;
        }
    }
}

unsigned max_xor(struct t_n *n, unsigned x, unsigned m) {
    if ((m & x) == 0) {
        if (n->right != NULL) {
            return m | max_xor(n->right, x, m >> 1);
        } else if (n->left != NULL) {
            return max_xor(n->left, x, m >> 1);
        } else {
            return 0;
        }
    } else {
        if (n->left != NULL) {
            return max_xor(n->left, x, m >> 1);
        } else if (n->right != NULL) {
            return m | max_xor(n->right, x, m >> 1);
        } else {
            return 0;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct t_n *r = (struct t_n *) malloc(sizeof(struct t_n));
    r->left = NULL;
    r->right = NULL;
    for (int i = 0; i < n; i++) {
        unsigned k, x;
        scanf("%u %u", &k, &x);
        if (k == 1) {
            insert(r, x);
        } else if (k == 2) {
            unsigned m = 1 << (8*sizeof(unsigned int) - 1);
            d1(r, x, m);
        } else if (k == 3) {
            unsigned m = 1 << (8*sizeof(unsigned int) - 1);
            printf("%u\n", max_xor(r, x, m));
        }
    }
}