class Solution {
public:
    void helper(vector<vector<int>> &image,int i,int j,int newColor,int color){
        if(i<0 || j<0 || i>image.size()-1|| j>image[0].size()-1){
            return;
        }
        
        if(image[i][j]!=color){
            return;
        }
        
        image[i][j]=newColor;
        helper(image,i+1,j,newColor,color);
        helper(image,i-1,j,newColor,color);
        helper(image,i,j-1,newColor,color);
        helper(image,i,j+1,newColor,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(image.size()==0){
            return image;
        }
        if(image[0].size()==0){
            return image;
        }
        
        int color=image[sr][sc];
        if(color==newColor){
            return image;
        }
        helper(image,sr,sc,newColor,color);
        return image;
    }
};