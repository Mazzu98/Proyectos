#include "clienteConMascota.h"

int hardCodeEmascota(Emascota list[], int len,Ecliente listaCliente[],int tamCliente,char nombre[],int tipo,char raza[],int edad,float peso,char sexo,int idDueno,int idRaza)
{
    int index,indexCliente;
    index = getEmptyPositionEmascota(list,len);
    if(index != -1 )
    {
        list[index].id = newIdEmascota(list,len);
        strcpy(list[index].nombre,nombre);
        list[index].tipo = tipo;
        strcpy(list[index].raza,raza);
        list[index].edad = edad;
        list[index].peso = peso;
        list[index].sexo = sexo;
        list[index].idDueno = idDueno;
        list[index].isEmpty = 0;
        list[index].idRaza = idRaza;
        indexCliente = findEclienteById(listaCliente,tamCliente,list[index].idDueno);
        listaCliente[indexCliente].cantMascotas ++;
        return 0;
    }
    else
    {
        return -1;
    }
    return -1;
}

void hardCodeInicialMascotas(Emascota listaMascota[],int tam,Ecliente listaCliente[],int tamCliente)
{
    hardCodeEmascota(listaMascota,tam,listaCliente,tamCliente,"miau",1,"persa",6,3,'f',1,3);
    hardCodeEmascota(listaMascota,tam,listaCliente,tamCliente,"gatex",1,"siames",5,2,'f',1,3);
    hardCodeEmascota(listaMascota,tam,listaCliente,tamCliente,"sam",2,"caniche",9,3,'m',2,1);
    hardCodeEmascota(listaMascota,tam,listaCliente,tamCliente,"roco",2,"terrier",2,15,'m',2,1);
    hardCodeEmascota(listaMascota,tam,listaCliente,tamCliente,"michi",1,"bengala",3,2,'m',2,3);
    hardCodeEmascota(listaMascota,tam,listaCliente,tamCliente,"bruh",2,"pitbull",4,13,'m',3,1);
    hardCodeEmascota(listaMascota,tam,listaCliente,tamCliente,"zzzz",3,"gfsdgfg",3,0.5,'f',3,2);
    hardCodeEmascota(listaMascota,tam,listaCliente,tamCliente,"perrito",2,"labrador",6,11,'m',4,1);
    hardCodeEmascota(listaMascota,tam,listaCliente,tamCliente,"titi",1,"maine coon",8,13,'m',5,3);
    hardCodeEmascota(listaMascota,tam,listaCliente,tamCliente,"wkrt",1,"persa",2,3,'m',5,3);
    hardCodeEmascota(listaMascota,tam,listaCliente,tamCliente,"guau",2,"bulldog",1,9,'m',5,1);
}

void imprimirClientesConMascota(Ecliente listaCliente[],int tamCliente,Emascota listaMascota[],int tamMascota)
{
    int i,j;

    for(i=0;i<tamCliente;i++)
    {
        if(listaCliente[i].isEmpty == 0)
        {
            printf("------------------------Duenio---------------------------\n");
            printf(" id   nombre\tapellido  localidad  telefono  edad  sexo\n");
            imprimirEcliente(listaCliente[i]);
            printf("\n         --------------------Mascota--------------------------");
            printf("\n\t id\tnombre\t      raza   edad   peso    sexo  tipo\n");
            for(j=0;j<tamMascota;j++)
            {
                if(listaMascota[j].idDueno == listaCliente[i].id)
                {
                    printf("%10d%12s%12s%6d%8.2f%6c    ",listaMascota[j].id,listaMascota[j].nombre,listaMascota[j].raza,listaMascota[j].edad,listaMascota[j].peso,listaMascota[j].sexo);
                    switch(listaMascota[j].tipo)
                    {
                        case 1: printf("gato \n");
                            break;
                        case 2: printf("perro\n");
                            break;
                        case 3: printf("raro \n");
                            break;
                    }

                }
            }
            printf("\n_______________________________________________________________\n\n");
        }
    }
}

