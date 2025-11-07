#include <iostream>
#include <new>
#include <sstream>
#include <cstdlib>

using namespace std;

template <typename T>
void insertion_sort(T *v, int n){
	for(int i = 0; i < n; ++i){
		int j = i-1;
		T chave = v[i];

		while(j >= 0 and v[j] > chave){
			T aux = v[j];
			v[j] = v[j+1];
			v[j+1] = aux;
			--j;
		}

		v[j+1] = chave;
	}
}	

template <typename T>
void imprimir_vetor(T *v, int n){

    cout << "[";


    for (int i = 0; i < n-1; ++i){
        cout << "P" << i << ": " << v[i] << ", ";
    }

    cout <<"P" << n-1 <<": "<< v[n-1] << "]\n";
}

int mex(int* v, int n){
    insertion_sort<int>(v,n);
    
    int resp = 0;

    for(int i = 0; i < n; i++){
        if(resp == v[i]){
            resp++;
        }
    }

    return resp;
}