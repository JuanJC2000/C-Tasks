#include <string>
#include <iostream>
using namespace std;

int main() {
        string line;
        string longestLine;
        int maxLineLength = 0;
        while(getline(cin, line))
        {
            if(line.length() > maxLineLength)
            {
                maxLineLength = line.length();
                longestLine = line;
            }
        }
                

        cout << "Longest line: \n " << longestLine << '\n';

        return 0;
        
}
