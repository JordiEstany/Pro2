/** @file Cjt_Patrones.hh
    @brief Especificación de la clase Cjt_Patrones
*/

#ifndef _CJT_PATRONES_
#define _CJT_PATRONES_

#include "Patron.hh"


/** @class Cjt_Patrones
    @brief Representa una conjunto de Patrones

*/
class Cjt_Patrones
{
private:

  /** @brief Vector de patrones */
  vector<Patron> vector_ptr;

public:

  /** @brief Creadora por defecto
    \pre Cierto
    \post Inicializa un conjunto de patrones vacío
  */
  Cjt_Patrones();

  /** @brief Inicializa un conjunto de patrones
      \pre Cierto
      \post Lee un numero P, genera y guarda un vector de P elementos Patron, identificados por el
      orden en que se leen, para cada patron se leerá Para cada patrón
      se leerán sus valores en preorden con marca −1
  */
  void inicializar_ptr();

  /** @brief Añade un nuevo patron
    \pre Cierto
    \post Lee y añade un patron al conjunto de patrones
  */
  void nuevo_patron();

  /** @brief Codifica un mensaje con un patron guardado
    \pre Identificador de patron valido y tamaño de bloque valido
    \post Lee y codifica un mensaje mediante el patrón con
          identificador idp, dividiendo el mensaje en bloques de tamaño b. 
  */
  void codificar_patron(int& idp, int& b);

  /** @brief Codifica un mensaje guardado con un patron guardado
    \pre Identificador de patron valido, identificador de mensaje valido, tamaño de bloque valido, Conjunto de mensajes valido
    \post Codifica un mensaje guardado con identificador idm, mediante el patrón con
          identificador idp, dividiendo el mensaje en bloques de tamaño b. 
  */
  void codificar_guardado_patron(int& idp, string& idm, int& b, Cjt_Mensajes& mensajes);
  
  /** @brief Decodifica un mensaje con un patron guardado
    \pre Identificador de patron valido y tamaño de bloque valido
    \post Lee y decodifica un mensaje mediante el patrón con
          identificador idp, dividiendo el mensaje en bloques de tamaño b. 
  */
  void decodificar_patron(int& idp, int& b);

  /** @brief Consulta si existe un patron 
    \pre Identificador de patron valido
    \post Devuelve un booleano que indica si el patron con identificado "idp" existe
  */
  bool existe_patron (const int& idp) const;

  /** @brief Imprime el total de patrones
    \pre Cierto
    \post Imprime el tamaño del vector de patrones
  */
  void imprimir_total_ptr() const;

  /** @brief Lista los cursos
    \pre Cierto
    \post Se listan los patrones del sistema en orden creciente de identificador. 
  */
  void listar_patrones();
  
};
#endif