void imprimirListaEmascotaCD(Emascota listaMascota[],int tam,Ecliente listaCliente[],int tamCliente,Eraza listaRaza [] ,int tamRaza)
{
    int i;
    printf(" id\tnombre\t  edad  peso    sexo      tipo        duenio\t    raza\tpais\n\n");
    for(i=0;i<tam;i++)
    {
        if(listaMascota[i].isEmpty == 0)
        {
            imprimirMascotaCD(listaMascota[i],listaCliente,tamCliente,listaRaza,tamRaza);
        }
    }
    printf("\n");
}

int addMascota(Emascota listaMascota[], int tamMascota,Ecliente listaCliente[], int tamCliente,Eraza listaRaza[] ,int tamRaza )
{
        int indexMascota,id,indexCliente,i;
        indexMascota = getEmptyPositionEmascota(listaMascota,tamMascota);
        if(indexMascota != -1 )
        {
            listaMascota[indexMascota].id = newIdEmascota(listaMascota,tamMascota);
            getOLString("Ingresar nombre de la mascota: ",listaMascota[indexMascota].nombre);

            listaMascota[indexMascota].tipo = getInt("Ingrese:\n\t1. Gato \n\t2. Perro\n\t3. Raro");
            for(i=0;i<tamRaza;i++)
            {
                if(listaRaza[i].isEmpty == 0)
                {
                    printf("%d%12s%12s\n",listaRaza[i].id,listaRaza[i].raza,listaRaza[i].pais );
                }
            }
            listaMascota[i].idRaza = getInt("\nIngrese el id de la raza\n");

            listaMascota[indexMascota].edad = getInt("Ingrese  la edad de su mascota: ");
            listaMascota[indexMascota].peso = getFloat("Ingrese el peso de su mascota: ");
            do{
                printf("Ingrese el sexo de su mascota f(femenino) m(masculino): ");
                fflush(stdin);
                listaMascota[indexMascota].sexo = getchar();
            }while(listaMascota[indexMascota].sexo != 'f' && listaMascota[indexMascota].sexo != 'm');
            do{
                imprimirListaEcliente(listaCliente,tamCliente);
                id = getInt("Ingrese el id de el due�o de la mascota: ");
                indexCliente = findEclienteById(listaCliente,tamCliente,id);
                if(indexCliente == -1)
                {
                    printf("\n\nerror: ingrese nuevamente\n\n");
                }
                else
                {
                    listaCliente[indexCliente].cantMascotas ++;
                }
            }while(indexCliente == -1);
            listaMascota[indexMascota].idDueno = id;
            listaMascota[indexMascota].isEmpty = 0;

            return 0;
        }
        else
        {
            return -1;
        }
        return -1;
    }

int bajaMascota(Emascota listaMascota[],int tamMascota,Ecliente listaCliente[],int tamCliente,Eraza listaRaza[] ,int tamRaza)
{
    int indexMascota,id,indexCliente;

    imprimirListaEmascotaCD(listaMascota,tamMascota,listaCliente,tamCliente,listaRaza,tamRaza );

    id = getInt("ingrese id de la mascota: ");
    indexMascota = findEmascotaById(listaMascota,tamMascota,id);
    if(indexMascota != -1)
    {
        listaMascota[indexMascota].isEmpty = 1;
        indexCliente = findEclienteById(listaCliente,tamCliente,listaMascota[indexMascota].idDueno);
        listaCliente[indexCliente].cantMascotas --;
        return 0;
    }

    return indexMascota;
}

