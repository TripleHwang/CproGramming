#include <stdio.h>
#include <conio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from manth & day */
int day_of_year(int year, int month, int day) {
	int i, leap;

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	if(year<0){
		return 0;
	}
	else{
		char *p = daytab[leap];
		if(month <= 12 && month >= 1){
			for (i = 1; i < month; i++){
				day += *(p+i);
			}
			return day;
		}
		else{
			return 0;
		}
	}
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
	int i, leap;

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	char *p = daytab[leap];
	if(leap && yearday > 366){
		*pmonth = -1;
		*pday = -1;
		return ;
	}
	else if(leap == 0 && yearday > 365){
		*pmonth = -1;
		*pday = -1;
		return ;
	}
	else{
		for (i = 1; i < 12 && yearday > *(p+i); i++)
			yearday -= *(p+i);
		*pmonth = i;
		*pday = yearday;
		if(yearday > *(p+i)){
		*pmonth = -1;
		*pday = -1;
		return ;
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

void main(){
	int year;
	int yearday;
	int day;
	int month;
	int pmonth;
	int pday;

	year = 2000;
	yearday = 300;
	month_day(year, yearday, &pmonth, &pday);
	printf("pmonth : %d pday : %d\n",pmonth, pday);
	year = 2000;
	yearday = 600;
	month_day(year, yearday, &pmonth, &pday);
	printf("pmonth : %d pday : %d\n",pmonth, pday);

	year = 1998;
	month = 22;
	day = 1;
	printf("year : %d month : %d day : %d yearday : %d\n",year,month,day,day_of_year(year,month,day));
	year = 1998;
	month = 3;
	day = 1;
	printf("year : %d month : %d day : %d yearday : %d\n",year,month,day,day_of_year(year,month,day));
	char c = getch();
}