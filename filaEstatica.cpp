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

class Fila{
    private:
        int frente;
        int tras;
        Tarefa *tarefa;
        int TAM;
        bool cheia();
        bool vazia();
    public:
        Fila(int tam){
            frente = 0;
            tras = frente;
            TAM = tam;
            tarefa = new Tarefa[TAM];
        }
        void enfileira(Tarefa t);
        void mostra();
        void desenfileira(Tarefa t);
};

bool Fila::cheia(){
    return (tras + 1) % TAM == frente;
}

bool Fila::vazia(){
    return tras == frente;
}

void Fila::enfileira(Tarefa t){
    if(cheia()){
        cout << "Fila Cheia";
    }else{
        tarefa[tras] = t;
        tras = (tras + 1) % TAM;
    }
}

void Fila::mostra(){
    for(int i = frente; i >= tras; i--){
        tarefa[i].printInfo();
    }
    cout << endl;
}

void Fila::desenfileira(Tarefa t){
    if(vazia()){
        cout << "Fila vazia" << endl;
    }else{
        t = tarefa[frente];
        frente = (frente + 1) % TAM;
    }
}

int main(){
    Fila f(6);
    Tarefa a(1,"A");
    Tarefa b(1,"B");
    Tarefa c(1,"C");
    Tarefa d(1,"D");
    Tarefa e(1,"E");

    f.enfileira(a);
    f.enfileira(b);
    f.enfileira(c);
    f.enfileira(d);
    f.enfileira(e);
    f.mostra();
    return 0;
    
}