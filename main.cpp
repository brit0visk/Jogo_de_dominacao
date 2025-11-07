#include "nim_pll.hpp"

int main(int argc, char **argv){
    int n = atoi(argv[1]);

    imprimir_vetor<int>(nim_pll(n),n+1);
}