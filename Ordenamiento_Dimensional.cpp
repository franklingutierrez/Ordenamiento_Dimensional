#include <iostream>
#include <conio.h>
#include <string.h>
#include <iomanip>


using namespace std;



struct persona{
    int id;
    char apellidos[20];
    char nombres[20];
    int edad;
    double talla;
    int celular;
    int ahorro;
};

void cargarDatos(struct persona *listaPersonas);
void imprimir(struct persona *listaPersonas);
void ordenarMetodoSeleccionEdad(struct persona *listaPersonas);

int main(){

    int opcion;
    persona listaPersonas[6];
    cargarDatos(listaPersonas);

    cout<<"**ORDENAMIENTO POR METODO SELECCION EN BASE A EDAD**"<<endl<<endl;
    imprimir(listaPersonas);
    ordenarMetodoSeleccionEdad(listaPersonas);
    imprimir(listaPersonas);

    getch();
    return 0;
}

void ordenarMetodoSeleccionEdad(persona *listaPersonas){
    //Ordenamiento en base a edad, de menor a mayor
    persona aux;
    int menorEdad;

    for(int x=0;x<6;x++){
        menorEdad = x;
        for(int y=x+1;y<6;y++){
            if(listaPersonas[y].edad < listaPersonas[menorEdad].edad){
                menorEdad = y;
            }
        }

        aux = listaPersonas[x];
        listaPersonas[x] = listaPersonas[menorEdad];
        listaPersonas[menorEdad] = aux;

    }
}


void imprimir(persona *listaPersonas){
    cout<<"ID  |  APELLIDO |  NOMBRE   |  EDAD  |  TALLA |  TELEFONO   |  AHORRO"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;

    int lonApellido = 7;
    int lonNombre = 7;
    int tamanioApel, tamanioNom;
    char e1[2]=" ";
    char e2[3]="  ";
    char e3[4]="   ";
    char e4[5]="    ";
    for(int x=0;x<6;x++){

        cout<<listaPersonas[x].id<<"   |  "<<listaPersonas[x].apellidos;
        tamanioApel = (int) strlen(listaPersonas[x].apellidos);
        switch(lonApellido-tamanioApel){
            case 1:
                cout<<e1;
                break;
            case 2:
                cout<<e2;
                break;
            case 3:
                cout<<e3;
                break;
            case 4:
                cout<<e4;
                break;
            default:
                break;
        }

        cout<<"  |  "<<listaPersonas[x].nombres;
        tamanioNom = (int) strlen(listaPersonas[x].nombres);
        switch(lonNombre-tamanioNom){
            case 1:
                cout<<e1;
                break;
            case 2:
                cout<<e2;
                break;
            case 3:
                cout<<e3;
                break;
            case 4:
                cout<<e4;
                break;
            default:
                break;
        }

        cout<<"  |  "<<listaPersonas[x].edad;
        if(listaPersonas[x].edad < 10){
            cout<<e3;
        }else if(listaPersonas[x].edad < 100){
            cout<<e2;
        }

        cout<<"  |  "<<fixed<<setprecision(2)<<listaPersonas[x].talla;
        cout<<"  |  "<<listaPersonas[x].celular<<"  |  "<<listaPersonas[x].ahorro<<endl;

    }
    cout<<endl;
    cout<<endl;
}

void cargarDatos(persona *listaPersonas){

    listaPersonas[0].id = 0;
    strcpy(listaPersonas[0].apellidos,"PEREZ");
    strcpy(listaPersonas[0].nombres,"JUAN");
    listaPersonas[0].edad = 11;
    listaPersonas[0].talla = 1.50;
    listaPersonas[0].celular = 919862100;
    listaPersonas[0].ahorro = 10;

    listaPersonas[1].id = 1;
    strcpy(listaPersonas[1].apellidos,"QUISPE");
    strcpy(listaPersonas[1].nombres,"LUISA");
    listaPersonas[1].edad = 45;
    listaPersonas[1].talla = 1.65;
    listaPersonas[1].celular = 951862421;
    listaPersonas[1].ahorro = 50000;

    listaPersonas[2].id = 2;
    strcpy(listaPersonas[2].apellidos,"LOPEZ");
    strcpy(listaPersonas[2].nombres,"MILENA");
    listaPersonas[2].edad = 24;
    listaPersonas[2].talla = 1.60;
    listaPersonas[2].celular = 961862129;
    listaPersonas[2].ahorro = 2000;

    listaPersonas[3].id = 3;
    strcpy(listaPersonas[3].apellidos,"ALVAREZ");
    strcpy(listaPersonas[3].nombres,"PABLO");
    listaPersonas[3].edad = 52;
    listaPersonas[3].talla = 1.70;
    listaPersonas[3].celular = 961860111;
    listaPersonas[3].ahorro = 80000;

    listaPersonas[4].id = 4;
    strcpy(listaPersonas[4].apellidos,"ZEA");
    strcpy(listaPersonas[4].nombres,"PEPE");
    listaPersonas[4].edad = 5;
    listaPersonas[4].talla = 0.80;
    listaPersonas[4].celular = 971562021;
    listaPersonas[4].ahorro = 0;

    listaPersonas[5].id = 5;
    strcpy(listaPersonas[5].apellidos,"VILCA");
    strcpy(listaPersonas[5].nombres,"ALBERTO");
    listaPersonas[5].edad = 22;
    listaPersonas[5].talla = 1.75;
    listaPersonas[5].celular = 986452129;
    listaPersonas[5].ahorro = 500;
}