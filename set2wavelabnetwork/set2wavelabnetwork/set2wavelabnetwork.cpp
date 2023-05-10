//only function


    int nodemintime(vector<vector<int>>& times, int n, int k) {
        vector <vector <pair <int, int> > > adj(n + 1);
        for (auto x : times)
            adj[x[0]].push_back(make_pair(x[1], x[2]));

        priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
        

        vector <int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push(make_pair(0, k));
       

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto x : adj[node]) {
                if (dist[x.first] > dist[node] + x.second) {
                    dist[x.first] = dist[node] + x.second;
                    pq.push(make_pair(dist[x.first], x.first));
                }
            }
        }

        int ans = -1;
        for (int i = 1; i <= n; i++)
            ans = max(ans, dist[i]);

        if (ans == INT_MAX)
            return -1;
        return ans;
    }
    