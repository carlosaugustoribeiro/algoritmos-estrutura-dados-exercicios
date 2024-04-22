// Implementacao de Fila Utilizando Alocacao Dinamica

#include <iostream>

using namespace std;

struct No{
    int Info;
    No *Lig;
};

typedef No *NoPtr;

struct Fila{
    NoPtr Com;
    int Nro;
    NoPtr Fim;
};

void IniciaFila(Fila& F){
    F.Nro = 0;
    F.Com = nullptr;
    F.Fim = nullptr;
}

bool FilaVazia(Fila F){
    return !F.Nro;
}

void InsereFila(Fila& F, int Novo){
    NoPtr P = new No;
    P->Info = Novo;
    P->Lig = nullptr;
    if (F.Nro == 0)
        F.Com = F.Fim = P;
    else {
        F.Fim->Lig = P;
        F.Fim = P;
    }
    F.Nro++;
}

bool RetiraFila(Fila& F, int& Valor){
    if (FilaVazia(F))
        return false;
    else {
        NoPtr P = F.Com;
        Valor = P->Info;
        F.Com = P->Lig;
        F.Nro--;
        if (F.Nro == 0)
            F.Fim = nullptr;
        delete P;
    }
    return true;
}

NoPtr Primeiro(Fila& F){
    NoPtr P = F.Com;
    return P;
}

void InverteFila(Fila &fila) {
    if (!FilaVazia(fila)) {
        int valor;
        RetiraFila(fila, valor);
        InverteFila(fila);
        InsereFila(fila, valor);
    }
}


int main (){

    Fila F;
    IniciaFila(F);

    if(FilaVazia(F))
        cout << "Fila Vazia " << endl;
    else cout << "Fila nao vazia " << endl;

    InsereFila (F, 1);
    InsereFila (F, 2);
    InsereFila (F, 3);

    InverteFila(F);

    if(FilaVazia(F))
        cout << "Fila Vazia " << endl;
    else cout << "Fila nao vazia " << endl;

    int valor;
    while(RetiraFila(F,valor))
        cout << "Valor retirado da fila: "<< valor << endl;

    if(FilaVazia(F))
        cout << "Fila Vazia " << endl;
    else cout << "Fila nao vazia " << endl;

    return 0;
}
