#include <iostream>
#include <string>

using namespace std;

string caesarCipher(const string& text, int shift) {
    string result = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            // Determine the case (uppercase or lowercase)
            char base = isupper(ch) ? 'A' : 'a';
            // Apply the shift and wrap around the alphabet
            result += static_cast<char>((ch - base + shift + 26) % 26 + base);
        }
        else {
            // Leave non-alphabetic characters unchanged
            result += ch;
        }
    }
    return result;
}

int main() {
    string inputText;
    int shiftValue;
    char choice;

    do {
        // Get user input for text and shift value
        cout << "Enter the text: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, inputText);

        // Get and validate the shift value
        do {
            cout << "Enter the shift value (0-25): ";
            cin >> shiftValue;

            if (shiftValue < 0 || shiftValue > 25) {
                cout << "Invalid shift value. Please enter a value between 0 and 25." << endl;
            }

        } while (shiftValue < 0 || shiftValue > 25);

        // Get user choice for encryption or decryption
        cout << "Choose an option (E for Encryption, D for Decryption): ";
        cin >> choice;

        // Perform encryption or decryption based on user choice
        string result;
        if (toupper(choice) == 'E') {
            result = caesarCipher(inputText, shiftValue);
            cout << "Encrypted text: " << result << endl;
        }
        else if (toupper(choice) == 'D') {
            result = caesarCipher(inputText, -shiftValue);
            cout << "Decrypted text: " << result << endl;
        }
        else {
            cout << "Invalid choice. Please enter 'E' for Encryption or 'D' for Decryption." << endl;
        }

        // Ask if the user wants to continue
        cout << "Do you want to continue? (Y/N): ";
        cin >> choice;

    } while (toupper(choice) == 'Y');

    return 0;
}
