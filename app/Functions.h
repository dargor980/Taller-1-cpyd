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
float ColorMax(float r, float g, float b);

/**
 * @param r color rojo.
 * @param g color verde.
 * @param b color azul.
 * 
 * @return El valor mínimo.
 * */
float ColorMin(float r, float g, float b);

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
float CalcularHue(float cmin, float cmax, float diff, float r, float g, float b);

/**
 * 
 * @param cmax valor máximo entre los colores rojo, verde y azul
 * @param diff Diferencia entre el máximo y minimo de los colores.
 * 
 * @return saturación;
 * 
 * */
float CalcularSaturacion(float cmax, float diff);

/**
 * @param cmax valor máximo entre los colores rojo, verde y azul.
 * 
 * @return Value (del HSV)
 * */
float CalcularValue(float cmax);
#endif /* FUNCTIONS_H */