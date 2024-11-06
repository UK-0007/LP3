#include<bits/stdc++.h>
using namespace std;

int rec_steps = 0;
int ite_steps = 0;

int rec_fib(int n){
    rec_steps++;
    if(n <= 1) return n;

    return rec_fib(n-1) + rec_fib(n-2);
}

int ite_fib(int n){
    if(n <= 1) return n;

    int num1 = 0;
    int num2 = 1;
    int num3;

    for(int i=2;i<=n;i++){
        num3 = num1 + num2;
        num1 = num2;
        num2 = num3;
        ite_steps++;
    }

    return num2;
}

int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;

    cout<<"Recursive Fibonacci: "<<rec_fib(n)<<endl;
    cout<<"Iterative Fibonnaci: "<<ite_fib(n)<<endl;
    cout<<"Recursive Fibonacci Steps: "<<rec_steps<<endl;
    cout<<"Iterative Fibonnaci Steps: "<<ite_steps<<endl;

    return 0;
}