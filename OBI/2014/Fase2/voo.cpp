#include <stdio.h>

typedef struct {
	int hour, minute;
} Time;

Time gettime() {
	char tempo[5];
	scanf("%s", tempo);

	Time t;
	t.hour = (tempo[0] - '0') * 10 + (tempo[1] - '0');
	t.minute = (tempo[3] - '0') * 10 + (tempo[4] - '0');

	return t;
}

int timediff(Time begin, Time end) {
	int result = (end.hour * 60 + end.minute) - (begin.hour * 60 + begin.minute);
	return result < 0 ? -result : result;
}

int is_at_next_day(Time a, Time b) {
	return (a.hour > b.hour) || (a.hour == b.hour && a.minute > b.minute);
}

int main() {
	Time p1 = gettime(), c1 = gettime(), p2 = gettime(), c2 = gettime(), np1, np2;
	int fuso, diff1, diff2;

	for (fuso = 12; fuso >= -12; fuso--) {
		np1 = p1;
		np1.hour += fuso;
		if (np1.hour > 24) np1.hour -= 24;
		else if (np1.hour < 0) np1.hour = (24 - np1.hour);

		np2 = p2;
		np2.hour -= fuso;
		if (np2.hour > 24) np2.hour -= 24;
		else if (np2.hour < 0) np2.hour = (24 - np2.hour);

		if (is_at_next_day(np1, c1)) {
			diff1 = 1440 - (timediff(c1, np1));
		} else {
			diff1 = timediff(np1, c1);
		}

		if (is_at_next_day(np2, c2)) {
			diff2 = 1440 - (timediff(c2, np2));
		} else {
			diff2 = timediff(np2, c2);
		}

		if (diff1 == diff2 && diff1 / 60 < 12) {
			break;
		}
	}

	printf("%d %d\n", diff1, fuso);

	return 0;
}