class Solution {
public:
    bool find(int m,int n,vector<vector<char>>& board,int i,int j,int indx,string &word){
        ;
        if(indx==word.size()) return true;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='$') return false;
        if(board[i][j] != word[indx]) return false;
        
        char temp = board[i][j];
        board[i][j] = '$';

        bool found = find(m,n,board,i+1,j,indx+1,word) || find(m,n,board,i-1,j,indx+1,word) || find(m,n,board,i,j+1,indx+1,word) || find(m,n,board,i,j-1,indx+1,word);      
        board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && find(m,n,board,i,j,0,word)) return true;
            }
        }
        return false;
        
    }
};