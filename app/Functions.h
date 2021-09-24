#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

/**
 * Muestra los integrantes del grupo.
 * */
void MostrarGrupo();

/**
 * @param r color rojo.
 * @param g color verde.
 * @param b color azul.
 * 
 * @return El valor máximo.
 * */
int ColorMax(int r, int g, int b);

/**
 * @param r color rojo.
 * @param g color verde.
 * @param b color azul.
 * 
 * @return El valor mínimo.
 * */
int ColorMin(int r, int g, int b);

/**
 * 
 * @param cmin valor mínimo entre r, g y b
 * @param cmax valor máximo entre r, g y b
 * @param diff Delta entre máximo y mínimo
 * @param r color rojo.
 * @param g color verde.
 * @param b color azul.
 * 
 * @return valor Hue
 * */
int CalcularHue(int cmin, int cmax, int diff, int r, int g, int b);

/**
 * 
 * @param cmax valor máximo entre los colores rojo, verde y azul
 * @param diff Diferencia entre el máximo y minimo de los colores.
 * 
 * @return saturación;
 * 
 * */
int CalcularSaturacion(int cmax, int diff);

/**
 * @param cmax valor máximo entre los colores rojo, verde y azul.
 * 
 * @return Value (del HSV)
 * */
int CalcularValue(int cmax);
#endif /* FUNCTIONS_H */