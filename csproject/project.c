#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BLACK_TEXT "\033[30m"
#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define BLUE_TEXT "\033[34m"
#define MAGENTA_TEXT "\033[35m"
#define CYAN_TEXT "\033[36m"
#define WHITE_TEXT "\033[37m"
#define RESET_TEXT "\033[0m"


// Menu
void option1();
void option2();
int option3();
void option4();
// End of menu


// Conversion
void convert1();
void convert2();
void convert3();
void convert4();
void convert5();
void convert6();
int daystoymd(int);
bool isLeapG(int);
int daysOfMonthQ(int);
int numberOfLeapsQ(int);
bool isLeapQ(int);
// End of conversion

// Age section
int daysOfLeapYears(int, int);
int daysInbyear(int , int, int);
int monthDaysInyear(int);
int monthDaysInbyear(int, int);
int daystoymdsh(int);
int askformore(int ,int ,int);
// End of Age section


// Calendar
int calendar(int , int);
bool isLeap(int);
int getFirstDayOfYear(int);
int numberOfLeaps(int);
int dayscounter(int , int);
int lenofmonth(int , int);
// End of calendar


int main() {

    printf(YELLOW_TEXT"\n---------------\n"YELLOW_TEXT);
    printf(GREEN_TEXT"[0] exit\n"GREEN_TEXT);
    printf(GREEN_TEXT"[1] calendar\n"GREEN_TEXT);
    printf(GREEN_TEXT"[2] age\n"GREEN_TEXT);
    printf(GREEN_TEXT"[3] conversion\n"GREEN_TEXT);
    printf(YELLOW_TEXT"---------------\n"YELLOW_TEXT);
    printf(WHITE_TEXT"SELECT OPTION: "WHITE_TEXT);

    int choice;
    scanf("%d", &choice);


    switch (choice) {
        case 0:
            option1();
            break;
        case 1:
            system("cls");
            option2();
            break;
        case 2:
            system("cls");
            option3();
            break;
        case 3:
            system("cls");
            option4();
            break;
        default:
            system("cls");
            printf(RED_TEXT"\nInvalid input!"RED_TEXT);
            main();
    }


    return 0;
}


void option1() {
    printf(GREEN_TEXT"Bye!"GREEN_TEXT);
    exit(0);
}

void option2() {
    
    int year;    
    int month;

    
    printf("[0] back to menu\n");
    printf("----------------\n");

    while(true){
        printf("\nENTER THE YEAR:");
        scanf("%d", &year);
        if(year == 0){
            system("cls");
            printf("\nback to menu!\n");
            main();
        }


        else if((year < 1206 || year > 1498) && (year != 0)){
            system("cls");
            printf("\nTHIS CALENDAR IS NOT DEVELOPED FOR THE YEARS LESS THAN 1206 OR MORE THAN 1498\n");
            main();
        }

        printf("Enter the month:");
        scanf("%d", &month);

        while(month == 0 || month > 12){
            printf("\nENTER THE MONTH:\n");
            scanf("%d", &month);
        }

        if(month != 0 && month < 12){}

        
        printf(YELLOW_TEXT "\n**************************************************" YELLOW_TEXT);
        calendar(year, month);

    }
    system("cls");
    main();
        
    }


