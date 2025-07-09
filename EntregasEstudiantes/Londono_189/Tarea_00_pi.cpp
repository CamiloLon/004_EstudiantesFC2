#include<iostream>
#include<cmath>

using namespace std;

// Este programa realiza el calculo de $$\pi$$ mediante la fórmula de Leibnitz:
// $\sum_{k=0}^{k=n} \dfrac{ (-1)^k }{ 2k + 1 }
// y lo compara con el valor teórico.

// Cuenta con dos funciones, la primera \verbatim{calcularPiLeibniz} calcula sumatoria término por término
// la segunda \verbatim{calcularPiSeparado} calcula los términos con denominador 4k + 1 y 4k + 3 por aparte y luego los resta.

// Funciona: Para ejecutar el codigo emplea: 
// verbatim{}./exe.out }
// Parametros entrada: 
//  n, cantidad de términos a calcular
// Parametros de salida: 
//  pi_leibnitz, pi_separado, diferencia_leibnitz, diferencia_separado



double calcularPiLeibniz(int);
double calcularPiSeparado(int);

int main(){
    int n;
    double pi;
    cout<<"Ingrese la cantidad de términos para sumar: ";
    cin>>n;
    if(n>0){
        pi = calcularPiLeibniz(n);
        cout<<"Primer método: "<<pi<<endl;
        cout<<"Diferencia: "<<abs(pi-M_PI)<<endl<<endl;
        pi = calcularPiSeparado(n);
        cout<<"Segundo método: "<<pi<<endl;
        cout<<"Diferencia: "<<abs(pi-M_PI)<<endl;
    }
    else{
        cout<<"Ingrese n mayor que 0";
    }

    return 0;
};

double calcularPiLeibniz(int n){
    double pi = 0;
    for(double k=0; k<=n; k++){
        pi += pow(-1, k)/(2*k+1);
    }
    return 4*pi;
}

double calcularPiSeparado(int n){
    double pi;
    double pos = 0;
    double neg = 0;
    for(double k=0; k<=n; k++){
        pos += 1/(4*k+1);
        neg += 1/(4*k+3);
    }

    pi = pos - neg;
    return 4*pi;
}