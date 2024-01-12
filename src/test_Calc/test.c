#include "test.h"

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;
  s = StartTest();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_VERBOSE);
  no_failed += srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

START_TEST(TEST_1) {
  double error = 0;
  double result = 55.363432;
  double x = 0;
  char string[SIZE] = "(((0.000002) - (9 - 0) + (2.3 ^ 5)))";
  int inval = 0;
  error = s21_main(string, x, &inval);
  ck_assert_double_eq_tol(result, error, 8);
}
END_TEST

START_TEST(TEST_2) {
  double error = 0;
  double result = 1;
  double x = 0;
  int inval = 0;
  char string[SIZE] = "109 + (450 / 450) - 110";

  error = s21_main(string, x, &inval);
  ck_assert_double_eq_tol(result, error, 8);
}
END_TEST

START_TEST(TEST_3) {
  double error = 0;
  double result = -21.12;
  double x = 0;
  int inval = 0;
  char string[SIZE] = "(-21.12) * (66 / 66)";

  error = s21_main(string, x, &inval);
  ck_assert_double_eq_tol(result, error, 8);
}
END_TEST

START_TEST(TEST_4) {
  double error = 0;
  double result = 63.52687747;
  int inval = 0;
  double x = 0;
  char string[SIZE] = "88 + (2 ^ 2) * (-569.0000987) / (99 - 6)";
  error = s21_main(string, x, &inval);
  ck_assert_double_eq_tol(result, error, 8);
}
END_TEST

START_TEST(TEST_5) {
  double error = 0;
  double result = -7.0370370;
  double x = 0;
  int inval = 0;
  char string[SIZE] = "(-7.0) + (-3 ^ (-3))";

  error = s21_main(string, x, &inval);
  ck_assert_double_eq_tol(result, error, 8);
}
END_TEST

START_TEST(TEST_7) {
  double error = 0;
  double result = -6794.53374717;
  double x = 0;
  int inval = 0;
  char string[SIZE] =
      "(-6696.0009867) + 1 / 4 / 2 / 1.3 * 5.0009 + (-56) + (-sqrt(9.9)) - 99 "
      "+ 1.4 ^ (-6) - 5 + 8 ^ 2";
  error = s21_main(string, x, &inval);
  ck_assert_double_eq_tol(result, error, 8);
}
END_TEST

START_TEST(TEST_8) {
  double error = 0;
  double result = 3.5759962;
  double x = 0;
  int inval = 0;
  char string[SIZE] =
      "(-cos(3)) - (-cos(1)) + 4 / 2 - (sin(1)) + 1 ^ 2.0000007 * 6.09 / "
      "(-tan(2)) / acos(-1)";

  error = s21_main(string, x, &inval);
  ck_assert_double_eq_tol(result, error, 8);
}
END_TEST

START_TEST(TEST_9) {
  double error = 0;
  double result = -4.9;
  double x = 0;
  int inval = 0;
  char string[SIZE] = "(-1) + (-1) + (-1) - 1.9 - (-1) - 1";
  error = s21_main(string, x, &inval);
  ck_assert_double_eq_tol(result, error, 8);
}
END_TEST

START_TEST(TEST_10) {
  double error = 0;
  double result = 0.6663667;
  double x = 0;
  int inval = 0;
  char string[SIZE] = "cos(sin(1))";

  error = s21_main(string, x, &inval);
  ck_assert_double_eq_tol(result, error, 8);
}
END_TEST

START_TEST(TEST_11) {
  double error = 0;
  double result = 4096;
  double x = 0;
  int inval = 0;
  char string[SIZE] = "8 ^ 2 ^ 2";

  error = s21_main(string, x, &inval);
  ck_assert_double_eq_tol(result, error, 8);
}
END_TEST

