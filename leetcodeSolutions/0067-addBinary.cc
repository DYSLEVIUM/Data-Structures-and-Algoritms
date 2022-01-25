class Solution {
public:
    string addBinary(string a, string b) {
      int carry = 0;
      int a_ptr = a.length()-1;
      int b_ptr = b.length()-1;

      string ans = "";
      while(a_ptr>=0 && b_ptr>=0){
        if(a[a_ptr]=='0' && b[b_ptr]=='0'){
          ans+=to_string(carry);
          carry=0;
        }else if(a[a_ptr]=='1' && b[b_ptr]=='1'){
          if(carry)ans+='1';
          else{
            ans+='0';
            carry=1;
          }
        }else{
          if(carry){
            ans+='0';
            carry = 1;            
          }else
            ans+='1';
        }
        
        --a_ptr, --b_ptr;
      }
      
      while(a_ptr>=0){
        ans+=to_string((a[a_ptr]-'0')^carry);
        carry = (a[a_ptr]-'0')&carry;
        --a_ptr;
      }
      
      while(b_ptr>=0){
        ans+=to_string((b[b_ptr]-'0')^carry);
        carry = (b[b_ptr]-'0')&carry;
        --b_ptr;
      }
      
      if(carry) ans+='1';
      
      reverse(ans.begin(), ans.end());
      return ans;
    }
};
