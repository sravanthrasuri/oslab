#include <stdio.h>

void main() {
    int tef = 0;
    int tlf = 0;
    int np;
    int nb;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of processes: ");
    scanf("%d", &np);

    int b[nb];
    int p[np];
    int a[np];

    printf("Enter the size of the memory blocks:\n");
    for (int i = 0; i < nb; i++) {
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the processes:\n");
    for (int i = 0; i < np; i++) {
        scanf("%d", &p[i]);
    }

    for (int i = 0; i < np; i++) {
        a[i] = -1;
    }

    printf("\nProcess No\tProcess Size \tBlock No\tFragmentation\n");

    for (int i = 0; i < np; i++) {
        int bestFitBlock = -1;

        for (int j = 0; j < nb; j++) {
            if (b[j] >= p[i]) {
                if (bestFitBlock == -1 || b[j] < b[bestFitBlock]) {
                    bestFitBlock = j;
                }
            }
        }

        if (bestFitBlock != -1) {
            a[i] = bestFitBlock;
            int internalFragmentation = b[bestFitBlock] - p[i];
            b[bestFitBlock] -= p[i];
            tlf += b[bestFitBlock];
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, p[i], a[i] + 1, b[a[i]);
        } else {
            tef += p[i];
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, p[i]);
        }
    }

    printf("\nTotal Internal Fragmentation: %d", tlf);
    printf("\nTotal External Fragmentation: %d\n", tef);
}

