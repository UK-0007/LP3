#include <iostream>
using namespace std;


int step_count = 0;


int fibonacci_with_steps(int n) {
    step_count++; 
    
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci_with_steps(n - 1) + fibonacci_with_steps(n - 2);
    }
}
int iterative_fibonaci(int n){
    int a = 0;
    int b = 1;
    int c;
    int count = 0;
    cout<<a<<" "<<b<<" ";
    for(int i=2;i<n;i++){
        c = a+b;
        cout<<c<<" ";
        a=b;
        b=c;
        count++;
    }
    cout<<"\nTotal No of Step Count for Iterative:"<<count;
}

int main() {
    int n;
    
   
    cout << "Enter the Fibonacci number (n): ";
    cin >> n;
    
    
    for (int i = 0; i <= n; i++) {
        step_count = 0;  
        int result = fibonacci_with_steps(i);
        cout << "Fibonacci(" << i << ") = " << result << ", Steps taken: " << step_count << endl;
    }

    iterative_fibonaci(n);
    
    return 0;
}
