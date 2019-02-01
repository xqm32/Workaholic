#include "life.h"

static int algorithm(attribute sign_hunger, attribute sign_power,
	attribute sign_health, attribute sign_money, date_type expected_time) {
		date_type temp_time=rand()%(int)expected_time;
		attribute temp_hunger=sign_hunger*(rand()%(int)full_hunger);
		attribute temp_power=sign_power*(rand()%(int)full_power);
		attribute temp_health=sign_health*(rand()%(int)full_health);
		attribute temp_money=sign_money*(rand()%(int)((full_hunger+full_power+full_health)/3));
		if (money<-temp_money) {
#ifdef IN_DEBT
			printf("=> [Warning]: You are in debt.\n");
#else
			printf("=> [Warning]: You have not enough money to do it.\n");
			return 1;
#endif
		}
		current_time+=temp_time;
		hunger+=temp_hunger;
		power+=temp_power;
		health+=temp_health;
		money+=temp_money;
		return 0;
	}

int eat() {
	algorithm(EAT);
	return 0;
}

int sleep() {
	algorithm(SLEEP);
	return 0;
}

int cure() {
	algorithm(CURE);
	return 0;
}

int work() {
	algorithm(WORK);
	return 0;
}