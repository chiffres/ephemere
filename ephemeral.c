#include "ephemeral.h"

Wallet *create_wallet_ptr(char *owner, double balance) {
    Wallet *w = malloc(sizeof(Wallet));

    if (w != NULL) {
        w->owner = owner;
        w->balance = balance;
        w->pay = &pay;
        w->last_activity_timestamp = time(NULL);
        return w;
    }
    return NULL;
}

Wallet *create_wallet(char *owner, double balance) {
    Wallet *w = malloc(sizeof(Wallet));

    if (w == NULL) {
        return NULL;
    }

    w->owner = owner;
    w->balance = balance;
    w->pay = &pay;
    w->last_activity_timestamp = time(NULL);

    return w;
}

Wallet *pay(Wallet *from, Wallet *to, double amount) {
    from->balance -= amount;
    to->balance += amount;
    return from;
}
