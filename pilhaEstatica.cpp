#include <iostream>

using namespace std;

class Pilha{
    private:
        int topo;
        int fundo;
        string *item;
    public:
        Pilha(int max){
            fundo = 0;
            topo = fundo;
            item = new string[max];
        }

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
        }
        void empilha(string it);
        void mostra();
        void desempilha(string it);
};

void Pilha::empilha(string it){
    if(topo == max ){
        cout << "pilha cheia" << endl;
    }else{
        topo++;
        item[topo] = it;
    }
}

void Pilha::mostra(){
    for(int i = fundo; i <= topo; i++){
        cout << item[i];        
    }
    cout << endl;
}

void Pilha::desempilha(string it){
    if(topo == fundo){
        cout << "Pilha vazia" << endl;
    }else{
        it = item[topo];
        topo--;
    }
}

int max(){
    Pilha p(6);
    p.empilha("Filip");
    p.empilha("Luiza");
    p.empilha("Julia");
    p.empilha("Bruna");
    p.empilha("Luna");
    p.empilha("Maria");
    p.mostra();
    return 0;
    
}