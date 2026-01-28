#include <iostream>
#include <vector>

using namespace std;

// QWord = nezáporné celé číslo (8 bytů)
using QWord = unsigned long long;

class TIntSet {
private:
    vector<QWord> data;

public:
    // Přidá číslo do množiny
    // vrací true, pokud bylo číslo přidáno
    bool Add(QWord n) {
       
        return false;
    }

    // TODO: doplnit metody Delete a isElement


    // Vrátí mohutnost množiny (počet prvků)
    QWord Cardinality() const {
        return 0;
    }

    // Zjistí, zda se dvě množiny rovnají
    bool IsEqual(const TIntSet& A) const {
 
        return false;
    }

    // TODO: doplnit metody IsSubset, Union, Intersection

    
};

int main() {
    cout << "=== TESTOVANI TRIDY TIntSet ===" << endl;

    TIntSet S;
    TIntSet A;

    cout << "\n1) TEST Add()" << endl;
    cout << "Pridani 5 do S (ocekavano: 1): "
         << S.Add(5) << endl;
    cout << "Pridani 3 do S (ocekavano: 1): "
         << S.Add(3) << endl;
    cout << "Pridani 5 znovu (ocekavano: 0): "
         << S.Add(5) << endl;

    cout << "\n2) TEST Cardinality()" << endl;
    cout << "Pocet prvku v S (ocekavano: 2): "
         << S.Cardinality() << endl;

    cout << "\n3) TEST IsElement()" << endl;
    cout << "Je 3 v S? (ocekavano: 1): "
         << S.IsElement(3) << endl;
    cout << "Je 10 v S? (ocekavano: 0): "
         << S.IsElement(10) << endl;

    cout << "\n4) TEST Delete()" << endl;
    cout << "Mazani 3 ze S (ocekavano: 1): "
         << S.Delete(3) << endl;
    cout << "Mazani 3 znovu (ocekavano: 0): "
         << S.Delete(3) << endl;
    cout << "Pocet prvku v S (ocekavano: 1): "
         << S.Cardinality() << endl;

    cout << "\n5) Priprava druhe mnoziny A" << endl;
    A.Add(5);
    A.Add(8);

    cout << "\n6) TEST IsEqual()" << endl;
    cout << "Jsou S a A stejne? (ocekavano: 0): "
         << S.IsEqual(A) << endl;

    cout << "\n7) TEST IsSubSet()" << endl;
    cout << "Je A podmnozina S? (ocekavano: 0): "
         << S.IsSubSet(A) << endl;

    cout << "\n8) TEST Union a Intersection" << endl;
    TIntSet U = S.Union(A);
    TIntSet I = S.Intersection(A);

    cout << "Union - pocet prvku (ocekavano: 2): "
         << U.Cardinality() << endl;
    cout << "Intersection - pocet prvku (ocekavano: 1): "
         << I.Cardinality() << endl;

    cout << "\n=== KONEC PROGRAMU ===" << endl;

    return 0;
}