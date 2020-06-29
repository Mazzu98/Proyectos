
#include "LinkedList.h"
#include "vuelo.h"
#include "parcer.h"
#include "piloto.h"
#include <string.h>

int controller_vuelosFromText(char* path, LinkedList* lista)
{
    FILE* archivo;
    int ret;

    archivo = fopen(path,"r");
    ret = parser_vueloFromText(archivo,lista);
    fclose(archivo);

    return ret;
}

int controller_pilotosFromText(char* path, LinkedList* lista)
{
    FILE* archivo;
    int ret;

    archivo = fopen(path,"r");
    ret = parser_pilotoFromText(archivo,lista);
    fclose(archivo);

    return ret;
}

int controller_findById(LinkedList* lista,int id)
{
    int idCompare;
    int i;
    int ret = -1;
    Piloto* piloto;

    if(lista != NULL && id > 0)
    {
        for(i=0;i<ll_len(lista);i++)
        {
            piloto = ll_get(lista,i);
            getIdP(piloto,&idCompare);
            if(idCompare == id)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

void imprimirListaVuelos(LinkedList* lista)
{
    int len;
    Vuelo* vuelo;
    int i;

    if(lista != NULL)
    {
        len = ll_len(lista);
        printf("idVuelo  idAvion  idPiloto     Fecha           Destino    CantPasajeros  Despegue  Llegada\n");
        for(i=0;i<len;i++)
        {
            vuelo = ll_get(lista,i);
            imprimirVuelo(vuelo);
        }
    }
}

void imprimirVueloConPiloto(LinkedList* listaPilotos,Vuelo* vuelo)
{
    int idPiloto;
    int index;
    char nombre[51];
    Piloto* piloto;
    if(vuelo != NULL)
    {
        printf("%4d%9d%9d/%d/%d%15s%11d%13d%10d",vuelo->idVuelo,vuelo->idAvion
               ,vuelo->fecha.dia,vuelo->fecha.mes,vuelo->fecha.anio,vuelo->destino
               ,vuelo->cantPasajeros,vuelo->horaDespegue,vuelo->horaLlegada);

        getIdPiloto(vuelo,&idPiloto);
        index = controller_findById(listaPilotos,idPiloto);
        if(index != -1)
        {
            piloto = ll_get(listaPilotos,index);
            getNombreP(piloto,nombre);
            printf("%18s\n",nombre);
        }
        else
        {
            printf("\n");
        }
    }
}


void imprimirListaVuelosConPiloto(LinkedList* listaVuelos,LinkedList* listaPilotos)
{
    int len;
    Vuelo* vuelo;
    int i;
    if (listaPilotos != NULL && listaVuelos != NULL)
    {
        len = ll_len(listaVuelos);
        printf("idVuelo  idAvion      Fecha           Destino    CantPasajeros  Despegue  Llegada      Piloto\n\n");
        for(i=0;i<len;i++)
        {
            vuelo = ll_get(listaVuelos,i);
            imprimirVueloConPiloto(listaPilotos,vuelo);
        }
    }
}


int cantPasajeros(void* vuelo)
{
    int ret;
    vuelo = (Vuelo*) vuelo;
    getCantPasajeros(vuelo,&ret);
    return ret;
}
int cantPasajerosIrlanda(void* vuelo)
{
    int ret = 0;
    char destino[21];
    vuelo = (Vuelo*) vuelo;

    getDestino(vuelo,destino);
    if(strcmp(destino,"Irlanda")==0)
    {
        getCantPasajeros(vuelo,&ret);
    }

    return ret;
}

int vuelosCortosCsv(char* path,LinkedList* listaVuelos)
{
    FILE* pFile;
    int len;
    int i;
    int ret = 1;
    char fecha[11];
    Vuelo vueloAux;
    int duracion;
    Vuelo* vuelo;
    if(listaVuelos != NULL)
    {
        pFile = fopen(path,"w");
        if(pFile != NULL)
        {
            len = ll_len(listaVuelos);
            for(i=0;i<len;i++)
            {
                vuelo = ll_get(listaVuelos,i);
                vueloAux = *vuelo;
                duracion = vueloAux.horaLlegada - vueloAux.horaDespegue;
                if(duracion < 3)
                {
                    fechaToString(vueloAux.fecha,fecha);
                    fprintf(pFile,"%d,%d,%d,%s,%s,%d,%d,%d\n",vueloAux.idVuelo,vueloAux.idAvion,vueloAux.idPiloto,fecha,
                            vueloAux.destino,vueloAux.cantPasajeros,vueloAux.horaDespegue,vueloAux.horaLlegada);
                }
            }
            fclose(pFile);
            ret = 0;
        }
    }
    return ret;
}

int vuelosPortugal(void* vuelo)
{
    int ret = 0;
    char destino[31];

    vuelo = (Vuelo*) vuelo;

    getDestino(vuelo,destino);
    if(strcmp(destino,"Portugal")==0)
    {
        ret = 1;
    }
    return ret;
}

int sinAlexLifeson(void* vuelo)
{
    int ret = 0;
    int id;

    vuelo = (Vuelo*) vuelo;

    getIdPiloto(vuelo,&id);
    if(id != 1)
    {
        ret = 1;
    }
    return ret;
}

void imprimirMenu()
{
    printf("1. Cargar archivos\n");
    printf("2. imprimir vuelos\n");
    printf("3. Cantidad de pasajeros\n");
    printf("4. Cantidad de pasajeros a Irlanda\n");
    printf("5. Filtrar vuelos cortos\n");
    printf("6. Listar vuelos a Portugal\n");
    printf("7. Filtrar a Alex Lifeson\n");
    printf("8. Salir\n");
}

void succes(int ret,char succes[],char error[])
{
    if(ret == 0)
    {
        printf("%s\n",succes);
    }
    else if(ret == 1)
    {
        printf("%s\n",error);
    }
}

void succesP(void* element,char succes[],char error[])
{
    if(element != NULL)
    {
        printf("%s\n",succes);
    }
    else if(element == NULL)
    {
        printf("%s\n",error);
    }
}




