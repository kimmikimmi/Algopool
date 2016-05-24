// input, output 
#include <iostream>
#include <iomanip>
// container
#include <vector>
#include <array>
#include <list>
#include <map>
#include <set>
#include <string>
// container adaper
#include <stack>
#include <queue>
#include <deque>
// STL algorithm related
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <memory>
#include <utility>
// C standard library
#include <cmath>
#include <cstdlib>
 
#include <cstring>
//
// #define DEBUG
using namespace std;
// Declaration of variables
 
 
// Declaration of auxiliary function
class genProbSolver {
 
    public:
        genProbSolver(string s) : name(s) {}
        void process_input(istream &);
        void process_solution();
        void process_output(ostream &);
        void echo_input();
    private:
        string name;
};
int longest_common_subsequence(string &X, string &Y) {
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> table(m+1, vector<int>(n+1, 0));
    //memset(table, 0, m+1*n+1*sizeof(int));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                table[i][j] = table[i-1][j-1] + 1;
            } else if(table[i][j-1] > table[i-1][j]) {
                table[i][j] = table[i][j-1];
            } else {
                table[i][j] = table[i-1][j];
            }
        }
    }
    return table[m][n];
}
 
int longest_common_subsequence(string &X, string &Y, string &Z) {
    int m = X.size();
    int n = Y.size();
    int o = Z.size();
    vector<vector<vector<int>>> table(m+1, vector<vector<int>>(n+1, vector<int>(o+1, 0)));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= o; k++) {
                if(X[i-1] == Y[j-1] && Y[j-1] == Z[k-1]) {
                    table[i][j][k] = table[i-1][j-1][k-1] + 1;
                } else {
                    table[i][j][k] = max({table[i-1][j][k], table[i][j-1][k], table[i][j][k-1]});
                }
            }
 
        }
    }
    return table[m][n][o];
}
void genProbSolver::process_input(istream &pin) {
    string s1, s2, s3;
    pin >> s1 >> s2 >> s3;
    cout << longest_common_subsequence(s1, s2, s3);
 
    //std::cout << n1 << std::endl;
    /*int index = table[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            lcs[index - 1] = s1[i-1];
            --i; --j; --index;
        } else if (table[i-1][j] > table[i][j-1]) {
            --i;
        } else {
            --j;
        }
    }*/
    //std::cout << table[m][n] << "\n";
    //std::cout << lcs;
}
void genProbSolver::echo_input() {
 
}
void genProbSolver::process_solution() {
     
}
void genProbSolver::process_output(ostream &pout) {
 
}
int main(int argc, const char *argv[]) {
    genProbSolver probsolver("");
    probsolver.process_input(std::cin);
    probsolver.echo_input();
    probsolver.process_solution();
    probsolver.process_output(std::cout);
    return 0;
}