int modificarMascota(Emascota listaMascota[],int tamMascota,Ecliente listaCliente[], int tamCliente,Eraza listaRaza[] ,int tamRaza)
{
    int opcion,id,index,i;
    imprimirListaEmascotaCD(listaMascota,tamMascota,listaCliente,tamCliente,listaRaza,tamRaza);
    id = getInt("Ingrese id de la mascota a modificar: ");
    system("cls");
    index = findEmascotaById(listaMascota,tamMascota,id);
    if(index != -1)
    {
        do{

            system("cls");
            printf("\n1. modificar nombre:\n2. modificar tipo:\n3. modificar raza:\n4. modificar edad: \n5. modificar peso:\n6. modificar sexo:\n7. modificar duenio:\n8. Modificar Raza\n9. cancelar\n");
            opcion = getInt("Ingrese una opcion: ");
            switch(opcion)
            {
                case 1: getOLString("Ingrese nuevo nombre",listaMascota[index].nombre);
                    break;
                case 2: do{
                        listaMascota[index].tipo = getInt("Ingrese:\n\t1. Gato \n\t2. Perro\n\t3. Raro\n");
                        }while(listaMascota[index].tipo <1 || listaMascota[index].tipo > 3);
                    break;
                case 3: getOLString("Ingrese nueva raza",listaMascota[index].raza);
                    break;
                case 4: listaMascota[index].edad = getInt("Ingrese nueva edad:");
                    break;
                case 5: listaMascota[index].peso= getFloat("Ingrese nuevo peso: ");
                    break;
                case 6: do{
                            printf("ingrese nuevo sexo f(femenino) m(masculino): ");
                            fflush(stdin);
                            listaMascota[index].sexo = getchar();
                        }while(listaMascota[index].sexo != 'f' && listaMascota[index].sexo != 'm');
                    break;
                case 7:
                        imprimirListaEcliente(listaCliente,tamCliente);
                        listaMascota[index].idDueno = getInt("Ingrese id del nuevo Duenio:");
                case 8: for(i=0;i<tamRaza;i++)
                        {
                            if(listaRaza[i].isEmpty == 0)
                            {

                                printf("%d%12s%12s\n",listaRaza[i].id,listaRaza[i].raza,listaRaza[i].pais );
                            }
                        }
                        listaMascota[index].idRaza = getInt("Ingrese nuevo id de raza:");
                        break;

                case 9: printf("Operacion cancelada\n");
                    return 1;
                    break;
            }
        }while(opcion <1 || opcion > 9);
        return 0;
    }
    return index;
}

int borrarCliente(Ecliente listaCliente[],int tamCliente,Emascota listaMascota[],int tamMascota)
{
    int id,indexCliente,i;
    imprimirListaEcliente(listaCliente,tamCliente);

    id = getInt("Ingrese id de el cliente a borrar: ");
    system("cls");
    indexCliente = findEclienteById(listaCliente,tamCliente,id);
    if(indexCliente != -1)
    {
        listaCliente[indexCliente].isEmpty = 1;
        for(i = 0;i<tamMascota;i++)
        {
            if(listaMascota[i].idDueno == id)
            {
                listaMascota[i].isEmpty = 1;
            }
        }
        return 0;
    }
    return indexCliente;
}

void imprimirMascotaCD(Emascota mascota,Ecliente listaCliente[],int tamCliente,Eraza listaRaza [] ,int tamRaza)
{
    int indexCliente,i;
    printf("%2d%12s%6d%8.2f%6c\t",mascota.id,mascota.nombre,mascota.edad,mascota.peso,mascota.sexo);
            indexCliente = findEclienteById(listaCliente,tamCliente,mascota.idDueno);
            switch(mascota.tipo)
            {
                case 1: printf("  gato ");
                    break;
                case 2: printf("  perro");
                    break;
                case 3: printf("  raro ");
                    break;
            }
            printf("%13s",listaCliente[indexCliente].nombre);
            for(i=0;i<tamRaza;i++)
            {
                if(mascota.idRaza == listaRaza[i].id)
                {
                    printf("%12s%12s\n",listaRaza[i].raza,listaRaza[i].pais);
                }
            }
            printf("\n");

}

