#ifndef QUIZ_H_
#define QUIZ_H_
#include <string>
#include "printResult.h"

class Quiz { //"Quiz" Class

    private:
    //private member variables
    std::string question {""};
    std::string answer {""};
    static int score;

    public:
    Quiz() = default; //Default constructor
    Quiz(std::string q, std::string a) {
        question = q;
        answer = a;
    } 
    
    //public member functions
    std::string getQuestion();
    std::string getAnswer();
    static int getScore();
    static void updateScore(int);
    friend std::string printResult(int q, int c, int w);
}; //End of Quiz
#endif //QUIZ_H_