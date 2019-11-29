/*  factor.c -- Compute T(s) from Project Euler Problem 256
    Written November 3, 2019 by Eric Olson

    Factor s to save memory at the expense of runtime.  */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define sMax 100000000
#define pNum 1300
#define fNum 13

int *P,pN;
int isprime(int p){
    for(int i=0;i<pN;i++){
        if(!(p%P[i])) return 0;
    }
    return 1;
}
void qinit(){
    int pMax=sqrt(sMax)+0.5;
    P=malloc(pNum*sizeof(int));
    P[0]=2; pN=1;
    for(int p=3;p<pMax;p++){
        if(isprime(p)) P[pN++]=p;
    }
}
typedef struct { int fN,p[fNum],n[fNum]; } factors;
factors factor(int s){
    factors r;
    r.fN=0;
    int sqrts=sqrt(s)+0.5;
    int p;
    for(int i=0;(p=P[i])<=sqrts;){
        if(!(s%p)){
            r.p[r.fN]=p; r.n[r.fN]=1;
            s/=p;
            while(!(s%p)){
                r.n[r.fN]++;
                s/=p;
            }
            r.fN++;
            sqrts=sqrt(s)+0.5;
        } else {
            i++;
        }
    }
    if(s>1){
        r.p[r.fN]=s; r.n[r.fN]=1;
        r.fN++;
    }
    return r;
}
int tfree(int k,int l){
    int n=l/k;
    int lmin=(k+1)*n+2;
    int lmax=(k-1)*(n+1)-2;
    return lmin<=l && l<=lmax;
}
int T(int s){
    if(s&1) return 0;
    int sqrts=sqrt(s)+0.5;
    factors f=factor(s);
    int z[fNum];
    bzero(z,fNum*sizeof(int));
    int r=0;
    for(;;){
        z[0]++;
        for(int i=0;i<f.fN;i++){
            if(z[i]>f.n[i]){
                z[i]=0;
                z[i+1]++;
            }
        }
        if(z[f.fN]) break;
        int k=1;
        for(int i=0;i<f.fN;i++){
            for(int s=0;s<z[i];s++) k*=f.p[i];
        }
        if(k<=sqrts) r+=tfree(k,s/k);
    }
    return r;
}
int main(){
    qinit();
    for(int s=2;s<sMax;s+=2){
        int r=T(s);
//        printf("T(%d)=%d\n",s,r);
        if(r==200){
            printf("T(%d)=%d\n",s,r);
            break;
        }
    }
    return 0;
}
