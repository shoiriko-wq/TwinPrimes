// 双子素数の発生確率をli(x)と比べてみる。
// 作成者：入江田　承
// 作成日：2019/9/7
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
// li(x)の設定
#define delta (1.0e-1)
// グローバル変数
int *primes;
int num,plus,cnt,psize;
// 関数のプロトタイプ宣言
int li(int x);
void initBuffer(int n);
void initPrime(int n);
bool isPrime(int n);
void nextPrime();
// メイン
int main()
{
  // 変数の宣言
  int i,j,n;
  double maxratio,minratio,ratio;
  bool ready;
  clock_t t_start,t_end;
  // スタート
  t_start = clock();
  maxratio=0.0;
  minratio=1.0;
for(n=1;n<=100;n++){
//  if(n>=1)printf("(3,5)\n");
  initPrime(n);
  if(n>=2){
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
  if (n==1){
    cnt=9;
    psize=10;
  }
  ratio=(double)cnt/psize;
  if(maxratio<ratio){
    maxratio=ratio;
//    printf("%d:%f\n",n,maxratio);
  }
  if(minratio>ratio){
    minratio=ratio;
//    printf("%d:%f\n",n,minratio);
  }
  printf("n=%d:cnt=%d:psize=%d\n",n,cnt,psize);
}
printf("max=%f:min=%f\n",maxratio,minratio);
  // psizeの表示
//  printf("psize:%d\n",psize );
  // 素数の表示
//  for(i=0;i<psize;i++)printf("%d\n",primes[i]);

  t_end = clock();
  printf("所要時間:%.10lf[sec]\n",(double)(t_end - t_start)/CLOCKS_PER_SEC);
  free(primes);
  return 0;
}
// x以下の素数の存在確率li(x)の計
int li(int x) {
  double sum=0;
  int loop=(int)((1.0*x-2)/delta);
  for(int i=0;i<loop;i++){
    sum+=(1.0/log(2.0+i*delta)+1.0/log(2.0+(i+1)*delta))*delta/2;
  }
  //printf("delta=%.16f,sum=%.16f\n",delta,sum);
  return (int)(sum+1);
}
// primes[]のバッファのサイズ(psize)を決定してバッファをpsizeの分だけ確保。
void initBuffer(int n){
  psize=2;
  while(psize/li(psize)<=n)psize++;
  primes=(int *)malloc(sizeof(int)*psize);
}
// primes[]のバッファをsizeの分だけ確保。num,cnt,plus,primes[]の初期化。
void initPrime(int n){
  initBuffer(n);
  if(psize>=2)primes[0]=2;
  if(psize>=3)primes[1]=3;
  if(psize>=5)primes[2]=5;
  if(psize>=7){
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
