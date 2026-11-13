#include "bst.h"
#include "generator.h"
#include "reporter.h"
#include "tester.h"
#include "search.h"

int main() {
    size_t N = 1300000;
    int samples = 50;
    generator gen;
    reporter r1("linear4.csv", "Selektiv Sökning");
    reporter r2("binary4.csv", "Binär Sökning");
    reporter r3("bst4.csv", "BST Sökning");
    reporter r4("hash4.csv", "Hash Table Sökning");
    std::vector<int> primes = generator::sieveOfEratosthenes(N);
    //std::vector<size_t> sizes = {1000, 5000, 10000, 30000, 50000, 60000, 80000, 100000};
    for (size_t size = 1000 ; size < 50001 ; size += 1000) {
        std::vector<int> sublist(primes.begin(), primes.begin() + size);
        std::vector<int> search_values = sublist;

        test_search(gen, sequential_search, r1, size, sublist, search_values, samples);
        test_search(gen, binary_search_recursive, r2, size, sublist, search_values, samples);
        bst tree(sublist);
        test_search(gen, bst_search, , size, tree, search_values, samples);
        hashTable ht(sublist);
        test_search(gen, hash_search, r4, size, ht, search_values, samples);
    }

    return 0;
}
