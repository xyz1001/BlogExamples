//
// Created by xyz1001 on 20-8-27.
//

#ifndef JNI_CALCULATOR_H
#define JNI_CALCULATOR_H


class Calculator {
public:
    void Plus(int a);
    void Minus(int a);
    void Multi(int a);
    void Divide(int a);
    int GetResult() const;

private:
    int result_ = 0;
};


#endif //JNI_CALCULATOR_H
