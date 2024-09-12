#include <stdio.h>

int recursion (int previousNum, int previousStart, int step, int c, int* used)
{
    int sum = 0;
}

int main(void)
{
    int numCases;
    int i;
    int j;
    int c;
    int* used;

    scanf("%d", &numCases);
    
    for (i = 0; i < numCases; i++)
    {
        scanf("%d", &c);

        if(c == 1)
        {
            printf("0\n");
        }
        else
        {
            used = malloc(sizeof(int) * (c * 2));
            for (j = 0; j < c  * 2; j++)
            {
                used[j] = 0;
            }

            printf("%d\n", recursion(0, -1, 2, c, used));
        }
    }

}