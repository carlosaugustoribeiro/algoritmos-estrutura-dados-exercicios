// Exemplo 02 - Implementacao de Pilha Utilizando Alocacao Dinamica de Memoria*

#include <iostream>

using namespace std;

struct No {
    int Info;
    No *Lig;
};

typedef No *Pilha;

void IniciaPilha(Pilha &Topo) {
    Topo = nullptr;
}

Pilha TopoPilha(Pilha Topo) {
    No *Aux = Topo;
    return Aux;
}

bool PilhaVazia(Pilha &Topo) {
    if (Topo == nullptr)
        return true;
    return false;
}

void Empilha(Pilha &Topo, int Elemento) {
    No *Aux = new No;
    Aux->Info = Elemento;
    Aux->Lig = Topo;
    Topo = Aux;
}

bool Desempilha(Pilha &Topo, int &Elemento) {
    if (PilhaVazia(Topo))
        return false;
    Elemento = Topo->Info;
    No *Aux = Topo;
    Topo = Topo->Lig;
    delete Aux;
    return true;
}

int TamanhoPilha(Pilha &pilha) {
    int tamanho = 0;
    int elemento;
    Pilha aux;
    IniciaPilha(aux);
    while (Desempilha(pilha, elemento)) {
        tamanho++;
        Empilha(aux, elemento);
    }
    while (Desempilha(aux, elemento)) {
        Empilha(pilha, elemento);
    }
    return tamanho;
}

float MediaPilha(Pilha &pilha) {
    int tamanho = 0;
    float sum = 0;
    int elemento;
    Pilha aux;
    IniciaPilha(aux);
    while (Desempilha(pilha, elemento)) {
        tamanho++;
        sum += elemento;
        Empilha(aux, elemento);
    }
    while (Desempilha(aux, elemento)) {
        Empilha(pilha, elemento);
    }
    if (tamanho == 0) return 0;
    return sum / tamanho;
}

int MenorPilha(Pilha &pilha) {
    int menor = TopoPilha(pilha)->Info;
    int elemento;
    Pilha aux;
    IniciaPilha(aux);
    while (Desempilha(pilha, elemento)) {
        if (elemento < menor) menor = elemento;
        Empilha(aux, elemento);
    }
    while (Desempilha(aux, elemento)) {
        Empilha(pilha, elemento);
    }
    return menor;
}


int main() {
    Pilha Topo;
    IniciaPilha(Topo);

    int Elemento;

    Empilha(Topo, 1);
    Empilha(Topo, 2);
    Empilha(Topo, 4);

    cout << "Tamanho: " << TamanhoPilha(Topo) << endl;
    cout << "Menor: " << MenorPilha(Topo) << endl;
    cout << "Media: " << MediaPilha(Topo) << endl;

    while (Desempilha(Topo, Elemento))
        cout << "Desempilhando elemento -> " << Elemento << endl;

    if (PilhaVazia(Topo))
        cout << "Pilha Vazia" << endl;

    delete Topo;

    return 0;
}
