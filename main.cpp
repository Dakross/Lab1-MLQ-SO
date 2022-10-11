#include <iostream>
#include <stdlib.h>
#include <ctime>


using namespace std;

struct{
    float tLlegada;
    int Rafaga;
} Jobs[9];

void Q1(int n);
void Q2(int n);
void FCFS(int jobs);

int main()
{
    int cJobs1 = 0, cJobs2 = 0, cJobs3 = 0;

    srand(time(NULL));

    cout << "Ingrese una cantidad de procesos para RR-Q3:" << endl;
    cin >> cJobs1;
    cout << "Ingrese una cantidad de procesos para RR-Q8:" << endl;
    cin >> cJobs2;
    cout << "Ingrese una cantidad de procesos para FCFS:" << endl;
    cin >> cJobs3;

    Q1(cJobs1);
    Q2(cJobs2);
    FCFS(cJobs3);


    return 0;
}

void Q1(int n){

    int i=0, j=0, quantum=3, ite=1;
    float tmp=0, wt=0, tt=0, copy=0;
    bool cambio = true;
    cout << "###########################################" << endl;
    cout << "###########################################" << endl << endl;
    cout << "------------------ RR-Q3 ------------------"<<endl<<endl;
    cout << "###########################################" << endl;
    cout << "###########################################" << endl;
    cout << "Cantidad de procesos: " << n << endl;

    for(i=0; i<n; i++){
        Jobs[i].tLlegada = (float) (1 + rand() % (110 - 10)) / 10;
        Jobs[i].Rafaga = 1 + rand() % (11 - 1);   
    }

    cout << "Se han creado: " << n << " Trabajos" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl; 

    for(i=0; i<n; i++){
        cout << "Proceso[" << i+1 <<"] \nTpo llegada: " << Jobs[i].tLlegada << "\nRafaga: " << Jobs[i].Rafaga << endl;
        cout << "--------------------------------------------" << endl;
    }

    cout << "~~~~~~~~~~~~~~~ Quantum = 3 ~~~~~~~~~~~~~~~~" << endl;
	
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

wt = Jobs[0].tLlegada;

    while (n > 0){
        for(i=0; i < n; i++){
            Jobs[i].Rafaga = Jobs[i].Rafaga - quantum;
            if (n==0){
                cout << "\n" << endl;
            }
            else{
                cout << "============================================" << endl;
                cout << "Iteracion "<< ite << endl;
                cout << "============================================" << endl;
                cout << "El nuevo orden de los Procesos es: " << endl;
                copy = n;
                for (j=0; j<copy; j++){
                    if(j==0){
                        tt = wt + quantum;
                        cout << "Proceso " << j+1 << endl;
                        if(Jobs[j].Rafaga <= 0){
                            Jobs[j].Rafaga = 0;
                        }
                        cout << "Tiempo llegada = "<< Jobs[j].tLlegada << " || " << "Remanente Rafaga = "<< Jobs[j].Rafaga << endl;
                        cout << "Waitingtime = "<< wt << " || " << "Turnaroundtime = "<< tt << endl;
                        cout << "--------------------------------------------" << endl;
                    }
                    else{
                        wt = wt + quantum;
                        tt = wt + quantum;
                        cout << "Proceso " << j+1 << endl;
                        if(Jobs[j].Rafaga <= 0){
                            Jobs[j].Rafaga = 0;
                        }
                        cout << "Tiempo llegada = "<< Jobs[j].tLlegada << " || " << "Remanente Rafaga = "<< Jobs[j].Rafaga << endl;
                        cout << "Waitingtime = "<< wt << " || " << "Turnaroundtime = "<< tt << endl;
                        cout << "--------------------------------------------" << endl;
                    }
                    if(j==copy-1){
                        wt = tt;
                        ite = ite + 1;
                    }
                }
            }
            if(Jobs[i].Rafaga <= 0){
                cout << "El Proceso [" << i+1 << "] ha finalizado." << endl<< endl;
                n = n - 1;
                for (j=0; j <= n; j++){
                    Jobs[i].tLlegada = Jobs[i+1].tLlegada;
                    Jobs[i].Rafaga = Jobs[i+1].Rafaga;            
                }
            }
        }
    }
    cout << "#########################################" << endl;
    cout << "#########################################" << endl <<endl;
}

