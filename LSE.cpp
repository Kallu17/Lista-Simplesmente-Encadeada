#include <iostream>
#include <locale>
#include <stdlib.h>

using namespace std;

typedef struct no{
    int num;
    struct no *prox;
}No;

typedef struct no* Lista;

Lista* cria_Lista(){
    Lista* li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }return li;
}

void libera_Lista(Lista* li){
    if(li != NULL){
        No* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int consulta_Lista(Lista* li, int valor){
    if(li == NULL){
        cout<<"Lista Vazia!\n";
        return 0;
    }
    No *no = *li;
    while(no != NULL && no->num != valor){
        no = no->prox;
    }
    if(no == NULL){
        cout<<"ERRO!\n";
        return 0;
    }else{
        no->num;
        return 1;
    }
}

int tamanho_Lista(Lista* li){
    if(li == NULL){
        cout<<"Lista Vazia!\n";
        return 0;
    }
    int tamanho = 0;
    No* no = *li;
    while(no != NULL){
        tamanho++;
        no = no->prox;
    }
    cout<<"Lista tem "<<tamanho<<" Posições!\n";
    return 1;
}

int insere_Posicao(Lista* li, int valor, int posicao){
    if(li == NULL){
        cout<<"Lista Vazia!\n";
        return 0;
    }
    No *no;
    no = (No*) malloc(sizeof(No));
    if(no == NULL){
        cout<<"ERRO!\n";
        return 0;
    }
    no->num = valor;
    no->prox = NULL;
    if((*li) == NULL){
        *li = no;
    }else{
        int tamanho = 0;
        No* aux = *li;
        while(aux != NULL){
            tamanho++;
            aux = aux->prox;
        }
        int cont, pos;
        No *aux2, *aux3;
        aux = *li;
        posicao = posicao-1;
        if(posicao > tamanho_Lista(li)){
            cout<<"Posição inválida!\n";
            return 0;
        }else{
            while(cont < pos){
            aux2 = aux2->prox;
            cont++;
            }
            aux3 = aux2->prox;
            aux2->prox = no;
            no->prox = aux3;
        }
    }
    cout<<"Inserido com sucesso!\n";
    return 1;
}

int insere_Final(Lista* li, int valor){
    if(li == NULL){
        cout<<"Lista Vazia!\n";
        return 0;
    }
    No *no;
    no = (No*) malloc(sizeof(No));
    if(no == NULL){
        cout<<"ERRO!\n";
        return 0;
    }
    no->num = valor;
    no->prox = NULL;
    if((*li) == NULL){
        *li = no;
    }else{
        No *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    cout<<"Inserido com sucesso!\n";
    return 1;
}

int insere_Inicio(Lista* li, int valor){
    if(li == NULL){
        cout<<"Lista Vazia!\n";
        return 0;
    }
    No* no;
    no = (No*) malloc(sizeof(No));
    if(no == NULL){
        cout<<"ERRO!\n";
        return 0;
    }
    no->num = valor;
    no->prox = (*li);
    *li = no;
    cout<<"Inserido com sucesso!\n";
    return 1;
}

int remove_Lista(Lista* li, int valor){
    if(li == NULL){
        cout<<"Lista Vazia!\n";
        return 0;
    }
    if((*li) == NULL){
        cout<<"Lista Vazia!\n";
        return 0;
    }
    No *aux, *no = *li;
    while(no != NULL && no->num != valor){
        aux = no;
        no = no->prox;
    }
    if(no == NULL){
        cout<<"ERRO!\n";
        return 0;
    }
    if(no == *li){
        *li = no->prox;
    }else{
        aux->prox = no->prox;
    }
    free(no);
    cout<<"Removido com sucesso!\n";
    return 1;
}

int imprime_Lista(Lista* li){
    if(li == NULL){
        cout<<"Lista Vazia!\n";
        return 0;
    }
    No* no = *li;
    while(no != NULL){
        cout<<no->num<<"; ";
        no = no->prox;
    }
}


int main(){
    int valor,posicao,insere,tamanho,remover,consulta,op,op1,op2;

    setlocale(LC_ALL, "Portuguese");

    Lista *li = cria_Lista();
    do{
    cout<<"1.Inserir na lista\n2.Remover da lista\n3.Imprimir lista\n4.Tamanho da Lista\n5.Consultar lista\n\n0.Sair\n\n\nEscolha: ";
    cin>>op;
    switch(op){
        case(0):
        break;
        case(1):
            cout<<"1.Inserir por posição: \n2.Inserir no Início: \n3.Inserir no Final: \n\nEscolha: ";
            cin>>op1;
            switch(op1){
                case(1):
                    cout<<"Entre com o dado: ";
                    cin>>valor;
                    cout<<"Posição: ";
                    cin>>posicao;
                    insere = insere_Posicao(li, valor, posicao);
                break;
                case(2):
                    cout<<"Entre com o dado: \n";
                    cin>>valor;
                    insere = insere_Inicio(li, valor);
                break;
                case(3):
                    cout<<"Entre com o dado: \n";
                    cin>>valor;
                    insere = insere_Final(li, valor);
                break;
                default:
                    cout<<"Opção inválida!\n";
                break;
            }
        break;
        case(2):
            cout<<"Digite o número que deseja excluir: ";
            cin>>valor;
            remover = remove_Lista(li, valor);
        break;
        case(3):
            cout<<"Lista: ";
            imprime_Lista(li);
            cout<<endl;
        break;
        case(4):
            tamanho = tamanho_Lista(li);
            cout<<"Tamanho da lista: "<<tamanho<<endl;
        break;
        case(5):
            cout<<"Entre com um numero: ";
            cin>>valor;
            consulta = consulta_Lista(li, valor);
            if(consulta == 1){
                cout<<"Esta contido\n";
            }
            else{
                cout<<"Não esta contido\n";
            }
        break;
        default:
            cout<<"opicao invalida!\n";
        break;
    }
    }while(op!=0);

    return 0;
}
