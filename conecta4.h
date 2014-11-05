int juego=1;
int tabla[6][7]={0};
int i,j, col=0, fil=0;
int ganador=0;
int n_fichas=21, n_fichas_ordenador=21;
void reset(){
for(i=0; i<6; i++){
    for(j=0; j<7; j++){
        tabla[i][j]=0;}}
n_fichas=n_fichas_ordenador=21;
juego=1;
ganador=0;
}
void pintar(){
    for(i=0; i<100; i++)
        printf("\n\n\n");

printf("\t");
    for(col=0; col<7; col++){
        printf(" %d\t", col);
    }
    printf("\n");


for(i=0; i<6; i++){
    printf("\n\n \t");
    for(j=0; j<7; j++){
        if(tabla[i][j]==0){
            printf("[ ]\t");
        }else if(tabla[i][j]==1){
            printf("[X]\t");
        }else{
            printf("[O]\t");
        }
    }
}
printf("\n\n\n\n");


}
void limpiar_tablero(){
    for(i=0; i<6; i++){
        for(j=0; j<7; j++){
            tabla[i][j]=0;
        }
    }
}
int aleatorio (){
    int secreto;

    srand((int)time(NULL));
    secreto = rand()%2 + 1;
    printf("\tsecreto: %d",secreto);

    return secreto;
}
int comprobar(int ficha){

//COMPROBAMOS EN HORIZONTAL
for(i=0; i<6; i++){
    for(j=0; j<4; j++){
        if(tabla[i][j]==ficha && tabla[i][j+1]==ficha && tabla[i][j+2]==ficha && tabla[i][j+3]==ficha)
            ganador=1;
}}
//COMPROBAMOS EN VERTICAL
for(j=0; j<7; j++){
    for(i=5; i>2; i--){
        if(tabla[i][j]==ficha && tabla[i-1][j]==ficha && tabla[i-2][j]==ficha && tabla[i-3][j]==ficha){
            ganador=1;}
    }
}
//COMPROBAMOS EN DIAGONAL

//HACIA LA DERECHA
for(i=3; i<6; i++){
    for(j=0; j<4; j++){
        if(tabla[i][j]==ficha && tabla[i-1][j+1]==ficha && tabla[i-2][j+2]==ficha && tabla[i-3][j+3]==ficha )
            ganador=1;
    }
}

//HACIA LA IZQUIERDA
for(i=3; i<6; i++){
    for(j=6; j>2; j--){
        if(tabla[i][j]==ficha && tabla[i-1][j-1]==ficha && tabla[i-2][j-2]==ficha && tabla[i-3][j-3]==ficha )
            ganador=1;
    }
}

return ganador;

}
int meter_ficha(int ficha, int columna){
i=0;
if(columna<7 && columna>=0){
if(!tabla[i][columna]){
    while(!tabla[i][columna] && !tabla[i+1][columna] && i<5){
        i++;
    }
    tabla[i][columna]=ficha;
    if(ficha==1){
        n_fichas--;
    }else{
        n_fichas_ordenador--;
    }return 1;
}else{
printf("La columna esta llena, seleccione otra.\n");
return 0;
}
}}

int comprobar_si(int ficha, int fila, int columna){
int horizontal=0, vertical=0, diagonal_der=0, diagonal_izq=0;
//HORIZONTAL
for(j=0; j<7; j++){
    if(tabla[fila][j]==ficha || columna==j){
        horizontal++;
    }else if(horizontal!=4){horizontal=0;}
}
//VERTICAL
for(i=0; i<6; i++){
    if(tabla[i][columna]==ficha || fila==i){
        vertical++;
    }else if(vertical!=4){vertical=0;}
}

//DIAGONAL DERECHA



}
