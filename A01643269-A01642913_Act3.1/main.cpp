/* 
Descripción:
Implementación de la estructura de datos llamada trie, la cual es una tipo de árbol; cada nodo puede tener cierta cantidad de nodos hijos,
dependerá del propósito del trie. En este caso usamos esta estructura para insertar y buscar palabras.
Cada nodo de este trie está compuesto por dos elementos, un hashmap (key: char, value: *node) y en valor
booleano.
En palabras generales, cada nodo guarda la letra (char) que representa y las conexiones o enlaces que tiene con otras letras,
además del valor booleano que nos ayuda a identificar el final de cada palabra o secuencia que se inserta.
El uso del hashmap es para mejorar la búsqueda y la inserción de palabras o secuencias, ya que nos permite saber si cieto carácter
ya se encuentra en los hijos o conexiones de manera constante O(1) y así conseguir una complejidad de O(n) para insertar,
y de O(n) para buscar, donde n es la longitud de la palabra (aunque esto depende de las colisiones que pudiera llegar a tener el hashmap).

Autores: 
Gael Venegas Gómez - A01642913
Arturo Ramos Martínez - A01643269 

Fecha: 10/Oct/2024

*/
#include<iostream>
#include<unordered_map>
using namespace std;

//Definicion del nodo 
struct trieNode{
    unordered_map<char, trieNode*> children; // hashmap para guardar los hijos de cada nodo, de acuerdo a las conexiones o vinculos de cada caractér.
    bool wordCompleted; //Para indicar el final de una palabra/secuencia.

    trieNode(){
        wordCompleted = false;
    }
};

//Definición de la clase, con sus dos métodos (insert y search).
class Trie{
    public: 
        trieNode* root;

        Trie(){
            root = new trieNode();
        }

        void insert(string word);
        bool search(string word);
        void dfs(trieNode* currNode, string word);
};

/* Método insert el cual recibe una palabra, la recorre, y en cada iteración revisa si alguno de los caracteres ya existía,
   si no, crea una nueva conexión a un nuevo nodo con el vínculo al carácter de esa iteración.
   Finalmente avanza al carácter que acaba de crear y una vez que el ciclo termina, marca el último nodo como true, para saber cuando termina la palabra.
 */
void Trie::insert(string word){
    trieNode* currNode = root;
    int wordLen = word.size();

    for(int i = 0; i < wordLen; i++){
        if(currNode->children.count(word[i]) == 0){
            currNode->children[word[i]] = new trieNode();
        }
        currNode = currNode->children[word[i]];
    }

    currNode->wordCompleted = true;
}

/*
    Método search, el cual nos regresa un valor booleano, indicando si la palabra se encuentra o no en el trie.
    este método es muy parecido al de insert, ya que igualmente itera la palabra que se le pasa como parámetro y
    en cada iteración va verificando que el carácter actual exista y va avanzando hacia él; en el momento que alguno
    de los caracteres no se encuentre, se retorna un false automáticamente, pero si el ciclo termina, se retorna el
    atributo (wordCompleted) del nodo donde termina la palabra, el cual será "true".
 */

bool Trie::search(string word){
    trieNode* currNode = root;
    int wordLen = word.size();

    for(int i = 0; i < wordLen; i++){
        if(currNode->children.count(word[i]) == 0){
            return false;
        }
        currNode = currNode->children[word[i]];
    }

    return currNode->wordCompleted;
}

/*
    Este método es recursivo, recibe como parámetros el nodo actual y la palabra que hasta el momento se ha formado,
    Si el atributo (wordCompleted) del nodo actual es true significa que una palabra se ha recorrido/alcanzado, por lo que se imprime.
    Además, para cada llamada, se recorre el mapa de cada nodo (currNode->children) y se van agregando los caracteres a la variable word,
    cuando en la llamada recursiva actual se terminan las llamadas recursivas consecuentes, quiere decir que el fin de una palabra se ha alcanzado,
    por lo que necesitamos eliminar el último carácter de la variable word, para poder seguir imprimiendo futuras palabras correctamente.

    Cabe mecionar que no se imprimiran en orden, porque el hashmap no lo toma en cuenta. 
 */
void Trie::dfs(trieNode* currNode, string word){
    if(currNode->wordCompleted){
        cout << word << endl;
    }

    for (const auto& pair : currNode->children) {
        word.push_back(pair.first);
        dfs(pair.second, word);
        word.pop_back();
    }
}

int main(){
    int numberWords, numberSearches;
    cin>>numberWords;

    Trie myTrie;

    string word;
    //Insert
    for(int i = 0; i < numberWords; i++){
        cin>>word;
        myTrie.insert(word);
    } 

    //Traverse dfs
    myTrie.dfs(myTrie.root, "");

    cin>>numberSearches;

    //Search
    for(int i = 0; i < numberSearches; i++){
        cin>>word;
        cout << myTrie.search(word) << endl;
    } 
    return 0;
}