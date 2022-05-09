#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

std::vector<std::string> split(const std::string& source, const std::string& delimiters = " ") {
    std::size_t prev = 0;
    std::size_t currentPos = 0;
    std::vector<std::string> results;

    while ((currentPos = source.find_first_of(delimiters, prev)) != std::string::npos) {
        if (currentPos > prev) {
            results.push_back(source.substr(prev, currentPos - prev));
        }
        prev = currentPos + 1;
    }
    if (prev < source.length()) {
        results.push_back(source.substr(prev));
    }
    return results;
}

struct Node {
    string data;
    Node* next;
};

void spausdintiUzduotiesAprasyma() {
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "***UZUOTIES APRASYMAS***" << endl;
    cout << "Simbolius (raides, skyrybos simbolius bei tarpus) irasykite i" << endl;
    cout << "vienkrypti sarasa. Rasti trumpiausio zodzio ilgi." << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
}

Node* sukurtiSarasa() {
    string tekstas;
    cout << "Iveskite teksta: " << endl;
    getline(cin, tekstas);

    Node *head = new Node();
    head->next = NULL;
    Node *current = head;

    string delimiters = " ,.-':;?()+*/%$#!\"@^&";
    auto results = split(tekstas, delimiters);

    bool isFirst = true;
    for (const auto& word : results) {
        if (isFirst) {
            current->data = word;
            isFirst = false;
        } else {
            Node *newNode = new Node();
            newNode->data = word;
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

void rastiTrumpiausiaZodi(Node* head) {
    Node *current = head;
    Node *shorter = head;

    while (current != NULL) {
        if (size(current->data) < size(shorter->data)) {
            shorter->data = current->data;
        } else if (size(current->data) > size(shorter->data)) {
            current = current->next;
        } else if (size(current->data) == size(shorter->data)) {
            current = current->next;
        }
    }
    cout << "\n*ATSAKYMAS*" << endl;
    cout << "Pirmas trumpiausias zodis yra '" << shorter->data << "'." << endl;
    cout << "---------------------------------------------------------------------" << endl;
}

int main() {
    spausdintiUzduotiesAprasyma();
    cout << "\n***TRUMPIAUSIO ZODZIO RADIMAS***" << endl;

    bool rodytiPasirinkima = true;
    while (rodytiPasirinkima) {
        cout << "\nPasirinkite:" << endl;
        cout << "1 - rasti trumpiausia zodi" << endl;
        cout << "2 - iseiti is programos" << endl;
        cout << "\nIveskite savo pasirinkima: ";
        int pasirinkimas;
        cin >> pasirinkimas;
        cin.ignore();
        while (cin.fail()) {
            cout << "\nJusu ivestis netinkama!";
            cin.clear();
            cin.ignore(256, '\n');
            cout << "\nIveskite pasirinkima is meniu punktu (1-2): ";
            cin >> pasirinkimas;
        }

        if (pasirinkimas == 1) {
            Node *head = sukurtiSarasa();
            rastiTrumpiausiaZodi(head);
        } else if (pasirinkimas == 2) {
            rodytiPasirinkima = false;
            cout << "\nDekojame, kad naudojotes programa.\nLauksime sugriztant!" << endl;
        }
    }
    return 0;
}