#include<iostream>
using namespace std;

int main() {
    int n;
    
    cout<<"Enter a positive integer: ";
    cin>>n;
    
    if (n <= 0) {
        cout<<"enter a posistive integer: " <<endl;
        return 1;
    }
    
    int count = 0;
    int temp = n;
    
    while(temp>0) {
        temp/= 10;
        count++;
    }
    
    cout<<"The number " << n << " has " << count << " digits." <<endl;
    return 0;
}