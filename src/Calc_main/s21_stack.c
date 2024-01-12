#include "s21_stack.h"

#include <ctype.h>

int parser(char *str, Node **head, double x) {
  int step = 0;
  char function_string[9] = "sctalxp(";
  while (step < (int)strlen(str)) {
    int lexeme = token_check(str[step]);
    if (lexeme == NUMBER) {
      checking_numbers(str, head, &step);
      if (strchr(function_string, str[step]) && str[step] != '\0') {
        push(head, 0.0, 2, MUL);
      }
      step--;
    } else if (lexeme == OPERATION) {
      matematical_operations(str, head, x, step);
    } else if (lexeme == LETTER) {
      int a = function_check(str, head, step);
      step = a;
    }
    step++;
  }
  return 0;
}

void checking_numbers(char *str, Node **head, int *step) {
  char number_string[12] = "1234567890.";
  char digit[256] = {0};
  int i = 0;
  int step_flags = *step;

  while (strchr(number_string, str[step_flags]) && str[step_flags] != '\0') {
    digit[i] = str[step_flags];
    i++;
    step_flags++;
  }
  push(head, atof(digit), 0, NUMBER);
  *step = step_flags;
}

int function_check(char *str, Node **head, int step) {
  if (str[step] == 'c') {
    if (strstr(str, "cos") != NULL) {
      push(head, 0.0, 4, COS);
      step += 2;
    }
  } else if (str[step] == 's') {
    if (str[step + 1] == 'i') {
      push(head, 0.0, 4, SIN);
      step += 2;
    } else if (str[step + 1] == 'q') {
      push(head, 0.0, 4, SQRT);
      step += 3;
    }
  } else if (str[step] == 't') {
    if (str[step + 1] == 'a') {
      push(head, 0.0, 4, TAN);
      step += 2;
    }
  } else if (str[step] == 'a') {
    if (str[step + 1] == 'c') {
      push(head, 0.0, 4, ACOS);
      step += 2;
    } else if (str[step + 1] == 's') {
      push(head, 0.0, 4, ASIN);
      step += 2;
    } else if (str[step + 1] == 't') {
      push(head, 0.0, 4, ATAN);
      step += 2;
    }
  } else if (str[step] == 'l') {
    if (str[step + 1] == 'n') {
      push(head, 0.0, 4, LN);
    } else if (str[step + 1] == 'o') {
      push(head, 0.0, 4, LOG);
      step += 1;
    }
  }
  return step;
}

int token_check(char symbol) {
  int ExitCode = ERROR;
  char operations[9] = "()/+-*^%";
  if (symbol >= '0' && symbol <= '9') {
    ExitCode = NUMBER;
  } else if (symbol == '(') {
    ExitCode = OPERATION;
  } else if (symbol == ')') {
    ExitCode = OPERATION;
  } else if (strchr(operations, symbol) != NULL) {
    ExitCode = OPERATION;
  } else if (symbol == ' ') {
    ExitCode = SPACE;
  } else if (symbol == '.') {
    ExitCode = POINT;
  } else if (symbol >= 'a' && symbol <= 'z' && symbol != 'x') {
    ExitCode = LETTER;
  } else if (symbol == 'x') {
    ExitCode = OPERATION;
  }
  return ExitCode;
}

int matematical_operations(char symbol[SIZE], Node **head, double x, int step) {
  int flag = ERROR;
  int priority = 0;

  if (symbol[step] == '+') {
    if (symbol[step - 1] == '(') {
      flag = unary_plus;
      priority = 1;
    } else {
      flag = PLUS;
      priority = 1;
    }
  } else if (symbol[step] == '-') {
    if ((step == 0 && (symbol[step + 1]) == '(') ||
        ((isdigit(symbol[step + 1]) > 0) && (isdigit(symbol[step - 1]) == 0) &&
         ((symbol[step - 1]) != ')')) ||
        ((symbol[step - 1]) == '(')) {
      flag = unary_minus;
      priority = 1;
    } else {
      flag = MINUS;
      priority = 1;
    }
  } else if (symbol[step] == '*') {
    flag = MUL;
    priority = 2;
  } else if (symbol[step] == '/') {
    flag = DIV;
    priority = 2;
  } else if (symbol[step] == '%') {
    flag = MOD;
    priority = 2;
  } else if (symbol[step] == '^') {
    flag = POWER;
    priority = 3;
  } else if (symbol[step] == '(') {
    flag = OPEN_BRACKET;
    priority = 5;
  } else if (symbol[step] == ')') {
    flag = CLOSE_BRACKET;
    priority = 5;
  } else if (symbol[step] == 'x') {
    flag = X;
    priority = 0;
  }
  push(head, x, priority, flag);
  return flag;
}

void push(Node **head, double value, int priority, type_t operator_) {
  Node *tmp = (Node *)malloc(sizeof(Node));
  tmp->value = value;
  tmp->priority = priority;
  tmp->operator_ = operator_;
  tmp->next = (*head);
  (*head) = tmp;
}

void pop(Node **top) {
  Node *next_node = NULL;
  if (*top != NULL) {
    next_node = (*top)->next;
    free(*top);
    *top = next_node;
  }
}

int check(const Node *head) {
  int i = 0;
  while (head) {
    head = head->next;
    i++;
  }

  return i;
}

Node *peek(Node **head) {
  Node *node_head = NULL;
  if (*head != NULL) {
    node_head = *head;
  }
  return node_head;
}

Node *inverse_stack(Node *top) {
  Node *new_stack = NULL;
  if (top != NULL) {
    Node *current = top;
    while (current != NULL) {
      push(&new_stack, current->value, current->priority, current->operator_);
      current = current->next;
    }
    pop(&current);
    return new_stack;
  } else
    return new_stack;
}
