#include "s21_stack.h"

int spot_check(char mass[SIZE]) {
  if (mass == NULL || strlen(mass) == 0) {
    return STRING_EMPTY;
  }
  int error = 0;
  int count_general = 0;
  int digit = 0;
  while (*mass != '\0') {
    if (operator_manipulation_errors(mass) == 0) {
      if (*mass >= '0' && *mass <= '9') {
        digit++;
      } else if (*mass == '.') {
        count_general++;
        if (!digit) {
          return ERROR_EXPRESSION;
        } else if (*(mass + 1) == '\0') {
          return ERROR_EXPRESSION;
        }
        if (count_general > 1) {
          error = ERROR_EXPRESSION;
        }
      }
    } else {
      count_general = 0;
      digit = 0;
      if (*(mass - 1) == '.') {
        return ERROR_EXPRESSION;
      }
    }
    if (*mass == ')') {
      if (*(mass - 1) == '.') {
        return ERROR_EXPRESSION;
      }
    }
    mass += 1;
  }
  return error;
}

int operator_manipulation_errors(const char mass[SIZE]) {
  int error = 1;
  if (*mass != 'm' && *mass != '^' && *mass != '+' && *mass != '-' &&
      *mass != '*' && *mass != '/' && *mass != 'x') {
    error = 0;
  }
  return error;
}

int operations_with_parentheses(char mass[SIZE]) {
  if (mass == NULL || strlen(mass) == 0) {
    return STRING_EMPTY;
  }
  int count_left = 0;
  int count_right = 0;
  int count_general = 0;
  int error = 0;
  while (*mass != '\0') {
    if (count_general < 0) {
      return ERROR_EXPRESSION;
    } else if (*mass == '(') {
      if ((*(mass - 1) >= '0' && *(mass - 1) <= '9')) {
        return ERROR_EXPRESSION;
      }
      if (*(mass + 1) == ')') {
        return ERROR_EXPRESSION;
      }
      count_left++;
      count_general++;
    } else if (*mass == ')') {
      if (*(mass + 1) == '(') {
        return ERROR_EXPRESSION;
      }
      count_right++;
      count_general--;
    }
    mass += 1;
  }
  if (count_left != count_right) {
    return ERROR_EXPRESSION;
  }
  return error;
}

int operator_validator(char mass[SIZE]) {
  if (mass == NULL || strlen(mass) == 0) {
    return STRING_EMPTY;
  }
  int flag = 0;
  int error = 0;
  int i = 0;
  while (*mass != '\0' && !error) {
    if (operator_manipulation_errors(mass) == 1) {
      if ((i == 0 || *(mass + 1) == ')') && *mass != 'x') {
        return ERROR_EXPRESSION;
      }
      if (*mass == 'm') {
        if (modification_function(mass) || *(mass - 1) == '(') {
          return ERROR_EXPRESSION;
        }
        if (*(mass + 3) == '\0' || *(mass + 3) == ')' ||
            (*(mass + 3) && !operator_manipulation_errors(mass))) {
          return ERROR_EXPRESSION;
        }
      }
      if (*mass == 'x' && (*(mass - 1) >= '0' && *(mass - 1) <= '9')) {
        return ERROR_EXPRESSION;
      }
      if (*mass == 'x') {
        flag = 1;
      } else {
        if (*(mass + 1) == 'x') {
          flag = 1;
        }
        *(mass += 1) == '\0' ? error = 1 : error;
        if (operator_manipulation_errors(mass) == 1 && !flag) {
          return ERROR_EXPRESSION;
        }
      }
    } else if ((*(mass) >= '0' && *(mass) <= '9') && *(mass + 1) == 'x') {
      return ERROR_EXPRESSION;
    }
    if (additionaly_operator_check(mass) && !error) {
      return ERROR_EXPRESSION;
    } else if (operation_from_trigonometry(mass) && !error) {
      return ERROR_EXPRESSION;
    }
    mass++;
    i++;
  }
  return error;
}

int operation_from_trigonometry(char mass[SIZE]) {
  int error = 0;
  if (*mass == ')') {
    if (*(mass + 1) == 'c' || *(mass + 1) == 's' || *(mass + 1) == 'a' ||
        *(mass + 1) == 't' || *(mass + 1) == 'l' || *(mass + 1) == 'x') {
      error = 1;
    }
  }
  return error;
}

int modification_function(char mass[SIZE]) {
  int error = 1;
  if (*(mass + 3) == 'c' || *(mass + 3) == 's' || *(mass + 3) == 'a' ||
      *(mass + 3) == 't' || *(mass + 3) == 'l' || *(mass + 3) == 'x' ||
      (*(mass + 3) >= '0' && *(mass + 3) <= '9') || *(mass + 3) == '(') {
    error = 0;
  }
  return error;
}

int additionaly_operator_check(char mass[SIZE]) {
  int error = 0;
  if (*mass == '(') {
    if (*(mass + 1) == '*' || *(mass + 1) == '/' || *(mass + 1) == '^') {
      error = 1;
    }
  }
  return error;
}

int main_validator(char mass[SIZE]) {
  if (mass == NULL || strlen(mass) == 0 || strlen(mass) == 256) {
    return STRING_EMPTY;
  }
  int error = 0;
  error = spot_check(mass);
  if (!error) {
    error = operations_with_parentheses(mass);
  }
  if (!error) {
    error = operator_validator(mass);
  }
  return error;
}
