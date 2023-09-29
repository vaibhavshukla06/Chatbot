#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string GetResponse(const string& input) {
    // Define a list of possible user inputs and corresponding bot responses
    vector<pair<string, string>> responses = {
        {"Hello", "Hi there! How can I assist you today?"},
        {"How are you?", "I'm doing great, thanks for asking! How about you?"},
        {"What's your name?", "My name is ChatBot. Nice to meet you!"},
        {"Tell me a joke", "Sure! Why don't scientists trust atoms? Because they make up everything!"},
        {"Goodbye", "Goodbye! Have a great day!"}
    };

    // Add more user inputs and responses to the list
    responses.push_back({"What's the weather like?", "The weather is sunny and warm today. Perfect for outdoor activities!"});
    responses.push_back({"What's your favorite color?", "My favorite color is blue. What's yours?"});
    responses.push_back({"Can you recommend a good restaurant?", "Sure! I recommend trying out the Italian restaurant on Main Street. They have great pasta dishes!"});
    responses.push_back({"What's the meaning of life?", "That's a deep question. I think the meaning of life is to find your own purpose and make a positive impact on the world."});

    // Convert the user input to lowercase for case-insensitive matching
    string lowercase_input = input;
    transform(lowercase_input.begin(), lowercase_input.end(), lowercase_input.begin(), ::tolower);

    // Iterate through the list of possible user inputs and find a matching response
    for (const auto& pair : responses) {
        string lowercase_pair_first = pair.first;
        transform(lowercase_pair_first.begin(), lowercase_pair_first.end(), lowercase_pair_first.begin(), ::tolower);

        if (lowercase_input.find(lowercase_pair_first) != string::npos) {
            return pair.second;
        }
    }

    // If no matching response is found, return a default response
    return "I'm sorry, I didn't understand that. Can you please rephrase your question?";
}

int main() {
    cout << "Welcome to the ChatBot!" << endl;

    while (true) {
        string input;
        cout << "> ";
        getline(cin, input);

        if (input == "exit") {
            break;
        }

        string response = GetResponse(input);
        cout << response << endl;
    }

    return 0;
}
