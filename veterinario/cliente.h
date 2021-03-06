#include <stdio.h>
#include <string.h>
#define TAM 51

typedef struct
{
    int id;
    char nombre[TAM];
    char apellido[TAM];
    char localidad[TAM];
    int tel;
    int edad;
    char sexo;
    int cantMascotas;
    int isEmpty;
}Ecliente;

int initEcliente(Ecliente [], int );

int hardCodeEcliente(Ecliente [], int ,char [],char [],char [],int ,int ,char );

void hardCodeInicialCliente(Ecliente [],int);

int getEmptyPositionEcliente(Ecliente [],int );

int newIdEcliente(Ecliente [],int );

void imprimirListaEcliente(Ecliente [],int); // 1

void imprimirEcliente(Ecliente);

int findEclienteById(Ecliente [], int ,int );

int altaCliente(Ecliente [],int ); //7

int modificarCliente(Ecliente [],int); //10

void promClientes(Ecliente [],int);

