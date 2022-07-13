#include <iostream>

using namespace std;
//Array implementation of the stack
class stackedArray{
private:
    int N = 0;
    string* S;
public:
    stackedArray(int capacity):N(capacity){
        int *S = new int[capacity]();
    }
    bool isEmpty();
    void push(string item);//add an item to the stack
    string pop();//remove an item from the stack
    void resize(int capacity);//resize the array when the stack is full
    ~stackedArray();

};

bool stackedArray::isEmpty() {
    return N == 0;
}

void stackedArray::push(string item) {
    if (N == S->length()) resize(2*S->length());
    S[N++] = item;
}

string stackedArray::pop() {
    string item = S[--N];
    //S[N] = NULL;
    if(N > 0 && N==S->length()/4) resize(S->length()/2);
    return item;
}

void stackedArray::resize(int capacity) {
    string* copy = new string [capacity]();
    for (int i = 0; i < N; ++i) {
      copy[i] = S[i];
      S = copy;
    }
}

int main() {
    int m;
    string S;
    cout << "Enter the capacity";
    cin >> m;
    stackedArray fix(m);
    while (getline(cin,S)){
        if (S =="-")cout << fix.pop() <<endl;
        else fix.push(S);
    }
    return 0;
}
