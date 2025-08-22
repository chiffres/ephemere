#include "ephemeral.h"

double get_current_balance(Wallet *wallet) {
    time_t current_time = time(NULL);
    double time_elapsed = difftime(current_time, wallet->last_activity_timestamp);

    if (time_elapsed > 0) {
        double decay_factor = exp(-DECAY_RATE * time_elapsed);
        return wallet->balance * decay_factor;
    }
    return wallet->balance;
}

// Utiliser la version avec pointeur est plus robuste pour une librairie
Wallet *create_wallet(char *owner, double balance) {
    Wallet *w = (Wallet *) malloc(sizeof(Wallet));
    if (w == NULL) return NULL;

    w->owner = owner;
    w->balance = balance;
    w->last_activity_timestamp = time(NULL); // Initialisation cruciale !
    w->pay = &pay;

    return w;
}

void pay(Wallet *from, Wallet *to, double amount) {
    // 1. On calcule les soldes actuels en tenant compte de l'évaporation
    double from_current_balance = get_current_balance(from);
    double to_current_balance = get_current_balance(to);

    // 2. On met à jour les soldes "stockés" avec leur valeur actuelle
    from->balance = from_current_balance;
    to->balance = to_current_balance;

    // 3. On vérifie la provision sur le solde mis à jour
    if (from->balance > amount) {
        // 4. On effectue le transfert
        from->balance -= amount;
        to->balance += amount;
        // 5. On met à jour les timestamps. C'est l'acte de circulation qui "réinitialise" le compteur.
        time_t current_time = time(NULL);
        from->last_activity_timestamp = current_time;
        to->last_activity_timestamp = current_time;
    } else {
        printf("Transaction echouee : Solde insuffisant pour %s.\n", from->owner);
    }
}

// main() devient un simple exemple d'utilisation de la librairie
