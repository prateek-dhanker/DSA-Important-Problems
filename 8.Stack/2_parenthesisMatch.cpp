bool isMatch(stack<char> &st , char ch){
  if (ch == ')') {
    if (st.top() == '(')
      return true;
    return false;
  } else if (ch == '}') {
    if (st.top() == '{')
      return true;
    return false;
  }
    if(ch == ']'){
        if(st.top() == '[')
            return true;
        return false;
    }
    return false;
}
bool isValidParenthesis(string s)
{
    stack<char> st;
    // Write your code here.
    for(int i=0; i<s.length(); i++){
      if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        st.push(s[i]);
      else if (s[i] == ')' || s[i] == '}' || s[i] == ']'){
          if(st.empty())
            return false;
          if(isMatch(st , s[i]))
            st.pop();
          else return false;
      }
    }
    if(st.empty())
        return true;
    return false;
}