START_TEST(TEST_12) {
  double error = 0;
  double result = 8;
  double x = 0;
  int inval = 0;
  char string[SIZE] = "(8-(-9))-(9)";

  error = s21_main(string, x, &inval);
  ck_assert_double_eq_tol(result, error, 8);
}
END_TEST

START_TEST(TEST_13) {
  double error = 0;
  double result = -1;
  double x = 0;
  int inval = 0;
  char string[SIZE] = "(202-203)";
  error = s21_main(string, x, &inval);
  ck_assert_double_eq_tol(result, error, 8);
}
END_TEST

START_TEST(TEST_14) {
  double error = 0;
  double result = -13.0700007;
  double x = 0;
  char string[SIZE] =
      "3 * (8.0987 / 8.0987) - 65.02 + 13.01 - 6.0 - (0.0000001 * 7) + 6 * (9 "
      "- 2.01)";
  int inval = 0;
  error = s21_main(string, x, &inval);
  ck_assert_double_eq_tol(result, error, 8);
}
END_TEST

START_TEST(TEST_15) {
  double error = 0;

  double result = 4;
  int inval = 0;
  char string[SIZE] = "2 ^ 2";
  double x = 0;
  error = s21_main(string, x, &inval);
  ck_assert_double_eq_tol(result, error, 8);
}
END_TEST

START_TEST(TEST_16) {
  double error = 0;
  double result = -4;
  double x = 0;
  char string[SIZE] = "6 - 10";
  int inval = 0;
  error = s21_main(string, x, &inval);
  ck_assert_double_eq_tol(result, error, 8);
}
END_TEST

START_TEST(TEST_17) {
  char *str = "1+1";
  int inval = 0;
  double result_num = 2;
  double x = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq(test_num, result_num);
}

START_TEST(TEST_18) {
  char *str = "sin(x)";
  double result_num = 0.8414709848;
  double x = 1;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_19) {
  char *str = "cos(x)";
  double result_num = 1.000000;
  double x = 0;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq(test_num, result_num);
}

START_TEST(TEST_20) {
  char *str = "log(x)";
  double result_num = 0;
  double x = 1;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq(test_num, result_num);
}

START_TEST(TEST_21) {
  char *str = "asin(x)";
  double x = 1;
  int inval = 0;
  double result_num = 1.55740772465;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_22) {
  char *str = "tan(x)";
  double x = 1;
  int inval = 0;
  double result_num = 0.100335;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_23) {
  char *str = "log(x)";
  int inval = 0;
  double x = 1;
  double result_num = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_24) {
  char *str = "sqrt(x)";
  double x = 1;
  int inval = 0;
  double result_num = 1;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_25) {
  char *str = "sqrt(x)";
  double x = 4;
  int inval = 0;
  double result_num = 2;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_26) {
  char *str = "sqrt(x)+0.5";
  double result_num = 2.7360679775;
  double x = 5;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_27) {
  char *str = "sqrt(x)-0.5+0.1";
  double result_num = 1.836067977;
  double x = 5;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_28) {
  char *str = "0.6+0.5*2";
  double result_num = 1.6;
  double x = 0;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq(test_num, result_num);
}

START_TEST(TEST_29) {
  char *str = "atan(x)";
  double x = 1;
  int inval = 0;
  double result_num = 0.785398163;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_30) {
  char *str = "atan(x)-0.07";
  double x = 1;
  int inval = 0;
  double result_num = 0.715398163;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_31) {
  char *str = "acos(x)";
  double result_num = acos(1);
  double x = 1;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_32) {
  char *str = "acos(x)*2";
  double result_num = acos(1) * 2;
  double x = 1;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_33) {
  char *str = "(atan(x)-0.07)*3";
  double result_num = (atan(1) - 0.07) * 3;
  double x = 1;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_34) {
  char *str = "2*(atan(x)-0.07)*3";
  double result_num = 2 * (atan(1) - 0.07) * 3;
  double x = 1;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_35) {
  char *str = "(0.6+0.5*2)*3";
  double result_num = 4.8;
  double x = 0;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_36) {
  char *str = "(0.6+0.5*2)*4/2";
  double result_num = 3.2;
  double x = 0;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq(test_num, result_num);
}

