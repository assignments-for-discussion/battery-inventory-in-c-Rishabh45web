#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  struct CountsByUsage counts = {0, 0, 0};
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
 for(int i=0;i<numberOfBatteries;i++)
  {
    if(chargeCycleCounts[i]<410)     //checking the low count
    counts.lowCount++;               //incrementing the low count variable
    else if(chargeCycleCounts[i]>410 && chargeCycleCounts[i]<910) //checking medium count 
    counts.mediumCount++;            //incrementing the medium count
    else                              //checking for high count
    counts.highCount++;              // incrementing the high count
  }
  printf("%d\n",counts.lowCount);     //displaying the low count
  printf("%d\n",counts.mediumCount);  //displaying the medium count
  printf("%d\n",counts.highCount);   //displaying the high count
  assert(counts.lowCount == 2);
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
