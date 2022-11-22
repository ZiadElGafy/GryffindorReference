int phi(int x){
   int ret = x;

   for(int i = 2; i * i <= x; i++){
       if(x % i == 0){
           while(x % i == 0)
               x /= i;
           ret -= ret / i;
       }
   }

   if(x > 1)
       ret -= ret / x;

   return ret;
}

int phi[N];

void phiSieve(){
   for(int i = 0; i < N; i++)
       phi[i] = i;

   for(int i = 2; i < N; i++)
       if(phi[i] == i)
           for(int j = i; j < N; j += i)
               phi[j] -= phi[j] / i;
}
