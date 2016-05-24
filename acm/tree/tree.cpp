#include <iostream>
using namespace std;
 
int arr[52];
bool visited[52];
int vertex_num, remove_vertex;
int leafnode = 0;
 
void dfs(int vertex){
    visited[vertex] = true;
    bool flag = false;
    for (int i = 0; i < vertex_num; i++){
        if (arr[i] == vertex && !visited[i]){ // i노드의 부모가 v이고, i를 방문한 적이 없는경우,
            flag = true;
            dfs(i);
        }
    }
    if (!flag) {
    	leafnode++;
    	// cout << "leaf, " << vertex << endl;
    }
}
 
int main(){
    cin >> vertex_num;

    for (int i = 0; i < vertex_num; i++){
        cin >> arr[i];
    
    }

    cin >> remove_vertex;
    if(arr[remove_vertex] == -1) {
    	cout << 0 << endl;
    	return 0;
    }
    arr[remove_vertex] = -2;
    int tmp;
    // bool zeroflag = false;
	for (int i = 0; i < vertex_num; i++) {
		// if (arr[i] != -1){
  //           zeroflag = true;
  //           break;
  //       }
	    if (arr[i] != -2 && !visited[i] ) {
	        dfs(i);
	        break;
	    }
	}
	
	
    // if (zeroflag){
    //     dfs(0);
    // }
    
    cout << leafnode << endl;
    return 0;
}