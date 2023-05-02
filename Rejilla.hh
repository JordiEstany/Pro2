/** @file Rejilla.hh
    @brief Especificación de la clase Rejilla
*/

#ifndef _REJILLA_
#define _REJILLA_

#include "Cjt_Mensajes.hh"


/** @class Rejilla
    @brief Representa una Rejilla

*/
class Rejilla
{
private:

/** @brief Tamaño de rejilla*/
  int n;

/** @brief Numero de huecos de la rejilla*/
  int k;

/** @brief Vector de huecos de la rejilla tras girarla 90º*/
  vector<pair<int,int>> huecos_ordenados;


public:

  /** @brief Constructora por defecto
    \pre Cierto
    \post Se crea una Rejilla vacío 
  */
  Rejilla();

  /** @brief Lee la rejilla
    \pre Cierto
    \post Lee su tamaño, número de huecos, y posición de dichos huecos
  */
  void leer_rejilla(int& nn, int& kk);

  /** @brief Escribe la rejilla
    \pre Cierto
    \post Escribe la rejilla, con sus huecos inicials y sus huecos después de girar la rejilla 90 grados 
    3 veces
  */
  void escribir_rejilla();

  /** @brief Lee y codifica un mensaje 
    \pre String valido
    \post Codifica el mensaje "p" mediante la rejilla.  
  */
  void codificar_rej(string& p);

  /** @brief Lee y decodifica un mensaje
    \pre String valido
    \post Codifica el mensaje "p" mediante la rejilla.
  */
  void decodificar(string& p);

  /** @brief Indica si hay intersección
    \pre Cierto
    \post Devuelve un boleano que indica si hay intersección entre los huecos de la rejilla
  */
  bool interseccion() const;


private:

  /** @brief Función auxiliar de comparación
    \pre 2 pares de numeros
    \post Compara 2 huecos, ordenados de más pequeño a más grande
  */
  static bool cmp(const pair <int, int> &i, const pair <int, int> &j);

};
#endif
