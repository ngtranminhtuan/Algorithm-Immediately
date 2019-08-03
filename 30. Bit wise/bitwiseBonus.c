// To debug and research bitwise, we have some function in C and Python to print binary form of an integer

//Python:
def int_to_bin(num, bits=8):
 r = ''
 while bits:
  r = ('1' if num&1 else '0') + r
  bits = bits - 1
  num = num >> 1
 print r

//  C:
void int_to_bin(int num) {
  char str[9] = {0};
  int i;
  for (i=7; i>=0; i--) {
    str[i] = (num&1)?'1':'0';
    num >>= 1;
  }
  printf("%s\n", str);
}
