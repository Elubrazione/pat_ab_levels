/**
 * sscanf() – 从一个字符串中读进与指定格式相符的数据
 * sprintf() – 字符串格式化命令，主要功能是把格式化的数据写入某个字符串中
 *
 * 当sscanf读入的字符串没有与之匹配的类型的时候，temp的值会是浮点数的0，
 * 这样在sprintf将0写到字符数组b后，和字符数组a相比较就会不同。
 * 轻松解决了判断是否含有非数字，有几个小数点等，计算小数部分和整数部分的问题
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, cnt = 0;
  char a[50], b[50];
  double temp = 0.0, sum = 0.0;
  cin >> n;
  for(int i = 0; i < n; i++) {
    scanf("%s", a);
    sscanf(a, "%lf", &temp);
    sprintf(b, "%.2f",temp);
    int flag = 0;
    for(int j = 0; j < strlen(a); j++)
      if(a[j] != b[j]) flag = 1;
    if(flag || temp < -1000 || temp > 1000) {
      printf("ERROR: %s is not a legal number\n", a);
      continue;
    } else {
      sum += temp;
      cnt++;
    }
  }
  if(cnt == 1)
    printf("The average of 1 number is %.2f", sum);
  else if(cnt > 1)
    printf("The average of %d numbers is %.2f", cnt, sum / cnt);
  else
    printf("The average of 0 numbers is Undefined");
  return 0;
}