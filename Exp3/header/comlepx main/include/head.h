#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
typedef struct xd
{
    float real;
    float fake;
}comp;
comp add(comp a,comp b);
comp abst(comp a,comp b);
comp mut(comp a,comp b);
comp divi(comp a,comp b);


#endif 
