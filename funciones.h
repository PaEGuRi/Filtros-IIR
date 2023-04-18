#ifndef FUNCIONES_H
#define FUNCIONES_H

/*Parametros del filtro IIR*/

typedef struct coef_iir_2_ord {// este va a ser el nombre de la estructura
  float num[3]; // ponga aqu� su numerador
  float den[3]; // ponga aqu� su denominador
  float w[3];
  float gan;
} coef_iir_2_ord;// este va a ser el nombre del typedef

void inicializar_iir_2_ord(float*num, float*den, float*w, float gan, coef_iir_2_ord* ir);

float filtrarIIR(float in,coef_iir_2_ord* ir);

#endif


/***
 *                 _      <-. (`-')_ 
 *       <-.      (_)        \( OO) )
 *    (`-')-----. ,-(`-') ,--./ ,--/ 
 *    (OO|(_\---' | ( OO) |   \ |  | 
 *     / |  '--.  |  |  ) |  . '|  |)
 *     \_)  .--' (|  |_/  |  |\    | 
 *      `|  |_)   |  |'-> |  | \   | 
 *       `--'     `--'    `--'  `--' 
 */