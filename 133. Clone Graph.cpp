/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
/*
A C++ program to Clone an Undirected Graph
#include<bits/stdc++.h>
using namespace std;
 
struct GraphNode
{
    int val;
 
    //A neighbour vector which contains addresses to all the neighbours of a GraphNode
    vector<GraphNode*> neighbors;
};
*/

/**
The idea is to do a BFS traversal of the graph and while visiting a node make a clone node of it 
(a copy of original node). If a node is encountered which is already visited then it already has a clone node.

How to keep track of the visited/cloned nodes?
A HashMap/Map is required in order to maintain all the nodes which have already been created.
Key stores: Reference/Address of original Node
Value stores: Reference/Address of cloned Node

A copy of all the graph nodes has been made, how to connect clone nodes?
While visiting the neighboring vertices of a node front get the corresponding cloned node for front, 
let’s call that newNode, now visit all the neighboring nodes for front and for each neighbor find the corresponding 
clone node(if not found create one) and then push into the neighboring vector of newNode node.

How to verify if the cloned graph is a correct?
Do a BFS traversal before and after the cloning of graph. In BFS traversal display the value of a node along with its
address/reference.
Compare the order in which nodes are displayed, if the values are same but the address/reference is different for both
the traversals than the cloned graph is correct.
**/

class Solution{
public:
    GraphNode* cloneGraph(GraphNode *src){
        if(!src) return NULL;
        unordered_map<int, GraphNode*> m;
        return clone(src, m);
    }
    GraphNode* clone(GraphNode *src, unordered_map<int,GraphNode*> &m){
        if(!src) return NULL;
        else if(m.count(src->label)){
            return m[src->label];
        }
        else{
            GraphNode *newNode = new GraphNode(src->label);
            m[src->label] = newNode;
            for (int i=0; i<src->neighbors.size(); i++){
                GraphNode *nbrsOfNbr = clone(src->neighbors[i], m);
                (newNode->neighbors).push_back(nbrsOfNbr);
            }
            return newNode;
        }
    }
};



/* 用一个hash table记录原图节点和复制图节点间的对应关系，以防止重复建立节点。
   和那题的不同在于遍历原图相对比linked list的情况复杂一点。可以用BFS或DFS来遍历原图。
   而hash table本身除了记录对应关系外，还有记录原图中每个节点是否已经被visit的功能。*/
class Solution {
public:
    GraphNode *cloneGraph(GraphNode *src) {
        if(!src) return NULL;
        GraphNode *p1 = src;
        GraphNode *p2 = new GraphNode(src->label);
        unordered_map<GraphNode*, GraphNode*> m;
        queue<GraphNode*> q;        
        q.push(src);
        m[src] = p2;
        
        while(!q.empty()) {
            p1 = q.front();
            p2 = m[p1];
            q.pop();
            for(int i=0; i<p1->neighbors.size(); i++) {
                GraphNode *nb = p1->neighbors[i];       
                if(m.count(nb)) 
                    p2->neighbors.push_back(m[nb]);
                else {
                    GraphNode *temp = new GraphNode(nb->label);
                    p2->neighbors.push_back(temp);
                    m[nb] = temp;
                    q.push(nb);
                }
            }
        }
        return m[src];
    }
};