START_TEST(TEST_37) {
  char *str = "(2*acos(x)+15)*tan(x)";
  double result_num = (2 * acos(1) + 15) * tan(1);
  double x = 1;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_38) {
  char *str = "(2*asin(x)+21)*asin(x)";
  double result_num = (2 * asin(1) + 21) * asin(1);
  double x = 1;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_39) {
  char *str = "log(cos(log(x)))";
  double result_num = log(cos(log(1)));
  double x = 1;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_40) {
  char *str = "cos(log(cos(x)))";
  double result_num = 1.000000;
  double x = 0;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq(test_num, result_num);
}

START_TEST(TEST_41) {
  char *str = "sin(log(sin(x)))";
  double result_num = sin(log(sin(1)));
  double x = 1;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_42) {
  char *str = "sin(atan(sin(x)))";
  double result_num = sin(atan(sin(1)));
  double x = 1;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq_tol(result_num, test_num, 8);
}

START_TEST(TEST_43) {
  char *str = "atan(tan(x))";
  double result_num = 0;
  double x = 0;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq(test_num, result_num);
}

START_TEST(TEST_44) {
  char *str = "asin(sin(x))";
  double result_num = 0;
  double x = 0;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq(test_num, result_num);
}

START_TEST(TEST_45) {
  char *str = "acos(cos(x))";
  double result_num = 0;
  double x = 0;
  int inval = 0;
  double test_num = s21_main(str, x, &inval);
  ck_assert_double_eq(test_num, result_num);
}

