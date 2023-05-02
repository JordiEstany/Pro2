/** @file Mensaje.cc
    @brief Codigo de la clase Mensaje
*/

#include "Mensaje.hh"

Mensaje::Mensaje(){
getline(cin, texto);
getline(cin, texto);
}

string Mensaje::consul_texto() const{
    return texto;
}
