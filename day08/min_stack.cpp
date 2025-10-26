#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <stack>
using namespace std;

class MinStack {
    private :
    std::stack<int> stack;
    std::stack<int> minStack;
    public:
        MinStack() {
           
        }
        
        void push(int val) {
            stack.push(val);
            if(!minStack.empty())
            {
                val = min(val,minStack.top());
            }
            minStack.push(val);
        }
        
        void pop() {
            if(stack.size() ==0)
                return;
            
            stack.pop();
            minStack.pop();
        }
        
        int top() {
            return stack.top();
        }
        
        int getMin() {
            return minStack.top();
        }
       
    };
    
int main()
{
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
   std::cout<< minStack->getMin()<<'\n'; // return -3
    minStack->pop();
   std::cout<< minStack->top()<<'\n';    // return 0
   std::cout<< minStack->getMin()<<'\n'; // return -2


}