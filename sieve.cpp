/*
    Template for Eratosthenes sieve
*/

// calculate primality upto
const int N = 1000003;
int isPrime[N];

void sieve() {
    // initially we thought that all numbers are prime
    fill(isPrime, isPrime + N, 1);

    // 0 and 1 are not primes
    isPrime[0] = isPrime[1] = 0;

    // the iteration
    for (int i = 2; i < N; i++) {
        // not a prime, move on
        if (!isPrime[i]) continue;

        // no multiples of prime are prime
        for (int j = i + i; j < N; j++) isPrime[j] = 0;
    }
}