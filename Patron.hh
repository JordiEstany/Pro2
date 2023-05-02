/** @file Patron.hh
    @brief Especificación de la clase Patron
*/

#ifndef _PATRON_
#define _PATRON_

#include "Cjt_Mensajes.hh"

/** @class Patron
    @brief Representa un Patron

*/
class Patron
{
private:

  /** @brief Arbol del patron */
  BinTree<int> arbolpatron;

public:

  /** @brief Constructora por defecto
    \pre Cierto
    \post Se crea una Patron vacío 
  */
  Patron();

  /** @brief Lee el patron
    \pre Cierto
    \post Lee el patron siguiendo su estructura de prerrequisitos en preorden.
  */
  void leer_patron();

  /** @brief Imprime el patron
    \pre Cierto
    \post Escribe el patrón siguiendo suestructura de prerrequisitos en preorden.
  */
  void escribir_patron();

  /** @brief Codifica un mensaje
    \pre String valido, tamaño de bloque valido
    \post Codifica el mensaje "p" mediante el patrón con
          identificador idp, dividiendo el mensaje en bloques de tamaño b. 
  */
  void codificar(string& p, int b);

  /** @brief Deodifica un mensaje
    \pre String valido, tamaño de bloque valido
    \post Deodifica el mensaje "p" mediante el patrón, dividiendo el mensaje en bloques de tamaño b. 
  */
  void decodificar(string& p, int b);

private:

  /** @brief Imprime el patron
    \pre Arbol valido
    \post Escribe el patrón siguiendo suestructura de prerrequisitos en preorden, mediante una función recursiva.
  */  
  static void escribir_patron_recursiva(const BinTree<int>& a); 

  /** @brief Lee el patron
    \pre Arbol valido
    \post Lee el patron siguiendo su estructura de prerrequisitos en preorden, mediante una función recursiva.
  */
  void leer_patron_recursiva(BinTree<int>& a);

  /** @brief Genera una lista de los elementos del patron
    \pre Arbol valido, tamaño de bloque valido, y lista valida
    \post Genera una lista (l), de "b" elementos de los nodos del patron, repitiendo el patron si es necesario, respetando su estructura de arbol
  */
  void generar_lista_patron(const BinTree<int>& a, int& b, list<int>& l);

};
#endif