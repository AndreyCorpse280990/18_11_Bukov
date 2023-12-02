#include <iostream>
#include <string>

int evaluateExpression(const std::string& expression, size_t& index) 
{
    int result = 0;
    int currentNumber = 0;
    char currentOperator = '+';

    while (index < expression.length()) 
    {
        char currentChar = expression[index++];

        if (isdigit(currentChar)) 
        {
            currentNumber = currentNumber * 10 + (currentChar - '0');
        }
        else if (currentChar == '+' || currentChar == '-') 
        {
            result = (currentOperator == '+') ? result + currentNumber : result - currentNumber;
            currentNumber = 0;
            currentOperator = currentChar;
        }
        else if (currentChar == '(') 
        {
            currentNumber = evaluateExpression(expression, index);
        }
        else if (currentChar == ')')
        {
            break;
        }
    }

    return (currentOperator == '+') ? result + currentNumber : result - currentNumber;
}

// Функция для вызова evaluateExpression
int evaluateExpression(const std::string& expression)
{
    size_t index = 0;
    return evaluateExpression(expression, index);
}

int main() 
{
    setlocale(LC_ALL, "rus");
    try 
    {

        std::string expression;
        std::cout << "Введите математическое выражение: ";
        std::getline(std::cin, expression);


        int result = evaluateExpression(expression);
        std::cout << "Результат: " << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
