/*
1 Billion Users
We have N different apps with different user growth rates. At a given time t, measured in days, the number of users using an app is g^t (for simplicity we'll allow fractional users), where g is the growth rate for that app. These apps will all be launched at the same time and no user ever uses more than one of the apps. We want to know how many total users there are when you add together the number of users from each app.
After how many full days will we have 1 billion total users across the N apps?
Signature
int getBillionUsersDay(float[] growthRates)
Input
1.0 < growthRate < 2.0 for all growth rates
1 <= N <= 1,000
Output
Return the number of full days it will take before we have a total of 1 billion users across all N apps.
Example 1
growthRates = [1.5]
output = 52
Example 2
growthRates = [1.1, 1.2, 1.3]
output = 79
Example 3
growthRates = [1.01, 1.02]
output = 1047


*/
#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

float getGrowth(int d, vector<float>& gr) {
  float ret = 0.0;
  float base = d;
  for(int i = 0; i < gr.size(); i++) {
    ret += pow(gr[i], d);
  }
  return ret;
}

int getBillionUsersDay(vector <float> growthRates) {
  // Write your code here
  int ans = 0;
  float g = 0;
  for(int i = 1; i < INT_MAX; i++) {
    g = getGrowth(i, growthRates);
    if(g >= 1000000000.00) {
      ans = i;
      break;
    }
  }
  return ans;
}






// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printInteger(int n) {
  cout << "[" << n << "]";
}

int test_case_number = 1;

void check(int expected, int output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printInteger(expected);
    cout << " Your output: ";
    printInteger(output);
    cout << endl;
  }
  test_case_number++;
}

int main() {

  vector <float> test_1{1.1, 1.2, 1.3};
  int expected_1 = 79;
  int output_1 = getBillionUsersDay(test_1);
  check(expected_1, output_1);

  vector <float> test_2{1.01, 1.02};
  int expected_2 = 1047;
  int output_2 = getBillionUsersDay(test_2);
  check(expected_2, output_2);

  // Add your own test cases here

}
