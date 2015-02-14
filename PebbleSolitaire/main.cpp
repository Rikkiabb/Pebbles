#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

map<string, int>mem;
map<string, int>::iterator it;

int moves(string board, int i){ // rescursive function

    it = mem.find(board); // See if we have found for the string before
    
    int count = 0;
    
    if(it == mem.end()){ // If we haven't used this string before
    
        for(int i = 0; i < 23; i++){ // Count the current number of pebbles
        
            if(board[i] == 'o'){
            
                count++;
            
            }
        
        }
    
        for(; i < 23; i++){
        
            if(i < 23 && board[i] == 'o' && board[i + 1] == 'o'){ // A move is possible
    
                if(i < 22 && board[i + 2] == '-'){ // Move to right
        
                    board[i] = '-'; // Try the move
                    board[i + 1] = '-';
                    board[i + 2] = 'o';
                    count = min(count, moves(board, 0)); // Recursively find the min
                    board[i] = 'o'; // Try the board without the move
                    board[i + 1] = 'o';
                    board[i + 2] = '-';
            
                }
            
                if(i > 1 && board[i - 1] == '-'){ // move to left
            
                    board[i - 1] = 'o';
                    board[i] = '-';
                    board[i + 1] = '-';
                    count = min(count, moves(board, 0));
                    board[i - 1] = '-';
                    board[i] = 'o';
                    board[i + 1] = 'o';
            
                }
    
            }
        }
    
    } else { // We have calculated min for this string before
    
        count = it->second;
    
    }
    
    mem.insert(pair<string, int>(board, count));
    
    return count;
    
}

int main() {

    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false); // For cin with string
    
    int n = 0; // n = number of inputs
    cin >> n;
    
    for(int i = 0; i < n; i++){ // For each input
    
        string board = "";
        cin >> board;
        
        int count = moves(board, 0); // Find the minimum pebbles
        
        mem.insert(pair<string, int>(board, count)); // Insert into map for original string
        
        cout << count << endl;

        
    }
    
    return 0;
    
}
