/**
 * @mainpage <b>Encriptación de mensajes</b>: Programa de encriptación de mensajes de 2 formas distintas.

    
*/

#include "Cjt_Rejillas.hh"
#include "Cjt_Patrones.hh"


/** @file program.cc
    @brief Programa principal para el ejercicio <b>Encriptación de mensajes</b>.
*/


/** @brief Programa principal <b>Encriptación de mensajes</b>.
*/
int main(){

  Cjt_Mensajes ms;
  Cjt_Rejillas re;
  Cjt_Patrones pt;

    ms.inicializar_msg();
    re.inicializar_rej();
    pt.inicializar_ptr();

    string op;

    cin >> op;

    while(op != "fin"){

        if(op == "nuevo_mensaje" or op == "nm"){
            string idm;
            cin >> idm;
            cout << "#" << op << " " << idm << endl;
            if (not ms.existe_msg(idm)) {
                ms.add_msg(idm);
                ms.imprimir_total_msg();
            }
            else cout << "error: ya existe un mensaje con ese identificador" << endl;
        }
        
        else if(op == "nueva_rejilla" or op == "nr"){
            cout << "#" << op << endl;
            re.add_rejilla();          
        }

        else if(op == "nuevo_patron" or op == "np"){
            cout << "#" << op << endl;
            pt.nuevo_patron();          
        }
        
        else if(op == "borra_mensaje" or op == "bm"){
            string idm;
            cin >> idm;
            cout << "#" << op << " " << idm << endl;
            if (ms.existe_msg(idm)) {
                ms.borrar_msg(idm);
                ms.imprimir_total_msg();               
            }
            else cout << "error: el mensaje no existe" << endl;
        }
        
        else if(op == "listar_mensajes" or op == "lm"){
            cout << "#" << op << endl;
            ms.listar_msg();
        }
        
        else if(op == "listar_rejillas" or op == "lr"){
            cout << "#" << op << endl;
            re.listar_rejillas();
        }
        
        else if(op == "listar_patrones" or op == "lp"){
            cout << "#" << op << endl;
            pt.listar_patrones();
        }
        
        else if(op == "codificar_rejilla" or op == "cr"){
            int idr;
            cin >> idr;
            cout << "#" << op << " " << idr << endl;
            if (re.existe_rejilla(idr)) {
                re.codificar_rejilla(idr);
            }
            else cout << "error: la rejilla no existe" << endl;
        }
        
        else if(op == "codificar_guardado_rejilla" or op == "cgr"){
            int idr;
            string idm;
            cin >> idm >> idr;
            cout << "#" << op << " " << idm << " " << idr << endl;
            if (ms.existe_msg(idm)) {
                if (re.existe_rejilla(idr)) {
                    re.codificar_guardado_rejilla(idr, idm, ms);
                }
                else cout << "error: la rejilla no existe" << endl;
            }
            else cout << "error: el mensaje no existe" << endl;
        }
        
        else if(op == "decodificar_rejilla" or op == "dr"){
            int idr;
            cin >> idr;
            cout << "#" << op << " " << idr << endl;
            if (re.existe_rejilla(idr)) {
                re.descodificar_rejilla(idr);
            }
            else cout << "error: la rejilla no existe" << endl;
        }
        
        else if(op == "codificar_patron" or op == "cp"){
            int idp, b;
            cin >> idp >> b;
            cout << "#" << op << " " << idp << " " << b << endl;
            if (pt.existe_patron(idp)) {
                pt.codificar_patron(idp, b);
            }
            else cout << "error: el patron no existe" << endl;
        }
        
        else if(op == "codificar_guardado_patron" or op == "cgp"){
            string idm;
            int b, idp;
            cin >> idm >> idp >> b;
            cout << "#" << op << " " << idm << " " << idp << " " << b << endl;
            if (ms.existe_msg(idm)) {
                if (pt.existe_patron(idp)) {
                    pt.codificar_guardado_patron(idp, idm, b, ms);
                }
                else cout << "error: el patron no existe" << endl;
            }
            else cout << "error: el mensaje no existe" << endl;
        }

        else if(op == "decodificar_patron" or op == "dp"){
            int idp, b;
            cin >> idp >> b;
            cout << "#" << op << " " << idp << " " << b << endl;
            if (pt.existe_patron(idp)) {
                pt.decodificar_patron(idp, b);
            }
            else cout << "error: el patron no existe" << endl;
        }
        
        cin >> op;

    }
}