void ordenarPorTipo(Emascota listaMascota[],int tamMascota,Ecliente listaCliente[],int tamCliente,Eraza listaRaza[] ,int tamRaza)
{
    int i,j;
    Emascota aux;

    for(i = 0; i < tamMascota-1; i++ )
    {
        for(j = i+1; j < tamMascota; j++)
        {
            if(listaMascota[i].tipo > listaMascota[j].tipo)   //de menor a mayor
            {
                aux = listaMascota[i];
                listaMascota[i] = listaMascota[j];
                listaMascota[j] = aux;
            }
        }
    }
    imprimirListaEmascotaCD(listaMascota,tamMascota,listaCliente,tamCliente,listaRaza,tamRaza);
}

void imprimirClientesVariasMascotas(Ecliente listaCliente[],int tamCliente,Emascota listaMascota[],int tamMascota,int masDe)
{
    int i,j,cant;

    printf(" id   nombre\tapellido  localidad  telefono  edad  sexo\n\n");

    for(i=0;i<tamCliente;i++)
    {
        cant = 0;
        if(listaCliente[i].isEmpty == 0)
        {
            for(j=0;j<tamMascota;j++)
            {
                if(listaCliente[i].id == listaMascota[j].idDueno)
                {
                    cant ++;
                }
            }
            if(cant > masDe)
            {
                imprimirEcliente(listaCliente[i]);
            }
        }
    }
}

void imprimirMascotasSiEsMayorA(Ecliente listaCliente[],int tamCliente,Emascota listaMascota[],int tamMascota,Eraza listaRaza[] ,int tamRaza,int mayorDe)
{
    int i;

    printf(" id\tnombre\t      raza   edad   peso    sexo  tipo        duenio\n\n");

    for(i=0;i<tamMascota;i++)
    {
        if(listaMascota[i].isEmpty == 0 && listaMascota[i].edad > mayorDe)
        {
            imprimirMascotaCD(listaMascota[i],listaCliente,tamCliente,listaRaza,tamRaza);
        }
    }
}

void imprimirMascotaPorTipo(Emascota listaMascota[],int tamMascota,Ecliente listaCliente[],int tamCliente,int tipo,Eraza listaRaza[] ,int tamRaza)
{
    int i;

    printf(" id\tnombre\t      raza   edad   peso    sexo  tipo        duenio\n\n");

    for(i=0;i<tamMascota;i++)
    {
        if(listaMascota[i].isEmpty == 0 && listaMascota[i].tipo == tipo)
        {
            imprimirMascotaCD(listaMascota[i],listaCliente,tamCliente,listaRaza,tamRaza);
        }
    }
}

void ordenarDuenoPorCantidades(Ecliente listaCliente[],int tamCliente)
{
    int i,j;
    Ecliente aux;

    for(i=0;i<tamCliente-1;i++)
    {
        for(j=i+1;j<tamCliente;j++)
        {
            if(listaCliente[i].cantMascotas > listaCliente[j].cantMascotas)
            {
                aux = listaCliente[i];
                listaCliente[i] = listaCliente[j];
                listaCliente[j] = aux;
            }
        }
    }
    imprimirListaEcliente(listaCliente,tamCliente);
}

void ordenarDuenoPorCantidadesYalfabeto(Ecliente listaCliente[],int tamCliente)
{
    int i,j;
    Ecliente aux;

    for(i=0;i<tamCliente-1;i++)
    {
        for(j=i+1;j<tamCliente;j++)
        {
            if(listaCliente[i].cantMascotas > listaCliente[j].cantMascotas)
            {
                aux = listaCliente[i];
                listaCliente[i] = listaCliente[j];
                listaCliente[j] = aux;
            }
            else if(listaCliente[i].cantMascotas == listaCliente[j].cantMascotas && strcmp(listaCliente[i].nombre,listaCliente[j].nombre) > 0)
            {
                aux = listaCliente[i];
                listaCliente[i] = listaCliente[j];
                listaCliente[j] = aux;
            }
        }
    }
    imprimirListaEcliente(listaCliente,tamCliente);
}

