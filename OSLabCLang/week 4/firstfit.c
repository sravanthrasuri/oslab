#include <stdio.h>

int main() {
    int np, nb;
    printf("Enter the block size and process size: ");
    scanf("%d %d", &nb, &np);
    int b[nb], p[np],ab[nb];

    printf("Enter the block size processes:\n");
    for (int i = 0; i < nb; i++) {
        scanf("%d", &b[i]);
        ab[i]=-1;
    }

    printf("Enter the process size:\n");
    for (int i = 0; i < np; i++) {
        scanf("%d", &p[i]);
    }

    int inf[np];
   
    int a[np];
    int k = 0;  
    int ext_frag = 0;  

    for (int i = 0; i < np; i++) {
        a[i] = -1;
        inf[i] = 0; 
    }

    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nb; j++) {
            if (b[j] >= p[i]&&(ab[j]==-1)) {
                a[i] = j;
                inf[i] = b[j] - p[i];
                b[j]  = b[j]- p[i];
                ab[j]=1;
                
                break;
            }
        }
        k += inf[i];
    }

    for (int i = 0; i < nb; i++) {
        if (ab[i]==-1) {
            ext_frag += b[i];
        }
    }
  int s=ext_frag;
    printf("\nPNo. Process Size   Block no.     Fragmentation\n");
    for (int i = 0; i < np; i++) {
        printf("%d \t%d\t", i + 1, p[i]);
        if (a[i] != -1)
            printf("     %d\t\t%d\n", a[i] + 1, inf[i]);
        else
            printf("Not Allocated \t\t\t-\n");
    }

 
    printf("Internal Fragmentation: %d\n", k);
    printf("External Fragmentation: %d\n", s);

    return 0;
}