int option3(){
    
    printf("\n[0] back to menu\n");
    printf(YELLOW_TEXT"----------------\n"YELLOW_TEXT);

    int year;
    int month;
    int day;

    int byear;
    int bmonth;
    int bday;

    int daysToNow;

    printf("please enter your year of birth: \n");
    scanf("%d", &byear);
    if(byear == 0 || byear < 0){
        system("cls");
        main();
    }

    printf("and the month of your birth: \n");
    scanf("%d", &bmonth);
    if(bmonth == 0 || bmonth < 0 || bmonth > 12){
        system("cls");
        printf(RED_TEXT"\ninvalid input!\n"RED_TEXT);
        main();
    }
    printf("and your birthday: \n");
    scanf("%d", &bday);
    if(bday == 0 || bday < 0 || bday > 31){
        system("cls");
        printf(RED_TEXT"\ninvalid input!\n"RED_TEXT);
        main();

    }
    printf("Please enter today's date, first enter year: \n");
    scanf("%d", &year);
    if(year == 0 || year < 0 || year < byear){
        system("cls");
        printf(RED_TEXT"\ninvalid input!\n"RED_TEXT);
        main();
    }

    printf("Please enter today's date, second enter month: \n");
    scanf("%d", &month);
    if(month == 0 || month < 0 || month > 12){
        system("cls");
        printf(RED_TEXT"\ninvalid input!\n"RED_TEXT);
        main();
    }

    printf("Please enter today's date, third enter day: \n");
    scanf("%d", &day);
    if(day == 0 || day > 31 || day < 0){
        system("cls");
        printf(RED_TEXT"\ninvalid input!\n"RED_TEXT);
        main();
    }
    daysToNow = ((year - byear) * 365) + monthDaysInbyear(byear,bmonth) +  monthDaysInyear(month) + daysInbyear(byear, bmonth, bday) + day + daysOfLeapYears(year, byear);

    daystoymdsh(daysToNow);


    printf(GREEN_TEXT"\nYOU CAN SEE THE DAY THAT YOU BORNED IN THE TABLE BELOWE: \n"GREEN_TEXT);
    calendar(byear , bmonth);

    askformore(byear , bmonth , bday);

}   

void option4() {

    printf("[0] back to menu\n");
    printf(YELLOW_TEXT"*********************\n"YELLOW_TEXT);
    printf("which type of conversion do you want to do?\n");
    printf("-------------------\n");
    printf("[1] SHAMSI to MILADI\n");
    printf("[2] SHAMSI to QAMARI\n");
    printf("[3] miladi to shamsi\n");
    printf("[4] miladi to qamari\n");
    printf("[5] qamari to miladi\n");
    printf("[6] qamari to shamsi\n");
    printf("-------------------\n");

    int choise;
    scanf("%d", &choise);
    
    switch(choise){
        case 0:
           system("cls");
           main();
        case 1:
           system("cls");
           convert1();
           break;
        case 2:
           system("cls");
           convert2();
           break;
        case 3:
           system("cls");
           convert3();
           break;
        case 4:
           system("cls");
           convert4();
           break;
        case 5:
           system("cls");
           convert5();
           break;
        case 6:
           system("cls");
           convert6();
           break;
        default:
           system("cls");
           printf(RED_TEXT"\ninvlaid input!\n"RED_TEXT);
           option4();
           break;

    }
}

int daystoymdsh(int days){

    int daysInMonth[] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};
    int shamsiYear = 1; // The Gregorian calendar starts from year 1

    while (days > 365) {
        if (isLeap(shamsiYear)) {
            if (days >= 366) {
                days -= 366;
                shamsiYear++;
            }
        } else {
            days -= 365;
            shamsiYear++;
        }
    }

    int shamsiMonth = 0;
    while (days > daysInMonth[shamsiMonth]) {
        if (shamsiMonth == 12 && (isLeap(shamsiYear))) {
            if (days > 29) {
                days -= 29;
                shamsiMonth++;
            }
        } else {
            days -= daysInMonth[shamsiMonth];
            shamsiMonth++;
        }
    }

    int shYear = shamsiYear - 2;
    int shmMonth = shamsiMonth;
    int shDay = days + 1; // Days are 1-indexed

    printf(YELLOW_TEXT"\nYour age is %d year and %d month and %d day\n"YELLOW_TEXT, shYear , shmMonth, shDay);
}

int daystoymdshFC(int days){

    int daysInMonth[] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};
    int shamsiYear = 1;

    while (days > 365) {
        if (isLeap(shamsiYear)) {
            if (days >= 366) {
                days -= 366;
                shamsiYear++;
            }
        } else {
            days -= 365;
            shamsiYear++;
        }
    }

    int shamsiMonth = 0;
    while (days > daysInMonth[shamsiMonth]) {
        if (shamsiMonth == 12 && (isLeap(shamsiYear))) {
            if (days > 29) {
                days -= 29;
                shamsiMonth++;
            }
        } else {
            days -= daysInMonth[shamsiMonth];
            shamsiMonth++;
        }
    }

    int shYear = shamsiYear;
    int shmMonth = shamsiMonth;
    int shDay = days; // Days are 1-indexed

    printf("%d %d %d", shYear , shmMonth, shDay);
}

