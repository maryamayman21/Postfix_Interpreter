#include <iostream>
#include <string>
#include <cmath>
#include "StackArray.h"
using namespace std;

/*PROCEDURE: isOperator
Input: char ch
Output: bool

Algorithm:
1.  IF (ch = '+' OR ch = '-' OR ch = '*' OR ch = '/' OR ch = '^')
2.     THEN   RETURN true
3.  ELSE
4.     THEN   RETURN false
5.  END IF
*/

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}


/*
Input: char operator, integer operand1 and integer operand2
Output: int

Algorithm:
1. PROCEDURE applyOperator(operator , operand1 , operand2)

2.  CASE OF operator
3.   '+' : RETURN operand1 + operand2
4.   '-' : RETURN operand2 - operand1
5.   '*' : RETURN operand1 * operand2
6.   '/' : IF(operand1 ≠  0)
7.           THEN RETURN operand2 / operand1
8.           ELSE  error
9.         END IF
10.   '^':  RETURN operand1 ^ operand2
11.       OTHERWISE
12.  ENDCASE
*/

int applyOperator(char op, int operand1, int operand2)
{
    switch (op)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand2 - operand1;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand1 != 0)
        {
            return operand2 / operand1;
        }
        else
        {
            cout << "Error: Division by zero" << endl;
            exit(0);
        }
    case '^':
        return pow(operand2, operand1);
    default:
        cout << "Error: Invalid operator\n";
        exit(0);
    }
}

/*
PROCEDURE : postFixEvaluation
INPUT :  input as a string
OUTPUT : Result of postfix expression evaluation

Algorithm :
1.begin
2.For i <- 0 to input.length
3.     IF input[i] is whitespace OR a comma
4.           THEN  continue
          //Skip to the next iteration
5.     END IF
6.     IF input[i] is an alphabet
5.          IF stack.getValue(input[i]) ≠  0
          //To check if an alphabet exists in symbol table to push its value
6.               THEN  push value of input[i] in stack
7.          ELSE THEN  push  ASCII value of input[i] to stack
          // alphabet doesn't exist in symbol table
8.          END IF
9.     ELSE IF input[i] is a digit

10.          THEN  push ConvertCharToInteger(input[i]) to stack
                 /*ConvertCharToInteger is a placeholder for a function or operation
                    that converts the character ch[i] to its integer equivalent * /
11.    ELSE
12.            IF stack is empty
13.               THEN error
14.            END IF

15.            operand1 <- stack.pop()
                         //get the result at top of stack and assign it to operand1
16.            IF stack is empty
17.               THEN error
18.            END IF

19.            operand2 <- stack.pop()
                         //get the result at top of stack and assign it to operand2
20.            IF (input[i] = '=') THEN

21.               IF operand2 is an alphabet AND operand1 is digit
                     THEN stack.assign(operand2, operand1)
                         //assigning operation is done with respect to symbol table
22.               ELSE THEN stack.assign(operand2, stack.Value(operand1);
                         /*get the value of operand1 from symbol table
                            assign value of operand1 to the value of operand2  * /
23.               END IF
24.            END IF

25.            IF input[i] is an operator
26.                 THEN
27.                 IF operand1 is not alpahbet
28.                    THEN
29.                    IF operand2 is alphabet
30.                       THEN error
31.                    ELSE
32.                        tempRes<- applyOperator(input[i],operand1,operan2)
33.                        push temRes to stack
34.                    END IF
35.                 ELSE IF operand1 is alphabet
36.                     THEN
37.                      IF stack.value(operand1)!=0 THEN
38.                             //to check if the variable is previously assigned to symbol table
39.                        tempRes<- applyOperator(input[i],stack.value(operand1),operand2)
40.                        push temptRes to stack
41.                      ELSE
42.                       THEN error
43.                      END IF
44.                 END IF
45.            END IF

46.            IF stack is not empty
47.                 THEN result <- stack.pop()
48.            END IF

49.            IF stack is not empty
50.               THEN error
51.            END IF

52.    END IF
53.RETURN result
54.end

*/


int postFixEvaluation(string ch)
{
    StackArray postFixStack;

    int operand1, operand2;

    for (int i =0; i<ch.length() ; i++)
    {

        if (ch[i] == ' ' || ch[i] == ',')
            continue;

        if(isalpha(ch[i]))
        {

            if (postFixStack.getVariableValue((char)ch[i]) != 0)
            {
                postFixStack.push(postFixStack.getVariableValue((char)ch[i]));

                if(!postFixStack.isEmpty())
                    postFixStack.printStack();

            }
            else
            {

                postFixStack.push((int)ch[i]);

            }
        }
        else if (isdigit(ch[i]))
        {

            postFixStack.push(ch[i]-'0');

            if(!postFixStack.isEmpty())
                postFixStack.printStack();
        }
        else
        {

            if (postFixStack.isEmpty())
            {
                cout<<"Error in expression"<<endl;
                exit(0);
            }

            operand1 = postFixStack.Top();
            postFixStack.pop();

            if (postFixStack.isEmpty())
            {
                cout<<"Error in expression"<<endl;
                exit(0);
            }

            operand2 = postFixStack.Top();
            postFixStack.pop();


            if (ch[i]=='=')
            {

                if (isalpha((char)operand2) && !isalpha((char)operand1))
                {

                    postFixStack.assignVariable((char)operand2, operand1);

                    if(!postFixStack.isEmpty())
                        postFixStack.printStack();
                }

                else
                {
                    postFixStack.assignVariable((char)operand2, postFixStack.getVariableValue((char)operand1));


                }
            }

            if (isOperator(ch[i]))
            {

                if (!isalpha((char)operand1))
                {

                    if(isalpha((char)operand2))
                    {
                        cout<<"Error in expression"<<endl;
                        exit(0);
                    }
                    else
                    {
                        int tempRes1 = applyOperator(ch[i], operand1, operand2);
                        postFixStack.push(tempRes1);

                        if(!postFixStack.isEmpty())
                            postFixStack.printStack();
                    }
                }

                else if (isalpha((char)operand1))
                {
                    if(postFixStack.getVariableValue((char)operand1)!=0)
                    {
                        int tempRes =  applyOperator(ch[i], postFixStack.getVariableValue((char)operand1),operand2 ) ;
                        postFixStack.push(tempRes);

                        if(!postFixStack.isEmpty())
                            postFixStack.printStack();
                    }
                    else
                    {
                        cout<<"Error in expression"<<endl;
                        exit(0);

                    }

                }
            }
        }



    }

    int result=0;
    if(!postFixStack.isEmpty())
    {
        result =  postFixStack.Top();
        postFixStack.pop();
    }
    if (!postFixStack.isEmpty())
    {
        cout<<"Error in expression!"<<endl;
        exit(0);
        return -1;
    }
    else
        return result;
}


int main()
{

    cout<<"Enter postfix expression :  "<<endl;
    string inputString;

    getline(cin, inputString);


    int result =  postFixEvaluation(inputString);
    cout<<"Result : "<<result<<endl;

    return 0;
}
