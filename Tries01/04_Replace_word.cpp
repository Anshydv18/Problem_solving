struct Node{
    Node* list[26];
    bool flag = false;

    bool containsKey(char ch){
        return list[ch-'a']!=NULL;
    }

    void put(char ch,Node* node){
        list[ch-'a']=node;
    }

    Node* get(char ch){
        return list[ch-'a'];
    }

    void setEnd(){
        flag=true;
    }
    bool getEnd(){
        return flag;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Node* root = new Node();
        for(auto x:dictionary){
            Node* node = root;
            for(int i=0;i<x.length();i++){
                if(!node->containsKey(x[i])){
                    node->put(x[i],new Node());
                }
                node=node->get(x[i]);
            }
            node->setEnd();
        }

        string res="";
        stringstream ss(sentence);
        string word;
        while(getline(ss,word,' ')){
            Node* node = root;
            string temp="";
            bool done=false;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    break;
                }
                if(node->getEnd()){done=true; res+=(temp+" "); break;}
                temp+=word[i];
                node=node->get(word[i]);
            }
            if(done) continue;
            if(node->getEnd()) res+=(temp+" ");
            else res+=(word+" ");
        }
        res.pop_back();
        return res;
    }
};