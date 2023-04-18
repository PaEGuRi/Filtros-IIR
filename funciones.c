#include "funciones.h"

/*Funciones del filtro IIR*/

void inicializar_iir_2_ord(float*num, float*den, float*w, float gan, coef_iir_2_ord* ir)
{
  for (int i = 0; i < 3; i++) {
    ir->num[i] = num[i];
    ir->den[i] = den[i];
    ir->  w[i] = w[i];
  }
       ir->gan = gan;
}

/*ver la ayuda de matlab de dfilt.df2 para ver la estructura implementada en este filtro*/
float filtrarIIR(float in, coef_iir_2_ord* ir) {
  float y;
  /*Ecuacion implementada:
  w0=a0*x-a1*w1-a2*w2 donde x es la entrada  a denota a los denominadores notese que a0 es siempre 1 por lo que da lo mismo quitarlo
  y =b0*w0+b1*w1+b2*w2
  w2=w1
  w1=w0
  */
  ir->w[0] = ((1/(ir->den[0]))*ir->gan* in) - ((1/(ir->den[0]))*ir->den[1]* ir->w[1]) - ((1/(ir->den[1]))*ir->den[2] * ir->w[2]);
  y = ((ir->num[0] * ir->w[0]) + (ir->num[1] * ir->w[1]) + (ir->num[2] * ir->w[2]));
  ir->w[2] = ir->w[1];//debe ser primero este
  ir->w[1] = ir->w[0];// y luego este para no sobreescribir
  if (y<=0){return 0;} //Se define un rango de valores
  if (y>=4095){return 4095;}
  return y;
}

/***
                   _      <-. (`-')_
         <-.      (_)        \( OO) )
      (`-')-----. ,-(`-') ,--./ ,--/
      (OO|(_\---' | ( OO) |   \ |  |
       / |  '--.  |  |  ) |  . '|  |)
       \_)  .--' (|  |_/  |  |\    |
        `|  |_)   |  |'-> |  | \   |
         `--'     `--'    `--'  `--'
*/
