/** @file Mensaje.hh
    @brief Especificación de la clase Mensaje
*/

#ifndef _MENSAJE_
#define _MENSAJE_

#ifndef NO_DIAGRAM 
#include "BinTree.hh"
#include <iostream>
#include <list>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#endif

using namespace std;

/** @class Mensaje
    @brief Representa un Mensaje

*/
class Mensaje
{
private:

   /** @brief Texto del mensaje */
  string texto;

public:

  /** @brief Constructora por defecto
    \pre Cierto
    \post Se crea un mensaje vacío
  */
  Mensaje();

  /** @brief Devuelve el mensaje
    \pre Cierto
    \post Devuelve el texto del mensaje como string
  */
  string consul_texto() const;

};
#endif
