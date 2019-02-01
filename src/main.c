#include "life.h"

static void printinfo() {
	printf("Day "DAY_FORMAT", "TIME_FORMAT":"TIME_FORMAT":"TIME_FORMAT"\n", \
		current_time/86400, current_time/3600%24, \
		current_time/60%60, current_time%60);
	printf("Hunger: "PER_ATTR_FORMAT_FORMAT" "PERCENT_FORMAT"\n"
		"Power:  "PER_ATTR_FORMAT_FORMAT" "PERCENT_FORMAT"\n"
		"Health: "PER_ATTR_FORMAT_FORMAT" "PERCENT_FORMAT"\n"
		"Money:  $"ATTR_FORMAT"\n", \
		hunger, full_hunger, hunger/full_hunger*100, \
		power, full_power, power/full_power*100, \
		health, full_health, health/full_health*100, \
		money);
}

static void wait() {
	printf("-> ");
}

static void gameover() {
	printinfo();
	printf("=> Game over.\n");
}

static int menu() {
	srand(time(NULL));
	printinfo();
	wait();
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
			wait();
		}
	}
	return 1;
}

int main(void) {
	menu();
	return 0;
}