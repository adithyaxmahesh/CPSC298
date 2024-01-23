#include <iostream>
using namespace std;

int main() {
    char first, second, third;
    string messageCode;
    string authenticatorCode = "ECA"; 

    cout << "Enter the first character of the message code: ";
    cin >> first;
    cout << "Enter the second character of the message code: ";
    cin >> second;
    cout << "Enter the third character of the message code: ";
    cin >> third;

    messageCode = string(1, first) + string(1, second) + string(1, third);


    cout << "\nCharacterization of Message Code\n";
    cout << "----------------------------------\n";
    int sumASCII = int(first) + int(second) + int(third);
    cout << "ASCII Values of Message Code Characters: " << int(first) << ", " << int(second) << ", " << int(third) << "\n";
    cout << "Sum of ASCII values for Message Code Characters: " << sumASCII << "\n";
    int checksum = sumASCII % 8;
    cout << "Message Code Checksum is valid: " << checksum << "\n";

    if (messageCode == authenticatorCode) {
        cout << "\nMessage is authentic.\n";
        cout << "Concurrence: message is authentic\n";
    } else {
        cout << "\nMessage is not authentic.\n";
        for (int i = 0; i < 3; i++) {
            if (messageCode[i] != authenticatorCode[i]) {
                cout << i + 1 << " characters do not match: Message: " << messageCode[i] << "; Authenticator: " << authenticatorCode[i] << "\n";
            }
        }
        if (messageCode < authenticatorCode) {
            cout << "Message code (" << messageCode << ") is lexicographically less than Authenticator code (" << authenticatorCode << ")\n";
        } else {
            cout << "Message code (" << messageCode << ") is lexicographically greater than Authenticator code (" << authenticatorCode << ")\n";
        }
    }

    return 0;
}
