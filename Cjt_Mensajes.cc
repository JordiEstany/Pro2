/** @file Cjt_Mensajes.cc
    @brief Codigo de la clase Cjt_Mensajes
*/


#include "Cjt_Mensajes.hh"
Cjt_Mensajes::Cjt_Mensajes(){}


void Cjt_Mensajes::inicializar_msg() {
    int m;
    string idm;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> idm;
        Mensaje msg;
        mapa_msg.insert(make_pair(idm, msg));
    }
}

void Cjt_Mensajes::add_msg(string& idm) {
    Mensaje msg;
    mapa_msg.insert(make_pair(idm, msg));    
}

void Cjt_Mensajes::borrar_msg(string& idm) {
    mapa_msg.erase(idm);    
}

bool Cjt_Mensajes::existe_msg(string& idm) const {
    return mapa_msg.find(idm) != mapa_msg.end();
}

void Cjt_Mensajes::imprimir_total_msg() const{
    cout << mapa_msg.size() << endl;
}

void Cjt_Mensajes::listar_msg() {
    vector<pair<string, Mensaje>> vector_mensajes;

    for (map<string, Mensaje>::iterator it = mapa_msg.begin(); it != mapa_msg.end(); ++it) {
        vector_mensajes.push_back(make_pair(it->first, it->second));
    }

    sort (vector_mensajes.begin(), vector_mensajes.end(), cmp);

    for (int i = 0; i < vector_mensajes.size(); ++i) {
        cout << vector_mensajes[i].first << endl;
        cout << '"' << vector_mensajes[i].second.consul_texto() << '"' << endl;
    }
}

bool Cjt_Mensajes::cmp(const pair <string, Mensaje> &mensaje1, const pair <string, Mensaje> &mensaje2){
    return mensaje1.first < mensaje2.first;
}

string Cjt_Mensajes::devolver_mensaje(string idm){
    map<string, Mensaje>::iterator it = mapa_msg.find(idm);
    return (it->second).consul_texto();
}
