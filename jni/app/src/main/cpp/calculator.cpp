//
// Created by xyz1001 on 20-8-27.
//

#include "calculator.h"

void Calculator::Plus(int a) {
   result_ += a;
}

void Calculator::Minus(int a) {
   result_ -= a;
}

void Calculator::Multi(int a) {
   result_ *= a;
}

void Calculator::Divide(int a){
   result_ /= a;
}

int Calculator::GetResult() const {
   return result_;
}
