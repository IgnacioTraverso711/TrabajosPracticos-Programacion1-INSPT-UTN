#include <stdio.h>
#include <stdlib.h>

int main()
{
    // CONSIGNA: El programa principal debe ingresar dos números enteros m y n, si ambos son positivos validar (usar la función “Signo”)
    // Armar un menú de opciones que me permita elegir qué operaciones voy a realizar incluyendo alguna opción que pida salir del programa.
    int m,n,opcion_usuario, nMayor, nMenor;

    printf("------------------------------------------------------------------\n");
    printf("------ Programa Permutaciones, Variaciones y Combinaciones -------\n");
    printf("------------------------------------------------------------------\n");
    printf("------- Vamos a ingresar 2 numeros y hacer los calculos ----------\n");
    printf("------------------------------------------------------------------\n");
    printf("-------------- Ambos numeros deben de ser positivos --------------\n");
    printf("------------------------------------------------------------------\n");

    // Entrada de datos
    m = entrada();
    n = entrada();

    // Do while perteneciente al menu
    do{
        printf("------------------------------------------------------------------\n");
        printf("----------- Seleccione que operacion quiere realizar -------------\n");
        printf("------------------------------------------------------------------\n");
        printf("1- Calcular Permutaciones del primer numero \n");
        printf("2- Calcular Permutaciones del segundo numero \n");
        printf("3- Calcular Variaciones entre ambos numeros \n");
        printf("4- Calcular Combinaciones entre ambos numeros \n");
        printf("5- Terminar Programa \n");
        printf("------------------------------------------------------------------\n");
        printf("------------------------------------------------------------------\n");
        printf("------------------------------------------------------------------\n");

        // Eleccion del usuario
        scanf(" %d", &opcion_usuario);
        nMayor = mayor(m,n);
        nMenor = menor(m,n);
        // Ejecucion de las funciones
        switch(opcion_usuario){
            case 1:
                printf("Las permutaciones del primer numero son: %d \n", factorial(m));
                break;
            case 2:
                printf("Las permutaciones del segundo numero son: %d \n", factorial(n));
                break;
            case 3:
                printf("Las variaciones entre numeros son: %d \n", calcularVariaciones(nMayor,nMenor));
                break;
            case 4:
                printf("Las combinaciones entre numeros son %d \n", calcularCombinaciones(nMayor,nMenor));
                break;
            case 5:
                printf("Terminando ejecucion.....");
                break;
            default:
                printf("el numero que ingreso no es una opcion valida\n");
                break;
        }

    }while(opcion_usuario != 5);
}


int entrada(){
    int numero;
    do{
     printf("Ingresar un numero \n");
     scanf(" %d", &numero);
     if(!signo(numero)){
        printf("El numero no es positivo, intentelo nuevamente\n");
        printf("Vuelva a ");
     }
    }while(!signo(numero));
    return numero;
}
//Recibe un número entero y devuelva como resultado 1 si es positivo y 0 si es negativo
int signo (int numero){
    if(numero < 0){
        return 0;
    }else{
        return 1;
    }
}

//Recibe dos números enteros y devuelve el mayor de ellos.
int mayor(int numero1, int numero2){
    if(numero1 > numero2){
        return numero1;
    }else if(numero1 < numero2){
        return numero2;
    }else{
        //Para la resolucion de nuestro ejercicio si ambos son iguales da igual que numero devuelve. Lo que haria al (else if) de arriba reduntante
        return numero2;
    }
}

//Recibe dos números enteros y devuelve el menor de ellos.
int menor(int numero1, int numero2){
    if(numero1 < numero2){
        return numero1;
    }else if(numero1 > numero2){
        return numero2;
    }else{
        //Para la resolucion de nuestro ejercicio si ambos son iguales da igual que numero devuelve. Lo que haria al (else if) de arriba reduntante
        return numero2;
    }
}

//Recibe un número entero y calcula su factorial.
int factorial(int numero){
    for(int x = numero-1 ; x > 0; x--){
        numero = numero * x;
    }
    return numero;
}

//Recibe dos numeros el primer parametro siendo el numero mayor y el segundo parametro siendo el numero menor, devuelve sus Variaciones
int calcularVariaciones(int nMayor, int nMenor){
    int variaciones;
    variaciones = factorial(nMayor)/factorial(nMayor-nMenor);
    return variaciones;
}

//Recibe dos numeros el primer parametro siendo el numero mayor y el segundo parametro siendo el numero menor, devuelve sus Combinaciones
int calcularCombinaciones(int nMayor, int nMenor){
    int combinaciones;
    combinaciones = factorial(nMayor)/(factorial(nMenor)*factorial(nMayor-nMenor));
    return combinaciones;
}
