#include "pch.h"

#ifndef GRAPH_H
#define GRAPH_H

#include "vNode.cpp"
#include "eNode.cpp"
#include "adjListNode.cpp"

#ifndef MAX_V_NUM
#define MAX_V_NUM 40

#endif

class graph
{
public:
	graph();
	graph(const char *fileName);
	int init_list(void);
	int dfsTraversal_l();
	int dfsTraversal_l(vNode *V);
	int dfs_l(vNode *V);
	int bfsTraversal_l();
	int bfsTraversal_l(vNode *V);
	int bfs_l(vNode *V);
	int dfsTraversal_t_l();
	int dfsTraversal_t_l(vNode *V);
	int dfs_t_l(vNode *V, std::list<vNode *>&Lv, std::list<eNode *>&Le);
	int bfsTraversal_t_l();
	int bfsTraversal_t_l(vNode *V);
	int bfs_t_l(vNode *V, std::list<vNode *>&Lv, std::list<eNode *>&Le);
	int get_Enum_l();
	int Prim_l(vNode *V);
	int Kruskal_l(void);
	int Dijkstra_l(vNode *V);
	int Floyd_l(void);
	int AOV_l(void);
	int AOE_l(void);
	int dfsTraversal_m();
	int dfs_m(vNode *V);
	bool empty(void);
	bool error(void);
	vNode *getNode_for_data(const char n_data);
	vNode *getNode_for_ID(const int id);
	int clear_vFlag();
	int clear_eFlag();
	int clear_eFlag_l();
	int coverGraph(const char *fileName);
	int delete_G(void);
	~graph();
private:
	bool G_empty;
	bool G_error;
	bool G_U;
	bool G_N;
	int G_type;
	int G_Vnum;
	int G_Enum;
	vNode *G_vList[MAX_V_NUM];
	std::list<eNode *> G_eList;
	eNode *G_adjMat[MAX_V_NUM][MAX_V_NUM];
	std::list<adjListNode *> G_adjList;
	std::list<adjListNode *> G_i_adjList;
};

#endif
