#include "life.h"

static int live(long long sign_hunger, long long sign_power,
	long long sign_health, long long sign_money) {
		long long temp_hunger=rand()%(full_hunger/10);
		long long temp_power=rand()%(full_power/10);
		long long temp_health=rand()%(full_health/10);
		long long temp_money=rand()%((full_hunger+full_power+full_health)/30);
		hunger+=sign_hunger*temp_hunger;
		power+=sign_power*temp_power;
		health+=sign_health*temp_health;
		money+=sign_money*temp_money;
		return 0;
	}

int eat() {
	live(1, 1, -1, -1);
	return 0;
}

int sleep() {
	live(-1, 1, 1, -1);
	return 0;
}

int cure() {
	live(1, -1, 1, -1);
	return 0;
}

int work() {
	live(-1, -1, 1, 1);
	return 0;
}

/*
	Relationship:
	Event	Hunger	Power	Health	Money
	Eat		+		+		-		-
	Sleep	-		+		+		-
	Cure	+		-		+		-
	Work	-		-		+		+
 */