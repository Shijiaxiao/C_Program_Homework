#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MDF 5
typedef struct grade
{
    char name[100];
    int mark[MDF];
}gra;
void input(gra p[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%s",p[i].name);
        scanf("%d %d %d %d %d",&p[i].mark[0],&p[i].mark[1],&p[i].mark[2],&p[i].mark[3],&p[i].mark[4]);
    }
}
void maxmin(gra p[100],int n)
{
    int max[MDF],min[MDF];//”–ŒÂ√≈ø∆ƒø£¨±ÿ–Î¥¥Ω®≥§∂»Œ™ŒÂµƒ ˝◊Èº«¬º∑÷±µƒ◊Ó¥Û◊Ó–°≥…º®
    int k,maxflag[MDF],u,minflag[MDF];//¥¥Ω®±Í÷æ£¨’“µΩ∂‘”¶Ω·ππÃÂ£¨∑Ω±„ ‰≥ˆ»À√˚
    for(u=0;u<MDF;u++)
    {
        max[u]=p[0].mark[u];
        min[u]=p[0].mark[u];
        maxflag[u]=0;
        minflag[u]=0;
        for(k=0;k<n;k++)
        {
            if(p[k].mark[u]<min[u])
            {
                min[u]=p[k].mark[u];
                minflag[u]=k;
            }
            if(p[k].mark[u]>max[u])
            {
                max[u]=p[k].mark[u];
                maxflag[u]=k;
            }
        }
    }
        printf("Chinese: max:%d%s  min:%d%s\n",max[0],p[maxflag[0]].name,min[0],p[minflag[0]].name);
        printf("Math: max:%d%s  min:%d%s\n",max[1],p[maxflag[1]].name,min[1],p[minflag[1]].name);
        printf("English: max:%d%s  min:%d%s\n",max[2],p[maxflag[2]].name,min[2],p[minflag[2]].name);
        printf("Physics: max:%d%s  min:%d%s\n",max[3],p[maxflag[3]].name,min[3],p[minflag[3]].name);
        printf("Chemistry: max:%d%s  min:%d%s\n",max[4],p[maxflag[4]].name,min[4],p[minflag[4]].name);
}
void tol(gra p[100],int n)
{
    int ma=0,mi=0,sum=0;
    int i,q,maxfla=0,minfla=0;
    for(q=0;q<MDF;q++)
    {
        ma+=p[0].mark[q];
        mi+=p[0].mark[q];
    }
    for(i=0;i<n;i++)
    {
        for(q=0;q<MDF;q++)
        {
            sum+=p[i].mark[q];
        }
        if(sum>ma)
        {
            ma=sum;
            maxfla=i;
        }
        if(sum<mi)
        {
            mi=sum;
            minfla=i;
        }
        sum=0;
    }
    printf("Total: max:%d%s  min:%d%s",ma,p[maxfla].name,mi,p[minfla].name);
}
int main()
{
    gra students[100];
    int n;
    scanf("%d",&n);
    input(students,n);
    maxmin(students,n);
    tol(students,n);
}

