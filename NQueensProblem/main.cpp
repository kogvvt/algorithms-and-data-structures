#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int temporaryCost = 0;
int minimumCost =INT_MAX;
vector<int> resultColumns;
vector<int> temporaryColumnsVector;

class HuntZone{
public:
    int buildingCost;
    int isProtected;
};

void incrementValue(vector<vector<HuntZone>> &huntBoard, int col, int row, int huntArea) {
    int i, j;
    huntBoard[col][row].isProtected++;
    for (i = row + 1; i < huntArea; ++i) {
        huntBoard[col][i].isProtected++;
    }
    for (i = row+1, j = col-1; i < huntArea && j >= 0; ++i, --j) {
        huntBoard[j][i].isProtected++;
    }
    for (i = row+1, j = col+1; j < huntArea && i < huntArea; ++i, ++j) {
        huntBoard[j][i].isProtected++;
    }
}
void decrementValue(vector<vector<HuntZone>> &huntBoard, int col, int row, int huntArea) {
    int i, j;
    huntBoard[col][row].isProtected--;
    for (i = row + 1; i < huntArea; ++i) {
        huntBoard[col][i].isProtected--;
    }
    for (i = row+1, j = col-1; i < huntArea && j >= 0; ++i, --j) {
        huntBoard[j][i].isProtected--;
    }
    for (i = row+1, j = col+1; j < huntArea && i < huntArea; ++i, ++j) {
        huntBoard[j][i].isProtected--;
    }
}

void leastCostCampPlacement( vector<vector<HuntZone>> &huntBoard, int column, int huntArea) {
    if (column == huntArea) {
        resultColumns = temporaryColumnsVector;
        minimumCost = temporaryCost;
        return;
    }
    for (int i = 0; i < huntArea; ++i) {
        if (huntBoard[i][column].isProtected == 0 && temporaryCost + huntBoard[i][column].buildingCost < minimumCost ) {
            incrementValue(huntBoard,i,column,huntArea);
            temporaryCost += huntBoard[i][column].buildingCost;
            temporaryColumnsVector.push_back(i);
            leastCostCampPlacement(huntBoard, column + 1, huntArea);
            temporaryCost -= huntBoard[i][column].buildingCost;
            decrementValue(huntBoard,i,column,huntArea);
            temporaryColumnsVector.pop_back();
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int huntArea;
    cin >> huntArea;
    vector<vector<HuntZone>> huntBoard;
    huntBoard.resize(huntArea,vector<HuntZone>(huntArea));
    for (int i = 0; i < huntArea; ++i) {
        for (int j = 0; j < huntArea; ++j) {
            cin >> huntBoard[j][i].buildingCost;
            huntBoard[j][i].isProtected = 0;
        }
    }
    leastCostCampPlacement(huntBoard, 0, huntArea);
    for (int i = 0; i < huntArea; ++i) {
        cout << resultColumns[i] << " ";
    }
    return 0;
}
/*
 * MODYFIKUJEMY N HETMANOW
 * SUMUJEMY ROZWIAZANIE, JEZELI SUMA JEST MNIEJSZA OD MIN TO NIE MA SENSU DALEJ SZUKAC
 * REKURENCJA (PODANY OBECNY KOSZT I NA JAKIM POZIOMIE "ZAGLEBIENIA" JESTESMY )
 * I SPRAWDZAMY TEN KOSZT
 * USTAWIAMY NAMIOT NA PIERWSZYM MIEJSCU I USTAWIAMY MIEJSCA SASIADUJACE JAKO "NIEZDATNE",
 * IDZIEMY DO NAST WIERSZA I SZUKAMY MIEJSCA DO WSTAWIENIA, USTAWIAMY MIEJSCA SASIADUJACE (N,S,W,E) JAKO "NIEZDATNE"
 * SZUKAMY WSZYSTKICH I COFAMY SIE, ODZNACZAMY MIEJSCA ZAZNACZONE WCZESNIEJ I SZUKAMY DALEJ
 * PRZERYWAMY GDY:
 * NIE DA SIE POSTAWIC NAMIOTU,
 * OBECNE ROZSTAWIENIE POSIADA WIEKSZA SUME NIZ MIELISMY WCZESNIEJ
 *
 *
 *
 *
 */