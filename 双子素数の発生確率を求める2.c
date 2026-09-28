// 双子素数をn個表示する
// 作成者：入江田　承
// 作成日：2019/7/28
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
// グローバル変数
int *primes;
int num,plus,cnt;
// 関数のプロトタイプ宣言
void initPrime(int n);
bool isPrime(int n);
void nextPrime();
// メイン
int main()
{
  // 変数の宣言
  int i,j,n,psize;
  double maxratio,minratio,ratio;
  bool ready;
  clock_t t_start,t_end;
  // 内容
//  printf("双子素数をn個表示します。\n");
//  printf("nを指定してください :");
//  scanf("%d", &n);
  t_start = clock();
  maxratio=0.0;
  minratio=1.0;
for(n=1;n<=100;n++){
//  if(n>=1)printf("(3,5)\n");
  if(n>=2){
    psize=2;
    while(1.125*psize/log(psize+40)<=n)psize++;
    initPrime(psize);
    for (i=1;i<n;i++){
      while(true){
        if(plus==2){
          nextPrime();
          if(num-2==primes[cnt-2]){
//            printf("(%d,%d)\n",num-2,num);
            break;
          }
        }
        else{
          nextPrime();
        }
      }
    }
  }
  ratio=(double)cnt/psize;
  if(maxratio<ratio){
    maxratio=ratio;
    printf("%d:%f\n",n,maxratio);
  }
  if(minratio>ratio){
    minratio=ratio;
    printf("%d:%f\n",n,minratio);
  }
  printf("%d:%d:%d\n",n,cnt,psize);
}
printf("%f:%f\n",maxratio,minratio);
  // psizeの表示
//  printf("psize:%d\n",psize );
  // 素数の表示
//  for(i=0;i<psize;i++)printf("%d\n",primes[i]);

  t_end = clock();
  printf("所要時間:%.10lf[sec]\n",(double)(t_end - t_start)/CLOCKS_PER_SEC);
  free(primes);
  return 0;
}
// primes[]のバッファをsizeの分だけ確保。num,cnt,plus,primes[]の初期化。
void initPrime(int size){
  primes=(int *)malloc(sizeof(int)*size);
  if(size>=1)primes[0]=2;
  if(size>=2)primes[1]=3;
  if(size>=3)primes[2]=5;
  if(size>=4){
    num=5;
    plus=2;
    cnt=3;
  }
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
void nextPrime(){
  num+=plus;
  plus=6-plus;
  while(!isPrime(num)){
    num+=plus;
    plus=6-plus;
  }
  primes[cnt++]=num;
//  printf("%d\n",num );
}
// 100000 12sec
// 100000 12sec
// 1000000 228sec
