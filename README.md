#include <iostream>
#include <stack>
using namespace std;

int main() {
  int h=0, n, m, a=0;
  stack<int> s;

  cin>>n;//n 받고 
  for(int i=0; i<n; i++)
  {
    cin>>m;//m 받고 
    s.push(m); // m을 메모리에 넣는다
  }
  while(s.size())//스택 사이즈 까지 돌림
  {
    if(h<s.top())//ㅅ스택에서 처음이 아닌 끝에 있는 원소 반환
    {            // 해서 비교후 새로운 스택이 더크면 h를 바꾸고
      h=s.top();// a값 증가 시킨다.
      a++;
    }
    s.pop();//top에 있는 원소 삭제 시키기 
  }
  cout<<a;
}
