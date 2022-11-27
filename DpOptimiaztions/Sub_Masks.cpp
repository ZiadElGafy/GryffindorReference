//3^n 

for(int msk=0; msk < (1<<n); msk++)
{
    for(int sub=msk; sub > 0; sub = (sub-1)&msk)
    {
        // iterate over all the subsets of the mask
    }
}
