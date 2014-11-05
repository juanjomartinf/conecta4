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
int aleatorio (int minimo, int maximo){

    srand((int)time(NULL));
    return rand()%maximo + minimo;

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
void adversario(){
int libre=0, mejor_puntuacion=0, mejor_posicion=0;
int puntuacion[7]={0};
printf("\n Turno del ordenador (le quedan %d fichas)...", n_fichas_ordenador);
for(j=0; j<7; j++){
    while(tabla[libre][j]==0 && tabla[libre+1][j]==0 && libre<6){
        libre++;
    }
    if(comprobar_si(2,libre,j) && j>=0){
        meter_ficha(2,j);
    }else if(comprobar_si(1,libre,j) && j>=0){
        meter_ficha(2,j);
    }else{
    switch(cuantas_fichas_tengo_al_lado(j)){
        case 1:
            puntuacion[j]=1;
            break;
        case 2:
            puntuacion[j]=10;
            break;
        case 3:
            puntuacion[j]=100;
            break;
        case 0:
            puntuacion[j]=0;
            break;
    }

    }
}
mejor_puntuacion=puntuacion[0];
for(i=0; i<7; i++){
    if(mejor_puntuacion<puntuacion[i]){
    mejor_puntuacion=puntuacion[i];
    mejor_posicion=i;
    }
}
if(mejor_puntuacion==0)
    meter_ficha(2,5);
else
    meter_ficha(2,mejor_posicion);


}
int comprobar_si(int ficha, int fila, int columna){

int horizontal=0, vertical=0, diagonal_der=0, diagonal_izq=0;

//HORIZONTAL
for(j=0; j<7; j++){
    if(tabla[fila][j]==ficha || columna==j){
        horizontal++;
    }else if(horizontal!=4){horizontal=0;}
}
if(horizontal!=4)
    horizontal=0;
//VERTICAL
for(i=0; i<6; i++){
    if(tabla[i][columna]==ficha || fila==i){
        vertical++;
    }else if(vertical!=4){vertical=0;}
}
if(vertical!=4)
    vertical=0;
//DIAGONAL DERECHA ----->
for(i=3; i<6; i++){
    for(j=0; j<4; j++){
        if((tabla[i][j]==ficha || (i==fila &&columna==j))&& (tabla[i-1][j+1]==ficha ||(i-1==fila &&columna==j+1)) && (tabla[i-2][j+2]==ficha || (i-2==fila &&columna==j+2)) && (tabla[i-3][j+3]==ficha || (i-3==fila &&columna==j+3) ))
            diagonal_der=1;
    }
}

//DIAGONAL IZQUIERDA <-------
for(i=3; i<6; i++){
    for(j=6; j>2; j--){
         if((tabla[i][j]==ficha || (i==fila &&columna==j))&& (tabla[i-1][j-1]==ficha ||(i-1==fila &&columna==j-1)) && (tabla[i-2][j-2]==ficha || (i-2==fila &&columna==j-2)) && (tabla[i-3][j-3]==ficha || (i-3==fila &&columna==j-3) ))
            diagonal_izq=1;
    }
}
return horizontal+vertical+diagonal_der+diagonal_izq;

}

int cuantas_fichas_tengo_al_lado(int columna){
int libre=0, horizontal=0, vertical=0, diagonal_d=0, diagonal_i=0;
while(tabla[libre][columna]==0 && tabla[libre+1][columna]==0 && libre<6){
    libre++;
}
//HORIZONTAL(Derecha)
for(i=1; i<4 && i+columna!=7 && tabla[libre][columna+i]==2; i++){
        horizontal++;
}
//HORIZONTAL(IZQUIERDA)
for(i=1; i<4 && columna-i!=-1 && tabla[libre][columna-i]==2; i++){
        horizontal++;
}
//VERTICAL
for(i=1; i<4 && libre-i!=-1 &&tabla[libre+i][columna]==2; i++){
        vertical++;
}
if(vertical>horizontal){
        printf("\nFICHAS AL LADO (v)= %d [%d][%d]", vertical, libre, columna);
    return vertical;
}else{
    printf("\nFICHAS AL LADO(h)= %d [%d][%d]", horizontal,libre, columna);
    return horizontal;
}
}
