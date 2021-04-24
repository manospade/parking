#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// manos pantermarakis am:2018087

#define M 40  // thesis mixanwn
#define A 200 // theseis autokinitwn

int checkIfVehicleIsOn(char oximata[][10], char arithmosKukloforias[10], int typosOximatos)
{
    int thesi = -1;
    if (typosOximatos == 1)
    {
        //autokinito
        for (int i = 0; i < A; i++)
        {
            if (strcmp(oximata[i], arithmosKukloforias) == 0)
            {
                //vrethike mesa
                thesi = i;
                break;
            }
        }
    }else{
        //mixani
        for (int i = 0; i < M; i++)
        {
            if (strcmp(oximata[i], arithmosKukloforias) == 0)
            {
                //vrethike mesa
                thesi = i;
                break;
            }
        }
    }
    return thesi;
}

int main()
{
    char autokinita[A][10];
    char mixanes[M][10];
    char arithmosKukloforias[10];
    int typosOximatos;
    int thesi;
    int tameio = 0;
    for (int i = 0; i < A; i++)
    {
        autokinita[i][0] = 0;
    }
    for (int i = 0; i < M; i++)
    {
        mixanes[i][0] = 0;
    }

    printf("\n==== WELCOME TO PARKING ==== \n\n");
    while (1)
    {
        printf("=> Dwse arithmo kukloforias mexri 10 psifia p.x HRT4041: ");
        scanf("%s", arithmosKukloforias);
        if (strcmp(arithmosKukloforias, "end") == 0)
        {
            break;
        }
        printf("=> Dwse typo oximatos (1:autokinito, 2:mixani): ");
        scanf("%d", &typosOximatos);
        if (typosOximatos == 1)
        {
            // GIA AUTOKINITO
            thesi = checkIfVehicleIsOn(autokinita, arithmosKukloforias, typosOximatos);
            if (thesi < 0)
            {
                printf("\nden uparxei");
                //to amaxi den uparxei sto parking
                for (int i = 0; i < A; i++)
                {
                    if (autokinita[i][0] == 0)
                    {
                        printf("\nMPIKEEE");
                        strcpy(autokinita[i], arithmosKukloforias);
                        break;
                    }
                }
            }
            else
            {
                printf("\nuparxei");
                strcpy(autokinita[thesi], "0");
                tameio = tameio + 10;
            }
        }
        else if (typosOximatos == 2)
        {
            // GIA MIXANI
            thesi = checkIfVehicleIsOn(mixanes, arithmosKukloforias, typosOximatos);
            if (thesi < 0)
            {
                printf("\nden uparxei");
                //to mixanaki den uparxei sto parking
                for (int i = 0; i < M; i++)
                {
                    if (mixanes[i][0] == 0)
                    {
                        printf("\nMPIKEEE");
                        strcpy(mixanes[i], arithmosKukloforias);
                        break;
                    }
                }
            }
            else
            {
                printf("\nuparxei");
                strcpy(mixanes[thesi], "0");
                tameio = tameio + 4;
            }
        }
        else
        {
            printf("\nMi eguros typos oximatos\n");
        }
    }
    printf("\n\nEISPRAXEIS: %d", tameio);
    printf("\nKENES THESEIS GIA AUTOKINITA: { ");
    for (int i = 0; i < A; i++)
    {
        if (autokinita[i][0] == 0)
        {
            printf("%d, ", i);
        }
    }
    printf(" }\n");
    printf("\nKENES THESEIS GIA MIXANES: { ");
    for (int i = 0; i < M; i++)
    {
        if (mixanes[i][0] == 0)
        {
            printf("%d, ", i);
        }
    }
    printf(" }\n");
    printf("\n==== GOODBYE ==== \n\n");
    return 0;
}
