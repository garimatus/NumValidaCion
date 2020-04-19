#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
//Validar string de carácteres a numero float
void main(){
    char numero[20];
    int i, len, swtch=0;
    float aux, decimales=0, potencia, digitos=0, validado=0;
    printf("Ingrese numero : ");
    gets(numero);
    len=strlen(numero);
    for(i=0;i<len;i++){
        if(isdigit(numero[i])){
            digitos+=1;
        }
        if(numero[i]=='.'){
            swtch+=1;
        }
        if(isdigit(numero[i]) && swtch==1){
            decimales+=1;
        }
    }
    potencia=pow(10,digitos-1);
    if (numero[0]=='-'){
        numero[0]=0;
        potencia*=-1;
    }
    for(i=0;i<len;i++){
        if(isalpha(numero[i]) || isspace(numero[i]) || swtch>1 || numero[i]=='|' || numero[i]=='!' || numero[i]=='"' || numero[i]=='-' || numero[i]=='#' || numero[i]=='$' || numero[i]=='%' || numero[i]=='&' || numero[i]=='/' || numero[i]=='(' || numero[i]==')' || numero[i]=='=' || numero[i]=='?' ||  numero[i]=='¿' || numero[i]=='¡' || numero[i]==','){
            printf("No es un numero valido.\n");
            main();
        }
        if(isdigit(numero[i])){
            aux=numero[i]-48;
            validado+=aux*potencia;
            potencia/=10;
        }
    }
    validado/=pow(10,decimales);
    printf("El numero en formato float es : %f\n",validado);
    main();
}