START_TEST(TEST_46) {
  int error = 0;
  char mass[SIZE] = "(--1+1)";
  error = operator_validator(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_47) {
  int error = 0;
  char mass[SIZE] = "1(-cos(1-0.5))";
  error = operator_validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(TEST_48) {
  int error = 0;
  char mass[SIZE] = "1--10000000000000000000000000000000000000000000";
  error = operator_validator(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_49) {
  int error = 0;
  char mass[SIZE] = "13-13-";
  error = operator_validator(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_50) {
  int error = 0;
  char mass[SIZE] = "(/11)-+";
  error = operator_validator(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_51) {
  int error = 0;
  char mass[SIZE] = "(11+*)/(cos(7+))";
  error = operator_validator(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_52) {
  int error = 0;
  char mass[SIZE] = "11^2-_-";
  error = operator_validator(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_53) {
  int error = 0;
  char mass[SIZE] = "^^2";
  error = operator_validator(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_54) {
  int error = 0;
  char mass[SIZE] = "22^(^2)";
  error = operator_validator(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_55) {
  int error = 0;
  char mass[SIZE] = "^(-^2)";
  error = operator_validator(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_56) {
  int error = 0;
  char mass[SIZE] = "11^(2mod)";
  error = operator_validator(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_57) {
  int error = 0;
  char mass[SIZE] = "1mod-1";
  error = operator_validator(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_58) {
  int error = 0;
  char mass[SIZE] = "cos(1)cos(1)";
  error = operator_validator(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_59) {
  int error = 0;
  char mass[SIZE] = "1mod2mod";
  error = operator_validator(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_60) {
  int error = 0;
  char mass[SIZE] = "cos(1)+cos(1)modtan(1)-acos(-1)";
  error = operator_validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(TEST_61) {
  int error = 0;
  char mass[SIZE] = "1-1+9(-1+(-cos(1-)))";
  error = operator_validator(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_62) {
  int error = 0;
  char mass[SIZE] = "1^-1";
  error = operator_validator(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_63) {
  int error = 0;
  char mass[SIZE] = "1-mod2mod";
  error = operator_validator(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_64) {
  int error = 0;
  char mass[SIZE] = "-(-1)+tan(1)";
  error = operator_validator(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_65) {
  int error = 0;
  char mass[SIZE] = "5000.0000-(-1)+tan(1)^2/(-2)*1+398mod3mod2";
  error = operator_validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(TEST_66) {
  int error = 0;
  char mass[SIZE] = "1.1 - 1.1";
  error = spot_check(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(TEST_67) {
  int error = 0;
  char mass[SIZE] = "11.- 1.1";
  error = spot_check(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_68) {
  int error = 0;
  char mass[SIZE] = "11 - 1.1";
  error = spot_check(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(TEST_69) {
  int error = 0;
  char mass[SIZE] = "11-.11";
  error = spot_check(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_70) {
  int error = 0;
  char mass[SIZE] = "1.1-11.";
  error = spot_check(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_71) {
  int error = 0;
  char mass[SIZE] = "1.1-11";
  error = spot_check(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(TEST_72) {
  int error = 0;
  char mass[SIZE] = "100..1-11";
  error = spot_check(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_73) {
  int error = 0;
  char mass[SIZE] = "1.1.-1.1";
  error = spot_check(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_74) {
  int error = 0;
  char mass[SIZE] = "11.-1.1";
  error = spot_check(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_75) {
  int error = 0;
  char mass[SIZE] = ".11-11";
  error = spot_check(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_76) {
  int error = 0;
  char mass[SIZE] = ".cos(1)";
  error = spot_check(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_77) {
  int error = 0;
  char mass[SIZE] = "acos(1.)";
  error = spot_check(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_78) {
  int error = 0;
  char mass[SIZE] = "acos(1.1.)";
  error = spot_check(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_79) {
  int error = 0;
  char mass[SIZE] = "acos(1.1-3.3-.)";
  error = spot_check(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_80) {
  int error = 0;
  char mass[SIZE] = "";
  error = spot_check(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_81) {
  int error = 0;
  char mass[SIZE] = "((1))";
  error = operations_with_parentheses(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(TEST_82) {
  int error = 0;
  char mass[SIZE] = "()(1)-(1))";
  error = operations_with_parentheses(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_83) {
  int error = 0;
  char mass[SIZE] = "()";
  error = operations_with_parentheses(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_84) {
  int error = 0;
  char mass[SIZE] = "(-1 * )1())";
  error = operations_with_parentheses(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_85) {
  int error = 0;
  char mass[SIZE] = ")";
  error = operations_with_parentheses(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_86) {
  int error = 0;
  char mass[SIZE] = "()99900)";
  error = operations_with_parentheses(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_87) {
  int error = 0;
  char mass[SIZE] = "(909(90)((";
  error = operations_with_parentheses(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_88) {
  int error = 0;
  char mass[SIZE] = "(1)())((2)";
  error = operations_with_parentheses(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_89) {
  int error = 0;
  char mass[SIZE] = "sin(((1-(1))";
  error = operations_with_parentheses(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_90) {
  int error = 0;
  char mass[SIZE] = "tan)10(";
  error = operations_with_parentheses(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(TEST_91) {
  int error = 0;
  char mass[SIZE] = "";
  error = operations_with_parentheses(mass);
  ck_assert_int_eq(1, error);
}
END_TEST

Suite *StartTest(void) {
  Suite *s = suite_create("\033[45m-=TEST FOR CALC=-\033[0m");
  TCase *tc = tcase_create("TESTS RESULT: ");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, TEST_1);
  tcase_add_test(tc, TEST_2);
  tcase_add_test(tc, TEST_3);
  tcase_add_test(tc, TEST_4);
  tcase_add_test(tc, TEST_5);
  tcase_add_test(tc, TEST_7);
  tcase_add_test(tc, TEST_8);
  tcase_add_test(tc, TEST_9);
  tcase_add_test(tc, TEST_10);
  tcase_add_test(tc, TEST_11);
  tcase_add_test(tc, TEST_12);
  tcase_add_test(tc, TEST_13);
  tcase_add_test(tc, TEST_14);
  tcase_add_test(tc, TEST_15);
  tcase_add_test(tc, TEST_16);
  tcase_add_test(tc, TEST_17);
  tcase_add_test(tc, TEST_18);
  tcase_add_test(tc, TEST_19);
  tcase_add_test(tc, TEST_20);
  tcase_add_test(tc, TEST_21);
  tcase_add_test(tc, TEST_22);
  tcase_add_test(tc, TEST_23);
  tcase_add_test(tc, TEST_24);
  tcase_add_test(tc, TEST_25);
  tcase_add_test(tc, TEST_26);
  tcase_add_test(tc, TEST_27);
  tcase_add_test(tc, TEST_28);
  tcase_add_test(tc, TEST_29);
  tcase_add_test(tc, TEST_30);
  tcase_add_test(tc, TEST_31);
  tcase_add_test(tc, TEST_32);
  tcase_add_test(tc, TEST_33);
  tcase_add_test(tc, TEST_34);
  tcase_add_test(tc, TEST_35);
  tcase_add_test(tc, TEST_36);
  tcase_add_test(tc, TEST_37);
  tcase_add_test(tc, TEST_38);
  tcase_add_test(tc, TEST_39);
  tcase_add_test(tc, TEST_40);
  tcase_add_test(tc, TEST_41);
  tcase_add_test(tc, TEST_42);
  tcase_add_test(tc, TEST_43);
  tcase_add_test(tc, TEST_44);
  tcase_add_test(tc, TEST_45);
  tcase_add_test(tc, TEST_46);
  tcase_add_test(tc, TEST_47);
  tcase_add_test(tc, TEST_48);
  tcase_add_test(tc, TEST_49);
  tcase_add_test(tc, TEST_50);
  tcase_add_test(tc, TEST_51);
  tcase_add_test(tc, TEST_52);
  tcase_add_test(tc, TEST_53);
  tcase_add_test(tc, TEST_54);
  tcase_add_test(tc, TEST_55);
  tcase_add_test(tc, TEST_56);
  tcase_add_test(tc, TEST_57);
  tcase_add_test(tc, TEST_58);
  tcase_add_test(tc, TEST_59);
  tcase_add_test(tc, TEST_60);
  tcase_add_test(tc, TEST_61);
  tcase_add_test(tc, TEST_62);
  tcase_add_test(tc, TEST_63);
  tcase_add_test(tc, TEST_64);
  tcase_add_test(tc, TEST_65);
  tcase_add_test(tc, TEST_66);
  tcase_add_test(tc, TEST_67);
  tcase_add_test(tc, TEST_68);
  tcase_add_test(tc, TEST_69);
  tcase_add_test(tc, TEST_70);
  tcase_add_test(tc, TEST_71);
  tcase_add_test(tc, TEST_72);
  tcase_add_test(tc, TEST_73);
  tcase_add_test(tc, TEST_74);
  tcase_add_test(tc, TEST_75);
  tcase_add_test(tc, TEST_76);
  tcase_add_test(tc, TEST_77);
  tcase_add_test(tc, TEST_78);
  tcase_add_test(tc, TEST_79);
  tcase_add_test(tc, TEST_80);
  tcase_add_test(tc, TEST_81);
  tcase_add_test(tc, TEST_82);
  tcase_add_test(tc, TEST_83);
  tcase_add_test(tc, TEST_84);
  tcase_add_test(tc, TEST_85);
  tcase_add_test(tc, TEST_86);
  tcase_add_test(tc, TEST_87);
  tcase_add_test(tc, TEST_88);
  tcase_add_test(tc, TEST_89);
  tcase_add_test(tc, TEST_90);
  tcase_add_test(tc, TEST_91);

  return s;
}
