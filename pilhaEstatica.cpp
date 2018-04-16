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

class Pilha{
    private:
        int topo;
        int fundo;
        Tarefa *tarefa;
        int TAM;
    public:
        Pilha(int tam){
            fundo = 0;
            topo = fundo;
            TAM = tam;
            tarefa = new Tarefa[TAM];
        }
        /*
        void setTopo(int topo){
            this->topo = topo;
        }

        void setFundo(int fundo){
            this->fundo = fundo;
        }
        int getTopo(){
            return topo;
        }

        int getFundo(){
            return fundo;
        }*/
        void empilha(Tarefa t);
        void mostra();
        void desempilha(Tarefa t);
};

void Pilha::empilha(Tarefa t){
    if(topo == tam ){
        cout << "pilha cheia" << endl;
    }else{
        topo++;
        tarefa[topo] = t;
    }
}

void Pilha::mostra(){
    for(int i = fundo; i <= topo; i++){
         tarefa[i].printInfo();
         cout << endl;       
    }
}

void Pilha::desempilha(Tarefa t){
    if(topo == fundo){
        cout << "Pilha vazia" << endl;
    }else{
        t = tarefa[topo];
        topo--;
    }
}

int max(){
    Pilha p(6);
    p.empilha(1,"Filip");
    p.empilha(2,"Luiza");
    p.empilha(3,"Julia");
    p.empilha(4,"Bruna");
    p.empilha(5,"Luna");
    p.empilha(6,"Maria");
    p.mostra();
    return 0;
    
}