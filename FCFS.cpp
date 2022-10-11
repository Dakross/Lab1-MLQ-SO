#include<iostream>
#include<stdlib.h>
#include<ctime>

using namespace std;

struct{
    float tLlegada;
    int Rafaga;
} Jobs[9];

void FCFS(int jobs);

int main() {
    int jobs=0;

    srand(time(NULL));

    cout << "ingrese una cantidad de procesos (maximo 10 procesos): " << endl;
    cin >> jobs;

    FCFS(jobs);
    system("pause");
    return 0;
}

void FCFS(int jobs) {
    int i=0 , j=0;
    float tmp, wt, tt, copy;
    bool cambio=true;

    cout << "la cantidad de procesos a hacer son: " << jobs << endl << endl;

    for (i=0;i<jobs;i++){
         Jobs[i].tLlegada = (float) (1 + rand() % (110 - 10)) / 10;
        Jobs[i].Rafaga = 1 + rand() % (11 - 1);   
    }

    cout << "Se han creado: " << jobs << " procesos" << "\n" << endl;
    for (i=0;i<jobs;i++){
        cout << "tiempo de llegada: " << Jobs[i].tLlegada << "\n" << "rafaga: " << Jobs[i].Rafaga << endl;
        cout << "-------------------------------" << endl;
    }
    cout << "#########################################" << endl;

    while (cambio) /*BUBBLESORT*/{
        cambio = false;
        j++;
        for (i = 0; i < jobs - j; i++){
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

    cout << "#########################################" << endl;

    for (i = 0;i<jobs;i++){
        if(i==0){
            wt = Jobs[i].tLlegada + copy;
            copy = Jobs[i].Rafaga;
            tt = wt + copy;
            cout << "Proceso " << i+1 << endl;
            cout << "Tiempo llegada = "<< Jobs[i].tLlegada << " || " << "Rafaga = "<< Jobs[i].Rafaga << endl;
            cout << "Waitingtime = "<< wt << " || " << "Turnaroundtime = "<< tt << endl;
            cout << "============================================" << endl;
        }
        else{
            wt = wt + copy;
            copy = Jobs[i].Rafaga;
            tt = wt + copy;
            cout << "Proceso " << i+1 << endl;
            cout << "Tiempo llegada = "<< Jobs[i].tLlegada << " || " << "Rafaga = "<< Jobs[i].Rafaga << endl;
            cout << "Waitingtime = "<< wt << " || " << "Turnaroundtime = "<< tt << endl;
            cout << "============================================" << endl;
        }
    }
}

