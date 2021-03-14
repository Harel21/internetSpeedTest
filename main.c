#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

  char line[128]; // To read the byte from rx_bytes
  const char PATH[] = "/sys/class/net/eno1/statistics/rx_bytes"; // Path to file
  FILE *fp; // rx_bytes

  // Declaring vars to calculate the speed
  long long int bytes_first;
  long long int bytes_second;
  long long int result = 0;

  for(int i = 0; i < 100; i++){
    fp = fopen(PATH, "r");
    fgets(line, 128, fp);
    bytes_first = atoll(line);
    fclose(fp);

    sleep(1); // To calculate the difference

    fp = fopen(PATH, "r");
    fgets(line, 128, fp);
    bytes_second = atoll(line);
    fclose(fp);

    result += bytes_second - bytes_first;

    bytes_first = 0;
    bytes_second = 0;
    // result = 0;
  }

  printf("your internet speed is: %lld b/sec\n", result / 100); // printing the speed

  return 0;
}