void mensaje(int num,char bien[],char mal[])
{
    if(num == -1)
    {
        printf("\n%s\n",mal);
    }
    else if(num == 0)
    {
        printf("\n%s\n",bien);
    }
}

void menuPrincipal()
{
    printf("\n1. Listar\n2. ABM\n3. Ordenar\n4. promedios\n5. Salir\n");
}

void menuListar(Emascota listaMascota[],int tamMascota,Ecliente listaCliente[],int tamCliente,Eraza listaRaza[] ,int tamRaza)
{
    int opcion,tipo;
    do{
        printf("\n1. Listado de clientes\n");
        printf("2. Listado de mascotas\n");
        printf("3. Listado de clientes con mascota\n");
        printf("4. Listado de clientes con mas de una mascota\n");
        printf("5. Listado de mascotas de mas de 3 anios, con duenios\n");
        printf("6. Listar las mascotas por un tipo en particular\n");
        printf("7. Listar los clientes con mascotas del mismo sexo\n");
        printf("8. Volver\n\n");
        opcion = getInt("Ingrese una opcion: ");
        system("cls");
        switch(opcion)
        {
        case 1: imprimirListaEcliente(listaCliente,tamCliente);
                break;
        case 2: imprimirListaEmascotaCD(listaMascota,tamMascota,listaCliente,tamCliente,listaRaza,tamRaza);
                break;
        case 3: imprimirClientesConMascota(listaCliente,tamCliente,listaMascota,tamMascota);
                break;
        case 4: imprimirClientesVariasMascotas(listaCliente,tamCliente,listaMascota,tamMascota,1);
                break;
        case 5: imprimirMascotasSiEsMayorA(listaCliente,tamCliente,listaMascota,tamMascota,3,listaRaza,tamMascota);
                break;
        case 6:
                    tipo = getInt("Ingrese:\n\t1. Gato \n\t2. Perro\n\t3. Raro");
                    system("cls");
                    if(tipo==1 || tipo == 2 || tipo == 3)
                    {
                        imprimirMascotaPorTipo(listaMascota,tamMascota,listaCliente,tamCliente,tipo,listaRaza,tamRaza);
                    }
                    else
                    {
                        printf("\nOpcion invalida\n");
                    }

                break;
        case 7: listarDueniosDeMascotasDelMismoSexo(listaCliente,tamCliente,listaMascota,tamMascota);
            break;
        case 8: break;
        default: printf("\nOpcion invalida, intente de nuevo\n\n");
        }
    }while(opcion < 1 || opcion > 8);
}

void menuABM(Emascota listaMascota[],int tamMascota,Ecliente listaCliente[],int tamCliente,Eraza listaRaza[],int tamRaza)
{
    int opcion,succes;
    do{
        printf("\n1. Alta de mascota\n");
        printf("2. Modificar mascota\n");
        printf("3. Baja de mascota\n");
        printf("4. Alta duenio\n");
        printf("5. Modificacion Duenio\n");
        printf("6. Borrado de duenio en cascada\n");
        printf("7. Volver\n\n");
        opcion = getInt("Ingrese una opcion: ");
        system("cls");
        switch(opcion)
        {
        case 1: succes = addMascota(listaMascota,tamMascota,listaCliente,tamCliente,listaRaza,tamRaza);
                system("cls");
                mensaje(succes,"Operacion realizada","Error, operacion no realizada por falta de espacio");
                break;
        case 2: succes = modificarMascota(listaMascota,tamMascota,listaCliente,tamCliente,listaRaza,tamRaza);
                system("cls");
                mensaje(succes,"Operacion realizada","Error, operacion no realizada por id invalido");
                break;
        case 3: succes = bajaMascota(listaMascota,tamMascota,listaCliente,tamCliente,listaRaza,tamRaza);
                system("cls");
                mensaje(succes,"Operacion realizada","Error, operacion no realizada");
                break;
        case 4: succes = altaCliente(listaCliente,tamCliente);
                system("cls");
                mensaje(succes,"Operacion realizada","Error, operacion no realizada por falta de espacio");
                break;
        case 5: succes = modificarCliente(listaCliente,tamCliente);
                system("cls");
                mensaje(succes,"Operacion realizada","Error, operacion no realizada por id invalido");
                break;
        case 6: succes = borrarCliente(listaCliente,tamCliente,listaMascota,tamMascota);
                system("cls");
                mensaje(succes,"Operacion realizada","Error, operacion no realizada");
                break;
        case 7: break;
        default: printf("\nOpcion invalida, intente de nuevo\n\n");
        }
    }while(opcion < 1 || opcion > 7);
}

