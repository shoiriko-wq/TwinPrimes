// li(x)を求める。
// 作成者：入江田　承
// 作成日：2019/9/7
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#define delta (1.0e0)
#define f(x) (1.0/log(x))
double li(int x);
bool isPrime(int n);
int pi(int x);
//
int *primes;
int main(){
  int x,p;
  double l;
  for(x=2;x<10;x++){
    p=pi(x);
    l=li(x);
    printf("x=%d,誤差=%.16f\n",x,l-p);
  }

  return 0;
}
double li(int x){
  double sum=0;
  int i,cnt;
  cnt=(int)((x-2)/delta);
  for(i=0;i<cnt;i++){
    sum+=(f(2+delta*i)+f(2+delta*(i+1)))*delta/2;
  }
  return sum;
}
int pi(int x){
  int result,cnt,num,plus;
  primes=(int *)malloc(sizeof(int)*x);
  if(x>=2){
    primes[0]=2;
    cnt=1;
  }
  if(x>=3){
    primes[1]=3;
    cnt=2;
  }
  if(x>=5){
    primes[2]=5;
    cnt=3;
  }
  if(x>=7){
    num=7;
    plus=4;
    while(num<=x){
      if (isPrime(num)){
        primes[cnt]=num;
        cnt++;
      }
      num+=plus;
      plus=6-plus;
    }
  }
  return cnt;
}
// 7以上の奇数を指定して素数かどうか判定する。
bool isPrime(int n){
  int i,m,num;
  m=(int)(sqrt(n));
  for(i=2;i<n;i++){
    num=primes[i];
    if (num<=m) {
      if (n%num==0) {
        return false;
      }
    }
    else {
      return true;
    }
  }
  return true;
}
