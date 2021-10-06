#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'fizzBuzz' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void fizzBuzz(int n) {
    int i;
	for(i = 1; i <= n; i++) {
        if((i%3!=0) && (i%5!=0)){
            cout<<i<<endl;
        } else if ((i%3 == 0) && (i%5 != 0)) {
            cout<<"Fizz"<<endl;
        }else if((i%5 == 0) && (i%3 != 0)) {
            cout<<"Buzz"<<endl;
        }else {
            cout<<"fizzBuzz"<<endl;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    fizzBuzz(n);
    system("pause");
}

