#include "carro.h"


int check_in(carro *x, int bp[15],int placa,int cheg, int said, int desc) {

    for (int i = 0; i < 15; i++)  //Verifica se a placa é duplicada no banco
    {
      if(placa == bp[i])
        return 0;
    }
    x->placa = placa;
    x->hor_cheg = cheg;
    x->hor_said = said;
    x->desc = desc;    
    return 1;
}
int disp(carro car, p1 *pi, p2 *fi) {
    if(pi->topo == NULL)            //Caso o patio 1 estiver VAZIO 
        return 0;         //Estacionar no patio 1
    else                            //Caso o patio 1 NÃO estiver VAZIO
        if(fi->ini == NULL)       //Caso o patio 2 estiver VAZIO
            return 1;     //Estacionar no patio 2
        else {                      //Caso o patio 1 e o 2 NÃO estiverem VAZIOS
            if(p1_estaCheio(pi) && pi->topo->atual.hor_said > car.hor_said) // patio 1 lotado e o novo carro vai sair depois do último estácionado
                return 1; //Estacionar no patio 2
            if(p2_estaCheio(fi))    //Caso o patio 2 esteja CHEIO
                return 0; //Estacionar no patio 1
        }   
        
}        

int rejeita(carro car) {

}
void registrar_carro(){

}