int monthDaysInbyear(int byear, int bmonth) {
    if (bmonth < 6 && isLeap(byear)) {
        return ((6-bmonth) * 31) + 180;
    } else if (bmonth == 6 && isLeap(byear)) {
        return 180;
    } else if (bmonth < 6 && !(isLeap(byear))) {
        return ((6-bmonth) * 31) + 179;
    } else if (bmonth == 6 && !(isLeap(byear))) {
        return 179;
    } else if (bmonth > 6 && bmonth !=12 && isLeap(byear)) {
        return ((11 - bmonth) * 30) + 30;
    } else if (bmonth > 6 && bmonth !=12 && !(isLeap(byear))) {
        return ((11 - bmonth) * 30) + 29;
    } else if (bmonth > 6 && bmonth ==12) {
        return 0;
    }
}

int monthDaysInyear(int month){
    if (month <= 6) {
        return ((month - 1) * 31);
    } else if (month > 6) {
        return (((month - 7) * 30) + 186);
    }
}

int daysInbyear(int byear, int bmonth, int bday){
    if (bmonth <= 6){
        return 31 - bday;
    } else if (bmonth > 6 && bmonth < 12) {
        return 30 - bday;
    } else if (bmonth == 12 && !(isLeap(byear))){
        return 29 - bday;
    } else if (bmonth == 12 && (isLeap(byear))){
        return 30 - bday;
    }
}

int daysOfLeapYears(int year, int byear) {
    int i;
    int counter = 0;
    
    for(i = byear ; i < year ; i++){
        if(isLeap(i)){
            counter += 1;
        }
    }
    
    return counter;
}



//functions for calendar
int calendar(int year, int month){
    char *months[] = {"Farvardin", "Ordibehesht", "Khordad", "Tir", "Mordad", "Shavrivar", "Mehr", "Aban", "Azar", "Day", "Bahman", "Esfand"};
    int daysOfMonth[] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};
    int i, j, weekDay = 0, spaceCounter = 0;

    //check leap year
    int x = year % 128;

    if(x==0 || x==4 || x==8 || x==12 || x==16 || x==20 || x==24 || x==29 || x==33 || x==37 || x==41 || x==45 || x==49 || x==53 || x==57 || x==62 || x==66 || x==70 || x==74 || x==78 || x==82 || x==86 || x==90 || x==95 || x==99 || x==103 || x==107 || x==111 || x==115 || x==119 || x==124){
        daysOfMonth[12]=30;
    }


    //get first day of year.
    weekDay += getFirstDayOfYear(year) + 5;

    if(weekDay > 6){
        weekDay = weekDay - 7;
    }

    //get first day of month
    int firstdayofmonth = (weekDay + dayscounter(month, year)) % 7;

    //print days
    printf("\n-------------------- %s ------------------\n", months[month - 1]);
    printf("    SH     YEK     DO     SE     CH     PA     JO    \n");
    //print space
    for(spaceCounter = 1; spaceCounter <= firstdayofmonth; spaceCounter++){
        printf("       ");
    }

    int fm = firstdayofmonth;

    //print date of month
    for(j=1; j<= lenofmonth(month , year); j++){
        printf("%7d",j);
        firstdayofmonth++;

        if(firstdayofmonth > 6){
            printf("\n   --------------------------------------------------\n");
            printf("\n");
            firstdayofmonth = 0;
        }
    }
    printf("\n enter the day to tell the name of that day:\n");

    int ans;
    scanf("%d", &ans);

    int wanted = fm + ans - 1;

    if(wanted % 7 == 0)
        printf("sh");
    else if(wanted % 7 == 1)
        printf("ye");
    else if(wanted % 7 == 2)
        printf("do");
    else if(wanted % 7 == 3)
        printf("se");
    else if(wanted % 7 == 4)
        printf("ch");
    else if(wanted % 7 == 5)
        printf("pa");
    else if(wanted % 7 == 6)
        printf("go");

    
}

