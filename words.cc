#include <string>
#include <iostream>
using namespace std;

int main() {
        //string word;
        //int wordCount = 0;
        //while (cin >> word)
                //wordCount++;

        //cout << "Word count: " << wordCount << '\n';

        string line;
        int lineCount = 0;
        while(getline(cin, line))
                lineCount++;

        cout << "Line count: " << lineCount << '\n';

        return 0;
        
}
