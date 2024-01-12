#include "s21_stack.h"

int trigonometry(Node *head) {
  return (head->operator_ >= 8 && head->operator_ <= 16) ? 1 : 0;
}

int math_operation(Node *head) {
  return (head->operator_ >= 2 && head->operator_ <= 7) ? 1 : 0;
}

void sort_operator(Node **Operator, Node **helper, Node **Conclusion) {
  if (*Operator == NULL) {
    push(Operator, 0, (*helper)->priority, (*helper)->operator_);
  } else {
    while (*Operator != NULL && (*Operator)->priority >= (*helper)->priority) {
      push(Conclusion, 0, (*Operator)->priority, (*Operator)->operator_);
      pop(Operator);
      *Operator = peek(Operator);
    }
    push(Operator, 0, (*helper)->priority, (*helper)->operator_);
  }
}

void sorting_parentheses(Node **Operator, Node **Conclusion) {
  Node *temp = peek(Operator);

  while (temp->operator_ != 17 && temp != NULL) {
    push(Conclusion, temp->value, temp->priority, temp->operator_);
    pop(Operator);
    temp = peek(Operator);
    if (temp == NULL) {
      pop(&temp);
      break;
    }
  }
  pop(Operator);
}

Node *polish_notation(Node *helper) {
  Node *Conclusion = {0};
  Node *Operator = {0};
  helper = inverse_stack(helper);

  while (helper != NULL) {
    if (helper->operator_ == 1 || helper->operator_ == 23) {
      push(&Conclusion, helper->value, helper->priority, helper->operator_);
    } else if (trigonometry(helper)) {
      push(&Operator, helper->value, helper->priority, helper->operator_);
    } else if (math_operation(helper)) {
      sort_operator(&Operator, &helper, &Conclusion);
    } else if (helper->operator_ == 17) {
      push(&Operator, 0, 0, helper->operator_);
    } else if (helper->operator_ == 18) {
      sorting_parentheses(&Operator, &Conclusion);
    } else if (helper->operator_ == 24) {
      push(&Operator, 0, 1, helper->operator_);
    }
    helper = helper->next;
  }
  while (Operator != NULL) {
    push(&Conclusion, 0, Operator->priority, Operator->operator_);
    pop(&Operator);
  }
  pop(&helper);
  pop(&Operator);
  Conclusion = inverse_stack(Conclusion);
  return Conclusion;
}
