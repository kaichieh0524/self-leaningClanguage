//Count Primes (easy)
// Runtime: 16 ms, faster than 91.54% of C online submissions for Count Primes.
// Memory Usage: 8.2 MB, less than 49.51% of C online submissions for Count Primes.
// key idea : to find out all composite number first and construct True or False table    
int countPrimes(int num)
{
    bool* torf = calloc(num+1,sizeof(bool));
    
    for (int i = 2 ; i*i < num ; i++)
    {
        if (torf[i]==0) 
        {
            for (int j = i ; i*j < num ; j++)
            {
                torf[i*j]=1;
            }
        }
    }
    int count = 0 ;
    for (int i = 2 ; i < num ; i++)
    {
        if (torf[i]==0){
            count+=1;
        }
    }
    return count;
}
