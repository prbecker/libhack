#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libhack.h"

typedef struct {
   int i;
   int j;
   char* c;
} Hackeado;

//*************************************************************************************************************************************************************************
void vetorToString(int vetor[], char* string, int tamanho)
{
    int  i = 0, flag=0, contador=0;
    char vetorInvert[1000] = "";

    for(i=0;i<tamanho;i++)
    {
        while(flag==0)
        {
            if(vetor[contador] != 0 )
            {
                flag = 1;
            }
            else
            {
               contador++;
            }
        }
        if ((i+contador) <= tamanho)
        {
            switch(vetor[contador+i])
            {
                case 0: vetorInvert[i] = '0'; break;
                case 1: vetorInvert[i] = '1'; break;
                case 2: vetorInvert[i] = '2'; break;
                case 3: vetorInvert[i] = '3'; break;
                case 4: vetorInvert[i] = '4'; break;
                case 5: vetorInvert[i] = '5'; break;
                case 6: vetorInvert[i] = '6'; break;
                case 7: vetorInvert[i] = '7'; break;
                case 8: vetorInvert[i] = '8'; break;
                case 9: vetorInvert[i] = '9'; break;
            }
        }
    }
    strcpy(string, vetorInvert);
}
//*************************************************************************************************************************************************************************
void copystring(char* stringa, char* stringb)
{
    char vetorInvert[1000] = "";
    int tamanho=0,i=0;
    tamanho=strlen(stringb);
    for(i=0;i<tamanho;i++)
    {
        vetorInvert[i] = stringb[i];
    }

    strcpy(stringa,vetorInvert);
}
//*************************************************************************************************************************************************************************
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
//*************************************************************************************************************************************************************************
int multiplica (int vetor1[], int vetor2[], int vetorfinal[], int tamanho1, int tamanho2)
{
    int i=0, j=0, maior=0, buffer=0, aux=0, menor=0, contador=0;
    maior = tamanho1;
    menor = tamanho2;
    int vetortemp[maior+1];
    for(i=0; i<tamanho1+1; i++)
    {
        vetortemp[i] = 0;
    }
    for(i=0; i<tamanho1+tamanho2; i++)
    {
        vetorfinal[i] = 0;
    }
    for(i=(menor-1); i>=0; i--)
    {
        for(j=(maior-1); j>=0; j--)
        {
            aux = vetor1[j] * vetor2[i] + buffer;
            buffer = aux / 10;
            aux = aux % 10;
            vetortemp[j+1] = aux;
        }
        vetortemp[0] = buffer;
        buffer = 0;
        for(j=(tamanho1+tamanho2)-1; j>=0 ; j--)
        {
            if(j-menor+1 >= 0)
            {
                aux = vetorfinal[j-contador] + vetortemp[j-menor+1] + buffer;
                buffer = aux/10;
                aux = aux%10;
                vetorfinal[j-contador] = aux;
            }
        }
        contador = contador + 1;
        buffer = 0;
    }
    return 0;
}
//*************************************************************************************************************************************************************************
int stringtovetor (char* string, int vetor[])
{
    int n=0, i=0;
    n = strlen(string);
    for(i=0;i<n;i++)
    {
        switch(string[i])
        {
            case '0': vetor[i] = 0; break;
            case '1': vetor[i] = 1; break;
            case '2': vetor[i] = 2; break;
            case '3': vetor[i] = 3; break;
            case '4': vetor[i] = 4; break;
            case '5': vetor[i] = 5; break;
            case '6': vetor[i] = 6; break;
            case '7': vetor[i] = 7; break;
            case '8': vetor[i] = 8; break;
            case '9': vetor[i] = 9; break;
        }
    }
    return 0;
}
 //************************************************************************************************************************************************************************
