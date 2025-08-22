#ifndef EPHEMERAL_EPHEMERAL_H
#define EPHEMERAL_EPHEMERAL_H
#include <time.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

const double DECAY_RATE = 0.000008;

typedef struct Wallet {
    char *owner;
    double balance;
    time_t last_activity_timestamp;
    struct Wallet *(*pay)(struct Wallet *from, struct Wallet *to, double amount);
} Wallet;


double elapsed(const Wallet *w);

/**
 *
 * @param owner The wallet owner
 * @param balance The owner balance
 *
 * @return Wallet
 *
 */
Wallet *create_wallet(char *owner, double balance);

Wallet *pay(Wallet *from, Wallet *to, double amount);

#endif
