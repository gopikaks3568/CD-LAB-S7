#include <stdio.h>
#include <string.h>

int k = 0, z = 0, i = 0, j = 0, c = 0;
char a[16], ac[20], stk[15], act[10];

void check();
int main() {
    printf("GRAMMAR is E->E+E \n E->E*E \n E->(E) \n E->id\n");
    printf("Enter input string: ");
    gets(a);  // You can replace this with fgets() if needed

    c = strlen(a);  // Length of input
    strcpy(act, "SHIFT->");  // Initialize action message

    printf("\nstack\t\tinput\t\taction\n");

    // Start parsing input string
    for (k = 0, i = 0; j < c; k++, i++, j++) {
        if (a[j] == 'i' && a[j + 1] == 'd') {
            // Handling "id"
            stk[i] = a[j];
            stk[i + 1] = a[j + 1];
            stk[i + 2] = '\0';
            a[j] = ' ';  // Clear from input
            a[j + 1] = ' ';
            printf("$%-10s\t%s$\t%sid\n", stk, a, act);
            check();
        } else {
            // Handling symbols like +, *, (, )
            stk[i] = a[j];
            stk[i + 1] = '\0';
            a[j] = ' ';
            printf("$%-10s\t%s$\t%ssymbols\n", stk, a, act);
            check();
        }
    }
}

void check() {
    strcpy(ac, "REDUCE TO E");

    // Reduce "id" to "E"
    for (z = 0; z < c; z++) {
        if (stk[z] == 'i' && stk[z + 1] == 'd') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            printf("$%-10s\t%s$\t%s\n", stk, a, ac);
            j++;
        }
    }

    // Reduce "E + E" to "E"
    for (z = 0; z < c; z++) {
        if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("$%-10s\t%s$\t%s\n", stk, a, ac);
            i -= 2;
        }
    }

    // Reduce "E * E" to "E"
    for (z = 0; z < c; z++) {
        if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("$%-10s\t%s$\t%s\n", stk, a, ac);
            i -= 2;
        }
    }

    // Reduce "( E )" to "E"
    for (z = 0; z < c; z++) {
        if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("$%-10s\t%s$\t%s\n", stk, a, ac);
            i -= 2;
        }
    }
}

