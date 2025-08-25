#include <iostream>
#include <string>
using namespace std;

string bitStuffing(string data) {
    string stuffed = "";
    int count = 0;
    for (char bit : data) {
        stuffed += bit;
        if (bit == '1') {
            count++;
            if (count == 5) {
                stuffed += '0'; // Stuff a '0' after five '1's
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    // Add HDLC flag (01111110) at start and end
    return "01111110" + stuffed + "01111110";
}

int main() {
    string data;
    cout << "Enter bit stream (e.g. 1111101111110): ";
    cin >> data;

    cout << "Original Data : " << data << endl;
    cout << "Bit Stuffed   : " << bitStuffing(data) << endl;

    return 0;
}