#include <stdio.h>
#include "carro.h"
#include "patio1.h"

int main() {
   int opcao;
   printf("(1) Registrar Carro, (2) Imprimir Carros, (3) Sair: ");
   scanf("%d", &opcao);

   switch (opcao) {
   case 1:
    printf("1 \n");
    carro car = check_in();
    check_out();
    //registrar_carro();
       break;
   case 2:
    printf("2 \n");
    //imprimir_carro();
        break;
   case 3:
    printf("3 \n");
    //sair();
        break;
   default:
    printf("Opção invalida");
       break;
   } 
}