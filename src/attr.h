#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef double attribute;
typedef long long date_type;

#define ATTR_FORMAT "%-6.2lf"
#define PER_ATTR_FORMAT_FORMAT "%6.2lf/%-6.2lf"
#define PERCENT_FORMAT "%%%-6.2lf"
#define DAY_FORMAT "%lld"
#define TIME_FORMAT "%02lld"

#define DAYS *24*60*60
#define HOURS *60*60
#define MINUTES *60
#define SECONDS *1

extern attribute hunger, power, health, money;
extern attribute full_hunger, full_power, full_health;
extern date_type current_time;

#define LOW_HUNGER 0.4
#define LOW_POWER 0.4
#define LOW_HEALTH 0.1
#define LOW_HUNGER_WARNING "=> [Warning]: Low hunger.\n"
#define LOW_POWER_WARNING "=> [Warning]: Low power.\n"
#define LOW_HEALTH_WARNING "=> [Warning]: Low health.\n"

int check();