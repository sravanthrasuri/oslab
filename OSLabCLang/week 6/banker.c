#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int n, m; // n = number of processes, m = number of resources

void input()
{
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    printf("Enter the available resources:\n");
    for (int j = 0; j < m; j++)
        scanf("%d", &available[j]);

    printf("Enter the maximum resources required by each process:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &maximum[i][j]);

    printf("Enter the resources allocated to each process:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
}

void bankersAlgorithm()
{
    int finish[MAX_PROCESSES];
    for (int i = 0; i < n; i++)
    {
        finish[i] = -1;
    }

    int safeSequence[MAX_PROCESSES];
    int count = 0;

    while (count < n)
    {
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (finish[i] == -1)
            {
                int canAllocate = 1;

                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        canAllocate = 0;
                        break;
                    }
                }

                if (canAllocate)
                {
                    for (int j = 0; j < m; j++)
                    {
                        available[j] += allocation[i][j];
                    }

                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found)
        {
            printf("No safe sequence exists.\n");
            return;
        }
    }

    printf("Safe sequence: ");
    for (int i = 0; i < n - 1; i++)
    {
        printf("P%d -> ", safeSequence[i] + 1);
    }
    printf("P%d\n", safeSequence[n - 1] + 1);
}

int main()
{
    input();
    bankersAlgorithm();

    return 0;
}

