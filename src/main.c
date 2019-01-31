#include "life.h"

static void printinfo() {
	printf("Hunger: %lld/%lld\n"
		"Power: %lld/%lld\n"
		"Health: %lld/%lld\n"
		"Money: %lld\n"
		"$ ", \
		hunger, full_hunger, \
		power, full_power, \
		health, full_health, \
		money);
}

static void gameover() {
	printf("Game over.\n");
}

static int menu() {
	srand(time(NULL));
	printinfo();
	for (;;) {
		for (int ch=getchar(); ch!='\n'; ch=getchar()) {
			switch(ch) {
				case 'E':
				case 'e': {
					eat();
					break;
				}
				case 'S':
				case 's': {
					sleep();
					break;
				}
				case 'C':
				case 'c': {
					cure();
					break;
				}
				case 'W':
				case 'w': {
					work();
					break;
				}
				case 'X':
				case 'x': {
					return 0;
				}
				default: {
					break;
				}
			}
			if (check()) {
				gameover();
				return 0;
			}
			printinfo();
		}
	}
	return 1;
}

int main(void) {
	menu();
	return 0;
}