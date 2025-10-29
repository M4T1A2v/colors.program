/*
Cargar un vector de N elementos con valores ingresados por el usuario. V

Mostrar por pantalla los elementos del vector. V

Calcular y mostrar la suma de todos los elementos del vector. V

Buscar un número en el vector e indicar si se encuentra y en qué posición. V

Mostrar el vector en orden inverso (del último al primero). V

Calcular y mostrar el promedio de los valores del vector. V

Contar cuántos elementos del vector son pares e impares. V

Ordenar los numero del menor al mayor. V

Crear un segundo vector que contenga solo los elementos pares del primero. V

Determinar el mayor y el menor valor del vector.

Contar cuántas veces se repite un número ingresado por el usuario.

Verificar si el vector está ordenado en forma ascendente.

Copiar un vector en otro, pero en orden invertido.

Sumar dos vectores y guardar el resultado en un tercer vector.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cantidad 15

struct colores{
    short num;
    char nombre[22];
};

short sumar(short, short);
float promediar( float );
short impares( short );
short pares( short );

int main(void){
    
    struct colores color[cantidad] = { {10,"AZUL"},{32,"ROJO"},{54,"VERDE"},{87,"AMARILLO"},{70,"NARANJA"},{13,"VIOLETA"},{41,"NEGRO"},
                        {35,"BLANCO"},{62,"GRIS"},{38,"ROSA"},{77,"CELESTE"},{69,"MARRÓN"},{43,"TURQUESA"},{55,"LILA"},{22,"DORADO"} };
    short indice;
    short suma = 0;
    char opcion;
    char opcionb;
    
    //BUSCAR INDICE:
    char color_buscar[22];
    short posicion = 0;
    
    //SACAR PROMEDIO
    float num_float = 0.00;
    float promedio = 0.00;
    
    //IMPAR O PAR
    short j;
    short impar = 0;
    short par[cantidad];
    
    //ORDENAMIENTO
    short auxiliar = 0;

    do{
        printf("\n\tMenú de opciones:");
        printf("\n\tM = mostrar vector");
        printf("\n\tX = continuar");
        printf("\n\tA = indice");
        printf("\n\tY = sumar");
        printf("\n\tB = buscar posición");
        printf("\n\tT = orden inverso");
        printf("\n\tD = promedio");
        printf("\n\tI = mostrar impares");
        printf("\n\tP = mostrar pares");
        printf("\n\tO = ordenado");
        printf("\n");

        scanf(" %c", &opcion);
        
        
        switch( opcion ){
            case 'M':  for( indice = 0 ; indice < cantidad ; indice++ ){
                            printf("El color y el numero asignado es: | %s | %hd |\n", color[indice].nombre, color[indice].num);
                        }
                        break;
            case 'A':   indice = 0;
                        printf("\nDime el numero del indice que quieres ver (14 max)\n");
                        scanf(" %hd", &indice);
                        printf("\nThis is your color chosed: | %s | y su num es: | %hd |\n", color[indice].nombre, color[indice].num);
                        
                        printf("\n\tDesea cambiar este valor por otro?\n\tS = si , N = no\n");
                        scanf(" %c", &opcionb);
                        if( opcionb == 'S'){
                            printf("Nombre del nuevo color: \n");
                            scanf(" %21s", color[indice].nombre);
                            printf("Numero del nuevo color: \n");
                            scanf(" %hd", &color[indice].num);
                                        
                            for( indice = 0 ; indice < cantidad ; indice++ ){
                                printf("El color y el numero asignado es: | %s | %hd |\n", color[indice].nombre, color[indice].num);
                            } 
                        }
                        if( opcionb == 'N'){
                            printf("Saliendo...\n");  
                        }
                        if( (opcionb != 'S') && (opcionb != 'N') ){
                            printf("Opcion invalida\n");
                        }   
                        break;
                
            case 'Y':   suma = sumar( suma, color[indice].num );
                        printf(" Su agregado fue de: %hd\n", suma);
                        break;
                        
            case 'B':   printf("\nDime un color, te diré el indice y la posición\n");
                        scanf(" %21s", color_buscar);
                        for( indice = 0 ; indice < cantidad ; indice++ ){
                            if( strcmp(color_buscar, color[indice].nombre) == 0 ){
                                posicion = indice + 1;
                                printf("\nEncontrado en el indice: | %hd | y es el elemento: | %hd |\n\n", indice, posicion);
                            }
                            if( strcmp(color_buscar, color[indice].nombre) != 0 ){
                            printf("No sea ha encontrado es color en nuestro registro\n");
                            }
                        }
                        break;
                        
            case 'T':   for( indice = 14 ; indice >= 0 ; indice-- ){
                            printf("Su vector inverso es del color: | %s | del num | %hd | en el indice | %hd |\n",
                                                                    color[indice].nombre, color[indice].num, indice);
                        }
                        break;
                        
            case 'D':   for( indice = 0 ; indice < cantidad ; indice++ ){
                            num_float += sumar( suma, color[indice].num );
                        }
                        promedio = promediar(num_float);
                        printf("La suma total es de: | %.2f |\n", num_float);
                        printf("El promedio total es de | %.2f |\n", promedio);
                        break;
                        
            case 'I':   printf("Los 0 sonlos numero son impares\n\n");
                        for( indice = 0 ; indice < cantidad ; indice++){
                                impar = impares( color[indice].num );
                                printf("Los numeros impares son: | %hd |\n", impar);
                            
                        }
                        break;
                        
            case 'P':   for( indice = 0 ; indice < cantidad ; indice++ ){
                            //De esta manera solo se imprimen lo pares
                            if( pares(color[indice].num) ){
                                printf("Sus numeros pares son | %hd | \n", color[indice].num);
                                par[j] = color[indice].num;
                                j++;
                            }
                        }
                        printf("Escribe el indice del nuevo vector de pares: \n");
                        scanf("%hd", &indice);
                        printf("El numero en ese indice es de: %hd\n", par[indice]);
                        break;
                        
            case 'O':   printf("Ordenado de menor a mayor:\n"); 
                        for( indice = 0 ; indice < cantidad -1 ; indice++ ){
                            for( j = indice +1 ; j < cantidad ; j++){
                                if( color[indice].num > color[j].num ){
                                    
                                    auxiliar = color[indice].num;
                                    color[indice].num = color[j].num;
                                    color[j].num = auxiliar;
                                }
                            }
                        } 
                        for( indice = 0 ; indice < cantidad ; indice++ ){
                            printf("Los numero son: | %hd | \n", color[indice].num);
                        }
                        break;
                        
            default: printf("No hay ninguna funcion asignada para es letra.\n");
                     break;
        }

    }while( indice != -1);    
    
    printf("\nUsted ha salido del bucle, gracias por participar\n");
    printf("Suma total: %hd\n", suma);
    
    
    return 0;
}

short sumar( short total, short nuevo){
    
    return total + nuevo;
}

float promediar( float nuevo ){
    return nuevo / 14;
}

short impares( short numero ){
    
    if(numero % 2 != 0 ){
        return numero;
    }
    
    /* 
    De esta manera solo devuelve 1 y 0
    return(numero % 2 != 0);
    */
}

short pares( short numero ){
    
    return( numero % 2 == 0);
}