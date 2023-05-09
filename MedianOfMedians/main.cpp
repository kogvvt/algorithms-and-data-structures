#include <iostream>
#include <algorithm>
using namespace std;

class Person{
public:
    string firstName;
    string lastName;
    unsigned int id;
};

void swap(Person &a, Person &b){
    Person temp = a;
    a = b;
    b = temp;
}

bool isEqual(const Person& a, const Person& b){
    if(a.id == b.id && a.lastName == b.lastName && a.firstName == b.firstName){
        return true;
    }else{
        return false;
    }
}

bool compare(const Person& a, const Person& b){
    if(a.id < b.id){
        return true;
    }else if(a.id == b.id){
        if(a.lastName < b.lastName){
            return true;
        }else if (a.lastName == b.lastName){
            if (a.firstName < b.firstName){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}

Person medianOfMedians(Person* people, int size, int numberToFind){
    if(size <=10){
        sort(people, people+size, compare);
        return people[numberToFind];
    }
    int group = (size + 4)/5;
    Person *medians = new Person[group];
    for (int i = 0; i < group; i++){
        int left = i * 5;
        int right = min((i + 1) * 5, size) - 1;
        sort(people + left, people + right + 1, compare);
        medians[i] = people[left + (right - left) / 2];
    }
    Person pivot = medianOfMedians(medians, group, group / 2);
    delete[] medians;
    int i = 0;
    int j = 0;
    while (j < size){
        if(compare(people[j], pivot) && !isEqual(people[j], pivot)){
            swap(people[i], people[j]);
            i++;
        }
        j++;
    }

    if (numberToFind < i){
        return medianOfMedians(people, i, numberToFind);
    } else if (numberToFind > i){
        return medianOfMedians(people + i, size - i, numberToFind - i);
    } else{
        return pivot;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    unsigned int numberOfProposals, numberToFind;
    cin >> numberOfProposals >> numberToFind;
    Person* people = new Person[numberOfProposals];
    Person result;
    for(int i = 0; i < numberOfProposals; ++i ){
        cin >> people[i].firstName;
        cin >> people[i].lastName;
        cin >> people[i].id;
    }
    result = medianOfMedians(people, numberOfProposals,numberToFind);
    cout << result.firstName <<"\n";
    cout << result.lastName << "\n";
    cout << result.id << "\n";
    delete[] people;
    return 0;
}

//odpalam funkcje szukajaca mediany
//napisac w funkcji : mniej niz 10 : to co mam
//wecej niz dziesiec : wtedy szukamy median dla przedzialow ktorych wyliczamy (czy wejdzie dodatkowy przedziel, ile tych przedzialow bedzie)
//na poczatku tablicy swapem zeby latwiej znalezc, ew charakterystyczne punkty sortem idx = 0 dal danej piatki, tam gdzie bedzie mediana, na tym funkcja mediana median,
//jak mam inf dot. mediany median to pozostaje podzial na podtablice b,c,d, układamy (przechodzimy forem przez tablice i sprawdzamy warunki dla B (funkcją compare!!))
//jeżeli należy do B to zamienić
// mamy zmienna liczaca ilosc elementow b, wejsciowo 0, iterujac w tym forze to jezeli znajdziemy to sprawdzamy people[counter] i ustawiamy wartosc people[i]'
//i zaczyna sie od start, nie od 0
//jezeli c : kolejny for dla i = bcount, do momentu znalezienia mediany to nastawiamy na polu bcount
//jezeli d : z automatu bedzie ustawione,
// robimy ify, musza sie wykluczac (if,else if, else)
//1 if : k>=bcount : hoare(people, start, bcount)
//2 if : k == mediana -> wyswietlic mediane
//3 if : rekurencja : (zanim : zmienic wartosc k dla zawezonego przedzialu przesunietego "dalej")// k = k-bcount-1 funkcja (people, bcount, ccount, end,k)
//nadpisanie b : w ifie najpierwsiejszym : tuz przed wyswietleniem do k dodac startowy index, poniewaz do wyswietlania odwolujemy sie do org wartosci k





//wykorzystac algorytm z liniowym - mediana median
//wybieranie elementu : wybor przez mediane median
/*
 * nie tworzyc dodatkowych kontenerow na wartosci, mozemy sie poruszac po niej
 * odwolujac sie po danych elementach,
 * dzielac na 5 nie musimy tworzyc tych kontenerow, mozemy o tym
 * pamietac pozniej dzielac na > = < (miejsca w tablicy)
 * czasowo : przekazywanie danych do funkcji
 * msuimy zalozyc warunek stopu (jesli mniej badz rowne 10 el to zwracamy k-ty element)
 * sortujemy i porownujemy elementy(sortownaie z komparatorem)
 * 1. n<=10 -> return (sorted) person[k]
 * 2. mediana median -> e
 * 3. Hovre:
 *          3 tablice,
 *          1.  elementy < e = k-ty element tu,
 *          2. elementy = e = k-ty element tu,
 *          3. elementy > e = k-ty element tu;
 *
 *          pracowac na tej samej liscie, sprawdzac elementy, jesli jest wiekszy to zostawiamy, w przeciwnym wypadku
 *          zamieniamy odpowiedni element na koniec listy
 *
 */
