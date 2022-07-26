//leetcode problem no 8
int myAtoi(string s) {
       long int i=0,ans=0,neg=1;
        while(i<s.size() and s[i]==' ')
            i+=1;
        if(i<s.size() and s[i]=='-'){
            neg=-1;i++;}
        else if(i<s.size() and s[i]=='+')
            i++;
        while(i<s.size() and (s[i]>='0' and s[i]<='9'))
        {
            
            ans=ans*10+(s[i]-'0');
            if(neg*ans<=INT_MIN)return INT_MIN;
            else if(neg*ans>=INT_MAX)return INT_MAX;
            i++;
        }
        
        return neg*ans;
    }