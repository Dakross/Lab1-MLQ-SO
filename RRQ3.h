#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

struct{
    float tLlegada;
    int Rafaga;
} Jobs[9];

void Q1(int n);

int main()
{
    int cJobs = 0;

    srand(time(NULL));

    cout << "Ingrese una cantidad de procesos:" << endl;
    cin >> cJobs;

    Q1(cJobs);

    cout << "Todos los Procesos han finalizado con exito" << endl;

    system("pause");

    return 0;
}

void Q1(int n){

    int i=0, j=0, quantum=3;
    float tmp;
    bool cambio = true;

    cout << "Cantidad de procesos: " << n << endl;

    for(i=0; i<n; i++){
        Jobs[i].tLlegada = (float) (1 + rand() % (110 - 10)) / 10;
        Jobs[i].Rafaga = 1 + rand() % (11 - 1);   
    }

     cout << "Se han creado: " << n << " Trabajos" << endl;
     cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    for(i=0; i<n; i++){
        cout << "Proceso[" << i+1 <<"] \n Tpo llegada: " << Jobs[i].tLlegada <<" | " << "Rafaga: " << Jobs[i].Rafaga << endl;
        cout << "-------------------------" << endl;
    }

    cout << "*********************************************" << endl; 
	
    while (cambio) //BUBBLESORT CENTINELA
    {
        cambio = false;
        j++;
        for (i=0; i < n - j; i++){
            if (Jobs[i].tLlegada > Jobs[i+1].tLlegada){
                tmp = Jobs[i].tLlegada;
                Jobs[i].tLlegada = Jobs[i+1].tLlegada;
                Jobs[i+1].tLlegada = tmp;
                cambio = true;

                if(cambio = true){
                    tmp = Jobs[i].Rafaga;
                    Jobs[i].Rafaga = Jobs[i+1].Rafaga;
                    Jobs[i+1].Rafaga = tmp;
                }
            }
        }
    }

    cout << "Los Procesos ordenados por tiempo de llegada son: " << endl << endl;
    for(i=0; i<n; i++){
        cout << "Proceso[" << i+1 <<"] \n Tpo llegada: " << Jobs[i].tLlegada <<" | " << "Rafaga: " << Jobs[i].Rafaga << endl;
        cout << "-------------------------" << endl;
    }

    while (n > 0){
        for(i=0; i < n; i++){
            Jobs[i].Rafaga = Jobs[i].Rafaga - quantum;
            if(Jobs[i].Rafaga <= 0){
                cout << "El Proceso [" << i+1 << "] ha finalizado." << endl;
                n = n - 1;
                for (j=0; j <= n; j++){
                    Jobs[i].tLlegada = Jobs[i+1].tLlegada;
                    Jobs[i].Rafaga = Jobs[i+1].Rafaga;            
                }
            }
            if (n==0)
                cout << "\n El Proceso [" << i+1 << "] ha finalizado." << endl;
            else{
                cout << "----------------------------------------------" << endl;
                cout << "El nuevo orden de los Procesos es: " << endl;
                for (j=0; j<n; j++)
                    cout << "Proceso[" << j+1 <<"] \n Tpo llegada: " << Jobs[j].tLlegada <<" | " << "Remanente Rafaga: " << Jobs[j].Rafaga << endl;
            }
        }
    }
}
/*
    cola=MLQ;
    cola 1 y 2 RR = q=3; q=8
    cola 3 = FCFS

    Se ordenan por tiempo de llegada los procesos dentro de cada array de menor a mayor
    La rafaga y el tpo de llegada se crean con rand(); RR: rafaga < quantum termina antes. FCFS = Solo tpo de llegada y suma la rafaga a cada proceso

    cola[9]

*/