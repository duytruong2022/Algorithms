#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'goldbach' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

long long a[10000000];
int i = 0;

int check (long long n) {
    int j;
    long long min = 0;
    for (j = 0; j < i; j++) {
        if (n % a[j] == 0)
            return 0;
        if (min > a[j])
            min = a[j];
    }
    for (j = min; j >=2; j-=2) {
        if (n % j == 0)
            return 0;
    }
    a[i] = n;
    i++;
    printf ("%d\n", n);
    return 1;
}

int goldbach(int n) {
    long long p, k, j, c, d;
    int checka, checkb, chackall;
    c = n/2;
    if (check(c) && (c*2 == n))
    	return c;
    if (c % 2 == 0)
        c--;
    for (k = c; k > 0; k-=2) {
    	for (j = k/2; j >=2; j--) {
        	if (k % j == 0) {
        		checka = 0;
        		break;
			}
		}
		if (checka){
			a[0] = k;
			break;
		}
	}	
	if (check(n - a[0]))
		return a[0];
    for (k = c; k > 0; k-=2) {
        checka = check(k);
        if (checka){
            checkb = check(n - k);
            if (checkb) {
                d = (n - k)/2;
                for (j = c; j <= d; j++){
                    if ((n - k) % j == 0)
                        checkb = 0;
                }
            }
        }
        if (checka&&checkb)
            return i;
    }
    return 2;
}

int main()
{
	int n;
	scanf("%d", &n);
    printf("%d", goldbach(n));

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

