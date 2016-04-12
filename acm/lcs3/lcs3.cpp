/* Dynamic Programming implementation of LCS problem */
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int ind;
char* lcs;

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
void lcs_func( string X, string Y, int m, int n )
{
   int L[m+1][n+1];
 
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
 
   // Following code is used to print LCS
   ind = L[m][n];
 
   // Create a character array to store the lcs string
    lcs = new char[ind+1];
   lcs[ind] = '\0'; // Set the terminating character
 
   // Start from the right-most-bottom-most corner and
   // one by one store characters in lcs[]
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (X[i-1] == Y[j-1])
      {
          lcs[ind-1] = X[i-1]; // Put current character in result
          i--; j--; ind--;     // reduce values of i, j and index
      }
 
      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }
 
   // Print the lcs
   
}
 
/* Driver program to test above function */
int main()
{
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  
  int m = s1.size();
  
  int n = s2.size();
  int k = s3.size();
  lcs_func(s1, s2, m, n);
  n = sizeof(lcs) -1;
  char tmp[n];
  k = s3.size();
  for(int i=0; i<n; i++) {
    if(lcs[i] != 0) 
      tmp[i] = lcs[i];
    else {
      break;
    }
  }
  lcs = NULL;
  lcs_func(tmp,s3,n, k );
  int cnt;
  for(int i=0; i<sizeof(lcs); i++) {
    if(lcs[i] != 0) cnt++;

    else {
      break;
    }
  }
  cout << cnt;
  return 0;
}