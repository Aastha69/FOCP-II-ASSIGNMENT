#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string name;

    // Take user input
    cout << "Enter your name: ";
    cin >> name;

    // Excuse templates
    vector<string> excuses = {
        "{name} couldn't complete the assignment because the laptop updated for hours.",
        "{name} was about to submit but the WiFi suddenly stopped working.",
        "{name}'s file mysteriously disappeared at the last moment.",
        "{name}'s keyboard stopped working right before submission.",
        "{name} tried finishing the work but the system crashed unexpectedly.",
        "{name} forgot after taking a short break that lasted too long.",
        "{name}'s assignment was ready but got deleted accidentally.",
        "{name} was about to upload when the internet stopped cooperating.",
        "{name} almost finished, but something went wrong at the last step.",
        "{name} couldn’t complete it because the laptop battery died suddenly."
    };

    // Seed random number generator
    srand(time(0));

    // Pick random excuse
    int index = rand() % excuses.size();
    string excuse = excuses[index];

    // Replace {name} with actual name
    size_t pos = excuse.find("{name}");
    while (pos != string::npos) {
        excuse.replace(pos, 6, name);
        pos = excuse.find("{name}");
    }

    // Display final excuse
    cout << excuse << endl;

    return 0;
}
