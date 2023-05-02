#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int cargarArreglo (int arreglo[], Pila *pila);
void mostrarArreglo (int arreglo[], int cant);
int busqueda (int arreglo[], int validos, int numero);
int quitarPila(Pila *pila);

int main()
{
    Pila pila1;
    inicpila(&pila1);
    int arreglo[99];
    int cantidad;
    int num;
    int flag;
    int menorPila;


    cantidad = cargarArreglo(arreglo, &pila1);
    mostrarArreglo(arreglo, cantidad);              //punto 1

    mostrar(&pila1);

    printf("Ingresa el valor a buscar en el arreglo");
    fflush(stdin);
    scanf("%i", &num);

    flag = busqueda(arreglo, cantidad, num);
    if(flag = 1){

        printf("El valor esta en el arreglo");

    }else{

        printf("El valor no esta en el arreglo");
    }

    menorPila = quitarPila(&pila1);
    printf("EL MENOR ELEMENTO ES: %d", menorPila);

}

int cargarArreglo (int arreglo[], Pila *pila){

    int i = 0;
    int num = 0;
    char letra = 's';

    while(letra == 's' && i < 99){

    printf("Ingresa el valor al arreglo");
    fflush(stdin);
    scanf("%i", &num);

    if(num%2 == 1 && num%3 == 0){

        apilar(pila, num);



    }else if(num%2 == 1){

        arreglo[i] = num;
        i++;

    }else if(num%2 == 0){

        printf("Solo ingresar numeros impares C:\n");

    }

    printf("Presiona 's' para continuar");
    fflush(stdin);
    scanf("%c", &letra);

    }

    return i;
}

void mostrarArreglo (int arreglo[], int cant){

    int i = 0;

    while(i<cant){

        printf(" | %d |", arreglo[i]);
        i++;
    }
}

int busqueda (int arreglo[], int validos, int numero){

    int i = validos-1;
    int flag = 0;

    while(i>=0){

        if(numero = arreglo[i]){

            flag = 1;

        }

        i--;

    }
        return flag;
}

int quitarPila(Pila *pila){

    Pila aux, aux2;
    inicpila(&aux);
    inicpila(&aux2);

    int menor = 0;

    while(!pilavacia(pila)){

        apilar(&aux, desapilar(pila));


        if(tope(pila) < tope(&aux)){

            apilar(&aux2, desapilar(&aux));
            apilar(&aux, desapilar(pila));
        }else{

            apilar(&aux2, desapilar(pila));

        }
    }

    while(!pilavacia(&aux2)){

        apilar(pila, desapilar(&aux2));

    }

        menor = tope(&aux);

    return menor;

}
