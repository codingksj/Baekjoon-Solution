#include <stdio.h>
#include <string.h>

int main() {
    char expression[51];
    scanf("%s", expression);
    
    int result = 0;
    int num = 0;
    int isNegative = 0;
    
    for (int i = 0; i <= strlen(expression); i++) {
        if (expression[i] == '+' || expression[i] == '-' || i == strlen(expression)) {
            if (isNegative)
                result -= num;
            else
                result += num;
            
            num = 0;
            
            if (expression[i] == '-')
                isNegative = 1;
        } else {
            num = num * 10 + (expression[i] - '0');
        }
    }
    
    printf("%d\n", result);
    
    return 0;
}
