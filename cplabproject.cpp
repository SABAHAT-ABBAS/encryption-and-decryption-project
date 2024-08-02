#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

// Function to convert a string to lowercase
string toLower(const string& str) {
    string lowerStr = str;
    for (char& c : lowerStr) {
        c = tolower(c);
    }
    return lowerStr;
}

// Function to respond to user input
void respond(const string& input) {
    // Define responses
    static map<string, string> responses = {
        {"hello", "Hi there! How can I help you today?"},
        {"how are you", "I'm a computer program, so I don't have feelings, but I'm here to assist you!"},
        {"bye", "Goodbye! Have a great day!"},
        {"whats your name","sorry! i dont have any name" }
    };

    // Convert input to lowercase
    string lowerInput = toLower(input);

    // Check if response exists for the input
    auto it = responses.find(lowerInput);
    if (it != responses.end()) {
        cout << it->second << endl;
    }
    else {
        cout << "Sorry, I don't understand that." << endl;
    }
}

int main() {
    string input;

    cout << "ChatBot: Hello! Type 'bye' to exit." << endl;

    while (true) {
        cout << "You: ";
        getline(cin, input);

        if (toLower(input) == "bye") {
            cout << "ChatBot: Goodbye!" << endl;
            break;
        }

        respond(input);
    }

    return 0;
}
