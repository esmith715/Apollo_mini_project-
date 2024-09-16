#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string filename = "Apollo_memory.txt";
    fstream file;

    while (true) {
        // Opening the file in read mode to check for the prompt
        file.open(filename, ios::in);

        if (!file) {
            cout << "File could not be opened!" << endl;
            return 1;
        }

        // Create the prompt and the input
        cout << "What question would you like to ask: " << endl;
        string prompt;
        getline(cin, prompt);

        // Convert prompt to lowercase for case-insensitive comparison
        transform(prompt.begin(), prompt.end(), prompt.begin(), ::tolower);

        // Inside the file, find the prompt and see if there is an answer
        string line;
        bool found = false;

        while (getline(file, line)) {
            // Convert line to lowercase for case-insensitive comparison
            string lower_line = line;
            transform(lower_line.begin(), lower_line.end(), lower_line.begin(), ::tolower);

            size_t pos = lower_line.find(prompt + ":");
            if (pos != string::npos) {
                string result = line.substr(pos + prompt.length() + 1);
                cout << "Found: " << result << endl;
                found = true;
                break;
            }
        }

        // Close the file after reading
        file.close();

        if (!found) {
            cout << "The line with the prompt \"" << prompt << "\" was not found in the file." << endl;
            cout << "Do you have an answer to your prompt? (yes/no): ";
            string response;
            getline(cin, response);

            if (response == "yes") {
                cout << "Please enter the answer: ";
                string answer;
                getline(cin, answer);

                // Open the file in append mode to add the new prompt and answer
                file.open(filename, ios::out | ios::app);

                if (!file) {
                    cout << "File could not be opened!" << endl;
                    return 1;
                }

                // Append the prompt and answer to the file
                file << prompt << ": " << answer << endl;

                // Close the file after writing
                file.close();

                cout << "The prompt and answer have been added to the file." << endl;
            }
        }

        cout << "Do you want to ask another question? (yes/no): ";
        string continue_response;
        getline(cin, continue_response);

        if (continue_response != "yes") {
            break;
        }
    }

    return 0;
}
