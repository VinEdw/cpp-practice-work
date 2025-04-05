#include <stdio.h>
#include <stdbool.h>

int modulo(int n, int d) {
  const int result = n % d;
  if ((n < 0 && d > 0) || (n > 0 && d < 0)) {
    return result + d;
  }
  return result;
}

// Return whether the given year is a leap year.
bool is_leap_year(int year) {
  if (year % 400 == 0) {
    return true;
  }
  else if (year % 100 == 0) {
    return false;
  }
  else if (year % 4 == 0) {
    return true;
  }
  return false;
}

// Return the number of days in the given month of the given year.
// Return 0 if an invalid month is given.
int month_length(int year, int month) {
  switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    case 2:
      return is_leap_year(year) ? 29 : 28;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    default:
      return 0;
  }
}

// Return the day of the week of the given date.
// The day of the week is represented by an integer between 0 and 6, with Sunday being 0
int day_of_week(int year, int month, int day) {
  // Since the calendar repeats every 400 years, the day of the week depends on the year relative to the cycle
  const int effective_year = modulo(year, 400);


  int day_count = 0;
  for (int yr = 0; yr < effective_year; ++yr) {
    day_count += is_leap_year(yr) ? 366 : 365;
  }

  for (int mn = 1; mn < month; ++mn) {
    day_count += month_length(year, mn);
  }
  
  day_count += day - 1;

  // The start of the cycle starts on a Saturday in a leap year
  int initial_dow = 6;
  int week_length = 7;
  return (initial_dow + day_count) % week_length;
}

// Count how many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)
int main() {
  int count = 0;

  for (int year = 1901; year <= 2000; ++year) {
    for (int month = 1; month <= 12; ++month) {
      if (day_of_week(year, month, 1) == 0) {
        count += 1;
      }
    }
  }

  printf("%d\n", count);

  return 0;
}
