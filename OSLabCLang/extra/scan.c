c scan
#include <stdio.h>

void scanr(int v[], int n, int headstart, int tno)
{
    printf("%d ", headstart);
    int v2[n];
    int v3[n];

    int count_v2 = 0, count_v3 = 0;

    for (int i = 0; i < n; i++)
    {
        if (headstart <= v[i])
        {
            v2[count_v2++] = v[i];
        }
        else
        {
            v3[count_v3++] = v[i];
        }
    }

    for (int i = 0; i < count_v2; i++)
    {
        printf("%d ", v2[i]);
    }
    printf("%d ", tno - 1);
    headstart = tno - 1;

    for (int i = 0; i < count_v3; i++)
    {
        printf("%d ", v3[i]);
        headstart = v3[i];
    }

    printf("\n THE total distance is %d\n", headstart);
}

void scanl(int v[], int n, int headstart, int tno)
{
    printf("%d ", headstart);
    int v2[n];
    int v3[n];

    int count_v2 = 0, count_v3 = 0;

    for (int i = 0; i < n; i++)
    {
        if (headstart <= v[i])
        {
            v2[count_v2++] = v[i];
        }
        else
        {
            v3[count_v3++] = v[i];
        }
    }

    for (int i = 0; i < count_v3; i++)
    {
        printf("%d ", v3[i]);
        headstart = v3[i];
    }
    printf("0 ");
    headstart = 0;

    for (int i = 0; i < count_v2; i++)
    {
        printf("%d ", v2[i]);
        headstart = v2[i];
    }

    printf("\n THE total distance is %d\n", headstart);
}

int main()
{
    printf("\n enter the no.of tracks: ");
    int n, tno;
    scanf("%d", &n);
    printf("enter the total no of tracks");
    scanf("%d", &tno);
    int v[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    printf("\nEnter the head start position: ");
    int headstart;
    scanf("%d", &headstart);
    printf("\nENter the direction :\n1 for right\n2 for left\n");
    int d;
    scanf("%d", &d);

    switch (d)
    {
    case 1:
    {
        scanr(v, n, headstart, tno);
        break;
    }

    case 2:
    {
        scanl(v, n, headstart, tno);
        break;
    }
    default:
        printf("invalid");

    }

    return 0;
}


#include <stdio.h>

void scanr(int v[], int n, int headstart, int tno)
{
    printf("%d ", headstart);
    int v2[n];
    int v3[n];

    int count_v2 = 0, count_v3 = 0;

    for (int i = 0; i < n; i++)
    {
        if (headstart <= v[i])
        {
            v2[count_v2++] = v[i];
        }
        else
        {
            v3[count_v3++] = v[i];
        }
    }

    for (int i = 0; i < count_v2; i++)
    {
        printf("%d ", v2[i]);
    }

    for (int i = 0; i < count_v3; i++)
    {
        printf("%d ", v3[i]);
    }

    int totalheadmovement = 0;
    for (int i = 0; i < count_v2; i++)
    {
        totalheadmovement += abs(v2[i] - headstart);
        headstart = v2[i];
    }

    for (int i = 0; i < count_v3; i++)
    {
        totalheadmovement += abs(v3[i] - headstart);
        headstart = v3[i];
    }

    printf("\n THE total distance is %d\n", totalheadmovement);
}

void scanl(int v[], int n, int headstart, int tno)
{
    printf("%d ", headstart);
    int v2[n];
    int v3[n];

    int count_v2 = 0, count_v3 = 0;

    for (int i = 0; i < n; i++)
    {
        if (headstart <= v[i])
        {
            v2[count_v2++] = v[i];
        }
        else
        {
            v3[count_v3++] = v[i];
        }
    }

    for (int i = 0; i < count_v3; i++)
    {
        printf("%d ", v3[i]);
    }

    printf("0 ");

    for (int i = 0; i < count_v2; i++)
    {
        printf("%d ", v2[i]);
    }

    int totalheadmovement = 0;
    for (int i = 0; i < count_v3; i++)
    {
        totalheadmovement += abs(v3[i] - headstart);
        headstart = v3[i];
    }

    for (int i = 0; i < count_v2; i++)
    {
        totalheadmovement += abs(v2[i] - headstart);
        headstart = v2[i];
    }

    printf("\n THE total distance is %d\n", totalheadmovement);
}

int main()
{
    printf("\n enter the no.of tracks: ");
    int n, tno;
    scanf("%d", &n);
    printf("enter the total no of tracks");
    scanf("%d", &tno);
    int v[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    printf("\nEnter the head start position: ");
    int headstart;
    scanf("%d", &headstart);
    printf("\nENter the direction :\n1 for right\n2 for left\n");
    int d;
    scanf("%d", &d);

    switch (d)
    {
    case 1:
    {
        scanr(v, n, headstart, tno);
        break;
    }

    case 2:
    {
        scanl(v, n, headstart, tno);
        break;
    }
    default:
        printf("invalid");
    }

    return 0;
}


printf("\n THE total distance is %d\n", totalheadmovement);

