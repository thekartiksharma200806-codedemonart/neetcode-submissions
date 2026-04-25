class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
         for(string s:strs){

            res+= to_string(s.length())+'#'+s;

         }
         return res;

    }

    vector<string> decode(string s) {

        int pointer=0;

        vector<string>res;

        while(pointer!=s.length()){

            int range=pointer;

            while(s[range]!='#'){
                range++;
            }

            int len= stoi(s.substr(pointer,range-pointer));

            res.push_back(s.substr(range+1,len));
            pointer= range + 1 + len;
        

        }
        return res;
    }
      

};
