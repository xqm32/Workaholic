#include "attr.h"

long long hunger=100, power=100, health=100, money=0;
long long full_hunger=100, full_power=100, full_health=100;

static int affect(long long *value, long long *effect) {
	if (*value<0) {
		*effect+=*value;
		*value=0;
	}
	return 0;
}

static int overflow(long long *current, long long *full) {
	if (*current>*full) {
		long long temp=*full;
		*full=*current;
		*current=temp;
	}
	return 0;
}

int check() {
	affect(&hunger, &health);
	affect(&power, &health);
	if (health<0) {
		return 1;
	}
	overflow(&hunger, &full_hunger);
	overflow(&power, &full_power);
	overflow(&health, &full_health);
	return 0;
}