/** @file Rejilla.cc
    @brief Codigo de la clase Rejilla
*/

#include "Rejilla.hh"

Rejilla::Rejilla() {}

void Rejilla::leer_rejilla(int& nn, int& kk){
    n = nn;
    k = kk;
    int H1, H2;
    for (int i = 0; i < k; ++i) {
        cin >> H1 >> H2;
        huecos_ordenados.push_back(make_pair(H1-1, H2-1));
    }
    for (int i = 0; i < k; ++i) {   
        H1 = n - 1 - huecos_ordenados[i].second;
        H2 = huecos_ordenados[i].first;   
        huecos_ordenados.push_back(make_pair(H1, H2));
    }
    for (int i = k; i < 2*k; ++i) {   
        H1 = n - 1 - huecos_ordenados[i].second;
        H2 = huecos_ordenados[i].first;   
        huecos_ordenados.push_back(make_pair(H1, H2));
    }
    for (int i = 2*k; i < 3*k; ++i) {   
        H1 = n - 1 - huecos_ordenados[i].second;
        H2 = huecos_ordenados[i].first;   
        huecos_ordenados.push_back(make_pair(H1, H2));
    }

    sort (huecos_ordenados.begin(), huecos_ordenados.begin()+k, cmp);
    sort (huecos_ordenados.begin() + k, huecos_ordenados.begin() + 2*k, cmp);
    sort (huecos_ordenados.begin() + 2*k, huecos_ordenados.begin() + 3*k, cmp);
    sort (huecos_ordenados.begin() + 3*k, huecos_ordenados.begin() + 4*k, cmp);
}

void Rejilla::escribir_rejilla() {
    cout << n << " " << k << endl;
    for (int i = 0; i < k; ++i) {
        cout << "("<< huecos_ordenados[i].first + 1 << "," << huecos_ordenados[i].second + 1 << ")";
        if (i < k - 1) cout << " ";
    }
    cout << endl;

    for (int i = k; i < 2*k; ++i) {
        cout << "("<< huecos_ordenados[i].first  + 1<< "," << huecos_ordenados[i].second + 1<< ")";
        if (i < 2*k - 1) cout << " ";
    }
    cout << endl;

    for (int i = 2*k; i < 3*k; ++i) {
        cout << "("<< huecos_ordenados[i].first  + 1<< "," << huecos_ordenados[i].second + 1<< ")";
        if (i < 3*k - 1) cout << " ";
    }
    cout << endl;

    for (int i = 3*k; i < 4*k; ++i) {
        cout << "("<< huecos_ordenados[i].first  + 1<< "," << huecos_ordenados[i].second + 1<< ")";
        if (i < 4*k - 1) cout << " ";
    }
    cout << endl;
}

void Rejilla::codificar_rej(string& p){   
    char matriz[n][n];
    int pos = 0;
    cout << '"';
    while (pos < p.size()) {
        for (int i = 0; i < 4*k; i++) {
            if (pos < p.size()){
               matriz[(huecos_ordenados[i].first)][(huecos_ordenados[i].second)] = p[pos];
                ++pos; 
            }
            else matriz[(huecos_ordenados[i].first)][(huecos_ordenados[i].second)] = ' ';
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matriz[i][j];
            }
        }
    }    
    cout << '"' << endl;
}

bool Rejilla::cmp(const pair <int, int> &i, const pair <int, int> &j){
    if (i.first != j.first) {
        return (i.first < j.first);
    } 
    else return (i.second < j.second);
}

void Rejilla::decodificar(string& p){
    vector<vector<char>> matriz(n, vector<char>(n));
    int pos = 0;    

    if ((p.size())%(n*n) == 0) {
        cout << '"';
        for (int i = 0; i < (p.size()/(n*n)); i++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {                
                matriz[i][j] = p[pos];
                pos++;                                
            }
        }
        
        for (int i = 0; i < 4*k; i++) cout << matriz[(huecos_ordenados[i].first)][(huecos_ordenados[i].second)];
        }
    cout << '"' << endl;
    }
    else cout << "error: la dimension del mensaje es inadecuada para la rejilla" << endl;
    
}


bool Rejilla::interseccion() const{
    vector<int> numbers(n);
    for (int i = 0; i < 4*k; i++) {
        numbers[huecos_ordenados[i].first]++;
        numbers[huecos_ordenados[i].second]++;
    }
    for (int i = 0; i < n; i++) {
        if (numbers[i] != 2*n) return true;
    }
    return false;
}