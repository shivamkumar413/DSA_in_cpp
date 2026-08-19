class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<list<int>> graph;
        graph.resize(numCourses,list<int>() );

        for(int i = 0; i < prerequisites.size(); i++){
            int src = prerequisites[i][1];
            int dest = prerequisites[i][0];
            graph[src].push_back(dest);
            indegree[dest]++;
        }

        queue<int> qu;
        unordered_set<int> visited;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                qu.push(i);
                visited.insert(i);
            }
        }

        while(!qu.empty()){
            int node = qu.front();
            qu.pop();

            for(auto neighbor : graph[node]){
                if(!visited.count(neighbor)){
                    indegree[neighbor]--;
                    if(indegree[neighbor] == 0){
                        qu.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
        }

        return (visited.size() == numCourses) ? true : false;
    }
};