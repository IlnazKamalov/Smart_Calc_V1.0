#ifndef S21_STACK
#define S21_STACK
#define SIZE 257
#define STACK_OVERFLOW 1
#define STACK_UNDERFLOW 1
#define STACK_EMPTY 1
#define STRING_EMPTY 1
#define STRING_OVERFLOW 1
#define STRING_OVERFLOW 1
#define ERROR_EXPRESSION 1
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum type_t {
  ERROR = 0,
  NUMBER,
  PLUS,
  MINUS,
  MUL,
  DIV,
  MOD,
  POWER,
  SQRT,
  ACOS,
  ASIN,
  ATAN,
  SIN,
  COS,
  TAN,
  LN,
  LOG,
  OPEN_BRACKET,
  CLOSE_BRACKET,
  SPACE,
  POINT,
  LETTER,
  OPERATION,
  X,
  unary_minus,
  unary_plus,
} type_t;

typedef struct Node {
  double value;
  int priority;
  type_t operator_;
  struct Node *next;
} Node;

void push(Node **head, double value, int priority, type_t operator_);
void pop(Node **top);
void deleteList(Node **head);
void printLinkedList(const Node *head);
void fromArray(Node **head, int *arr, size_t size);
void pushBack(Node *head, double value, int priority, type_t operator_);
void checking_numbers(char *str, Node **head, int *step);
void sort_operator(Node **Operator, Node **helper, Node **Conclusion);
void sorting_parentheses(Node **Operator, Node **Conclusion);
Node *peek(Node **head);
Node *inverse_stack(Node *top);
Node *getNth(Node *head, int n);
Node *getLast(Node *head);
Node *polish_notation(Node *helper);
double s21_main(char *argv, double x, int *valid);
double s21_calculator(Node **pnotation);
int popBack(Node **head);
int parser(char *strm, Node **head, double x);
int valid_operation(char *str);
int token_check(char symbol);
int matematical_operations(char symbol[SIZE], Node **head, double x, int step);
int function_check(char *str, Node **head, int step);
int main_validator(char mass[SIZE]);
int check(const Node *head);
int operator_manipulation_errors(const char mass[SIZE]);
int operations_with_parentheses(char mass[SIZE]);
int operator_validator(char mass[SIZE]);
int operation_from_trigonometry(char mass[SIZE]);
int modification_function(char mass[SIZE]);
int additionaly_operator_check(char mass[SIZE]);
int spot_check(char mass[SIZE]);

#endif
