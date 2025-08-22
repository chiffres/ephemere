#ifndef EPHEMERAL_EPHEMERAL_H
#define EPHEMERAL_EPHEMERAL_H
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

const double DECAY_RATE = 0.000008;

typedef struct Wallet {
    char *owner;
    double balance;
    time_t last_activity_timestamp;
    void (*pay)(struct Wallet *from, struct Wallet *to, double amount);
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

double get_current_balance(Wallet *wallet);

void pay(Wallet *from, Wallet *to, double amount);

#endif
