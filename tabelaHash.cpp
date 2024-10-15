#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Lista encadeada
class Node{
public:
    int chave;
    Node* prox;
};

class Lista{
private:
    Node* inicio;
    Node* fim;
    int n;
    
public:
    Lista();
    bool inserir(int valor);
    int buscar(int valor);
    void imprimirLista();
};

Lista::Lista(){
    inicio = fim = nullptr;
    n = 0;
}

//insere o valor no na lista
bool Lista::inserir(int valor){
    Node* P = new Node; //aloca um node novo
    if (P){
    //alocou
        P->chave = valor;
        P->prox = nullptr;
        if (inicio == nullptr){ //se a lista esta vazia
            inicio = fim = P;
        }else{//se a lista ja tem elementos
            fim->prox = P;
            fim = P;
        }
        n++;
        return true;
    }
    //nao alocou
    return false;
}

//busca um elemento na lista
int Lista::buscar(int valor) {
    Node* aux = inicio;
    while(aux && aux->chave != valor){//percorre a lista ate achar o valor
        aux = aux->prox;
    }
    if(aux){
        return aux->chave; //retorna o valor encontrado
    }else{
        return -1;//retorna erro
    }
}

//imprime a lista
void Lista::imprimirLista() {
    Node* aux = inicio;
    while(aux){
        cout<<aux->chave<<" ";
        aux = aux->prox;
    }
    cout<<endl;
}

//inicializa a hash
void inicializarHash(Lista tab[], int tam){
    for (int i = 0; i < tam; i++) {
        tab[i] = Lista(); 
    }
}

int funcaoHash(int chave, int tam) {
    return chave % tam;
}

void inserirHash(Lista tab[], int chave, int tam) {
    int idx = funcaoHash(chave, tam);
    tab[idx].inserir(chave); 
}

int buscarHash(Lista tab[], int chave, int tam) {
    int idx = funcaoHash(chave, tam); 
    return tab[idx].buscar(chave);     
}

int main() {
    srand(time(0));

    int n;
    cout<<"Digite o numero de elementos que serao inseridos: ";
    cin>>n;

    int tam = n * 2;
    Lista tabela[tam];

    inicializarHash(tabela, tam);

    int op;
    do {
        cout<<"\nEscolha uma opcao:\n";
        cout<<"1. Inserir elementos na tabela hash\n";
        cout<<"2. Imprimir tabela hash\n";
        cout<<"3. Buscar elemento na tabela hash\n";
        cout<<"4. Sair\n";
        cin>>op;

        switch(op){
            case 1:
                for(int i = 0; i < n; i++){
                    int chave = rand();
                    inserirHash(tabela, chave, tam);
                }
                cout<<"\nOs valores aleatorios foram inseridos na tabela!"<<endl;
                break;
            
            case 2: 
                cout<<"\n";
                for (int i = 0; i < tam; i++) {
                    cout<<"Idx "<<i<<": ";
                    tabela[i].imprimirLista();
                }
                break;
            
            case 3: 
                int chaveBuscada;
                cout<<"\nDigite o valor a ser buscado: ";
                cin>>chaveBuscada;

                int resultado = buscarHash(tabela, chaveBuscada, tam);
                if(resultado != -1){
                    cout<<"O valor "<<chaveBuscada<<" foi encontrado na tabela hash!"<<endl;
                }else{
                    cout<<"O valor nao foi encontrado na tabela hash!"<<endl;
                }
                break;
            
        }
    }while (op != 4);

    return 0;
}
