//
//  main.c
//  calendar
//
//  Created by 史家箫 on 2021/10/26.
//

#include <stdio.h>
#include <ctype.h>

int days_of_year(int year)
{
    if(year>1600)
    {
        if(year % 4==0)
        {
            if(year % 100!=0)
                return 366;
            else
            {
                if(year % 400==0)
                    return 366;
                else
                    return 365;
            }
        }
        else
            return 365;
    }
    else
    {
        if(year % 4==0)
            return 366;
        else
            return 365;
    }
}

int days_of_month(int year,int month)
{
    switch(month)
    {
        case 1: return 31;
        case 2:
            if(days_of_year(year)==366)
                return 29;
            else
                return 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
    }
    return 0;
}

int judge_again(char again[])
{
    int i,j;
    char yes[3]="yes";
    char no[2]="no";
    if(tolower(again[0])=='y')
    {
        j=3;
        for(i=1;i<j;i++)
            if(again[i]!=yes[i])
                return 0;
        return 1;
    }
    else if(tolower(again[0])=='n')
    {
        j=2;
        for(i=1;i<j;i++)
            if(again[i]!=no[i])
                return 0;
        return 2;
    }
    else return 0;
}

int main()
{
    int year,month;
    int i,row,column;
    int begin;
    char again[3];
    char rub1[1000],rub2[1000];
    while(1)
    {
        int days=0;
        int a=1;
        printf("Please tell me the year and month, then I will show you the calendar:");
        while(1)
        {
            scanf("%[^-0-9]",rub1);//filter the '\n' in the last loop as well
            scanf("%d",&year);
            scanf("%[^0-9]",rub2);
            scanf("%d",&month);
            if(year==0||month<0||month>12)
                printf("Please check your input:");
            else
                break;
        }
        
        if(year>=1900)
        {
            for(i=1900;i<year;i++)
                days+=days_of_year(i);
            for(i=1;i<month;i++)
                days+=days_of_month(year,i);
            begin=days%7;
            if(begin<6)
                begin+=1;
            else
                begin=1+begin-7;
        }
        else
        {
            if(year<0)
                year+=1;
            for(i=1899;i>year;i--)
                days+=days_of_year(i);
            for(i=12;i>=month;i--)
                days+=days_of_month(year,i);
            begin=days%7;
            if(begin<=1)
                begin=1-begin;
            else //if(begin>=2&&begin<=6)
                begin=1-begin+7;
        }
        if(year<=0)
            printf("---------B.C%04d-%02d----------\n",1-year,month);
        else
            printf("-----------%04d-%02d-----------\n",year,month);
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");
        for(row=1;row<=6;row++)
        {
            for(column=1;column<=7;column++)
            {
                if(row==1&&column<=begin)
                    printf("    ");
                else
                {
                    if(a<days_of_month(year,month))
                        printf(" %3d",a++);
                    else
                    {
                        printf(" %3d\n",a++);
                        break;
                    }
                    if(column==7)
                        printf("\n");
                }
            }
            if(a>days_of_month(year,month))
                break;
        }
        printf("That's all, wanna play again(yes/no):");
        while(1)
        {
            scanf("%s",again);//mind \n, %s do not read ' '
            if(judge_again(again)==1) break;
            else if(judge_again(again)==2) return 0;
            else printf("Please check your input:");
        }
    }
    return 0;
}
