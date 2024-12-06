#include <iostream>
#include <string>

template <typename T>
class DizionarioEsteso {
private:
    static const int TABLE_SIZE = 10; // Dimensione della tabella hash
    struct Entry {
        std::string key;
        T value;
        bool isOccupied = false; // Indica se lo slot è occupato
    };

    Entry table[TABLE_SIZE]; // Tabella hash

    int hashFunction(const std::string& key) const {
        int hash = 0;
        for (char ch : key) {
           hash += static_cast<int>(ch);
        }
        return hash  % TABLE_SIZE;
    }

    int findSlot(int index, const std::string& key) const {
        // Linear probing: cerca la prossima posizione libera
        while (table[index].isOccupied && table[index].key != key) {
            index = index++;  // Scansione ciclica
        }
        return (index);
    }

public:
    void inserisci(const std::string key, const T value) {
        int index = hashFunction(key);
        if (table[index].isOccupied) {
            std::cout << "Collisione trovata per la chiave: " << key << " all'indice " << index << ". Risoluzione della collisione.\n";
            index = findSlot(index, key);  // Trova la posizione libera
        }

        table[index].key = key;
        table[index].value = value;
        table[index].isOccupied = true;
        std::cout << "Inserito: " << key << " => " << value << " all'indice " << index << "\n";
    }

    void cancella(const std::string key) {
        int index = hashFunction(key);
        index = findSlot(index, key);  // Trova la posizione corretta
        if (table[index].isOccupied && table[index].key == key) {
            table[index].isOccupied = false;
            std::cout << "Eliminata: " << key << " all'indice " << index << "\n";
        } else {
            std::cout << "Chiave non trovata per eliminazione!\n";
        }
    }

    T recupera(const std::string key) const {
        int index = hashFunction(key);
        index = findSlot(index, key);  // Trova la posizione corretta
        if (table[index].isOccupied && table[index].key == key) {
            return table[index].value;
        }
        std::cout << "Chiave non trovata per il recupero!\n";
        return T();  // Restituisce un valore di default
    }

    bool appartiene(const std::string key) const {
        int index = hashFunction(key);
        index = findSlot(index, key);  // Trova la posizione corretta
        if (table[index].isOccupied && table[index].key == key) {
            return true;
        }
        return false;
    }

    void stampa() const {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i].isOccupied) {
                std::cout << "Indice " << i << ": " << table[i].key << " => " << table[i].value << "\n";
            }
        }
    }
};

// Esplicitazione dei template per i tipi comuni
template class DizionarioEsteso<std::string>;  // Esplicitazione per tipo std::string
