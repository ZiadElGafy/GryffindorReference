string stringNumberMultiplication(string s, int num){
   string ret = s;
   reverse(ret.begin(), ret.end());

   for(int i = s.size() - 1; i >= 0; i--){
       int cur = (ret[i] - '0') * num;
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
