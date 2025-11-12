/*
 * Baby C - minimal itoa variants (no return values, no zero/negative handling)
 * Globals (very small API for teaching):
 *   long number;   // input (assume > 0)
 *   char *str;     // output buffer
 *   int pos;       // working index (see below)
 *   int start;     // filled by function: index of first character of result
 *
 * Conventions (re-initialize before each call):
 * - top-decrement variants expect pos == buffer_length (one-past-end).
 * - bottom-decrement variants expect pos == buffer_length - 1 (last index).
 *
 * Each function writes the NUL terminator and digits; it DOES NOT return
 * a pointer -- instead it sets `start` to the index where the string begins.
 * This keeps the code tiny and clear for teaching loop forms.
 */

#include <stdio.h>

long number;      /* caller must set > 0 */
char *str;
int pos;          /* working index; must be re-initialized before each call */

void itoa_while_top(void) {
    long n = number;        /* copy so we don't destroy the global */

    --pos;
    str[pos] = '\0';      /* terminator written at --pos */

    while (n != 0) {
        --pos;
        str[pos] = '0' + (n % 10);
        n = n / 10;
    }

}

void itoa_while_bottom(void) {
    long n = number;

    str[pos] = '\0';      /* terminator at current pos */
    pos--;

    while (n != 0) {
        str[pos] = '0' + (n % 10);
        pos--;
        n = n / 10;
    }

    pos++;                 /* move to first digit */
}

void itoa_do_while_top(void) {
    long n = number;

    --pos;
    str[pos] = '\0';

    do {
        --pos;
        str[pos] = '0' + (n % 10);
        n = n / 10;
    } while (n != 0);
}

void itoa_do_while_bottom(void) {
    long n = number;

    str[pos] = '\0';
    pos--;

    do {
        str[pos] = '0' + (n % 10);
        pos--;
        n = n / 10;
    } while (n != 0);

    pos++;
}

/* Tiny test driver: very simple, re-initialize number and pos each time.
 * Prints using start index. No safety checks (fits your 'baby C' brief).
 */
int main(void) {
    char buf[32];
    long vals[] = {1, 42, 1234, 67890};

    for (int i = 0; i < 4; ++i) {
        /* while_top */
        number = vals[i]; str = buf; pos = (int)sizeof(buf);
        itoa_while_top();
        printf("while_top -> '%s'", str + pos);

        /* while_bottom */
        number = vals[i]; str = buf; pos = (int)sizeof(buf) - 1;
        itoa_while_bottom();
        printf("while_bottom -> '%s'", str + pos);

        /* do_while_top */
        number = vals[i]; str = buf; pos = (int)sizeof(buf);
        itoa_do_while_top();
        printf("do_top -> '%s'", str + pos);

        /* do_while_bottom */
        number = vals[i]; str = buf; pos = (int)sizeof(buf) - 1;
        itoa_do_while_bottom();
        printf("do_bottom -> '%s'", str + pos);

        printf("\n");
    }

    return 0;
}
