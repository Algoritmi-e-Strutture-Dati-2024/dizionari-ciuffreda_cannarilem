#include <iostream>
#include <string>
#include "DizionarioEsteso.cpp"

int main() {

    // Creazione di un dizionario esteso con stringhe come chiavi
    DizionarioEsteso<std::string> dict;

    // Aggiunta di voci che causeranno collisioni (ad esempio, "apple" e "car" potrebbero essere hashate nello stesso indice)
    std::cout << "Aggiungo 'apple' con valore 'fruit'.\n";
    dict.inserisci("apple", "fruit");

    std::cout << "Aggiungo 'car' con valore 'vehicle'.\n";
    dict.inserisci("car", "vehicle");

    std::cout << "Aggiungo 'book' con valore 'object'.\n";
    dict.inserisci("book", "object");

    std::cout << "Aggiungo 'pen' con valore 'writing tool'.\n";
    dict.inserisci("pen", "writing tool");

    // Test di recupero dei valori
    std::cout << "\nRecupero il valore associato alla chiave 'apple': " << dict.recupera("apple") << "\n";
    std::cout << "Recupero il valore associato alla chiave 'car': " << dict.recupera("car") << "\n";
    std::cout << "Recupero il valore associato alla chiave 'pen': " << dict.recupera("pen") << "\n";  // Dovrebbe restituire 'writing tool'
    std::cout << "Recupero il valore associato alla chiave 'nonexistent': " << dict.recupera("nonexistent") << "\n";  // Non esiste

    // Stampa della tabella per visualizzare la situazione corrente
    std::cout << "\nStampa della tabella dopo gli inserimenti:\n";
    dict.stampa();

    // Test della funzione cancella
    std::cout << "\nCancello la chiave 'apple'.\n";
    dict.cancella("apple");
    std::cout << "Tabella dopo la cancellazione:\n";
    dict.stampa();

    // Test di modifica (reattivando la chiave 'apple')
    std::cout << "\nAggiungo di nuovo 'apple' con valore 'fruit' dopo la cancellazione.\n";
    dict.inserisci("apple", "fruit");
    std::cout << "Tabella dopo aver ri-inserito 'apple':\n";
    dict.stampa();

    // Test della funzione appartiene
    std::cout << "\nVerifica se la chiave 'car' appartiene al dizionario: " << (dict.appartiene("car") ? "Sì" : "No") << "\n";
    std::cout << "Verifica se la chiave 'banana' appartiene al dizionario: " << (dict.appartiene("banana") ? "Sì" : "No") << "\n";

    // Aggiungo un altro caso di collisione e stampo il risultato
    std::cout << "\nAggiungo un altro caso di collisione:\n";
    dict.inserisci("desk", "furniture");  // Potenziale collisione
    dict.stampa();

    return 0;
}
