/*
Autores: 
David Hinojosa González - A01720601
Sebastián Joya Páez - A01025103
Ricardo Jorge Rodríguez Treviño - A00831595
Fecha: 21/11/2021
Descripción: Se le solicitan al usuario tanto los nombres, como las conexiones existentes entre los puertos ubicados en el 
canal de Suez. Esto con el fin de posteriormente solicitar un número máximo de puertos (MNP), que representará la cantidad de 
los mismos en los cuales un carguero podrá atracar antes de tener que recorrer la ruta en sentido contrario. Dada de una red 
de puertos, un puerto inicial de un carguero y un valor MNP, se determinará la cantidad de puertos que no lograrán ser visitados 
por ese carguero.
*/

#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

// Se carga cada uno de los arcos y nodos pertenecientes al grafo en una Lista de Adjacencia
// Complejidad: O(n)
void loadGraph(map<string,vector<string>> &listAdj, int m){
    string a, b;
    for (int i = 0; i<m; ++i) {
        cin >> a >> b;
        listAdj[a].push_back(b);
        listAdj[b].push_back(a);
    }
} 

// Se realiza el recorrido por medio del BFS (por anchura) a partir de un nodo inicial.
// De igual forma, se regresa la cantidad de puertos visitados por el carguero durante su
// recorrido.
// Complejidad: O(|V|+|E|)
void BFS(map<string,vector<string>> listAdj, string data, int mnp, int &cont, int m){   
    vector<string>::iterator itr = listAdj[data].begin();
    int count = 0; 
    queue<string> fila;
    map<string, bool> status;
    string dato;     
    while (itr != listAdj[data].end()) {  
        ++itr;
        count++;
    }
    mnp = mnp*(count+1);
    fila.push(data);
    status[data] = true;
    while (mnp){
        dato = fila.front();
        fila.pop();
        cont++;
        if (cont == listAdj.size()){
            break;
        }
        for (auto i : listAdj[dato]){
            if (!status[i]){
                fila.push(i);
                status[i] = true;
            }
        }
        mnp--;
    }
}

int main()
{
    // n = cantidad de nodos
    // m = cantidad de arcos   
    int n, m;
    cin >> n >> m;

    map<string,vector<string>> listAdj;
    vector<string> aux;
    string dato_aux;

    // Se cargan los nombres de los puertos del canal en un vector
    for (int i=0; i<n; i++){
        cin >> dato_aux;
        aux.push_back(dato_aux);
    }

    // Se cargan los datos correspondientes al grafo
    loadGraph(listAdj, m);

    int nq, mnp;
    string nombre;

    // Se lee el número de consultas deseadas
    cin >> nq;

    // Se realiza el número de recorridos deseado en base a la cantidad definida anteriormente, y el nombre del puerto especificado
    for(int i=0; i<nq; i++){
        cin >> nombre >> mnp;
        int cont = 0;
        BFS(listAdj, nombre, mnp, cont, m);
        cout << "Case " << i+1 << ": " << n-cont << " ports not reachable from port " << nombre << " with MNP = " << mnp << endl;
    }
}
