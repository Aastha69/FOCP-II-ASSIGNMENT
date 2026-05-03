#include <iostream>
#include <vector>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

// Function to replace {name} with the user's actual name
string replaceName(string roast, string name) {
    size_t pos = roast.find("{name}");
    
    if (pos != string::npos) {
        roast.replace(pos, 6, name); // Replace "{name}" with actual name
    }
    
    return roast;
}

int main() {
    string userName;

    // Ask user for their name
    cout << "Enter your name: ";
    getline(cin, userName);

    // Store roast templates
    vector<string> roasts = {
        "{name}, your brain has too many tabs open.",
        "{name}, if laziness was a sport, you'd still come second.",
        "{name}, you bring everyone so much joy... when you leave the room.",
        "{name}, even Wi-Fi signals avoid connecting with you.",
        "{name}, your secrets are always safe... nobody listens anyway.",
        "{name}, you are proof that evolution can go in reverse.",
        "{name}, your jokes are like software bugs... nobody wants them.",
        "{name}, if common sense were money, you'd be broke.",
        "{name}, even your shadow leaves you in the dark.",
        "{name}, you have something on your chin... no, the third one."
    };

    // Seed random number generator
    srand(time(0));

    // Pick a random roast
    int randomIndex = rand() % roasts.size();

    // Replace placeholder with user's name
    string finalRoast = replaceName(roasts[randomIndex], userName);

    // Display roast
    cout << "\nYour roast:\n";
    cout << finalRoast << endl;

    return 0;
}
