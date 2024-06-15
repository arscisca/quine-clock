#include <stdio.h>
#include <unistd.h>
#include <time.h>

time_t t;
char *src, *p, *e;
int font[] = {31599, 19812, 14479, 31207, 23524, 29411, 29679, 30866, 31727, 31719, 1040, 0};
int h, m, s;

int x = 0;
int y = 0;

#define NUM_DIGITS 8
#define DIGIT_WIDTH 3
#define DIGIT_PADDING 2
#define DIGIT_HEIGHT 5
void pixel(char c) {
    int digit_pos = x / (DIGIT_WIDTH + DIGIT_PADDING);
    int d;
    switch (digit_pos) {
        case 0: d = h / 10; break;
        case 1: d = h % 10; break;
        case 3: d = m / 10; break;
        case 4: d = m % 10; break;
        case 6: d = s / 10; break;
        case 7: d = s % 10; break;
        case 2: case 5: d = 10; break;
        default: d = 11;
    }
    int dx = x % (DIGIT_WIDTH + DIGIT_PADDING);
    int on = dx < DIGIT_WIDTH && font[d] >> (dx + DIGIT_WIDTH * (DIGIT_HEIGHT - y)) & 1;
    if (dx <= NUM_DIGITS * DIGIT_WIDTH && y <= DIGIT_HEIGHT && on) {
        printf("\e[41m%c\e[0m", c);
    } else {
        putchar(c);
    }
    if (c != '\n') {
        x++;
    } else {
        x = 0;
        y++;
    }
}

int main() {
    src = "..............................................\n..............................................\n..............................................\n..............................................\n..............................................\n..............................................\n..............................................\n..............................................\n";
    while (1) {
        p = src;
        e = src;
        time(&t);
        s = t % (3600 * 24);
        h = s / 3600;
        m = (s % 3600) / 60;
        s = s % 60;
        x = 0;
        y = 0;
        while (*p) {
            if (*p != 0x40) pixel(*p);
            else while (*e) {
                char c = *e;
                switch(c) {
                    case '\n':
                        c = 'n';
                    case '\\': case '"':
                        pixel('\\');
                }
                pixel(c);
                e++;
            }
            p++;
        }
        sleep(1);
        printf("\033[%dA\033[%dD", y, x);
    }
    return 0;
}
