// class Solution {
// public:
//     string makeGood(string s) {
//         int i=0;
       
//         while(i<s.length()-1)
//         {
//             if(abs(s[i+1]-s[i])==32)
//             {
//                 s.erase(s.begin()+i);
//                 s.erase(s.begin()+i);
//                 if(i!=0)
//                    i--;
//             }
//             else
//                 i++;
//         }
//         return s;
//     }
// };

class Solution {
public:
    string makeGood(string s) {
        int i=0;
        while(i<s.length()-1 && s.size()>0)
        {
            if(abs(s[i+1]-s[i]) == 32)
            {
                s.erase(s.begin()+i);
                s.erase(s.begin()+i);
                if(i!=0)
                   i--;
            }
            else
            {     
                i++;
            }
        }
        return s;
    }
};