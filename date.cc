#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

// Julian day numbers, representing the number of days since 1 Jan 4713BC,
// are used to avoid the various quirks of calendars, and to simplify
// various calculations with dates.
//
// The time function returns the number of seconds from the start of
// 1 Jan 1970 to now, from which we can compute today's Julian day number.

const long seconds_per_day = 24*60*60L;

// Day number when time() == 0 at start of day (1 Jan 1970)
const long time_epoch = 2440588L;

long julian_today();

// Up to 2 Sep 1752, Britain and colonies used the Julian calendar.
// From the next day, they used the Gregorian calendar, in which that
// day was 14 Sep 1752 (i.e. 11 days were dropped).
//
// Day number of first day of Gregorian calendar in Britain (14 Sep 1752)
const long gregorian_epoch = 2361222L;

// Convert a date to a Julian day number
long date_to_julian(int d, int m, int y);

// Convert a Julian day number to a date
void julian_to_date(const long jd, int &d, int &m, int &y);

class Date {
	// The date as a Julian day number
	long julian_day;

public:
	// Today's date
	Date() : julian_day(julian_today()) {}

	// A date in the current year
	Date(int d, int m) : julian_day(date_to_julian(d, m, Date().year())) {}

	// A fully specified date
	Date(int d, int m, int y) : julian_day(date_to_julian(d, m, y)) {}

	// The date of a Julian day number
	Date(long jd) : julian_day(jd) {}

	// The day of the month (1-31)
	int day() const;

	// The month of the year (1-12)
	int month() const;

	// The year number
	int year() const;

	// The date as a Julian day number
	long day_number() const { return julian_day; }
};

int Date::day() const {
	int d, m, y;
	julian_to_date(julian_day, d, m, y);
	return d;
}

int Date::month() const {
	int d, m, y;
	julian_to_date(julian_day, d, m, y);
	return m;
}

int Date::year() const {
	int d, m, y;
	julian_to_date(julian_day, d, m, y);
	return y;
}

long julian_today() {
	return time(0) / seconds_per_day + time_epoch;
}

// Convert a date to a Julian day number
long date_to_julian(int d, int m, int y) {
	// there was no year 0
	if (y < 0)
		y++;
	// consider Jan and Feb as belonging to previous year
	if (m <= 2) {
		y--;
		m += 12;
	}
	m++;
	long start_of_year = 1720995L + (long)floor(365.25 * y);
	int day_of_year = (long)floor(30.6001 * m) + d;
	long jd = start_of_year + day_of_year;
	// Gregorian correction
	if (jd >= gregorian_epoch)
		jd += 2 + y/400 - y/100;
	return jd;
}

// Convert a Julian day number to a date
void julian_to_date(const long jd, int &d, int &m, int &y) {
	if (jd >= gregorian_epoch)
		// JD 1721120 = 1 Mar 1BC (Gregorian calendar)
		y = (int)floor((jd - 1721120) / 365.2425);
	else
		// JD 1721118 = 1 Mar 1BC (Julian calendar)
		y = (int)floor((jd - 1721118) / 365.25);
	long start_of_year = 1720995L + (long)floor(365.25 * y);
	// Gregorian correction
	if (jd >= gregorian_epoch)
		start_of_year += 2 + y/400 - y/100;
	int day_of_year = jd - start_of_year;
	m = (int)floor(day_of_year / 30.6001);
	d = day_of_year - (long)floor(30.6001 * m);
	// consider Jan and Feb as belonging to previous year
	m--;
	if (m > 12)
		m -= 12;
	if (m <= 2)
		y++;
	// there was no year 0
	if (y <= 0)
		y--;
	assert(date_to_julian(d, m, y) == jd);
}


