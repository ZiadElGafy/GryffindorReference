while(s <= e){
   m1 = s + (e - s) / 3;
   m2 = e - (e - s) / 3;

   int ans1 = solve(m1);
   int ans2 = solve(m2);
  
   ans = min({ans, ans1, ans2});
  
   if(ans1 > ans2)
       s = m1 + 1;
   else
       e = m2 - 1;
}
