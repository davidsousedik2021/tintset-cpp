#include <iostream>
#include <vector>
using namespace std;

class TIntSet {
private:
    vector<unsigned long long> data;

    bool contains(unsigned long long n) const {
        for (auto x : data) {
            if (x == n) return true;
        }
        return false;
    }

public:
    bool Add(unsigned long long n) {
        if (contains(n)) return false;
        data.push_back(n); // jediné místo s push_back
        return true;
    }

    bool IsElement(unsigned long long n) const {
        return contains(n);
    }

    TIntSet Union(const TIntSet& A) const {
        TIntSet result = *this;
        for (auto x : A.data) {
            result.Add(x); // Add hlídá duplicity
        }
        return result;
    }

    TIntSet Intersection(const TIntSet& A) const {
        TIntSet result;
        for (auto x : data) {
            if (A.IsElement(x)) {
                result.Add(x); // žádný push_back mimo Add
            }
        }
        return result;
    }

    void Print() const {
        cout << "{";
        for (size_t i = 0; i < data.size(); i++) {
            cout << data[i];
            if (i + 1 < data.size()) cout << ", ";
        }
        cout << "}\n";
    }
};

int main() {
    cout << boolalpha;

    // test Add + Print
    TIntSet s;
    cout << "Pridani 5: " << s.Add(5) << "\n";        // true
    cout << "Pridani 5 znovu: " << s.Add(5) << "\n";  // false
    cout << "Pridani 10: " << s.Add(10) << "\n";      // true
    cout << "Mnozina s: ";
    s.Print();

    // test Union + Intersection + IsElement
    TIntSet s1, s2;
    s1.Add(1); s1.Add(2); s1.Add(3);
    s2.Add(2); s2.Add(3); s2.Add(4);

    cout << "2 je v s1: " << s1.IsElement(2) << "\n"; // true
    cout << "4 je v s1: " << s1.IsElement(4) << "\n"; // false

    cout << "Mnozina s1: ";
    s1.Print();
    cout << "Mnozina s2: ";
    s2.Print();

    TIntSet sjednoceni = s1.Union(s2);
    cout << "Sjednoceni: ";
    sjednoceni.Print();

    TIntSet prunik = s1.Intersection(s2);
    cout << "Prunik: ";
    prunik.Print();

    return 0;
}
