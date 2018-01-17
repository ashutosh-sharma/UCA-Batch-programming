/* It will return the length of the logest valid parenthesis in number of strings entered by the user
   Implementation is done through stack.
   
   Test Case:
   
  Input: )()())
  Output : 4
 
*/

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int max(int x, int y){
    return (x > y) ? x : y; 
}

int main() {
	int t;
	
	cin>>t;
	
	while(t--){
	    stack <int> s;
	    s.push(-1);
	    
	    string st;
	    cin>>st;
	    int n = st.length(), result = 0;
	    
    	for(int i = 0; i < n; i++){
	        if(st[i] == '(')
	            s.push(i);
	        else{
	            s.pop();
	        
	            if(!s.empty())
	                 result = max(result , i - s.top());
	            else{
	                s.push(i);
	            }
	        
	        }
	        
	    }
	    
	cout<<result<<endl;
	}
	return 0;
}
