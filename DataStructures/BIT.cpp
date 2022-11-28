void update( int x , int delta)
{
   for (;x < N ; x+= (x&-x))
           BIT[x] += delta;
}
int Sum( int x)
{
   int sum = 0 ;
   for (;x > 0;x -= (x&-x))
       sum += BIT[x];
   return sum;
}
