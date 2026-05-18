#include <stdio.h>
#include <string.h>

int main(void)
{

    char compare[] = "exemplo de frase para comparar";
    char toCompare[] = "ra";
    int count = 0;
    int positionSpace = 0;
    int countSteps = 0;

    for (int i = 0; i < strlen(compare); i++)
    {
        if (toCompare[0] == compare[i] || countSteps != 0)
        {
            (toCompare[countSteps] != compare[i]) ? countSteps = 0 : countSteps++;
        }
        if (countSteps == strlen(toCompare))
        {
            count++;
            countSteps = 0;
            if (strlen(toCompare) > 1 && compare[i + 1] == toCompare[1])
                i--;
        }
    }

    printf("%d", count);
}