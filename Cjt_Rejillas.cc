/** @file Cjt_Rejillas.cc
    @brief Codigo de la clase Cjt_Rejillas
*/

#include "Cjt_Rejillas.hh"

Cjt_Rejillas::Cjt_Rejillas(){}

void Cjt_Rejillas::inicializar_rej() {
    int r, nn, kk;
    cin >> r;
    for (int i = 0; i < r; ++i) {
        cin >> nn >> kk;
        Rejilla rej;
        rej.leer_rejilla(nn, kk);
        vector_rej.push_back(rej);
    }
}

void Cjt_Rejillas::add_rejilla() {
    int nn, kk;
    cin >> nn >> kk;
    if (nn > 3 and nn%2 == 0 and kk == (nn*nn)/4) {
        Rejilla rej;
        rej.leer_rejilla(nn, kk);
        if (not rej.interseccion()) {
            vector_rej.push_back(rej);
            cout << vector_rej.size() << endl;
        }
        else cout << "error: la rejilla con sus giros no cubre todas las posiciones N x N" << endl; 
    }
    else cout << "error: dimensiones incorrectas de la rejilla" << endl; 
}

void Cjt_Rejillas::listar_rejillas() {
    for (int i = 0; i < vector_rej.size(); ++i) {
        cout << "Rejilla " << i + 1 << ":" << endl;
        vector_rej[i].escribir_rejilla();
    }
}

void Cjt_Rejillas::imprimir_total_rej() const{
    cout << vector_rej.size() << endl;
}


bool Cjt_Rejillas::existe_rejilla(const int& idr) const{
    if (idr != 0 and idr <= vector_rej.size()) return true;
    else return false;
}


void Cjt_Rejillas::codificar_rejilla(int& idr) {
    string a;
    getline(cin, a);
    getline(cin, a);
    vector_rej[idr-1].codificar_rej(a);
}


void Cjt_Rejillas::codificar_guardado_rejilla(int& idr, string& idm, Cjt_Mensajes& mensajes){
    string a;
    a = mensajes.devolver_mensaje(idm);
    vector_rej[idr-1].codificar_rej(a);
}

void Cjt_Rejillas::descodificar_rejilla(int& idr) {
    string a;
    getline(cin, a);
    getline(cin, a);
    vector_rej[idr-1].decodificar(a);
}

