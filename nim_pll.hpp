#include "uteis.hpp"

int* conj_jogadas_pll(int i, int* respostas){
    int* nim_alcancados;

    nim_alcancados = new int[i+2];

    /*Escolher um dos três primeiros vértices*/
    nim_alcancados[0] = respostas[i-1];
    nim_alcancados[1] = respostas[i-2];
    nim_alcancados[2] = respostas[i-3];
    
    /*Escolher um dos três últimos vértices*/
    nim_alcancados[i+1] = respostas[i-1];
    nim_alcancados[i] = respostas[i-2];
    nim_alcancados[i-1] = respostas[i-3];

    /*Escolher os vértices do meio*/
    for(int k = 3; k < i-1; ++k){
        nim_alcancados[k] = respostas[k-2] ^ respostas[i-k-1];

        // cout << "Jogando em " << k << "\n";
        // cout << respostas[k-2] << " oplus " << respostas[i-k-1] << " = " << nim_alcancados[k] << "\n\n";
    }

    
    return nim_alcancados;
}

int* nim_pll(int n){
    int* p;

    p = new int[n+1];

    p[0] = 1;
    p[1] = 0;
    p[2] = 2;
    p[3] = 3;
    p[4] = 1;
    p[5] = 4;

    for (int i = 6; i < n+1; i++){
        p[i] = mex(conj_jogadas_pll(i, p), i+2);
    }

    
    return p;
}