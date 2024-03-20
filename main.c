#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

void ejercicioClase19_3();
void ejercicioClase19_32();
void cargaPilaRandom(Pila*k);
void pasaPila(Pila* k, Pila*l);
int cuentaElementosPila(Pila l);
int sumaElementosPila(Pila l);
int encuentraElemento(Pila k, int dato);


int main()
{
    int opcion;
    printf("Ingrese caso:\n");
    opcion = getche();

    switch(opcion)
    {
    case '1':
        ejercicioClase19_3();
        break;
    case '2':
        ejercicioClase19_32();
    }

    return 0;
}
void ejercicioClase19_3()
{
    Pila origen, destino;
    inicpila (&origen);
    inicpila (&destino);

    cargaPilaRandom(&origen);

    printf("Pila origen:\n");
    mostrar(&origen);

    int cantidad=cuentaElementosPila(origen);
    printf(" Cantidad elementos: %d \n", cantidad);

    int total=sumaElementosPila(origen);
    printf(" Suma elementos: %d \n", total);

    pasaPila(&origen, &destino);
    printf("Pila origen final:\n");
    mostrar(&origen);
    printf("Pila destino:\n");
    mostrar(&destino);
}

void ejercicioClase19_32()
{
    Pila origen;
    inicpila (&origen);

    cargaPilaRandom(&origen);

    printf("Pila origen:\n");
    mostrar(&origen);

    int flag=encuentraElemento(origen, 33);
    if(flag == 1){
        printf("El elemento esta presente.\n");
    } else {
        printf("El elemento no esta presente.\n");
    }

}

void cargaPilaRandom(Pila* k)
{
    int numero;
    srand(time(NULL));

    for (int i = 0; i < 50; i++)
    {
        numero = rand()%100+1;
        apilar(k, numero);
    }
}

void pasaPila(Pila*k, Pila*l)
{
    while(!pilavacia(k))
    {
        apilar(l, desapilar(k));
    }
}

int cuentaElementosPila(Pila l)
{
    int contador = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&l))
    {
        apilar(&aux, desapilar(&l));
        contador++;
    }
    return contador;
}

int sumaElementosPila(Pila l)
{
    int acumulador = 0;
    int topepila;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&l))
    {
        topepila = tope(&l);
        acumulador = acumulador + topepila;// acumulador = acumulador + tope(&l);
        apilar(&aux, desapilar(&l));
    }
    return acumulador;
}

int encuentraElemento(Pila k, int dato)
{
    int flag = 0;
    Pila aux;
    inicpila (&aux);

    while(!pilavacia(&k) && flag == 0)
    {
        if(tope(&k) == dato)
        {
            flag = 1;
        }
        apilar(&aux, desapilar(&k));
        return flag;
    }
}
