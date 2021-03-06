

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from manth & day */
int day_of_year(int year, int month, int day) {
	int i, leap;
	if(year < 0){
		return 0;
	}
	if(leap == 1){
		if(year > 366){
			return 0;
		}
		else{
			for (i = 1; i < month; i++)
				day += daytab[leap][i];
			return day;
		}
	}
	else{
		if(year>365){
			return 0;
		}
		else{
			for (i = 1; i < month; i++)
				day += daytab[leap][i];
			return day;
		}
	}

	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
	int i, leap;
	
	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

	if(month >= 1 && month <= 12){
		if(0 < day && day <= daytab[leap][month]){
			for (i = 1; yearday > daytab[leap][i]; i++)
				yearday -= daytab[leap][i];
			*pmonth = i;
			*pday = yearday;
		}
	}
}

/* month_name: return name of n-th month */
char *month_name(int n) {
	static char *name[] = {
		"Illegal month",
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"
	};

	return (n < 1 || n > 12) ? name[0] : name[n];
}