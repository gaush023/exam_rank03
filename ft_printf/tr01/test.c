#include <unistd.h>
#include <stdio.h>

void print_char(char c) {
    write(1, &c, 1);
}

void print_hex(unsigned int n) {
    if (n >= 16) {
        print_hex(n / 16);
    }
    n = n % 16;
    if (n < 10) {
        print_char(n + '0');
    } else {
        print_char(n - 10 + 'a');
    }
}

int main() {
    unsigned int number = 1006; // 例として12345678の16進数を使用
    print_hex(number);
	printf("\n%d\n", 100 % 16);
	print_char('\n');
    return 0;
}
