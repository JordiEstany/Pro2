/** @file Patron.cc
    @brief Codigo de la clase Patron
*/

#include "Patron.hh"

Patron::Patron() {}

void Patron::leer_patron(){
    leer_patron_recursiva(arbolpatron);

}

void Patron::escribir_patron(){
    escribir_patron_recursiva(arbolpatron);
}

void Patron::codificar(string& p, int b){
    char c;
    list<int> l;
    if (b > p.length()) b = p.length();
    generar_lista_patron(arbolpatron, b, l);

    list<int>::iterator it = l.begin();    
    cout << '"';
    for (int i = 0; i<p.length(); i++) {
        if (it == l.end()) it = l.begin();
        c = 32 + (p[i] + *it - 32)%95;
        cout << c;
        it++;
    }
    cout << '"' << endl;
}

void Patron::escribir_patron_recursiva(const BinTree<int>& a){
    
    if (not a.empty()){    
        cout << '(';
        cout << a.value();     
        escribir_patron_recursiva(a.left());
        escribir_patron_recursiva(a.right());        
        cout << ')';
    }
    else cout << '(' << ')';
    
}



void Patron::leer_patron_recursiva(BinTree<int>& a){
    int s;
    if (cin >> s and s != (-1)){
        BinTree<int> a1;
        BinTree<int> a2;

        leer_patron_recursiva(a1);
        leer_patron_recursiva(a2);
        a = BinTree<int> (s,a1,a2);
    }
}


void Patron::generar_lista_patron(const BinTree<int>& a, int& b, list<int>& l) {
    if (not a.empty()) {
        queue<BinTree<int>> c;
                
        c.push(a);
        while (not c.empty())
        {
            BinTree<int> aux = c.front();
            c.pop();
            l.push_back(aux.value());
            if (b-1 > 0) {
                if (not aux.left().empty()) c.push(aux.left());
                else c.push(arbolpatron);
                b--;
                    
            }
            if (b-1 > 0) {
                if (not aux.right().empty()) c.push(aux.right());
                else c.push(arbolpatron);
                b--;  
            }           
            
        }
        
    }
    
}

void Patron::decodificar(string& p, int b){
    char c;
    list<int> l;
    if (b > p.length()) b = p.length();
    generar_lista_patron(arbolpatron, b, l);

    list<int>::iterator it = l.begin();    
    cout << '"';
    for (int i = 0; i<p.length(); i++) {
        if (it == l.end()) it = l.begin();
        int x = (p[i]  - *it - 32)%95;
        if (x >= 0) c = 32 + x;
        else c = 127 + x;
        cout << c;
        it++;
    }
    cout << '"' << endl;
}