bool isLeap(int year){
    int x = year % 128;

    if(x==0 || x==4 || x==8 || x==12 || x==16 || x==20 || x==24 || x==29 || x==33 || x==37 || x==41 || x==45 || x==49 || x==53 || x==57 || x==62 || x==66 || x==70 || x==74 || x==78 || x==82 || x==86 || x==90 || x==95 || x==99 || x==103 || x==107 || x==111 || x==115 || x==119 || x==124){
        return true;
    }
    else
        return false;
}

int getFirstDayOfYear(int year){

    int firstday = ((year - 1206) * 365 + numberOfLeaps(year)) % 7;

    return firstday;
}

int numberOfLeaps(int year){

    int i;
    int counter = 0;
    
    for(i = 1206 ; i <= year ; i++){
        if(isLeap(i)){
            counter += 1;
        }
    }
    
    return counter;
}

int dayscounter(int month,int year){
    if(month >= 1 && month <= 6){
        int wantedmonth[31];
        int daystomonth = (month - 1) * 31;
        return daystomonth;
    }
    else if(month >= 7 && month < 12){
        int wantedmonth[30];
        int daystomonth = (6 * 31) + (month - 7) * 30;
        return daystomonth;
    }
    else if(month == 12){
        if(isLeap(year)){
            int wantedmonth[30];
        }
        else{
            int wantedmonth[29];
        }
        int daystomonth = (6 * 31) + (month - 7) * 30;
        return daystomonth;
    }
}
int lenofmonth(int month, int year) {
        if(month >= 1 && month <= 6){
        return 31;
    }
    else if(month >= 7 && month < 12){
        return 30;
    }
    else if(month == 12){
        if(isLeap(year)){
            return 30;
        }
        else{
            return 29;
        }
    }
}
// end of calendarfunctions


// functions for conversion


