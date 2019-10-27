
#ifndef _carro
	#define _carro

    #include <stdio.h>
    #include "patio1.h"
    #include "patio2.h"
    #include <time.h>
    #include <stdlib.h>

    typedef struct _carro {
		int placa, hor_cheg, hor_said;
        float desc;
	} carro;

    carro check_in(int bp[5]);
    void check_out();
    int disp(carro car);
    int rejeita(carro car);
    void registrar_carro(int bp[15], p1 pi, p2 fi, carro c);

#endif