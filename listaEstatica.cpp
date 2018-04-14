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

class Lista{
    private:
        Tarefa *tarefa;
        int TAM;
        int n;
        bool posicaoValida(int pos);
        bool vazia();
    public:
        Lista(int tam){
            n = 0;
            TAM = tam;
            tarefa = new Tarefa[TAM];
        }
        void insere(Tarefa t);
        void mostra();
        Tarefa*busca(string desc);
        void remove(int pos, Tarefa &t);
        int minimo(Tarefa &t);
};

void Lista::insere(Tarefa t){
    if(n < TAM){
        n++;
        tarefa[n] = t; 
    }
    else{
        cout << "Lista Cheia" << endl;
    }

}

void Lista::mostra(){
    for(int i = 1; i <= n; i++){
         tarefa[i].printInfo();
         cout << endl;
    }
}

Tarefa*Lista::busca(string desc){
    tarefa[0].setDesc(desc);
    int i = n;
    while(desc != tarefa[i].getDesc()){
        i--;
    }
    if(i > 0){
        return &tarefa[i];
    }
    else return NULL;
}

bool Lista::posicaoValida(int pos){
    return 1 <= pos && pos <= n;
}

bool Lista::vazia(){
    return n == 0;
}

void Lista::remove(int pos, Tarefa &t){
    if(!vazia() && posicaoValida(pos)){
        t = tarefa[pos];
        for(int i = pos; i < n; i++){
            tarefa[i] = tarefa[i+1];
        }
        n--;
    }else{
        cout << "lista vazia ou posicao invalida" << endl;
    }
}

int Lista::minimo(Tarefa &t){
    int min = 1;
    for(int i = 1; i <= n; i++){
        if(tarefa[i].getId() < tarefa[min].getId()){
            min = i;
        }
    }
    return &tarefa[min];
}


int main(){
    Tarefa a(1,"tocar violao");
    Tarefa b(2,"jogar dota");
    Tarefa c(3,"dormir");
    Tarefa d(4,"comer");

    Lista l(5);
    l.insere(a);
    l.insere(b);
    l.insere(c);
    l.insere(d);
    l.mostra();

    cout << "\n";

    string k = "dormir";
    Tarefa *x = l.busca(k);
    if(x == NULL){
        cout << "Descrição nao encontrada" << endl;
    }
    else{
        cout << "(Busca): ";
        x->printInfo();
    }
    cout << endl;

    Tarefa y;
    l.remove(4,y);
    l.mostra();
    cout << "removido: ";
    y.printInfo();
    cout << endl;

    l.minimo(a);
   
    return 0;
}