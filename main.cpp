#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Quiz.h"
#include "printResult.h"
using namespace std;

int main(int argc, char *argv[]) { //beginning of main
//Declarations
vector<Quiz> quizVector;
string txtFileIn = argv[1];
ifstream inFile(txtFileIn); //Opens text file 
int numQuestions;
int correct = 0;
int incorrect = 0;
string answer;
string str = txtFileIn;
string fileLine;



//inFile.open(txtFileIn);
if (!inFile.is_open()) { //Ends program if no txt file is open
    return -1;
}

// get question line
while (getline(inFile, fileLine)) {
    
    // skip to next line with "Q: " 
    if (fileLine.find("Q:") == 0) {
        // Reads from "Q: "
        size_t pos = 3; //Initializes starting position in txt file 3 characters
        string questionLine = fileLine.substr(pos);
        string answerLine;

        
    // skip to next line with "A: " 
    if (getline(inFile, fileLine) && fileLine.find("A:") == 0) {
    
            answerLine = fileLine.substr(pos);
        }

        //Creates objects for Q&A pairs and initializes them into a vector
        quizVector.push_back(Quiz(questionLine, answerLine));    
    }
}

//Sets the randomization seed
srand(unsigned(time(0))); 

//Randomly shuffles questions
random_shuffle(quizVector.begin(), quizVector.end());

//Initializes the number of questions with the size of the vector
numQuestions = quizVector.size();

//Asks for user input to answer each question
for(int i = 0; i < numQuestions; i++) {
    cout << quizVector[i].getQuestion() << endl;
    cout << "Type in your answer: ";
    getline(cin,answer);

    if (answer == quizVector[i].getAnswer()) {//outputs user if answer is currect and grants them a point
        cout << "Correct!" << endl;
        quizVector[i].updateScore(1);
        cout << "Current score: " << quizVector[i].getScore() << endl; //Displays current score
        cout << endl;
        correct++;
    }

    else if(answer != quizVector[i].getAnswer()) {//outputs user if answer is wrong and deducts a point
        cout << "Wrong! Correct answer: " << quizVector[i].getAnswer() << endl;
        quizVector[i].updateScore(-1);
        cout << "Current score: " << quizVector[i].getScore() << endl; //Displays current score
        cout << endl;
        incorrect++;
    }
}

cout << printResult(numQuestions, correct, incorrect); //Prints total results via stringstream

return 0;//Return
}//End of Main