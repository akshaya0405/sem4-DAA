#include <iostream>
#include <string>

using namespace std;

void naiveSearch(string pattern, string text)
{
    int patternLength = pattern.length();
    int textLength = text.length();
    int i, j;
 
    for (i = 0; i <= textLength - patternLength; i++) {
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == patternLength)
            cout << "\nPattern found at index " << i << endl;
    }
}
 
int main()
{
    string text;
    string pattern;
   
   cout<<"\nEnter the string :";
   getline(cin, text);
   cout<<"\nEnter the pattern you want to search :";
   getline(cin, pattern);
    naiveSearch(pattern, text);
    cout<<endl;
    return 0;
}