void menuOrdenar(Emascota listaMascota[],int tamMascota,Ecliente listaCliente[],int tamCliente,Eraza listaRaza[] ,int tamRaza)
{
    int opcion;
    do{
        printf("\n1. ordenar las mascotas por tipo y listarlas con sus duenios\n");
        printf("2. ordenar a los duenios por cantidades de mascotas y mostrarlos\n");
        printf("3. ordenar a los duenios por cantidades de mascotas y por orden alfabetico de los nombres y mostrarlos\n");
        printf("4. Volver\n\n");
        opcion = getInt("Ingrese una opcion: ");
        system("cls");
        switch(opcion)
        {
        case 1: ordenarPorTipo(listaMascota,tamMascota,listaCliente,tamCliente,listaRaza,tamRaza);
                break;
        case 2: ordenarDuenoPorCantidades(listaCliente,tamCliente);
                break;
        case 3: ordenarDuenoPorCantidadesYalfabeto(listaCliente,tamCliente);
                break;
        case 4: break;
        default: printf("\nOpcion invalida, intente de nuevo\n\n");
        }
    }while(opcion < 1 || opcion > 4);
}

void menuPromedios(Emascota listaMascota[],int tamMascota,Ecliente listaCliente[],int tamCliente)
{
    int opcion,tipo;
    do{
        printf("\n1. el promedio de edad entre las mascotas\n");
        printf("2. el promedio de edad entre las mascotas, por tipo\n");
        printf("3. el promedio que tengo entre varones y mujeres de mis clientes\n");
        printf("4. Volver\n\n");
        opcion = getInt("Ingrese una opcion: ");
        system("cls");
        switch(opcion)
        {
        case 1: printf("\npromedio = %.2f\n",promEdadMascotas(listaMascota,tamMascota));
                break;
        case 2: tipo = getInt("Ingrese:\n\t1. Gato \n\t2. Perro\n\t3. Raro");
                system("cls");
                printf("\npromedio = %.2f\n",promEdadMascotasTipo(listaMascota,tamMascota,tipo)) ;
                break;
        case 3: promClientes(listaCliente,tamCliente);
                break;
        case 4: break;
        default: printf("\nOpcion invalida, intente de nuevo\n\n");
        }
    }while(opcion < 1 || opcion > 4);
}

void listarDueniosDeMascotasDelMismoSexo(Ecliente listaCliente[],int tamCliente,Emascota listaMascota[],int tamMascota)
{
    int i,j,contf ,contm ;
    for(i=0;i<tamCliente;i++)
    {
        contf = 0;
        contm = 0;
        if(listaCliente[i].isEmpty  == 0)
        {
            for(j=0;j<tamMascota;j++)
            {
                if(listaMascota[j].isEmpty == 0 && listaMascota[j].idDueno == listaCliente[i].id)
                {
                    if(listaMascota[j].sexo == 'f')
                     {
                          contf++;
                     }
                     else if(listaMascota[j].sexo == 'm')
                     {
                          contm++;
                     }
                }
            }
            if(contf > 1 || contm > 1 )
            {
                imprimirEcliente(listaCliente[i]);
            }
        }
    }
}

