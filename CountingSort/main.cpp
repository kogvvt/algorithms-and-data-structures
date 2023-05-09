#include <iostream>
using namespace std;
struct LinkedList{
    string name;
    int crabsNumber, trapsNumber;
    struct LinkedList* next;
    struct LinkedList* tail;
};

void push(struct LinkedList* head, struct LinkedList* value){
    if(head->next == NULL){
        head->next = value;
        head->tail = value;
    }else{
        head->tail->next = value;
        head->tail = value;
    }
}

void displayLinkedList(struct LinkedList* listOfHunters){
    cout << listOfHunters->name << " ";
    if(listOfHunters->next != NULL){
        displayLinkedList(listOfHunters->next);
    }
}

void displayResults(struct LinkedList* listOfHunters, int indexes[100][10]){
    for(int i = 99; i>=0; --i){
        for(int j=0; j<10; ++j){
            if(indexes[i][j] != -1){
                displayLinkedList(&listOfHunters[indexes[i][j]]);
            }
        }
    }
}

void countingSort(LinkedList* listOfHunters,int indexes[100][10],unsigned int numberOfHunters){
    for(int i=0;i<numberOfHunters;++i){
        if(indexes[listOfHunters[i].crabsNumber][listOfHunters[i].trapsNumber] != -1){
            push(&listOfHunters[indexes[listOfHunters[i].crabsNumber][listOfHunters[i].trapsNumber] ],&listOfHunters[i]);
        }else{
            indexes[listOfHunters[i].crabsNumber][listOfHunters[i].trapsNumber] = i;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    struct LinkedList* listOfHunters = NULL;
    string name;
    unsigned int crabsNumber,trapsNumber,numberOfHunters;
    cin >> numberOfHunters;
    listOfHunters = new LinkedList[numberOfHunters];
    int indexes[100][10];

    for(int i=0;i<100;++i){
        for(int j = 0;j<10; ++j){
            indexes[i][j] = -1;
        }
    }

    for(int i=0; i<numberOfHunters; ++i){
        cin >> name >> crabsNumber >> trapsNumber;
        listOfHunters[i].name = name;
        listOfHunters[i].crabsNumber = crabsNumber;
        listOfHunters[i].trapsNumber = trapsNumber;
    }
    countingSort(listOfHunters, indexes, numberOfHunters);
    displayResults(listOfHunters, indexes);
    delete[] listOfHunters;
    return 0;
}
/*
 *  za tydz wejsciowka z kopcow, od puli maks odejmujemy 4 pkt, jedno jest nie jako dodatkowe
 *  (9 * 4 + 15 aktywnosc/wejsciowka)
 *
 *  malejąco względem liczby krabów, jesli tyle samo to mniejsza liczba pulapek, w przypadku rownosci
 *  obu arg zachowujemy kolejnosc
 *
 *  sortowanie przez zliczanie, malejaca, listowanie, tworzymy kontener na wartosci a dla kazdego przechowujemy
 *  liste, dodajemy drugi parametr poprzez:
 *  wykorzystanie 2d tablicy, zmieniamy kolejnosc wyswietlania
 *  lista tablicowa, osoby maja byc w liscie
 *
 *
 */
