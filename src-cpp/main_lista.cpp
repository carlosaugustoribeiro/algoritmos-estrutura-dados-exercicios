// Lista Ponteiros
// Sandro Izidoro - 2020

#include <iostream>

using namespace std;

struct No {
    int Info;
    No *Lig;
};

typedef struct No *NoPtr;


void InsereLista(NoPtr &L, int Novo) {
    if (L == nullptr) {
        // INSERCAO DO PRIMEIRO NO
        L = new No;
        L->Info = Novo;
        L->Lig = nullptr;
    } else {
        // AJUSTA PONTEIROS ANT E AUX
        NoPtr Ant = nullptr;
        NoPtr Aux = L;
        while ((Aux != nullptr) && (Aux->Info < Novo)) {
            //ENCONTRA POSICAO
            Ant = Aux;
            Aux = Aux->Lig;
        }
        Aux = new No;
        Aux->Info = Novo; // INSERE O NO E AJUSTA PONTEIROS
        if (Ant == nullptr) {
            Aux->Lig = L;
            L = Aux;
        } else {
            Aux->Lig = Ant->Lig;
            Ant->Lig = Aux;
        }
    }
}

bool RetiraLista(NoPtr &L, int Novo) {
    NoPtr Ant = nullptr;
    NoPtr Aux = L;
    while ((Aux != nullptr) && (Aux->Info != Novo)) {
        // TENTA ENCONTRAR ELEMENTO
        Ant = Aux;
        Aux = Aux->Lig;
    }
    if (Aux == nullptr)
        return false; // RETORNA FALSO SE NAO ENCONTRA ELEMENTO
    if (Aux == L) // SE ELEMENTO E O PRIMEIRO, REDIRECIONA O PONTEIRO
        L = L->Lig;
    else
        Ant->Lig = Aux->Lig; // REDIRECIONA O PONTEIRO
    delete Aux; // APAGA O ELEMENTO
    return true;
}

void ImprimeLista(NoPtr L) {
    NoPtr Aux = L;
    cout << "L -> ";
    while ((Aux != nullptr)) {
        cout << Aux->Info << " -> ";
        Aux = Aux->Lig;
    }
    if (Aux == nullptr)
        cout << "nullptr" << endl;
}

bool MembroLista(NoPtr no, int target) {
    if (no == nullptr) return false;
    if (no->Info == target) return true;
    return MembroLista(no->Lig, target);
}

NoPtr UltimoDaLista(NoPtr no) {
    if (no->Lig == nullptr) return no;
    return UltimoDaLista(no->Lig);
}

int TamanhoLista(NoPtr no) {
    if (no == nullptr) return 0;
    return TamanhoLista(no->Lig) + 1;
}

float MediaLista(NoPtr no) {
    NoPtr aux = no;
    float soma = 0;
    while (aux != nullptr) {
        soma += aux->Info;
        aux = aux->Lig;
    }
    return soma / TamanhoLista(no);
}

bool ListasIguais(NoPtr l1, NoPtr l2) {
    if (l1 == nullptr && l2 != nullptr) return false;
    if (l2 == nullptr && l1 != nullptr) return false;
    if (l1 == nullptr && l2 == nullptr) return true;
    if (l1->Info != l2->Info) return false;
    return ListasIguais(l1->Lig, l2->Lig);
}

NoPtr MergeListas(NoPtr l1, NoPtr l2) {
    NoPtr novaLista = nullptr;
    NoPtr aux = l1;
    while (aux != nullptr) {
        if (!MembroLista(novaLista, aux->Info))
            InsereLista(novaLista, aux->Info);
        aux = aux->Lig;
    }
    aux = l2;
    while (aux != nullptr) {
        if (!MembroLista(novaLista, aux->Info))
            InsereLista(novaLista, aux->Info);
        aux = aux->Lig;
    }
    return novaLista;
}

int main() {
    NoPtr L1 = nullptr;
    NoPtr L2 = nullptr;

    InsereLista(L1, 4);
    InsereLista(L1, 3);
    InsereLista(L1, 2);
    InsereLista(L1, 1);
    ImprimeLista(L1);

    InsereLista(L2, 5);
    InsereLista(L2, 6);
    InsereLista(L2, 7);
    InsereLista(L2, 8);
    InsereLista(L2, 9);
    ImprimeLista(L2);

    RetiraLista(L1, 3);
    RetiraLista(L2, 7);

    ImprimeLista(L1);
    ImprimeLista(L2);

    cout << "l1 tem 2: " << MembroLista(L1, 2) << endl;
    cout << "l2 tem 8: " << MembroLista(L2, 8) << endl;
    cout << "l2 tem 11: " << MembroLista(L2, 11) << endl;

    cout << "ultimo l1: " << UltimoDaLista(L1)->Info << endl;
    cout << "ultimo l2: " << UltimoDaLista(L2)->Info << endl;

    cout << "tamanho l1: " << TamanhoLista(L1) << endl;
    cout << "tamanho l2: " << TamanhoLista(L2) << endl;

    cout << "media l1: " << MediaLista(L1) << endl;
    cout << "media l2: " << MediaLista(L2) << endl;

    NoPtr L11 = nullptr;
    InsereLista(L11, 1);
    InsereLista(L11, 2);
    InsereLista(L11, 4);

    NoPtr L22 = nullptr;
    InsereLista(L22, 1);
    InsereLista(L22, 2);
    InsereLista(L22, 4);

    cout << "L1 == L11 " << ListasIguais(L1, L11) << endl;
    cout << "L2 == L22 " << ListasIguais(L2, L22) << endl;


    NoPtr L3 = nullptr;
    InsereLista(L3, 1);
    InsereLista(L3, 2);
    InsereLista(L3, 4);

    NoPtr L4 = nullptr;
    InsereLista(L4, 1);
    InsereLista(L4, 3);
    InsereLista(L4, 4);
    InsereLista(L4, 5);

    NoPtr L5 = MergeListas(L3, L4);
    ImprimeLista(L5);

    return 0;
}
