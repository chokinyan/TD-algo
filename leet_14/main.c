#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize);
char* longestCommonPrefix_naive(char** strs, int strsSize);
int compare(const void* s1, const void* s2);

int main(void) {
    // exo 1 : ["flower","flow","flight"]

    char* strs[] = {"flower", "flow", "flight"};
    printf("%s\n", longestCommonPrefix(strs, 3));

    // exo 2 : ["dog","racecar","car"]

    char* strs2[] = {"flower", "flow", "flight"};

    printf("%s\n", longestCommonPrefix(strs2, 3));

    return 0;
}

int compare(const void* s1, const void* s2) {
    const char* str1 = *(const char**)s1;
    const char* str2 = *(const char**)s2;

    return strcmp(str1, str2);
}

char* longestCommonPrefix(char** strs, int strsSize) {
    // Algo de vertical scanning pour le optimal
    int n = strlen(strs[0]);

    char* rep_opti = malloc((n + 1) * sizeof(char));

    for (int i = 0; i < n; i++) {
        char current_char = strs[0][i];
        for (int j = 0; j < strsSize; j++) {
            char* current_str = strs[j];
            if (current_str[i] == '\0' || current_str[i] != current_char) {
                rep_opti[i] = '\0';
                return rep_opti;
            }
        }
        rep_opti[i] = current_char;
    }

    rep_opti[n] = '\0';

    return rep_opti;
}

char* longestCommonPrefix_naive(char** strs, int strsSize) {
    // Naive : trié en lexicographique puis regarder le commun avec le premier
    // et le dernier step 1 : O(n.L.log(n)) step 2: O(L)

    qsort(strs, strsSize, sizeof(strs[0]), compare);

    char* min_str = strs[0];
    char* max_str = strs[strsSize - 1];

    int l = strlen(min_str);

    char* rep_naive = malloc((l + 1) * sizeof(char));

    for (int i = 0; i < l; i++) {
        if (min_str[i] != max_str[i]) {
            rep_naive[i] = '\0';
            return rep_naive;
        }
        rep_naive[i] = min_str[i];
    }
    rep_naive[l] = '\0';
    return rep_naive;
}