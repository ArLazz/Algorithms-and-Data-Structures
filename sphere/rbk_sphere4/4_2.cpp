#include <iostream>
#include <string.h>
int main(){
        string s;
        cin >> s;
        int i, freq[256];
        char prev[256], next[256];
        for(i = 1; i < 256; i++)
        freq[i] = prev[i] = next[i] = 0;
        int maxFreq = 0;
        for(i = 0; i < s.length(); i++)
        {
            char c = s[i];
            char p = (i == 0) ? 0 : s[i-1];
            char n = (i < s.length() - 1) ? s[i+1] : 0;
            if(freq[c] == 0) // first time to encounter this character
            {
                prev[c] = p;
                next[c] = n;
            }
            else // check if it is always preceded and followed by the same characters:
            {
                if(prev[c] != p)
                    prev[c] = 0;
                if(next[c] != n)
                    next[c] = 0;
            }
// increment frequency and track the maximum:
            if(++freq[c] > maxFreq)
                maxFreq = freq[c];
        }

        if(maxFreq == 0)
        return 0;
        int maxLen = 0;
        int startingChar = 0;
        for(i = 1; i < 256; i++)
        {
// should have a frequency equal to the max and not be preceded
// by the same character each time (or it is in the middle of the string)
            if((freq[i] == maxFreq) && (prev[i] == 0))
            {
                int len = 1, j = i;
                while(next[j] != 0)
                {
                    len++;
                    j = next[j];
                }
                if(len > maxLen)
                {
                    maxLen = len;
                    startingChar = i;
                }
            }
        }
        // print out the maximum length string:
        int j = startingChar;
        while(j != 0)
        {
            cout << (char)j;
            j = next[j];
        }
        cout << endl;
};