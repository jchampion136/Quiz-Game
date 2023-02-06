#include "Quiz.h"
#include "printResult.h"
#include <iostream>

int Quiz:: score;

std::string Quiz :: getQuestion() { //beginning of getQuestion
    return question; //returns question
}//end of getQuestion

std::string Quiz :: getAnswer() { //beginning of getAnswer
    return answer;//returns answer
}//end of getAnswer

int Quiz :: getScore() { //beginning of getScore
    return score;//returns static score
}//end of getScore

void Quiz :: updateScore(int val) {// beginning of updateScore
    
    //initializes static variable with int s and accumulates score
    score += val;

    if(score < 0) {//changes all negative scores to 0
        score = 0;
    }
}//end of updateScore
