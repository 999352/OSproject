// Banker's Algorithm 
#include <iostream> 
using namespace std; 

int main() 
{ 
	// P0, P1, P2, P3, P4 are the Process names here 
    
	int n,m;
	n = 5; // Number of processes 
	m = 3; // Number of resources 
	int allocated[5][3] = { { 0, 1, 0 }, // P0 // allocatedation Matrix 
						{ 2, 0, 0 }, // P1 
						{ 3, 0, 2 }, // P2 
						{ 2, 1, 1 }, // P3 
						{ 0, 0, 2 } }; // P4 

	int maximum[5][3] = { { 7, 5, 3 }, // P0 // maximum Matrix 
					{ 3, 2, 2 }, // P1 
					{ 9, 0, 2 }, // P2 
					{ 2, 2, 2 }, // P3 
					{ 4, 3, 3 } }; // P4 

	int available[3] = { 3, 3, 2 }; // availableable Resources 

	int f[n], safe_sequence[n], ind = 0; 
	for (int k = 0; k < n; k++) { 
		f[k] = 0; 
	} 
	int need[n][m]; 
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) 
			need[i][j] = maximum[i][j] - allocated[i][j]; 
	} 

	for (int k = 0; k < 5; k++) { 
		for (int i = 0; i < n; i++) { 
			if (f[i] == 0) { 

				int flag = 0; 
				for (int j = 0; j < m; j++) { 
					if (need[i][j] > available[j]){ 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0) { 
					safe_sequence[ind++] = i; 
					for (int k = 0; k < m; k++) 
						available[k] += allocated[i][k]; 
					f[i] = 1; 
				} 
			} 
		} 
	} 

	cout << "Following is the SAFE Sequence" << endl; 
	for (int i = 0; i < n - 1; i++) 
		cout << " P" << safe_sequence[i] << " ->"; 
	cout << " P" << safe_sequence[n - 1] <<endl; 

	return (0); 
} 
