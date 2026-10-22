#include <stdio.h>
#include <string.h>

int main(void)
{

    int pos = 0, pos_aux = 0;
    char aux[50];
    char nomes[10][50] = {
        "carlos",
        "ana",
        "roberto",
        "beatriz",
        "zuleica",
        "daniel",
        "mariana",
        "felipe",
        "amanda",
        "bruno"};

    for (int i = 0; i < 10 - 1; i++)
    {
        int p = i;
        for (int j = p + 1; j >= 0; j--)
        {
            if (nomes[p][0] > nomes[j][0])
            {
                strcpy(aux, nomes[j]);
                strcpy(nomes[j], nomes[p]);
                strcpy(nomes[p], aux);
                p--;
            }
            else if (nomes[p][0] == nomes[j][0])
            {
                int s = 1;
                for (s; s < strlen(nomes[p]); s++)
                {
                    if (nomes[p][s] != nomes[j][s])
                        break;
                }

                if (nomes[p][s] > nomes[j][s])
                {
                    strcpy(aux, nomes[j]);
                    strcpy(nomes[j], nomes[p]);
                    strcpy(nomes[p], aux);
                }
                p--;
            }
            else
                break;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%s\n", nomes[i]);
    }
}