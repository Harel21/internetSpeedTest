#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

  char line[128]; // to read the byte from rx_bytes
  const char PATH[] = "/sys/class/net/eno1/statistics/rx_bytes"; // path to file
  FILE *fp; // rx_bytes

  long long int bytes_first;
  long long int bytes_second;
  long long int result = 0;

  // fgets(line, 128, fp); // reading the number from file
  //
  // bytes_first = atoll(line); // returns a long long int
  // printf("first read: %lld\n", bytes_first);

  for(int i = 0; i < 10; i++){
    fp = fopen(PATH, "r");
    fgets(line, 128, fp);
    bytes_first = atoll(line);
    fclose(fp);

    sleep(2);

    fp = fopen(PATH, "r");
    fgets(line, 128, fp);
    bytes_second = atoll(line);
    fclose(fp);

    result += bytes_second - bytes_first;
    // printf("Your internet speed is %lld b/s\n", result);

    bytes_first = 0;
    bytes_second = 0;
    // result = 0;
  }

  printf("your internet speed is: %lld b/sec\n", result / 10);

  return 0;
}
