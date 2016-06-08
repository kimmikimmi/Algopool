#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <tuple>
#include <set>
using namespace std;

int n;
int m;
typedef vector<vector<int>> matrix;
#define INF 1000000
matrix adj_mat;

// matrix adj_mat2;

void input2(std::istream& pin) {
	pin >> n;
	adj_mat.assign(n, vector<int>(n));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			pin >> adj_mat[i][j];
		}
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(adj_mat[i][j] == 0) 
				adj_mat[i][j] = INF;
		}
	}
}

void input(std::istream& pin) {
	int r,c,cost;
	pin >> n;
	pin >> m;
	adj_mat.assign(n, vector<int>(n));
	for(int i=0; i<m; i++) {
		pin >> r >> c >> cost;
		if(adj_mat[r-1][c-1] > cost || adj_mat[r-1][c-1] == 0) 
			adj_mat[r-1][c-1] = cost; 		
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(adj_mat[i][j] == 0) 
				adj_mat[i][j] = INF;
		}
	}
}


void floyds()
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if ((adj_mat[i][k] * adj_mat[k][j] != 0) && (i != j))
                {
                    if ((adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j]) || (adj_mat[i][j] == 0))
                    {
                        adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                    }
                }
            }
        }
    }
    // for (i = 0; i < n; i++)
    // {
    //     // cout<<"\nMinimum Cost With Respect to Node:"<<i<<endl;
    //     for (j = 0; j < n; j++)
    //     {
    //     	if(adj_mat[i][j] == INF) cout << 0 << " ";
    //         else 
    //         	cout<<adj_mat[i][j]<<" ";
    //     }
    //     cout << endl;
 
    // }

    for (i = 0; i < n; i++) {    
        for (j = 0; j < n; j++) {
        	if(adj_mat[i][j] == INF) cout << 0 << " ";
            else 
            	cout << 1 << " ";
        }
        cout << endl;
	}
}

int method() {
	return 0;
}

int main() {
	

	 input2(cin);
	


	floyds();

	return 0;
}
