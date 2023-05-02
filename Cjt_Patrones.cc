/** @file Cjt_Patrones.cc
    @brief Codigo de la clase Cjt_Patrones
*/

#include "Cjt_Patrones.hh"

Cjt_Patrones::Cjt_Patrones(){}

void Cjt_Patrones::inicializar_ptr() {
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        Patron p;
        p.leer_patron();
        vector_ptr.push_back (p);
    }
}

void Cjt_Patrones::nuevo_patron() {
    Patron p;
    p.leer_patron();
    vector_ptr.push_back (p);
    imprimir_total_ptr();
}

void Cjt_Patrones::listar_patrones() {
    for (int i = 0; i < vector_ptr.size(); ++i) {
        cout << "Patron " << i + 1 << ':' << endl;
        vector_ptr[i].escribir_patron();
        cout << endl;
    }
}

void Cjt_Patrones::imprimir_total_ptr() const{
    cout << vector_ptr.size() << endl;
}


bool Cjt_Patrones::existe_patron(const int& idp) const{
    if (idp != 0 and idp <= vector_ptr.size()) return true;
    else return false;
}


void Cjt_Patrones::codificar_patron(int& idp, int& b) {
    string a;
    getline(cin , a);
    getline(cin , a);
    vector_ptr[idp-1].codificar(a, b);
}

void Cjt_Patrones::codificar_guardado_patron(int& idp, string& idm, int& b, Cjt_Mensajes& mensajes){
    string a;
    a = mensajes.devolver_mensaje(idm);
    vector_ptr[idp-1].codificar(a, b);
}

void Cjt_Patrones::decodificar_patron(int& idp, int& b) {
    string a;
    getline(cin, a);
    getline(cin, a);
    vector_ptr[idp-1].decodificar(a, b);
}





