#include <iostream>
#include <new>
#include <sstream>

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

int* conj_jogadas(int n, int* respostas){
    int* v;

    v = new int[n+2]

    v[0] = respostas[0];
    v[1] = respostas[1];
    v[2] = respostas[2];
    v[3] = respostas[3];
    
}

int nim(int n){
    int* v;

    v = new int[n];

    v[0] = 0;
    v[1] = 2;
    v[2] = 3;
    v[3] = 1;

    for (int i = 4; i < n; i++){
        v[i] = mex(conj_jogadas(i, v), n+2);
    }

    return v[n-1];
}

int main(){
    int v[] = {4,5,3,1};

    cout << mex(v,4) << "\n";
}