void Q2(int n){

    int i=0, j=0, quantum=8, ite=1;
    float tmp=0, wt=0, tt=0, copy=0;
    bool cambio = true;
    cout << "------------------ RR-Q8 ------------------"<<endl<<endl;
    cout << "###########################################" << endl;
    cout << "###########################################" << endl;
    cout << "Cantidad de procesos: " << n << endl;

    for(i=0; i<n; i++){
        Jobs[i].tLlegada = (float) (1 + rand() % (110 - 10)) / 10;
        Jobs[i].Rafaga = 1 + rand() % (11 - 1);   
    }

    cout << "Se han creado: " << n << " Trabajos" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl; 

    for(i=0; i<n; i++){
        cout << "Proceso[" << i+1 <<"] \nTpo llegada: " << Jobs[i].tLlegada << "\nRafaga: " << Jobs[i].Rafaga << endl;
        cout << "--------------------------------------------" << endl;
    }

    cout << "~~~~~~~~~~~~~~~ Quantum = 8 ~~~~~~~~~~~~~~~~" << endl; 
	
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

    wt = Jobs[0].tLlegada;

    while (n > 0){
        for(i=0; i < n; i++){
            Jobs[i].Rafaga = Jobs[i].Rafaga - quantum;
            if (n==0){
                cout << "\n" << endl;
            }
            else{
                cout << "============================================" << endl;
                cout << "Iteracion "<< ite << endl;
                cout << "============================================" << endl;
                cout << "El nuevo orden de los Procesos es: " << endl;
                copy = n;
                for (j=0; j<copy; j++){
                    if(j==0){
                        tt = wt + quantum;
                        cout << "Proceso " << j+1 << endl;
                        if(Jobs[j].Rafaga <= 0){
                            Jobs[j].Rafaga = 0;
                        }
                        cout << "Tiempo llegada = "<< Jobs[j].tLlegada << " || " << "Remanente Rafaga = "<< Jobs[j].Rafaga << endl;
                        cout << "Waitingtime = "<< wt << " || " << "Turnaroundtime = "<< tt << endl;
                        cout << "--------------------------------------------" << endl;
                    }
                    else{
                        wt = wt + quantum;
                        tt = wt + quantum;
                        cout << "Proceso " << j+1 << endl;
                        if(Jobs[j].Rafaga <= 0){
                            Jobs[j].Rafaga = 0;
                        }
                        cout << "Tiempo llegada = "<< Jobs[j].tLlegada << " || " << "Remanente Rafaga = "<< Jobs[j].Rafaga << endl;
                        cout << "Waitingtime = "<< wt << " || " << "Turnaroundtime = "<< tt << endl;
                        cout << "--------------------------------------------" << endl;
                    }
                    if(j==copy-1){
                        wt = tt;
                        ite= ite + 1;
                    }
                }
            }
            if(Jobs[i].Rafaga <= 0){
                cout << "El Proceso [" << i+1 << "] ha finalizado." << endl<< endl;
                n = n - 1;
                for (j=0; j <= n; j++){
                    Jobs[i].tLlegada = Jobs[i+1].tLlegada;
                    Jobs[i].Rafaga = Jobs[i+1].Rafaga;            
                }
            }
        }
    }
    cout << "###########################################" << endl;
    cout << "###########################################" << endl <<endl;
}


void FCFS(int jobs) {
    int i=0 , j=0;
    float tmp=0, wt=0, tt=0, copy=0;
    bool cambio=true;
    cout << "------------------ FCFS ------------------"<<endl<<endl;
    cout << "###########################################" << endl;
    cout << "###########################################" << endl;
    cout << "Cantidad de procesos: " << jobs << endl;

    for (i=0;i<jobs;i++){
         Jobs[i].tLlegada = (float) (1 + rand() % (110 - 10)) / 10;
        Jobs[i].Rafaga = 1 + rand() % (11 - 1);   
    }

    cout << "Se han creado: " << jobs << " Trabajos" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl; 


    for (i=0;i<jobs;i++){
        cout << "Tpo llegada: " << Jobs[i].tLlegada << "\n" << "Rafaga: " << Jobs[i].Rafaga << endl;
        cout << "--------------------------------------------" << endl;
    }

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

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl; 

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
