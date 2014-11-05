#include <stdio.h>
#include <stdlib.h>
#include<C:\Users\MISTERCRASH\Documents\C\conecta4\conecta4\conecta4\conecta4\conecta4.h>

void main(){
char jugar='y';
do{
    reset();
    a_jugar();
    printf("¿Otra partida?(y/n)\n:");
    fflush(stdin);
    scanf("%c",&jugar);
}while(jugar=='y' || jugar=='Y');
}

void a_jugar(){
 int lector;

    pintar();
while(juego){
        printf("Introduce la columna donde quiera poner su ficha (fichas restantes %d):", n_fichas);
    scanf("%d",&lector);
    while(!meter_ficha(1,lector)){
        scanf("%d", &lector);
    }
    adversario();
     if(comprobar(1)){
        juego=0;
     }else if(comprobar(2)){
     juego=0;
     }
        pintar();

}
        printf("HA GANADO MAMONA!");
        reset();
}
