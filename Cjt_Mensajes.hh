/** @file Cjt_Mensajes.hh
    @brief Especificación de la clase Cjt_Mensajes
*/

#ifndef _CJT_MENSAJES_
#define _CJT_MENSAJES_

#include "Mensaje.hh"




/** @class Cjt_Mensajes
    @brief Representa un conjunto de mensajes

*/
class Cjt_Mensajes


{
private:

  /** @brief Mapa de Mensajes con su respectivo identificador como primer elemento */
  map<string, Mensaje> mapa_msg;

public:

  /** @brief Creadora por defecto
    \pre Cierto
    \post Inicializa un conjunto de mensajes vacío
  */
  Cjt_Mensajes();

  /** @brief Inicializa un conjunto de mensajes
    \pre Cierto
    \post Inicializa el conjunto de mensajes, primero lee un numero M, 
    después genera y guarda una lista de M elementos Mensaje, con sus identificadores al mapa de mensajes
  */
  void inicializar_msg();

  /** @brief Añade un mensaje
    \pre String valido
    \post Inicializa y añade un mensaje al conjunto de mensajes, es decir al mapa de mensajes, 
    con su respectivo identificador (idm) como primer elemnto
  */
  void add_msg (string& idm); 

  /** @brief Borra un mensaje
    \pre String valido
    \post Borra del mapa de mensajes el mensaje con idetificador "idm"
  */
  void borrar_msg (string& idm); 

  /** @brief Consulta si el mensaje existe
    \pre String valido
    \post Devuelve un boleano en base a si el mensaje con identificador "idm" existia anteriormente en el mapa de mensajes
  */
  bool existe_msg(string& idm) const;

  /** @brief Imprime el numero de mensajes
    \pre Cierto
    \post Imprime el numero total de mensajes del conjunto de mensajes 
  */
  void imprimir_total_msg() const; 

  /** @brief Lista los mensajes
    \pre Cierto
    \post Lista los mensajes del sistema en orden alfabético de identificador.
  */
  void listar_msg();

  /** @brief Devuelve un mensaje
    \pre String valido
    \post Devuelve el texto del mensaje con identificador "idm"
  */
  string devolver_mensaje(string idm);


private:

  /** @brief Función auxiliar de comparación
    \pre 2 Mensajes validos
    \post Compara 2 mensajes y los ordena por orden alfabetico
  */
  static bool cmp(const pair <string, Mensaje> &mensaje1, const pair <string, Mensaje> &mensaje2);
  
};

#endif
