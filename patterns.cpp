
#include <iostream>
using namespace std;


void printPat1(int n){           
 for(int i=0; i< n; i++){
       for(int j=0; j<n; j++){
           cout<<"*";
       }
       cout<<endl;
   }
}

void printPat2(int n){
    for(int i =0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void printPat3(int n){
    for(int i =1; i<=n; i++){
        for(int j = 1; j <= i; j++){
            cout<<j<<" ";

        }
        cout<<endl;
    }
}

void printPat4(int n){
    for(int i =1; i<=n; i++){
        for(int j = 1; j <= i; j++){
            cout<<i<<" ";

        }
        cout<<endl;
    }
}

void printPat5(int n){
    for(int i =1; i<=n; i++){
        for(int j = 0; j<n-i+1; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void printPat6(int n){
    for(int i =0; i<=n; i++){
        for(int j = 1; j<n-i+1; j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void printPat7(int n){
    for(int i =0; i<n; i++){
        for(int j = 0; j<n-i-1; j++){
            cout<<" ";
        }
        for(int k = 0; k < 2*i+1; k++){
            cout<<"*";
        }
        for(int l = 0; l<n-i-1; l++){
            cout<<" ";
        }


        cout<<endl;
    }
}

void printPat8(int n){

    for(int i =0; i<n; i++){

        for(int j = 0; j<i; j++){
            cout<<" ";
        }
        for(int k = 0; k < 2*n - (2*i+1) ; k++){
            cout<<"*";
        }
        for(int l = 0; l<i; l++){
            cout<<" ";
        }


        cout<<endl;
    }
}

void printPat10(int n){
    for(int i = 1; i <= 2 * n -1; i++){
        int stars = i;
        if(i > n) stars = 2*n-i;
        for(int j = 1; j <= stars; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void printPat11(int n){
    for(int i =1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            if(j % 2 == 0)cout<<"0 ";
            else cout<<"1 ";
        }
        cout<<endl;
    }
}

void printPat12(int n){
    int space = 2*(n-1);
    for(int i = 1; i<=n; i++){

        for(int j = 1; j<=i; j++){
            cout<<j;
        }
        for(int j = 1; j <=space; j++){
            cout<<" ";
        }
        for(int j=i; j>=1; j--){
            cout<<j;
        }
        cout<<endl;
        space -= 2;
    }
}

void printPat13(int n){
    int num = 1;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
}

void printPat14(int n){

    for(int i = 0; i<n; i++){
        for(char ch = 'A'; ch<= 'A'+i; ch++){
            cout<<ch<<" ";
            
        }
        cout<<endl;
    }
}

void printPat15(int n){
    for(int i = 0; i<n; i++){
        for(char ch = 'A'; ch <= 'A'+(n-i-1); ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void printPat16(int n){
    for(int i = 0; i<n; i++){
        char ch = 'A'+ i;
        for(int j = 0; j<=i; j++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void printPat17(int n){
    for(int i = 1; i<=n; i++){
        
        for(int j = 1; j <= n-i; j++){
            cout<<" ";
        }

        char ch = 'A';
        int breakpoint = (2*i-1)/2;
        for(int j = 1; j <= 2*i-1; j++){
            cout<<ch;
            if(j <= breakpoint )ch++;
            else ch--;

        }

        for(int j = 1; j <= n-i; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

void printPat18(int n){
    for(int i = 1; i<=n; i++){

        char ch = 'A'+n-i;
        for(int j = 1; j<=i; j++){
            cout<<ch;
            ch++;
        }
        cout<<endl;
    }
}

void printPat19(int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-i; j++){
            cout<<"*";
        }
        for(int j = 0; j<2*i; j++){
            cout<<" ";
        }
        for(int j = 0; j<n-i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j<i+1; j++){
            cout<<"*";
        }

        for(int j = 0; j<((2*n)-2-(2*i)); j++){
            cout<<" ";
        }

        for(int j = 0; j<i+1; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void printPat20(int n){
    int spaces = 2*n-2;
    for(int i = 1; i <= 2*n-1; i++){

        int stars = i;
        if(i > n) stars = 2*n-i;

        for(int j = 1; j<=stars; j++){
            cout<<"*";
        }

        for(int j = 1; j <= spaces; j++){
            cout<<" ";
        }

        for(int j = 1; j<=stars; j++){
            cout<<"*";
        }

        cout<<endl;
        if(i < n) spaces -= 2;
        else spaces += 2;
    }
}

void printPat21(int n){
    for(int i = 0; i<n; i++){
        for(int j=0;j<n; j++){
            if(i == 0 || i == n-1 || j == n-1 || j==0) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
}

void printPat22(int n){
    for(int i = 0; i<n*2-1; i++){
        for(int j =0; j<2*n-2; j++){
            int top = i;
            int left = j;
            int right = (2*n-2)-j;
            int down = (2*n-2)-i;

            cout<<(n - min(min(top, down), min(left, right)))<<" ";
        }
        cout<<endl;
    }
}
int main()
{
 
    int n;
    cout<<"Enter n: ";
    cin>>n;
    printPat22(n);

    return 0;
}
