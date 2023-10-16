#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
        string line;
        vector<string> lines;
        
        while(getline(cin, line))
        {
            lines.push_back(line);
        }

        cout <<"Lines in reverse order:\n";

        for(int i = lines.size() - 1; i >= 0; i--)
            cout << lines[i] << '\n';
                

        

        return 0;
        
}
