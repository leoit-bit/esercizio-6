#include <stdio.h>
#include <math.h>
#include <string.h>


int main(void){
    FILE *fp, *fout;
    char string;
    float op1, op2;
    char operazione;

    fp = fopen("C:\\Users\\leoit\\Desktop\\Laboratorio Tecniche di programmazione\\Lab1\\esercizio_6\\Operations.txt", "r");
    fout = fopen("C:\\Users\\leoit\\Desktop\\Laboratorio Tecniche di programmazione\\Lab1\\esercizio_6\\risultato.txt", "w");

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (!feof(fp)){
        fscanf(fp, "%c %f %f \n", &operazione, &op1, &op2);
        //printf("%c %f %f \n", operazione, op1, op2);

        switch(operazione)
        {
            case '+': fprintf(fout, "%c %.2f1 \n", operazione,op1 + op2); break;
            case '-': fprintf(fout, "%c %.2f \n", operazione, op1 - op2); break;
            case '*': fprintf(fout, "%c %.2f \n",operazione, op1 * op2); break;
            case '/':
                if (op2 != 0){
                    fprintf(fout, "%c %.2f",operazione, op1 / op2); break;
                }
                else{
                    fprintf(fout, "Non \212 possibile dividere un numero per 0 \n"); break;
                }
            default: fprintf(fout, "Non \212 possibile eseguire l'operazione. \n"); break;
        }
    }

    fclose(fp);
    fclose(fout);
    return 0;
}