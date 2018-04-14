#include <iostream>

using namespace std;


class Tarefa{
    private:
        int id;
        string desc;
    public:
        Tarefa(){};
        Tarefa(int id, string desc){
            this->id = id;
            this->desc = desc;
        }
        void setId(int id){
            this->id = id;
        }
        
        void setDesc(string desc){
            this->desc = desc;
        }

        int getId(){
            return id;
        }

        string getDesc(){
            return desc;
        }
        
        void printInfo(){
            cout << id << "-";
            cout << desc;
        }
};

class No{
    private:
        Tarefa t;
        No *prox;
    public:
        No(){
            this->prox = NULL;
        }
        No(Tarefa t){
            this->t = t;
            this->prox = NULL;
        }

        void setProx(No *prox){
            this->prox = prox;
        }

        void setTarefa(Tarefa t){
            this->t = t;
        }

        No *getProx(){
            return prox;
        }

        Tarefa getTarefa(){
            return t;
        }
};

class Pilha{
    private:
        No *topo, *fundo;
    public:
        Pilha(){
            fundo = new No();
            fundo->setProx(NULL);
            topo = fundo;
        }
        void empilha(Tarefa t);
        void mostra();
        void desempilha();
};

void Pilha::empilha(Tarefa t){
    No *aux = new No();
    topo->setTarefa(t);
    aux->setProx(topo);
    topo = aux;
}

void Pilha::mostra(){
    No *p = topo->getProx();
    while(p != NULL){
        p->getTarefa().printInfo();
        p = p->getProx();
        cout << endl;
    }
}

void Pilha::desempilha(Tarefa t){
    No *aux = topo;
    topo = topo->getProx();
    t = topo->getTarefa();
    delete aux;
}