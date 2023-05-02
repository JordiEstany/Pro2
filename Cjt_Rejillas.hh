/** @file Cjt_Rejillas.hh
    @brief Especificación de la clase Cjt_Rejillas
*/

#ifndef _CJT_REJILLAS_
#define _CJT_REJILLAS_

#include "Rejilla.hh"

/** @class Cjt_Rejillas
    @brief Representa un conjunto de rejillas

*/
class Cjt_Rejillas
{
private:

  /** @brief Vector de rejillas, su posición en el vector son sus respectivos identificadores*/
  vector<Rejilla> vector_rej;
  

public:

  /** @brief Creadora por defecto
    \pre Cierto
    \post Inicializa un conjunto de rejillas vacío
  */
  Cjt_Rejillas();

  /** @brief Inicializa un conjunto de rejillas
    \pre cierto
    \post Lee un numero R, genera y guarda una lista de R elementos rejilla, para cada rejilla se leerá su tamaño, 
    número de huecos, y posición de dichos huecos
  */
  void inicializar_rej();
  
  /** @brief Añade una rejilla
    \pre cierto
    \post Añade una rejilla al conjunto de rejillas, se leerá su tamaño, 
    número de huecos, y posición de dichos huecos
  */
  void add_rejilla();

  /** @brief Codifica con una rejilla
    \pre Identificador de rejilla valido
    \post Lee un mensaje y lo codifica con la rejilla con identificador = idr
  */
  void codificar_rejilla(int& idr);

  /** @brief Codifica mensaje guardado con una rejilla
    \pre Identificador de rejilla valido, identificador de mensaje valido y tamaño de bloque valido
    \post Codifica con la rejilla con identificador "idr" el mensaje guardado con identificador "idm"
  */
  void codificar_guardado_rejilla(int& idr, string& idm, Cjt_Mensajes& mensajes);

  /** @brief Decodifica con una rejilla
    \pre Identificador de rejlla valido
    \post Lee un mensaje y lo decodifica con la rejilla con identificador = idr
  */
  void descodificar_rejilla(int& idr);  

  /** @brief Imprime el total de rejillas
    \pre Cierto
    \post Imprime el tamaño del vector de rejillas
  */
  void imprimir_total_rej() const;

  /** @brief Consulta si la rejilla existe
    \pre <em>cierto</em>
    \post El resultado es un boleano que indica si la rejilla existia anteriormente
  */
  bool existe_rejilla(const int& idr) const;

  /** @brief Lista las rejillas
    \pre <em>cierto</em>
    \post Imprime  las  rejillas  actuales  del vector, con sus huecos iniciales y sus huecos después de girar la rejilla 90 grados 
    3 veces
  */
  void listar_rejillas();
  
  
};
#endif
