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

        No *getProx(){
            return prox;
        }

        void setTarefa(Tarefa t){
            this->t = t;
        }

        Tarefa getTarefa(){
            return t;
        }
};

class Lista{
    private:
        No *prim, *ult;
        No *pred(No*);
        bool vazia();
    public:
        Lista(){
            prim = new No();
            prim->setProx(NULL);
            ult = prim;
        }
        void insere(Tarefa);
        No* busca(Tarefa);
        void remove(No*, Tarefa&);
        void print();
};

No*Lista::pred(No *r){
    No *p = prim->getProx();
    while(p->getProx() != r){
        p = p->getProx();

    }
    return p;
}

bool Lista::vazia(){
    return prim == ult;
}

void Lista::insere(Tarefa t){
    ult->setProx(new No());
    ult = ult->getProx();
    ult->setProx(NULL);
    ult->setTarefa(t);


}

void Lista::print(){
    No *p = prim->getProx();
    while(p != NULL){
        p->getTarefa().printInfo();
        p = p->getProx();
        cout << endl;
    }
}

No*Lista::busca(Tarefa t){
    No *p = prim->getProx();
    while(p != NULL && p->getTarefa().getDesc() != t.getDesc()){
        p = p->getProx();
    }
    return p;
}

void Lista::remove(No *r, Tarefa &t){
    if(vazia() || r == NULL || r == prim){
        cout << "Impossivel remover" << endl;
    }else{
        t = r->getTarefa();
        No *p = pred(r);
        p->setProx(r->getProx());
        if(p->getProx() == NULL){
            ult = p;
        }
        delete r;
    }
}

int main(){
    Tarefa a(1,"tocar violao");
    Tarefa b(2,"jogar dota");
    Tarefa c(3,"dormir");
    Tarefa d(4,"comer");

    Lista l;
    l.insere(a);
    l.insere(b);
    l.insere(c);
    l.insere(d);

    l.print();

    cout << endl;

    Tarefa e(5, "Correr");
    No *x = l.busca(e);
    if(x == NULL){
        cout << "Descricao nao encontrado" << endl;
    }
    else{
        x->getTarefa().printInfo();

    }
    return 0;
}
