#include<stdio.h>
#include"complex.h"

comp add(comp a,comp b)
{
    comp c;
    c.real=a.real+b.real;
    c.fake=a.fake+b.fake;
    return c;
}
comp abst(comp a,comp b)
{
    comp c;
    c.real=a.real-b.real;
    c.fake=a.fake-b.fake;
    return c;
}
comp mut(comp a,comp b)
{
    comp c;
    c.real=a.real*b.real-a.fake*b.fake;
    c.fake=a.fake*b.real+a.real*b.fake;
    return c;
}
comp divi(comp a,comp b)
{
    comp d,c;
    b.fake=-b.fake;
    d=mut(a,b);
    c.real=d.real/(b.real*b.real+b.fake*b.fake);
    c.fake=d.fake/(b.real*b.real+b.fake*b.fake);
    return c;
}
