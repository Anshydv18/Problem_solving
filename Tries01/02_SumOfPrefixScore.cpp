struct Node{
    Node* links[26];
    int cnt=0;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void set(char ch,Node* node){
        links[ch-'a']=node;
       
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setCnt(){
        cnt++;
    } 
    int getCnt(){
        return cnt;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int>ds;
        Node*  root = new Node();
        for(auto x:words){
            Node* node = root;
            for(int i=0;i<x.length();i++){
                if(!node->containsKey(x[i])){
                    node->set(x[i],new Node());
                }
               
                node=node->get(x[i]);
                 node->setCnt();
            }
        }
        for(auto x:words){
            int cnt=0;
            Node* node = root;
            for(int i=0;i<x.length();i++){
                cnt+=node->getCnt();
                node=node->get(x[i]);
            }
            cnt+=node->getCnt();
            ds.push_back(cnt);
        }
        return ds;
    }
};