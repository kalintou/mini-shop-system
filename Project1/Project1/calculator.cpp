#include <iostream>
#include <string>

using namespace std;

inline string get_rid_of_space(string s)
{
    string noSpaceResult = "";
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s.at(i) != ' ')
            noSpaceResult.push_back(s.at(i));
    }
    return noSpaceResult;
}

inline int Operator(char c) {
    if (c == '+')
        return 1;
    else if (c == '-')
        return 2;
    else if (c == '*')
        return 3;
    else if (c == '/')
        return 4;
    else if (c == '.')
        return 5;
    else
        return 6;
}

inline string calculator(string expression)
{
    //judge correct expression
    //case 1
    for (int i = 0; i < expression.size() - 1; ++i)
    {
        if (Operator((char)expression[i]))
        {
            if (Operator((char)expression[i + 1]))
            {
                cout << "double operator error" << endl;
                return expression;
            }
        }
    }


    return expression;
}



//
//bool isOperator(char c) {
//    if (c == '/' || c == '*' || c == '+' || c == '-' || c == '.')
//        return true;
//    return false;
//}
//
//bool validate(string s) {
//    if (s == "()")
//        return false;
//    stack<char> parenStack;
//    for (size_t i = 0; i < s.length(); i++)
//    {
//        if (s.at(i) == '(')
//            parenStack.push(s.at(i));
//        else if (s.at(i) == ')')
//        {
//            if (parenStack.empty())
//                return false;
//            parenStack.pop();
//        }
//    }
//    if (!parenStack.empty())
//        return false;
//    for (size_t i = 0; i < s.length(); i++)
//    {
//        if (!isOperator(s.at(i)) && s.at(i) != ')' && s.at(i) != '(' && !isdigit(s.at(i)))
//            return false;
//    }
//    return true;
//}

