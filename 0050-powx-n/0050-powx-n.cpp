class Solution {
public:
    double power(double x , long long n){
        if(n==0) return 1.0;
        if(n==1) return x;

        if(n%2==0) return power(x*x,n/2);
        return x*power(x,n-1);
    }
    double myPow(double x, int n) {
        // double ans = 1.0;
        // long long nn = n;
        // if(nn<0) nn = -1*nn;
        // while(nn){
        //     if(nn%2==1){
        //         ans = ans*x;
        //         nn = nn-1;
        //     }else{
        //         x = x*x;
        //         nn=nn/2;
        //     }
        // }
        // if(n<0) ans = (double)(1.0)/(double)(ans);
        // return ans;
        long long num = n;
        if(num<0){
            x=1.0/x;
            num=-num;
        }
        return power(x,num);


        
    }
};