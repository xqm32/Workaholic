#include "attr.h"

attribute hunger=100, power=100, health=100, money=0;
attribute full_hunger=100, full_power=100, full_health=100;
date_type current_time=8 HOURS;

static int affect(attribute *value, attribute *effect) {
	if (*value<0) {
		*effect+=*value;
		*value=0;
	}
	return 0;
}

static int overflow(attribute *current, attribute *full) {
	if (*current>*full) {
		attribute temp=*full;
		*full=*current;
		*current=temp;
	}
	return 0;
}

static int checklow(attribute current, attribute lowlimit, const char *warning) {
	if (current<lowlimit) {
		printf("%s", warning);
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
	checklow(hunger, full_hunger*LOW_HUNGER, LOW_HUNGER_WARNING);
	checklow(power, full_power*LOW_POWER, LOW_POWER_WARNING);
	checklow(health, full_health*LOW_HEALTH, LOW_HEALTH_WARNING);
	return 0;
}