// shamsi to miladi 
void convert1(){
    while(true){
        int year , month , day;

        printf("\n[0] back to menu of conversion\n");

        printf("**************************\n");
        printf("enter the year in SHAMSI: \n");
        scanf("%d" , &year);
        if(year == 0){
            system("cls");
            printf("back to menu !");
            option4();
        }
        else if(year != 0 && year < 0){
            system("cls");
            printf("invalid input\n");
            option4();
        }
        printf("enter the month in SHAMSI: \n");
        scanf("%d" , &month);
        if(month == 0 || month > 12 || month < 0){
            system("cls");
            printf("invalid input!\n");
            option4();
        }
        printf("Enter the day in SHAMSI: \n");
        scanf("%d", &day);
        if(day == 0 || day > 31 || day < 0){
            system("cls");
            printf("invalid input!\n");
            option4();
        }

        year += 1595;
        long days = -355668 + (365 * year) + (((int)(year / 33)) * 8) + ((int)(((year % 33) + 3) / 4)) + day + ((month < 7) ? (month - 1) * 31 : ((month - 7) * 30) + 186);
        long gy = 400 * ((int)(days / 146097));
        days %= 146097;
        if (days > 36524) {
        gy += 100 * ((int)(--days / 36524));
        days %= 36524;
        if (days >= 365) days++;
        }
        gy += 4 * ((int)(days / 1461));
        days %= 1461;
        if (days > 365) {
            gy += (int)((days - 1) / 365);
            days = (days - 1) % 365;
        }
        long gd = days + 1;
        long gm;
        {
            long sal_a[13] = {0, 31, ((gy % 4 == 0 && gy % 100 != 0) || (gy % 400 == 0)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            for (gm = 0; gm < 13 && gd > sal_a[gm]; gm++) gd -= sal_a[gm];
        }
        int gyear = gy;
        int gmonth = gm;
        int gday = gd;
        
        printf("\n");

        printf("%d %d %d", gyear , gmonth, gday);

    }
}


// shamsi to qamari
void convert2(){
    while(true){

        int year , month , day;
   
        printf("\n[0] back to menu of conversion\n");

        printf("**************************\n");
        printf("enter the year in SHAMSI: \n");
        scanf("%d" , &year);
        if(year == 0){
            system("cls");
            printf("back to menu !");
            option4();
        }
        else if(year != 0 && year < 0){
            system("cls");
            printf("invalid input\n");
            option4();
        }
        printf("enter the month in SHAMSI: \n");
        scanf("%d" , &month);
        if(month == 0 || month > 12 || month < 0){
            system("cls");
            printf("invalid input!\n");
            option4();
        }
        printf("Enter the day in SHAMSI: \n");
        scanf("%d", &day);
        if(day == 0 || day > 31 || day < 0){
            system("cls");
            printf("invalid input!\n");
            option4();
        }
        printf("\n**************************\n");

        year += 1595;
        long days = -355668 + (365 * year) + (((int)(year / 33)) * 8) + ((int)(((year % 33) + 3) / 4)) + day + ((month < 7) ? (month - 1) * 31 : ((month - 7) * 30) + 186);
        long gy = 400 * ((int)(days / 146097));
        days %= 146097;
        if (days > 36524) {
        gy += 100 * ((int)(--days / 36524));
        days %= 36524;
        if (days >= 365) days++;
        }
        gy += 4 * ((int)(days / 1461));
        days %= 1461;
        if (days > 365) {
            gy += (int)((days - 1) / 365);
            days = (days - 1) % 365;
        }
        long gd = days + 1;
        long gm;
        {
            long sal_a[13] = {0, 31, ((gy % 4 == 0 && gy % 100 != 0) || (gy % 400 == 0)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            for (gm = 0; gm < 13 && gd > sal_a[gm]; gm++) gd -= sal_a[gm];
        }
        int gyear = gy;
        int gmonth = gm;
        int gday = gd;
    
	    unsigned long jd,l,j,n;   

    	if ((gy>1582)||((gy==1582)&&(gm>10))||((gy==1582)&&(gm==10)&&(gd>14)))
	    	jd=(1461*(gy+4800+(gm-14)/12))/4+(367*(gm-2-12*((gm-14)/12)))/12-(3*((gy+4900+(gm-14)/12)/100))/4+gd-32075;

	    else jd = 367*gy-(7*(gy+5001+(gm-9)/7))/4+(275*gm)/9+gd+1729777;
        
	    l=jd-1948440+10632;
                                                
	    n=(l-1)/10631;
	    l=l-10631*n+354;
	    j=((10985-l)/5316)*((50*l)/17719)+(l/5670)*((43*l)/15238);
	    l=l-((30-j)/15)*((17719*j)/50)-(j/16)*((15238*j)/43)+29; 
                                        
                                        
        int hmonth = (24*l)/709;
	    int hyear = 30*n+j-30;
        int hday = l-(709 * hmonth)/24;

        printf("\n");

        printf("%d %d %d", hyear , hmonth, hday);
    }
}


// miladi to shamsi 
void convert3(){
    
    while(true){

    int year , month , day;

    printf("\n**************************\n");
    printf("enter the year in MILADI: \n");
    scanf("%d" , &year);
    if(year == 0){
        system("cls");
        printf("back to menu !");
        option4();
    }
    else if(year != 0 && year < 0){
        system("cls");
        printf("invalid input\n");
        option4();
    }
    printf("enter the month in MILADI: \n");
    scanf("%d" , &month);
    if(month == 0 || month > 12 || month < 0){
        system("cls");
        printf("invalid input!\n");
        option4();
    }
    printf("Enter the day in MILADI: \n");
    scanf("%d", &day);
    if(day == 0 || day > 31 || day < 0){
        system("cls");
        printf("invalid input!\n");
        option4();
    }
    printf("\n**************************\n");

    long days;
    long jm;
    long jd;
    {
        long gy2 = (month > 2) ? (year + 1) : year;
        long g_d_m[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        days = 355666 + (365 * year) + ((int)((gy2 + 3) / 4)) - ((int)((gy2 + 99) / 100)) + ((int)((gy2 + 399) / 400)) + day + g_d_m[month - 1];
    }
    long jy = -1595 + (33 * ((int)(days / 12053)));
    days %= 12053;
    jy += 4 * ((int)(days / 1461));
    days %= 1461;
    if (days > 365) {
        jy += (int)((days - 1) / 365);
        days = (days - 1) % 365;
    }
    if (days < 186) {
        jm = 1 + (int)(days / 31);
        jd = 1 + (days % 31);
    } else {
        jm = 7 + (int)((days - 186) / 30);
        jd = 1 + ((days - 186) % 30);
    }

    int jyear = jy;
    int jmonth = jm;
    int jday = jd;
    
    printf("\n");

    printf("%d %d %d", jyear , jmonth, jday);

    }

}


// miladi to qamari
void convert4(){

    while(true){

        int year , month , day;

        printf("\n[0] back to menu of conversion\n");

        printf("\n**************************\n");
        printf("enter the year in MILADI: \n");
        scanf("%d" , &year);
        if(year == 0){
            system("cls");
            printf("back to menu !");
            option4();
        }
        else if(year != 0 && year < 0){
            system("cls");
            printf("invalid input\n");
            option4();
        }
        printf("enter the month in MILADI: \n");
        scanf("%d" , &month);
        if(month == 0 || month > 12 || month < 0){
            system("cls");
            printf("invalid input!\n");
            option4();
        }   
        printf("Enter the day in MILADI: \n");
        scanf("%d", &day);
        if(day == 0 || day > 31 || day < 0){
            system("cls");
            printf("invalid input!\n");
            option4();
        }
        printf("\n**************************\n");


        unsigned long jd,l,j,n;   

	    if ((year>1582)||((year==1582)&&(month>10))||((year==1582)&&(month==10)&&(day>14)))
		    jd=(1461*(year+4800+(month-14)/12))/4+(367*(month-2-12*((month-14)/12)))/12-(3*((year+4900+(month-14)/12)/100))/4+day-32075;

	    else jd = 367*year-(7*(year+5001+(month-9)/7))/4+(275*month)/9+day+1729777;
        
	    l=jd-1948440+10632;
                                                
	    n=(l-1)/10631;
	    l=l-10631*n+354;
	    j=((10985-l)/5316)*((50*l)/17719)+(l/5670)*((43*l)/15238);
	    l=l-((30-j)/15)*((17719*j)/50)-(j/16)*((15238*j)/43)+29; 
                                        
                                        
        int hmonth = (24*l)/709;
	    int hyear = 30*n+j-30;
        int hday = l-(709 * hmonth)/24;

        printf("\n");

        printf("%d %d %d", hyear , hmonth, hday);

    }

}

// unfortunatly this conversion doesnt work 
// This is convert qamaro to miladi
void convert5(){

    while(true){

    int year , month , day;
    printf("\n[0] back to menu of conversion\n");

    printf("**************************\n");
    printf("enter the year in QAMARI: \n");
    scanf("%d" , &year);

    if(year == 0){
        system("cls");
        printf("back to menu !");
        option4();
    }
    else if(year != 0 && year < 0){
        system("cls");
        printf("invalid input\n");
        option4();
    }
    printf("enter the month in QAMARI: \n");
    scanf("%d" , &month);
    if(month == 0 || month > 12 || month < 0){
        system("cls");
        printf("invalid input!\n");
        option4();
    }
    printf("Enter the day in QAMARI: \n");
    scanf("%d", &day);
    if(day == 0 || day > 31 || day < 0){
        system("cls");
        printf("invalid input!\n");
        option4();
    }
    printf("\n**************************\n");

    int days = ((year - 1) * 354) + daysOfMonthQ(month) + day + numberOfLeapsQ(year) + 227074 - 60 ;

    printf("\n");

    daystoymd(days);

    }
}

// This is convert qamari to shamsi
void convert6(){

    while(true){
    int year , month , day;

    printf("\n[0] back to menu of conversion\n");
    
    

    printf("**************************\n");
    printf("enter the year in QAMARI: \n");
    scanf("%d" , &year);
    if(year == 0){
        system("cls");
        printf("back to menu !");
        option4();
    }
    else if(year != 0 && year < 0){
        system("cls");
        printf("invalid input\n");
        option4();
    }
    printf("enter the month in QAMARI: \n");
    scanf("%d" , &month);
    if(month == 0 || month > 12 || month < 0){
        system("cls");
        printf("invalid input!\n");
        option4();
    }
    printf("Enter the day in QAMARI: \n");
    scanf("%d", &day);
    if(day == 0 || day > 31 || day < 0){
        system("cls");
        printf("invalid input!\n");
        option4();
    }
    printf("\n**************************\n");

    //int days = ((year - 1) * 354) + daysOfMonthQ(month) + day + numberOfLeapsQ(year) - 60;
    //printf("\n");
    //daystoymdshFC(days);

    int qd = ((year - 1) * 354) + daysOfMonthQ(month) + day + numberOfLeapsQ(year) + 227074 - 60 ;
    printf("\n");
    //daystoymd(days);
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int gregorianYear = 1; // The Gregorian calendar starts from year 1

    while (qd > 365) {
        if (isLeapG(gregorianYear)) {
            if (qd >= 366) {
                qd -= 366;
                gregorianYear++;
            }
        } else {
            qd -= 365;
            gregorianYear++;
        }
    }

    int gregorianMonth = 0;
    while (qd > daysInMonth[gregorianMonth]) {
        if (gregorianMonth == 1 && (isLeapG(gregorianYear))) {
            if (qd > 29) {
                qd -= 29;
                gregorianMonth++;
            }
        } else {
            qd -= daysInMonth[gregorianMonth];
            gregorianMonth++;
        }
    }

    int Gyear = gregorianYear;
    int Gmonth = gregorianMonth + 1; // Months are 1-indexed
    int Gday = qd + 1; // Days are 1-indexed

    long days;
    long jm;
    long jd;
    {
        long gy2 = (Gmonth > 2) ? (Gyear + 1) : Gyear;
        long g_d_m[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        days = 355666 + (365 * Gyear) + ((int)((gy2 + 3) / 4)) - ((int)((gy2 + 99) / 100)) + ((int)((gy2 + 399) / 400)) + Gday + g_d_m[Gmonth - 1];
    }
    long jy = -1595 + (33 * ((int)(days / 12053)));
    days %= 12053;
    jy += 4 * ((int)(days / 1461));
    days %= 1461;
    if (days > 365) {
        jy += (int)((days - 1) / 365);
        days = (days - 1) % 365;
    }
    if (days < 186) {
        jm = 1 + (int)(days / 31);
        jd = 1 + (days % 31);
    } else {
        jm = 7 + (int)((days - 186) / 30);
        jd = 1 + ((days - 186) % 30);
    }

    int jyear = jy;
    int jmonth = jm;
    int jday = jd - 2;
    
    printf("\n");

    printf("%d %d %d", jyear , jmonth, jday + 1);

    }
}

bool isLeapG(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true; // It's a leap year
    } else {
        return false; // It's not a leap year
    }
}

// get the number of days and convert it to gregorian 
int daystoymd(int days){

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int gregorianYear = 1; // The Gregorian calendar starts from year 1

    while (days > 365) {
        if (isLeapG(gregorianYear)) {
            if (days >= 366) {
                days -= 366;
                gregorianYear++;
            }
        } else {
            days -= 365;
            gregorianYear++;
        }
    }
}

int daysOfMonthQ(int month) {
    if (month == 2) {
        return 30;
    } else if (month == 3){
        return 30 + 29;
    } else if (month == 4) {
        return 30 + 29 + 30;
    } else if (month == 5){
        return 30 + 29 + 30 + 29;
    } else if (month == 6){
        return 30 + 29 + 30 + 29 + 30;
    } else if (month == 7){
        return 30 + 29 + 30 + 29 + 30 + 29;
    } else if (month == 8){
        return 30 + 29 + 30 + 29 + 30 + 29 + 30;
    } else if (month == 9){
        return 30 + 29 + 30 + 29 + 30 + 29 + 30 + 29;
    } else if (month == 10){
        return 30 + 29 + 30 + 29 + 30 + 29 + 30 + 29 + 30;
    } else if (month == 11){
        return 30 + 29 + 30 + 29 + 30 + 29 + 30 + 29 + 30 + 29;
    } else if (month == 12){
        return 30 + 29 + 30 + 29 + 30 + 29 + 30 + 29 + 30 + 29 + 30;
    } 
}

int numberOfLeapsQ(int year){

    int i;
    int counter = 0;
    
    for(i = 0 ; i <= year ; i++){
        if(isLeapQ(i)){
            counter += 1;
        }
    }
    
    return counter;
}

bool isLeapQ(int year) {
    if (year % 30 == 2 || year % 30 == 5 || year % 30 == 7 || year % 30 == 10 || year % 30 == 13 || year % 30 == 16 || year % 30 == 18 || year % 30 == 21 || year % 30 == 24 || year % 30 == 26 || year % 30 == 29){
        return true;
    } else {
        return false;
    }
}

int askformore(int year , int month ,int day){
    while(true){
        printf("\n\nYOU CAN SEE YOUR BIRTHDATE IN QAMARI AND MILADI IN HERE:(m for miladi and q for qamari and 0 for stop) \n");

        char ans;
        scanf("%s",&ans);

        if(ans == '0'){
            system("cls");
            printf(BLUE_TEXT"back to menu!!!"BLUE_TEXT);
            option3();
        }

    
        else if(ans == 'm'){

            year += 1595;
            long days = -355668 + (365 * year) + (((int)(year / 33)) * 8) + ((int)(((year % 33) + 3) / 4)) + day + ((month < 7) ? (month - 1) * 31 : ((month - 7) * 30) + 186);
            long gy = 400 * ((int)(days / 146097));
            days %= 146097;
            if (days > 36524) {
            gy += 100 * ((int)(--days / 36524));
            days %= 36524;
            if (days >= 365) days++;
            }
            gy += 4 * ((int)(days / 1461));
            days %= 1461;
            if (days > 365) {
                gy += (int)((days - 1) / 365);
                days = (days - 1) % 365;
            }
            long gd = days + 1;
            long gm;
            {
                long sal_a[13] = {0, 31, ((gy % 4 == 0 && gy % 100 != 0) || (gy % 400 == 0)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                for (gm = 0; gm < 13 && gd > sal_a[gm]; gm++) gd -= sal_a[gm];
            }
            int gyear = gy;
            int gmonth = gm;
            int gday = gd;

        
            printf("\n");

            printf(BLUE_TEXT"YOUR BIRTHDATE IN MILADI: %d %d %d"BLUE_TEXT, gyear , gmonth, gday);

        }   

        else if(ans == 'q'){

        year += 1595;
        long days = -355668 + (365 * year) + (((int)(year / 33)) * 8) + ((int)(((year % 33) + 3) / 4)) + day + ((month < 7) ? (month - 1) * 31 : ((month - 7) * 30) + 186);
        long gy = 400 * ((int)(days / 146097));
        days %= 146097;
        if (days > 36524) {
        gy += 100 * ((int)(--days / 36524));
        days %= 36524;
        if (days >= 365) days++;
        }
        gy += 4 * ((int)(days / 1461));
        days %= 1461;
        if (days > 365) {
            gy += (int)((days - 1) / 365);
            days = (days - 1) % 365;
        }
        long gd = days + 1;
        long gm;
        {
            long sal_a[13] = {0, 31, ((gy % 4 == 0 && gy % 100 != 0) || (gy % 400 == 0)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            for (gm = 0; gm < 13 && gd > sal_a[gm]; gm++) gd -= sal_a[gm];
        }
        int gyear = gy;
        int gmonth = gm;
        int gday = gd;
        
        unsigned long jd,l,j,n;   

        if ((gy>1582)||((gy==1582)&&(gm>10))||((gy==1582)&&(gm==10)&&(gd>14)))
            jd=(1461*(gy+4800+(gm-14)/12))/4+(367*(gm-2-12*((gm-14)/12)))/12-(3*((gy+4900+(gm-14)/12)/100))/4+gd-32075;

        else jd = 367*gy-(7*(gy+5001+(gm-9)/7))/4+(275*gm)/9+gd+1729777;
            
        l=jd-1948440+10632;
                                                    
        n=(l-1)/10631;
        l=l-10631*n+354;
        j=((10985-l)/5316)*((50*l)/17719)+(l/5670)*((43*l)/15238);
        l=l-((30-j)/15)*((17719*j)/50)-(j/16)*((15238*j)/43)+29; 
                                            
                                            
        int hmonth = (24*l)/709;
        int hyear = 30*n+j-30;
        int hday = l-(709 * hmonth)/24;

        printf("\n");

        printf(BLUE_TEXT"YOUR BIRTHDAY IN QAMAMRI : %d %d %d"BLUE_TEXT, hyear , hmonth, hday);

        }

        else
        {
            system("cls");
            printf(RED_TEXT"\ninvlalid input!\n"RED_TEXT);
            option3();
        }

    }
}