void intToString(int valor, char* string)
{
    int digito = 0, i = 0, j = 0;
    char vetorInvert[10000] = "";
    char resposta[10000] = "";

    while(valor > 0)
    {
        digito = valor % 10;
        vetorInvert[i] = digito + '0';
        valor = valor / 10;
        i++;
    }

    for(j=0; j <strlen(vetorInvert); j++)
    {
        resposta[strlen(vetorInvert)-1-j] = vetorInvert[j];
    }

    strcpy(string, resposta);
}
//****************************************************************************************************************************************************************************
void encontraPrimo(int n, char* stringA) //encontra o maior primo
{
    int i, j, divisor = 0, digito = 0;
    char vetorInvert[1000] = "";
    long valor;
    char resposta[1000]= "";


    valor = atoi(stringA);
    for (i = 2; i <= valor; i++)
    {
        if(valor % i == 0)
        {
            divisor = i;
            while((valor/=i) % i == 0);
        }
    }
    i = 0;
    while(divisor > 0)
    {
        digito = divisor % 10;
        vetorInvert[i] = digito + '0';
        divisor = divisor / 10;
        i++;
    }

    for(j=0; j < strlen(vetorInvert); j++)
    {
        resposta[strlen(vetorInvert)-1-j] = vetorInvert[j];
    }
    strcpy(stringA,resposta);
}
//*****************************************************************************************************************************************************
void encontraSeq(int n, char* stringA, char* stringB)
{
    int i = 0, j = 0, k=0, l=0;
    int tam = 0, maior = 0;
    int posi_maior = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(stringA[i-1] != stringB[j-1] && stringA[i] == stringB[j])
            {
                tam = 0;
                k = i;
                l = j;
                while(stringA[k]==stringB[l] && k<n && l<n)
                {
                    tam++;
                    k++;
                    l++;
                }
                if(tam > maior)
                {
                    maior = tam;
                    posi_maior = i;
                }
            }
        }
    }
    i = posi_maior;
    j=0;
    char resposta[10000] = "";
    while(j<maior)
    {
        resposta[j] = stringA[i];
        j++;
        i++;
    }
    strcpy(stringA,resposta);
}
//**********************************************************************************************************************************************************
int main(int argc, char** argv)
{
    setHackerName("Gunt3r_XML_F4t0r14l");

    char** map = readMap(); //O mapa é lido para a variável map como uma matriz 2D de caracteres.
    printMap(); //Imprime o mapa

    hackerSpeak("glhf"); //Na arena, essa função vai mostrar um balão de fala em cima do hacker. Use sabiamente.

    int cols = getMapCols();
    int rows = getMapRows();
    Problem2 problemasensor;
    Problem2 problemaporta;
    Problem1 problemacomputer;
    char* chave;
    char* p;
    char* q;
    int i=0, j=0;
    char agoravai;
    char agoravai2;
    char agoravai3;

    int doorCol = -1;
    int doorRow = -1;
    int k = 0;
    int distsenstemp;
    int distporta = getDistance(doorRow,doorCol, getHackerRow(),getHackerCol()); //Você pode usar essa função para avaliar a distância.
    int distsens = distporta;
    int flagporta = 0;

    int sensCol = -1;
    int sensRow = -1;
    int sensColtemp = -1;
    int sensRowtemp = -1;
    int jafoihack = 0;
    int EOQ = 0;
    int tamanho1=0,tamanho2=0,tamanhofinal=0;
    Hackeado jafoihackeadosensor[100];
    Hackeado jafoihackeadocomputer[100];

    for (jafoihack=0; jafoihack <100; jafoihack++)
    {
        jafoihackeadosensor[jafoihack].i = 0;
        jafoihackeadosensor[jafoihack].j = 0;
        jafoihackeadocomputer[jafoihack].i = 0;
        jafoihackeadocomputer[jafoihack].j = 0;
    }
    while(flagporta == 0)
    {
        sensColtemp = -1;
        sensRowtemp = -1;
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                if (map[i][j] == DOOR)
                {
                    doorCol = j;
                    doorRow = i;
                    break;
                }
            }
        }
        distporta = getDistance(doorRow,doorCol, getHackerRow(),getHackerCol());
        distsens = distporta;
        for (i = 1; i < rows; i++)
        {
            for (j = 1; j < cols; j++)
            {
                jafoihack = 0;
                if (map[i][j] == SENSOR)
                {
                    sensColtemp = j;
                    sensRowtemp = i;
                    distsenstemp = getDistance(sensRowtemp,sensColtemp, getHackerRow(),getHackerCol());
                    for (k=0; k<100; k++)
                    {
                        if (jafoihackeadosensor[k].i==sensRowtemp && jafoihackeadosensor[k].j==sensColtemp)
                        {
                            jafoihack = 1;
                        }
                    }
                    if (distsenstemp < distsens && jafoihack == 0)
                    {
                        distsens = distsenstemp;
                        sensCol = sensColtemp;
                        sensRow = sensRowtemp;
                    }
                }
            }
        }
        jafoihack = 0;
        if (distporta > distsens)
        {
            moveHackerTo(sensRow,sensCol); //Movendo até o sensor mais proximo.
            problemasensor = inspectSensor(sensRow,sensCol);
            encontraPrimo(problemasensor.n, problemasensor.a);
            chave = problemasensor.a;
            hackSensor(sensRow, sensCol, chave);
            hackerSpeak("Windows>Linux");
            k=0;
            while(jafoihack==0)
            {
                if (jafoihackeadosensor[k].i==0 && jafoihackeadosensor[k].j==0)
                {
                    jafoihack = 1;
                    jafoihackeadosensor[k].i=sensRow;
                    jafoihackeadosensor[k].j=sensCol;
                }
                k++;
            }
        }
        else
        {
            moveHackerTo(doorRow,doorCol); //Movendo até a porta.
            problemaporta = inspectDoor(doorRow,doorCol); //Inspecionando a porta para ter acesso ao problema.
            flagporta = 1;
        }
    }
    int flagq = 0;
    int flagp = 0;
    sensCol = -1;
    sensRow = -1;
    int sensorcomp = -1;
    while (flagq==0 && flagp==0)
    {
        sensColtemp = -1;
        sensRowtemp = -1;
        distsens = 10000;
        sensorcomp = 0;
        for (i = 1; i < rows; i++)
        {
            for (j = 1; j < cols; j++)
            {
                jafoihack = 0;
                if ((map[i][j] == SENSOR) || (map[i][j] == COMPUTER))
                {
                    sensColtemp = j;
                    sensRowtemp = i;
                    distsenstemp = getDistance(sensRowtemp, sensColtemp, getHackerRow(),getHackerCol());
                    if (map[i][j]==SENSOR)
                    {
                        for (k=0; k<100; k++)
                        {
                            if (jafoihackeadosensor[k].i==sensRowtemp && jafoihackeadosensor[k].j==sensColtemp)
                            {
                                jafoihack = 1;
                            }
                        }
                    }
                    if (map[i][j]==COMPUTER)
                    {
                        for (k=0; k<100; k++)
                        {
                            if (jafoihackeadocomputer[k].i==sensRowtemp && jafoihackeadocomputer[k].j==sensColtemp)
                            {
                                jafoihack = 1;
                            }
                        }
                    }
                    if ((distsenstemp < distsens) && jafoihack == 0 && distsens != 0)
                    {
                        distsens = distsenstemp;
                        sensCol = sensColtemp;
                        sensRow = sensRowtemp;
                        if (map[sensRow][sensCol]==SENSOR)
                        {
                            sensorcomp = 1;
                        }
                        if (map[sensRow][sensCol]==COMPUTER)
                        {
                            sensorcomp = 2;
                        }
                    }
                }
            }
        }
        jafoihack = 0;
        if (sensorcomp == 1)
        {
            moveHackerTo(sensRow,sensCol); //Movendo até o sensor mais proximo.
            problemasensor = inspectSensor(sensRow,sensCol);
            encontraPrimo(problemasensor.n, problemasensor.a);
            chave = problemasensor.a;
            hackSensor(sensRow, sensCol, chave);
            hackerSpeak("Poe no Hard");
            k=0;
            while(jafoihack==0)
            {
                if (jafoihackeadosensor[k].i==0 && jafoihackeadosensor[k].j==0)
                {
                    jafoihack = 1;
                    jafoihackeadosensor[k].i=sensRow;
                    jafoihackeadosensor[k].j=sensCol;
                }
                k++;
            }
        }
        jafoihack = 0;
        if (sensorcomp == 2)
        {
            moveHackerTo(sensRow,sensCol); //Movendo até o computador mais proximo.
            problemacomputer = inspectComputer(sensRow, sensCol);
            encontraSeq(problemacomputer.n, problemacomputer.a, problemacomputer.b);
            chave = problemacomputer.a;
            hackComputer(sensRow, sensCol, chave);
            hackerSpeak("S-O-L-A-D-O");
            k=0;
            tamanhofinal = strlen(problemaporta.a);
            while(jafoihack==0)
            {
                if (jafoihackeadocomputer[k].i==0 && jafoihackeadocomputer[k].j==0)
                {
                    jafoihack = 1;
                    jafoihackeadocomputer[k].i=sensRow;
                    jafoihackeadocomputer[k].j=sensCol;
                    jafoihackeadocomputer[k].c=chave;
                    EOQ = 0;
                    tamanho1 = strlen(jafoihackeadocomputer[k].c);
                    while(EOQ < k)
                    {
                        tamanho2 = strlen(jafoihackeadocomputer[EOQ].c);
                        if(tamanho1+tamanho2 == tamanhofinal || tamanho1+tamanho2-1 == tamanhofinal)
                        {
                            int vetor1[tamanho1];
                            int vetor2[tamanho2];
                            stringtovetor(jafoihackeadocomputer[k].c,vetor1);
                            stringtovetor(jafoihackeadocomputer[EOQ].c,vetor2);
                            int vetorfinal[tamanho1+tamanho2];
                            multiplica(vetor1,vetor2,vetorfinal,tamanho1,tamanho2);
                            agoravai = vetorfinal[0] + '0';
                            agoravai2 = vetorfinal[1] + '0';
                            agoravai3 = vetorfinal[2] + '0';
                            if ((agoravai2 == problemaporta.a[0] && agoravai3 == problemaporta.a[1]) || (agoravai == problemaporta.a[0] && agoravai2 == problemaporta.a[1]))
                            {
                                vetorToString(vetorfinal, problemacomputer.b, tamanho1+tamanho2);
                                chave = problemacomputer.b;
                                if ((strncmp(chave,problemaporta.a,tamanhofinal)==0) || (strcmp(chave,problemaporta.a))==0)
                                {
                                    flagp = 1;
                                    flagq = 1;
                                    p = jafoihackeadocomputer[EOQ].c;
                                    q = jafoihackeadocomputer[k].c;
                                    break;
                                }
                            }
                        }
                        EOQ++;
                        if (flagp == 1)
                        {
                            break;
                        }
                    }
                }
                k++;
            }
        }
    }
    moveHackerTo(doorRow,doorCol);
    hackerSpeak("GGWP(easy)");
    if (strlen(p) > strlen(q))
    {
        hackDoor(doorRow,doorCol,p);
    }
    else
    {
        hackDoor(doorRow,doorCol,q);
    }
    return 0;
}
