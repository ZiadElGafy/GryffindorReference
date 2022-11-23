string stringStringAddition(string a, string b){
   string ret, other;

   if(a.size() > b.size())
       ret = a, other = b;
   else
       ret = b, other = a;

   reverse(ret.begin(), ret.end());
   reverse(other.begin(), other.end());

   int diff = ret.size() - other.size();
   other += string(diff, '0');

   for(int i = ret.size() - 1; i >= 0; i--){
       int cur = (ret[i] - '0') + (other[i] - '0');
       ret[i] = (cur % 10) + '0';
       cur /= 10;
       int currentIdx = i;
       while(cur > 0){
           currentIdx++;
           if(currentIdx == ret.size())
               ret += '0';

           cur += (ret[currentIdx] - '0');
           ret[currentIdx] = (cur % 10) + '0';
           cur /= 10;
       }
   }

   reverse(ret.begin(), ret.end());
   return ret;
}
