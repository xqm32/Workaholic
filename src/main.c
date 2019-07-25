#include "life.h"

static void printinfo() {
	printf("Day "DAY_FORMAT", "TIME_FORMAT":"TIME_FORMAT":"TIME_FORMAT"\n", \
		current_time STD, current_time STH, \
		current_time STM, current_time STS);
	printf("Health[Cure]: "PER_ATTR_FORMAT_FORMAT" "PERCENT_FORMAT"%s\n"
		"Hunger [Eat]: "PER_ATTR_FORMAT_FORMAT" "PERCENT_FORMAT"%s\n"
		"Power[Sleep]: "PER_ATTR_FORMAT_FORMAT" "PERCENT_FORMAT"%s\n"
		"Money [Work]: $"ATTR_FORMAT"\n", \
		health, full_health, health/full_health*100, LOW_HEA_STR, \
		hunger, full_hunger, hunger/full_hunger*100, LOW_HUN_STR, \
		power, full_power, power/full_power*100, LOW_POW_STR, \
		money);
}

static void wait() {
	printf("[C/E/S/W/X]\n"
		"-> ");
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