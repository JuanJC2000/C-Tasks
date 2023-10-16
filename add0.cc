// To run this:
// Type two integers separated by a space and press return.
// To stop the program type two zeros: 0 0
//
#include <iostream>
#include <climits>
using namespace std;

auto add_by_1 = []( int a, int b ) {
	// Keep adding 1 to a until b becomes 0.
	while (b != 0) {
        a++;  // Keep adding 1 to 'a' until 'b' becomes 0.
        b--;
    }
    return a;
};

int main() {
	int i, j;

	while (cin >> i >> j && (i != 0 || j != 0))
		cout << i <<  "+"  << j <<  "="  << add_by_1(i, j) << endl;

	i = 0; 
	j = 0;
	cout << i <<  "+"  << j <<  "=" << add_by_1(i, j) << endl;

	return 0;
}
