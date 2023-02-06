#include <iostream>
#include <sstream>
#include "Quiz.h"
#include "printResult.h"

std::string printResult(int q, int c, int w) {//Beginning of printResult
    
    //Declares a stringstream
    std::stringstream output;

    //Outputs result to user
    output << "Number of questions: " << q << std::endl;
    output << "Number correct answers: " << c << std::endl;
    output << "Number wrong answers: " << w << std::endl;
    output << "Final score: " << Quiz::score; //outputs score from "Quiz" class

    return output.str(); //converts stringstream into a string and returns 
}//end of printResult