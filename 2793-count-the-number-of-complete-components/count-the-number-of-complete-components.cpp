class Solution {
public:
vector<int> parent;
vector<int> rank;
int find(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}
void Union(int x,int y){
    int xPar = find(x);
    int yPar = find(y);
    if(rank[xPar] > rank[yPar]){
        parent[yPar] = xPar;
    }else if(rank[yPar] > rank[xPar]){
        parent[xPar] = yPar;
    }else{
        parent[xPar] = yPar;
        rank[yPar]++;
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
        for(auto &it : edges){
            Union(it[0],it[1]);
        }
        unordered_map<int,int> countNode;
        unordered_map<int,int> countEdge;
        for(int i = 0;i<n;i++){
            int it = find(i);
            countNode[it]++;
        }
        for(auto &it : edges){
            int edge = find(it[0]);
            countEdge[edge]++;
        }
        int components = 0;
        for(auto &it : countNode){
            int nodes = it.second;
            int edge = countEdge[it.first];
            if(edge == nodes * (nodes-1)/2){
                components++;
            } 
        }
        return components;

    }
};