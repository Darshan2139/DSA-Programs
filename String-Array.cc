#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string Str;
    getline(cin,Str);
    int Max=0, count=0;
    int l = Str.length();
    for (int i = 0 ; i<l ;i++) 
    {
        if (Str[i] == ' ')
        {
            if (count > Max) 
            {
                Max = count;
            }
            count = 0;
        } else {
            count++;
        }
    }

    if (count > Max) 
    {
        Max = count;
    }
    cout <<Max;
      
    return 0;
}