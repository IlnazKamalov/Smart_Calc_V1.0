#include <math.h>

#include "s21_stack.h"

double s21_main(char* argv, double x, int* valid) {
  double result = 0.0;
  Node* head = NULL;
  if (argv == NULL || *argv == '\0') {
    *valid = 1;
  } else {
    parser(argv, &head, x);
    int b = check(head);
    if (b <= 1) {
      *valid = 1;
    }
    if (*valid != 1) {
      Node* pnotation = polish_notation(head);
      result = s21_calculator(&pnotation);
      pop(&pnotation);
    }
  }
  pop(&head);
  return result;
}

double s21_calculator(Node** pnotation) {
  double result = 0.0;
  Node* Help = NULL;
  while (*pnotation != NULL) {
    while ((*pnotation)->priority == 0) {
      push(&Help, (*pnotation)->value, (*pnotation)->priority,
           (*pnotation)->operator_);
      pop(pnotation);
    }
    if ((*pnotation)->operator_ == PLUS) {
      double tmp = Help->value;
      pop(&Help);
      Help->value += tmp;
    } else if ((*pnotation)->operator_ == MINUS) {
      double tmp = Help->value;
      pop(&Help);
      Help->value -= tmp;
    } else if ((*pnotation)->operator_ == unary_minus) {
      double tmp = Help->value * -1;
      Help->value = tmp;
    } else if ((*pnotation)->operator_ == unary_plus) {
      double tmp = Help->value;
      pop(&Help);
      Help->value *= tmp;
    } else if ((*pnotation)->operator_ == X) {
      double tmp = Help->value;
      pop(&Help);
      Help->value += tmp;
    } else if ((*pnotation)->operator_ == MUL) {
      double tmp = Help->value;
      pop(&Help);
      Help->value *= tmp;
    } else if ((*pnotation)->operator_ == DIV) {
      double tmp = Help->value;
      pop(&Help);
      Help->value /= tmp;
    } else if ((*pnotation)->operator_ == MOD) {
      double tmp = Help->value;
      pop(&Help);
      Help->value = fmod(Help->value, tmp);
    } else if ((*pnotation)->operator_ == POWER) {
      double tmp = Help->value;
      pop(&Help);
      Help->value = pow(Help->value, tmp);
    } else if ((*pnotation)->operator_ == COS) {
      Help->value = cos(Help->value);
    } else if ((*pnotation)->operator_ == SIN) {
      Help->value = sin(Help->value);
    } else if ((*pnotation)->operator_ == TAN) {
      Help->value = tan(Help->value);
    } else if ((*pnotation)->operator_ == ACOS) {
      Help->value = acos(Help->value);
    } else if ((*pnotation)->operator_ == ASIN) {
      Help->value = asin(Help->value);
    } else if ((*pnotation)->operator_ == ATAN) {
      Help->value = atan(Help->value);
    } else if ((*pnotation)->operator_ == SQRT) {
      Help->value = sqrt(Help->value);
    } else if ((*pnotation)->operator_ == LN) {
      Help->value = log(Help->value);
    } else if ((*pnotation)->operator_ == LOG) {
      Help->value = log10(Help->value);
    }
    result = Help->value;
    if (*pnotation != NULL) {
      pop(pnotation);
    }
  }
  pop(&Help);
  return result;
}
