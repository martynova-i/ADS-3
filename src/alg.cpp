// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

static int priority(char p) {
    if (p == '*' || p == '/') {
        return 3;
    } else {
        if (p == '+' || p == '-') {
            return 2;
        } else {
            return 0;
        }
    }
}

std::string infx2pstfx(std::string inf) {
  TStack<char> stack1;
    std::string stroka;
    for (int i = 0; i < inf.length(); i++) {
        if ((inf[i] >= '0') && (inf[i] <= '9')) {
            stroka += inf[i];
            stroka += ' ';
        } else if ((inf[i] == '(')
                 || (priority(inf[i]) > priority(stack1.get()))
                 || (stack1.isEmpty())) {
            stack1.push(inf[i]);
        } else if (inf[i] == ')') {
            while (!stack1.isEmpty() && stack1.get() != '(') {
                stroka += stack1.get();
                stroka += ' ';
                stack1.pop();
            }
            if (stack1.get() == '(')
                stack1.pop();
        } else {
            while ((!stack1.isEmpty())
                   && (priority(stack1.get()) >= priority(inf[i]))) {
                stroka = stack1.get();
                stroka += ' ';
                stack1.pop();
            }
            stack1.push(inf[i]);
        }
    }
            while (!stack1.isEmpty()) {
                stroka += stack1.get();
                stroka += ' ';
                stack1.pop();
            }
    return stroka;
}

int eval(std::string pst) {
  TStack<int> stack2;
    int output;
    for (int i = 0; i < pst.length(); i++) {
        if ((pst[i] >= '0') && (pst[i] <= '9')) {
            stack2.push(pst[i]- '0');
        } else {
            if (pst[i] != ' ') {
                int a2 = stack2.get();
                stack2.pop();
                int a1 = stack2.get();
                stack2.pop();
                if (pst[i] == '-') {
                    stack2.push(a1 - a2);
                } else if (pst[i] == '+') {
                    stack2.push(a1 + a2);
                } else if (pst[i] == '*') {
                    stack2.push(a1 * a2);
                } else {
                    stack2.push(a1 / a2);
                }
            }
        }
    }
    output = stack2.get();
    return output;
}
