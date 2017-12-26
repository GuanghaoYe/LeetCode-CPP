class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node==NULL) return NULL;
        unordered_set<int> s;
		unordered_map<int,UndirectedGraphNode*> mem;
		queue<pair<UndirectedGraphNode*,UndirectedGraphNode*> > q;
        
		UndirectedGraphNode *  ret=(new UndirectedGraphNode(node->label));
		s.insert(node->label);
		mem[node->label] = ret;
		for(auto i: node->neighbors) {
			UndirectedGraphNode * new_node=(mem.find(i->label)!=mem.end())?
				mem[i->label]
				:(new UndirectedGraphNode(i->label));
			mem[i->label]=new_node;
			ret->neighbors.push_back(new_node);
			if(s.find(i->label)==s.end()) {
				q.push(make_pair(new_node,i));
				s.insert(i->label);
			}
		}
		while(q.size()) {
			pair<UndirectedGraphNode*,UndirectedGraphNode*> cur=q.front();
			q.pop();
			if(s.find(cur.first->label)!=s.end())
				continue;
			s.insert(cur.first->label);
			for(auto i:cur.second->neighbors) {
				UndirectedGraphNode * new_node=(mem.find(i->label)!=mem.end())?
					mem[i->label]
					:(new UndirectedGraphNode(i->label));
				mem[i->label]=new_node;
				cur.first->neighbors.push_back(new_node);

				if(s.find(i->label)==s.end()) {
					q.push(make_pair(new_node,i));
					s.insert(i->label);
				}
			}
		}
		return ret;
	}
};
