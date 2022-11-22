// works in one based
// be careful of overflows
ll pascal[N][N];

void prePascal(int limit)
{
   pascal[0][0] = 1;
   for (int i = 1; i <= limit; i++)
   {
       for (int j = 0; j <= limit; j++)
           pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
   }
}
