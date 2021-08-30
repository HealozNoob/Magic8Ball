
#include "Magic8Ball.h"

// main method
int main() {

	cout << "Hi there";

	// seed randoms
	srand(unsigned(time(NULL)));

	// load responses
	setMagic8Ball(RESPONSE_FILE_NAME);
	// activate magic 8-Ball
	playMagic8Ball();
	
	// wait and exit
	return 0;
}

// function bodies

void displayTitle() {
	cout << "\t ----------------------------------------\n";
	cout << "\t              Magic 8 Ball \n";
	cout << "\t ----------------------------------------\n \n";
}
void playMagic8Ball() {

	displayTitle(); 

	string playerName = askForString("Please enter your name: ");
	cout << "\nThanks, " + playerName + ".\n\n";
	cout << "Ask me something and I will tell you your destiny!\n\n";

	system("pause"); // wait for user to press a button

	// initialise variables to store users question and randomly selected index of array
	string userQuestion;
	int randomIndex;

	while (!(userQuestion == "q" || userQuestion == "Q")) {
		system("cls"); //clears screen
		displayTitle(); // displays title

		// Prompting user

		userQuestion = askForString("Ask your question or [Q] to quit: ");

		// Generating random response index
		randomIndex = rand() % responseList.size();

		// Outputting random response to user
		if (!(userQuestion == "q" || userQuestion == "Q")) { // checking if user wants to quit
			cout << "\n" + responseList[randomIndex] + "\n\n";
		}

		system("pause"); // waits for user to reset the game
	}



}
void setMagic8Ball(string myFileName) {
	// load responses from file
	ifstream fileToRead(myFileName);

	if (fileToRead.is_open()) {
		string line = "";
		while (!fileToRead.eof()) {
			getline(fileToRead, line, ';');
			responseList.push_back(line); //this adds the line to the vector
		}
	}
	else {
		cout << "\nFile not found\n";
	}
	fileToRead.close();



}
string askForString(string question) {
	string userInput = "";

	// gets full line response
	cin.clear();
	cout << "\n" + question;
	while (userInput.empty()) {
		getline(cin, userInput);
	}

	return userInput;
	}