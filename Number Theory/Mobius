int mobius(int x){
   int ret = 1;

   for(int i = 2; i * i <= x; i++){
       if(x % i == 0){
           if(x % (i * i) == 0)
               return 0;

           x /= i, ret *= -1;
       }
   }

   if(x > 1)
       ret *= - 1;

   return ret;
}

int mobius[N];
bool isPrime[N];

void mobiusSieve(){
   mobius[1] = 1;
   for(int i = 2; i < N; i++)
       mobius[i] = 1, isPrime[i] = 1;

   for(int i = 2; i < N; i++){
       if(isPrime[i]){
           mobius[i] = -1;
           for(int j = 2 * i; j < N; j += i){
               mobius[j] = (j % (1LL * i * i) == 0 ? 0 : -mobius[j]);
               isPrime[j] = 0;
           }
       }
   }
}
