//
// Created by hqnddw on 2019/11/13.
//

#include <cstring>

class Solution1 {
public:
    bool isNumeric(char *string) {
        if (string == nullptr)
            return false;
        bool numeric = scanInteger(&string);
        if (*string == '.') {
            ++string;
            numeric = scanUnsignedInteger(&string) || numeric;
        }
        if (*string == 'e' || *string == 'E') {
            ++string;
            numeric = numeric && scanInteger(&string);
        }
        return numeric && *string == '\0';
    }

    bool scanInteger(char **str) {
        if (**str == '+' || **str == '-')
            ++(*str);
        return scanUnsignedInteger(str);
    }

    bool scanUnsignedInteger(char **str) {
        const char *before = *str;
        while (**str != '\0' && **str >= '0' && **str <= '9')
            ++(*str);
        return *str > before;
    }
};


class Solution2 {
public:
    bool isNumeric(char *str) {
        // 标记符号、小数点、e是否出现过
        bool sign = false, decimal = false, hasE = false;
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == 'e' || str[i] == 'E') {
                if (i == strlen(str) - 1) return false; // e后面一定要接数字
                if (hasE) return false;  // 不能同时存在两个e
                hasE = true;
            } else if (str[i] == '+' || str[i] == '-') {
                // 第二次出现+-符号，则必须紧接在e之后
                if (sign && str[i - 1] != 'e' && str[i - 1] != 'E') return false;
                // 第一次出现+-符号，且不是在字符串开头，则也必须紧接在e之后
                if (!sign && i > 0 && str[i - 1] != 'e' && str[i - 1] != 'E') return false;
                sign = true;
            } else if (str[i] == '.') {
                // e后面不能接小数点，小数点不能出现两次
                if (hasE || decimal) return false;
                decimal = true;
            } else if (str[i] < '0' || str[i] > '9') // 不合法字符
                return false;
        }
        return true;
    }
};
