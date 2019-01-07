#include "pch.h"

#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "graph.h"

graph::graph()
{
	this->G_empty = true;
}

graph::graph(const char *fileName)
{
	int i;
	int j;
	i = 0;
	while (i < MAX_V_NUM)
	{
		this->G_vList[i] = NULL;
		j = 0;
		while (j < MAX_V_NUM)
		{
			this->G_adjMat[i][j] = NULL;
			j++;
		}
		i++;
	}
	
	this->coverGraph(fileName);
}

int graph::init_list(void)
{
	int i;
	adjListNode *pa = NULL;
	std::list<eNode *>::iterator i_e;
	std::list<adjListNode *>::iterator i_a;
	std::list<adjListNode *>::iterator i_i_a;
	i = 0;
	while (i < this->G_Vnum)
	{
		pa = new adjListNode(this->G_vList[i]);
		if (pa != NULL)
		{
			this->G_adjList.push_back(pa);
		}
		pa = new adjListNode(this->G_vList[i]);
		if (pa != NULL)
		{
			this->G_i_adjList.push_back(pa);
		}
		else
		{
			return -1;
		}
		i++;
	}
	i_e = this->G_eList.begin();
	while (i_e != this->G_eList.end())
	{
		i_a = this->G_adjList.begin();
		while (i_a != this->G_adjList.end())
		{
			if ((*i_a)->v()->data() == (*i_e)->begin()->data())
			{
				(*i_a)->add_adj_e(*i_e);
				break;
			}
			i_a++;
		}
		i_i_a = this->G_i_adjList.begin();
		while (i_i_a != this->G_i_adjList.end())
		{
			if ((*i_i_a)->v()->data() == (*i_e)->end()->data())
			{
				(*i_i_a)->add_adj_e(*i_e);
				break;
			}
			i_i_a++;
		}
		if (i_a == this->G_adjList.end() || i_i_a == this->G_i_adjList.end())
		{
			return -1;
		}
		i_e++;
	}
	return 0;
}

int graph::dfsTraversal_l()
{
	int i;
	std::cout << "深度优先遍历序列为:" << std::endl;
	this->clear_vFlag();
	i = 0;
	while (i < this->G_Vnum)
	{
		if (!this->G_vList[i]->flag1())
		{
			dfs_l(this->G_vList[i]);
		}
		i++;
	}
	std::cout << std::endl;
	return 0;
}

int graph::dfsTraversal_l(vNode * V)
{
	int i;
	if (V == NULL)
	{
		std::cout << "结点不存在!" << std::endl;
		return -1;
	}
	std::cout << "深度优先遍历序列为:" << std::endl;
	this->clear_vFlag();
	dfs_l(V);
	i = 0;
	while (i < this->G_Vnum)
	{
		if (!this->G_vList[i]->flag1())
		{
			dfs_l(this->G_vList[i]);
		}
		i++;
	}
	std::cout << std::endl;
	return 0;
}

int graph::dfs_l(vNode *V)
{
	std::list<adjListNode *>::iterator i_a;
	eNode *p_e;
	if (V == NULL)
	{
		return -1;
	}
	if (V->flag1())
	{
		return 0;
	}
	std::cout << V->data() << ' ';
	V->T_flag1();
	i_a = this->G_adjList.begin();
	while (i_a != this->G_adjList.end())
	{
		if ((*i_a)->v() == V)
		{
			break;
		}
		i_a++;
	}
	if (i_a == this->G_adjList.end())
	{
		return -1;
	}
	p_e = (*i_a)->get_first_adj_e();
	while (p_e != NULL)
	{
		//std::cout << p_e->begin()->data() << ' ' << p_e->end()->data() << std::endl;
		dfs_l(p_e->end());
		p_e = (*i_a)->get_next_adj_e(p_e);
	}
	return 0;
}

int graph::bfsTraversal_l()
{
	int i;
	std::cout << "广度优先遍历序列为:" << std::endl;
	this->clear_vFlag();
	i = 0;
	while (i < this->G_Vnum)
	{
		if (!this->G_vList[i]->flag1())
		{
			bfs_l(this->G_vList[i]);
		}
		i++;
	}
	std::cout << std::endl;
	return 0;
}

int graph::bfsTraversal_l(vNode * V)
{
	int i;
	if (V == NULL)
	{
		std::cout << "结点不存在!" << std::endl;
		return -1;
	}
	std::cout << "广度优先遍历序列为:" << std::endl;
	this->clear_vFlag();
	bfs_l(V);
	i = 0;
	while (i < this->G_Vnum)
	{
		if (!this->G_vList[i]->flag1())
		{
			bfs_l(this->G_vList[i]);
		}
		i++;
	}
	std::cout << std::endl;
	return 0;
}

int graph::bfs_l(vNode * V)
{
	vNode *p;
	std::queue<vNode *> Q;
	std::list<adjListNode *>::iterator i_a;
	std::list<eNode *>::iterator i_e;
	if (V == NULL)
	{
		return -1;
	}
	Q.push(V);
	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();
		if (p->flag1())
		{
			continue;
		}
		std::cout << p->data() << ' ';
		p->T_flag1();
		i_a = this->G_adjList.begin();
		while (i_a != this->G_adjList.end())
		{
			if ((*i_a)->v()->data() == p->data())
			{
				break;
			}
			i_a++;
		}
		if (i_a == this->G_adjList.end())
		{
			return -1;
		}
		i_e = (*i_a)->eList().begin();
		while (i_e != (*i_a)->eList().end())
		{
			if (!(*i_e)->end()->flag1())
			{
				Q.push((*i_e)->end());
			}
			i_e++;
		}
	}
	return 0;
}

int graph::dfsTraversal_t_l()
{
	int i;
	std::list<vNode*> Lv;
	std::list<eNode*> Le;
	std::list<vNode*>::iterator iv;
	std::list<eNode*>::iterator ie;
	std::cout << "深度优先遍历序列为:" << std::endl;
	this->clear_vFlag();
	i = 0;
	while (i < this->G_Vnum)
	{
		if (!this->G_vList[i]->flag1())
		{
			dfs_t_l(this->G_vList[i], Lv, Le);
		}
		i++;
	}
	std::cout << std::endl;
	std::cout << "深度优先遍历生成树(森林)如下:" << std::endl;
	std::cout << "点集:" << std::endl;
	iv = Lv.begin();
	while (iv != Lv.end())
	{
		std::cout << (*iv)->data() << ' ';
		iv++;
	}
	std::cout << std::endl;
	std::cout << "边集:" << std::endl;
	ie = Le.begin();
	while (ie != Le.end())
	{
		std::cout << (*ie)->begin()->data();
		if (G_U)
		{
			std::cout << '-';
		}
		else
		{
			std::cout << "->";
		}
		std::cout << (*ie)->end()->data() << std::endl;
		ie++;
	}
	std::cout << std::endl;
	return 0;
}

int graph::dfsTraversal_t_l(vNode * V)
{
	int i;
	std::list<vNode*> Lv;
	std::list<eNode*> Le;
	std::list<vNode*>::iterator iv;
	std::list<eNode*>::iterator ie;
	if (V == NULL)
	{
		std::cout << "结点不存在!" << std::endl;
		return -1;
	}
	std::cout << "深度优先遍历序列为:" << std::endl;
	this->clear_vFlag();
	dfs_t_l(V, Lv, Le);
	i = 0;
	while (i < this->G_Vnum)
	{
		if (!this->G_vList[i]->flag1())
		{
			dfs_t_l(this->G_vList[i], Lv, Le);
		}
		i++;
	}
	std::cout << std::endl;
	std::cout << "深度优先遍历生成树(森林)如下:" << std::endl;
	std::cout << "点集:" << std::endl;
	iv = Lv.begin();
	while (iv != Lv.end())
	{
		std::cout << (*iv)->data() << ' ';
		iv++;
	}
	std::cout << std::endl;
	std::cout << "边集:" << std::endl;
	ie = Le.begin();
	while (ie != Le.end())
	{
		std::cout << (*ie)->begin()->data();
		if (G_U)
		{
			std::cout << '-';
		}
		else
		{
			std::cout << "->";
		}
		std::cout << (*ie)->end()->data() << std::endl;
		ie++;
	}
	std::cout << std::endl;
	return 0;
}

int graph::dfs_t_l(vNode * V, std::list<vNode*>& Lv, std::list<eNode*>& Le)
{
	std::list<adjListNode *>::iterator i_a;
	eNode *p_e;
	if (V == NULL)
	{
		return -1;
	}
	if (V->flag1())
	{
		Le.pop_back();
		return 0;
	}
	std::cout << V->data() << ' ';
	V->T_flag1();
	Lv.push_back(V);
	i_a = this->G_adjList.begin();
	while (i_a != this->G_adjList.end())
	{
		if ((*i_a)->v() == V)
		{
			break;
		}
		i_a++;
	}
	if (i_a == this->G_adjList.end())
	{
		return -1;
	}
	p_e = (*i_a)->get_first_adj_e();
	while (p_e != NULL)
	{
		//std::cout << p_e->begin()->data() << ' ' << p_e->end()->data() << std::endl;
		Le.push_back(p_e);
		dfs_t_l(p_e->end(), Lv, Le);
		p_e = (*i_a)->get_next_adj_e(p_e);
	}
	return 0;
}

int graph::bfsTraversal_t_l()
{
	int i;
	std::list<vNode*> Lv;
	std::list<eNode*> Le;
	std::list<vNode*>::iterator iv;
	std::list<eNode*>::iterator ie;
	std::cout << "广度优先遍历序列为:" << std::endl;
	this->clear_vFlag();
	i = 0;
	while (i < this->G_Vnum)
	{
		if (!this->G_vList[i]->flag1())
		{
			bfs_t_l(this->G_vList[i], Lv, Le);
		}
		i++;
	}
	std::cout << std::endl;
	std::cout << "广度优先遍历生成树(森林)如下:" << std::endl;
	std::cout << "点集:" << std::endl;
	iv = Lv.begin();
	while (iv != Lv.end())
	{
		std::cout << (*iv)->data() << ' ';
		iv++;
	}
	std::cout << std::endl;
	std::cout << "边集:" << std::endl;
	ie = Le.begin();
	while (ie != Le.end())
	{
		std::cout << (*ie)->begin()->data();
		if (G_U)
		{
			std::cout << '-';
		}
		else
		{
			std::cout << "->";
		}
		std::cout << (*ie)->end()->data() << std::endl;
		ie++;
	}
	std::cout << std::endl;
	return 0;
}

int graph::bfsTraversal_t_l(vNode * V)
{
	int i;
	std::list<vNode*> Lv;
	std::list<eNode*> Le;
	std::list<vNode*>::iterator iv;
	std::list<eNode*>::iterator ie;
	if (V == NULL)
	{
		std::cout << "结点不存在!" << std::endl;
		return -1;
	}
	std::cout << "广度优先遍历序列为:" << std::endl;
	this->clear_vFlag();
	bfs_t_l(V, Lv, Le);
	i = 0;
	while (i < this->G_Vnum)
	{
		if (!this->G_vList[i]->flag1())
		{
			bfs_t_l(this->G_vList[i], Lv, Le);
		}
		i++;
	}
	std::cout << std::endl;
	std::cout << "广度优先遍历生成树(森林)如下:" << std::endl;
	std::cout << "点集:" << std::endl;
	iv = Lv.begin();
	while (iv != Lv.end())
	{
		std::cout << (*iv)->data() << ' ';
		iv++;
	}
	std::cout << std::endl;
	std::cout << "边集:" << std::endl;
	ie = Le.begin();
	while (ie != Le.end())
	{
		std::cout << (*ie)->begin()->data();
		if (G_U)
		{
			std::cout << '-';
		}
		else
		{
			std::cout << "->";
		}
		std::cout << (*ie)->end()->data() << std::endl;
		ie++;
	}
	std::cout << std::endl;
	return 0;
}

int graph::bfs_t_l(vNode * V, std::list<vNode*>& Lv, std::list<eNode*>& Le)
{
	vNode *p;
	std::queue<vNode *> Q;
	std::list<adjListNode *>::iterator i_a;
	std::list<eNode *>::iterator i_e;
	if (V == NULL || V->flag1())
	{
		return -1;
	}
	Q.push(V);
	V->T_flag1();
	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();
		std::cout << p->data() << ' ';
		Lv.push_back(p);
		i_a = this->G_adjList.begin();
		while (i_a != this->G_adjList.end())
		{
			if ((*i_a)->v()->data() == p->data())
			{
				break;
			}
			i_a++;
		}
		if (i_a == this->G_adjList.end())
		{
			return -1;
		}
		i_e = (*i_a)->eList().begin();
		while (i_e != (*i_a)->eList().end())
		{
			if (!(*i_e)->end()->flag1())
			{
				Q.push((*i_e)->end());
				(*i_e)->end()->T_flag1();
				Le.push_back(*i_e);
			}
			i_e++;
		}
	}
	return 0;
}

int graph::get_Enum_l()
{
	int e_num = 0;
	std::list<adjListNode *>::iterator i_a = this->G_adjList.begin();
	while (i_a != this->G_adjList.end())
	{
		e_num += (*i_a)->eList().size();
		i_a++;
	}
	if (G_U)
	{
		e_num /= 2;
	}
	return e_num;
}

int graph::Prim_l(vNode * V)
{
	int i = 0;
	int num = 1;
	vNode *pv = NULL;
	eNode *pe = NULL;
	std::list<vNode *> V_l;
	std::list<vNode *>::iterator iv;
	std::list<eNode *> E_l;
	std::list<eNode *> E_l2;
	std::list<eNode *>::iterator ie;
	std::list<adjListNode *>::iterator ia;
	if (V == NULL)
	{
		return -1;
	}
	this->clear_vFlag();
	V_l.push_back(V);
	while (E_l.size() < this->G_Vnum - 1)
	{
		pv = V_l.back();
		pv->T_flag1();
		ie = E_l2.begin();
		while (ie != E_l2.end())
		{
			if ((*ie)->end()->flag1())
			{
				ie = E_l2.erase(ie);
			}
			else
			{
				ie++;
			}
		}
		ia = this->G_adjList.begin();
		while (ia != this->G_adjList.end())
		{
			if ((*ia)->v()->data() == pv->data())
			{
				break;
			}
			ia++;
		}
		if (ia == this->G_adjList.end())
		{
			return -1;
		}
		ie = (*ia)->eList().begin();
		while (ie != (*ia)->eList().end())
		{
			if (!(*ie)->end()->flag1())
			{
				E_l2.push_back(*ie);
			}
			ie++;
		}
		if (!E_l2.empty())
		{
			ie = E_l2.begin();
			pe = (*ie);
			while (ie != E_l2.end())
			{
				if ((*ie)->len() < pe->len())
				{
					pe = (*ie);
				}
				ie++;
			}
		}
		else
		{
			break;
		}
		E_l.push_back(pe);
		V_l.push_back(pe->end());
	}
	std::cout << "Prim算法:" << std::endl;
	std::cout << "起点:" << V->data() << std::endl;
	std::cout << "最小生成树如下:" << std::endl;
	std::cout << "点集:" << std::endl;
	iv = V_l.begin();
	while (iv != V_l.end())
	{
		std::cout << (*iv)->data() << ' ';
		iv++;
	}
	std::cout << std::endl;
	std::cout << "边集:" << std::endl;
	if (E_l.empty())
	{
		std::cout << "null!" << std::endl;
	}
	else
	{
		ie = E_l.begin();
		while (ie != E_l.end())
		{
			if (!this->G_U)
			{
				std::cout << (*ie)->begin()->data() << "->" << (*ie)->end()->data() << ' ';
			}
			else
			{
				std::cout << (*ie)->begin()->data() << '-' << (*ie)->end()->data() << ' ';
			}
			if (this->G_N)
			{
				std::cout << "len:" << (*ie)->len();
			}
			std::cout << std::endl;
			ie++;
		}
	}
	return 0;
}

int graph::Kruskal_l(void)
{
	int i;
	int low_f;
	int high_f;
	int V_f[MAX_V_NUM];
	std::list<eNode *> E_l;
	std::list<eNode *> E_l2;
	std::list<eNode *>::iterator ie;
	std::list<eNode *>::iterator ie2;
	std::list<adjListNode *>::iterator ia = this->G_adjList.begin();
	i = 0;
	while (i < this->G_Vnum)
	{
		V_f[this->G_vList[i]->id()] = this->G_vList[i]->id();
		i++;
	}
	while (ia != this->G_adjList.end())
	{
		ie = (*ia)->eList().begin();
		while (ie != (*ia)->eList().end())
		{
			ie2 = E_l2.begin();
			while (ie2 != E_l2.end() && (*ie)->len() > (*ie2)->len())
			{
				ie2++;
			}
			E_l2.insert(ie2, *ie);
			ie++;
		}
		ia++;
	}
	ie2 = E_l2.begin();
	while (ie2 != E_l2.end() && E_l.size() < this->G_Vnum - 1)
	{
		if (V_f[(*ie2)->begin()->id()] != V_f[(*ie2)->end()->id()])
		{
			E_l.push_back(*ie2);
			if ((*ie2)->begin()->id() < (*ie2)->end()->id())
			{
				low_f = V_f[(*ie2)->begin()->id()];
				high_f = V_f[(*ie2)->end()->id()];
			}
			else
			{
				low_f = V_f[(*ie2)->end()->id()];
				high_f = V_f[(*ie2)->begin()->id()];
			}
			i = 0;
			while (i < this->G_Vnum)
			{
				if (V_f[i] == high_f)
				{
					V_f[i] = low_f;
				}
				//std::cout << V_f[i] << ' ';
				i++;
			}
			//std::cout << std::endl;
			//std::cout << "low:" << low_f << std::endl;
			//std::cout << "high:" << high_f << std::endl;
		}
		ie2++;
	}
	std::cout << "Kruskal算法:" << std::endl;
	std::cout << "最小生成树如下:" << std::endl;
	std::cout << "点集:" << std::endl;
	i = 0;
	while (i < this->G_Vnum)
	{
		std::cout << this->G_vList[i]->data() << ' ';
		//std::cout << "flag:" << V_f[i] << ' ';
		i++;
	}
	std::cout << std::endl;
	std::cout << "边集:" << std::endl;
	if (E_l.empty())
	{
		std::cout << "null!" << std::endl;
	}
	else
	{
		ie = E_l.begin();
		while (ie != E_l.end())
		{
			if (!this->G_U)
			{
				std::cout << (*ie)->begin()->data() << "->" << (*ie)->end()->data() << ' ';
			}
			else
			{
				std::cout << (*ie)->begin()->data() << '-' << (*ie)->end()->data() << ' ';
			}
			if (this->G_N)
			{
				std::cout << "len:" << (*ie)->len();
			}
			std::cout << std::endl;
			ie++;
		}
	}
	return 0;
}

int graph::Dijkstra_l(vNode * V)
{
	int i;
	int j;
	int V_pathLen[MAX_V_NUM];
	vNode *pv;
	eNode *pe;
	vNode *V_prior[MAX_V_NUM];
	std::list<eNode *>::iterator ie;
	std::list<adjListNode *>::iterator ia;
	std::stack<char> S_ch;

	if (V == NULL)
	{
		return -1;
	}

	this->clear_vFlag();

	i = 0;
	while (i < MAX_V_NUM)
	{
		V_pathLen[i] = -1;
		V_prior[i] = NULL;
		i++;
	}

	V_pathLen[V->id()] = 0;
	V->T_flag1();
	pv = V;
	do
	{
		pe = NULL;
		ia = this->G_adjList.begin();
		while (ia != this->G_adjList.end())
		{
			if ((*ia)->v()->flag1())
			{
				ie = (*ia)->eList().begin();
				while (ie != (*ia)->eList().end())
				{
					if (!(*ie)->end()->flag1())
					{
						if (pe == NULL || 
							pe->len() + V_pathLen[pe->begin()->id()] > 
							(*ie)->len() + V_pathLen[(*ie)->begin()->id()])
						{
							pe = *ie;
						}
					}
					ie++;
				}
			}
			ia++;
		}
		if (pe != NULL)
		{
			pe->end()->T_flag1();
			V_pathLen[pe->end()->id()] = V_pathLen[pe->begin()->id()] + pe->len();
			V_prior[pe->end()->id()] = pe->begin();
		}
	} while (pe != NULL);
	std::cout << "Dijkstra算法:" << std::endl;
	std::cout << "起点:" << V->data() << std::endl;
	std::cout << "从起点至其他各结点的最短路径如下:" << std::endl;
	i = 0;
	while (i < this->G_Vnum)
	{
		std::cout << V->data() << "->" << this->G_vList[i]->data() << ':';
		if (V_prior[i] != NULL)
		{
			j = i;
			while (V_prior[j] != NULL)
			{
				S_ch.push(this->getNode_for_ID(j)->data());
				j = V_prior[j]->id();
			}
			std::cout << V->data();
			while (!S_ch.empty())
			{
				std::cout << "->" << S_ch.top();
				S_ch.pop();
			}
			std::cout << " 路径长度:" << V_pathLen[i];
		}
		else if (V_pathLen[i] == 0)
		{
			std::cout << this->G_vList[i]->data();
			std::cout << " 路径长度:" << V_pathLen[i];
		}
		else
		{
			std::cout << "路径不存在!";
		}
		std::cout << std::endl;
		i++;
	}
	return 0;
}

int graph::Floyd_l(void)
{
	int i;
	int j;
	int k;
	int path_len[MAX_V_NUM][MAX_V_NUM];
	vNode *path[MAX_V_NUM][MAX_V_NUM];
	std::list<eNode *>::iterator ie;
	std::list<adjListNode *>::iterator ia;
	std::stack<char> S_ch;

	i = 0;
	while (i < this->G_Vnum)
	{
		j = 0;
		while (j < this->G_Vnum)
		{
			path[i][j] = NULL;
			if (i == j)
			{
				path_len[i][j] = 0;
			}
			else
			{
				path_len[i][j] = -1;
			}
			j++;
		}
		i++;
	}

	ia = this->G_adjList.begin();
	while (ia != this->G_adjList.end())
	{
		ie = (*ia)->eList().begin();
		while (ie != (*ia)->eList().end())
		{
			path[(*ie)->begin()->id()][(*ie)->end()->id()] = (*ie)->begin();
			path_len[(*ie)->begin()->id()][(*ie)->end()->id()] = (*ie)->len();
			ie++;
		}
		ia++;
	}

	k = 0;
	while (k < this->G_Vnum)
	{
		i = 0;
		while (i < this->G_Vnum)
		{
			j = 0;
			while (j < this->G_Vnum)
			{
				if (path[i][k] != NULL && path[k][j] != NULL && i != j)
				{
					if (path[i][j] == NULL ||
						path_len[i][k] + path_len[k][j] < path_len[i][j])
					{
						path[i][j] = this->G_vList[k];
						path_len[i][j] = path_len[i][k] + path_len[k][j];
					}
				}
				j++;
			}
			i++;
		}
		k++;
	}

	std::cout << "Floyd算法:" << std::endl;
	std::cout << "各对结点之间的最短路径如下:" << std::endl;
	i = 0;
	while (i < this->G_Vnum)
	{
		j = 0;
		while (j < this->G_Vnum)
		{
			std::cout << this->G_vList[i]->data() << "->" << this->G_vList[j]->data() << ':';
			if (path[i][j] != NULL)
			{
				k = j;
				while (path[i][k] != NULL && k != i)
				{
					S_ch.push(this->G_vList[k]->data());
					k = path[i][k]->id();
				}
				if (k != i)
				{
					std::cout << "路径不存在!";
				}
				else
				{
					std::cout << this->G_vList[i]->data();
					while (!S_ch.empty())
					{
						std::cout << "->" << S_ch.top();
						S_ch.pop();
					}
					std::cout << " 路径长度:" << path_len[i][j];
				}
			}
			else
			{
				if (i != j)
				{
					std::cout << "路径不存在!";
				}
				else
				{
					std::cout << this->G_vList[i]->data();
					std::cout << " 路径长度:" << path_len[i][j];
				}
			}
			std::cout << std::endl;
			j++;
		}
		i++;
	}


	return 0;
}

int graph::AOV_l(void)
{
	int i;
	int deg_i[MAX_V_NUM];
	std::list<char> L_ch;
	vNode *pv;
	std::queue<vNode *> Q;
	std::list<adjListNode *>::iterator ia;
	std::list<eNode *>::iterator ie;

	this->clear_vFlag();

	i = 0;
	while (i < this->G_Vnum)
	{
		deg_i[i] = 0;
		i++;
	}

	ia = this->G_adjList.begin();
	while (ia != this->G_adjList.end())
	{
		ie = (*ia)->eList().begin();
		while (ie != (*ia)->eList().end())
		{
			deg_i[(*ie)->end()->id()] += 1;
			ie++;
		}
		ia++;
	}

	i = 0;
	while (i < this->G_Vnum)
	{
		if (deg_i[i] == 0)
		{
			Q.push(getNode_for_ID(i));
		}
		i++;
	}

	while (!Q.empty())
	{
		pv = Q.front();
		Q.pop();

		pv->T_flag1();
		L_ch.push_back(pv->data());

		ia = this->G_adjList.begin();
		while (ia != this->G_adjList.end())
		{
			if ((*ia)->v() == pv)
			{
				ie = (*ia)->eList().begin();
				while (ie != (*ia)->eList().end())
				{
					deg_i[(*ie)->end()->id()] -= 1;
					if (deg_i[(*ie)->end()->id()] == 0 && !(*ie)->end()->flag1())
					{
						Q.push((*ie)->end());
					}
					ie++;
				}
			}
			ia++;
		}
	}

	if (L_ch.size() < this->G_Vnum)
	{
		std::cout << "该图无拓扑序列!" << std::endl;
	}
	else
	{
		std::cout << "该图的拓扑序列为:";
		while (!L_ch.empty())
		{
			std::cout << L_ch.front() << ' ';
			L_ch.pop_front();
		}
		std::cout << std::endl;
	}

	return 0;
}

int graph::AOE_l(void)
{
	int i;
	int j;
	int len = 0;
	int deg_i[MAX_V_NUM];
	int deg_o[MAX_V_NUM];
	int minLs[MAX_V_NUM];
	int minLe[MAX_V_NUM];
	int maxLs[MAX_V_NUM];
	int maxLe[MAX_V_NUM];
	vNode *prior[MAX_V_NUM];
	vNode *pv;
	eNode *pe;
	std::list<vNode *> L;
	std::list<vNode *> path;
	std::list<vNode *>::iterator iv;
	std::list<adjListNode *>::iterator ia;
	std::list<eNode *>::iterator ie;

	this->clear_vFlag();
	this->clear_eFlag_l();

	i = 0;
	while (i < this->G_Vnum)
	{
		prior[i] = NULL;
		deg_i[i] = 0;
		deg_o[i] = 0;
		minLs[i] = 0;
		minLe[i] = 0;
		maxLs[i] = 0;
		maxLe[i] = 0;
		i++;
	}

	ia = this->G_adjList.begin();
	while (ia != this->G_adjList.end())
	{
		ie = (*ia)->eList().begin();
		while (ie != (*ia)->eList().end())
		{
			deg_i[(*ie)->end()->id()] += 1;
			deg_o[(*ie)->begin()->id()] += 1;
			ie++;
		}
		ia++;
	}

	i = 0;
	while (i < this->G_Vnum)
	{
		if (deg_i[i] == 0)
		{
			minLs[i] = 0;
			L.push_back(getNode_for_ID(i));
			getNode_for_ID(i)->T_flag1();
		}
		i++;
	}

	while (!L.empty())
	{
		iv = L.begin();
		while (iv != L.end())
		{
			maxLe[(*iv)->id()] = len;
			iv++;
		}

		pe = NULL;
		iv = L.begin();
		while (iv != L.end())
		{
			ia = this->G_adjList.begin();
			while (ia != this->G_adjList.end())
			{
				if ((*ia)->v() == (*iv))
				{
					ie = (*ia)->eList().begin();
					while (ie != (*ia)->eList().end())
					{
						if (!(*ie)->flag1())
						{
							if (pe == NULL || 
								pe->len() - (maxLe[pe->begin()->id()] - minLs[pe->begin()->id()]) >
								(*ie)->len() - (maxLe[(*ie)->begin()->id()] - minLs[(*ie)->begin()->id()]))
							{
								pe = *ie;
							}
						}
						ie++;
					}
					break;
				}
				ia++;
			}
			iv++;
		}

		if (pe != NULL)
		{
			//std::cout << pe->begin()->data() << "->" << pe->end()->data() << std::endl;

			len += pe->len() - (maxLe[pe->begin()->id()] - minLs[pe->begin()->id()]);
			deg_i[pe->end()->id()] -= 1;
			deg_o[pe->begin()->id()] -= 1;
			pe->T_flag1();


			if (deg_o[pe->begin()->id()] == 0)
			{
				iv = L.begin();
				while (iv != L.end())
				{
					if ((*iv) == pe->begin())
					{
						break;
					}
					iv++;
				}
				(*iv)->T_flag2();
				maxLe[(*iv)->id()] = len;
				//std::cout << (*iv)->data() << ' ';
				L.erase(iv);
			}

			if (deg_i[pe->end()->id()] == 0)
			{
				if (!pe->end()->flag1())
				{
					minLs[pe->end()->id()] = len;
					prior[pe->end()->id()] = pe->begin();
					if (deg_o[pe->end()->id()] != 0)
					{
						L.push_back(pe->end());
					}
					else
					{
						if (!pe->end()->flag2())
						{
							maxLe[pe->end()->id()] = len + pe->len();
							pe->end()->T_flag2();
						}
					}
					pe->end()->T_flag1();
				}
			}
		}
		else
		{
			break;
		}
	}

	i = 0;
	j = 0;
	while (i < this->G_Vnum)
	{
		//std::cout << maxLe[i] << std::endl;
		if (maxLe[i] > maxLe[j])
		{
			j = i;
		}
		i++;
	}

	i = 0;
	while (i < this->G_Vnum)
	{
		if (!this->G_vList[i]->flag2())
		{
			std::cout << "该图不存在关键路径!" << std::endl;
			return 0;
		}
		i++;
	}

	pv = getNode_for_ID(j);
	while (pv != NULL)
	{
		path.push_front(pv);
		pv = prior[pv->id()];
	}
	std::cout << "该图的关键路径为:" << std::endl;
	iv = path.begin();
	while (iv != path.end())
	{
		std::cout << (*iv)->data();
		++iv;
		if (iv != path.end())
		{
			std::cout << "->";
		}
	}
	std::cout << std::endl;
	std::cout << "关键路径的长度为:" << maxLe[j] << std::endl;

	return 0;
}

bool graph::empty(void)
{
	return this->G_empty;
}

bool graph::error(void)
{
	return this->G_error;
}

vNode * graph::getNode_for_data(const char n_data)
{
	int i = 0;
	while (i < this->G_Vnum)
	{
		if (this->G_vList[i] != NULL && this->G_vList[i]->data() == n_data)
		{
			break;
		}
		i++;
	}
	if (i >= this->G_Vnum)
	{
		return NULL;
	}
	return this->G_vList[i];
}

vNode * graph::getNode_for_ID(const int id)
{
	if (id >= 0 && id < this->G_Vnum)
	{
		return this->G_vList[id];
	}
	return NULL;
}

int graph::clear_vFlag()
{
	int i = 0;
	while (i < this->G_Vnum)
	{
		this->G_vList[i]->clear_flag();
		i++;
	}
	return 0;
}

int graph::clear_eFlag()
{
	std::list<eNode *>::iterator ie = this->G_eList.begin();
	while (ie != this->G_eList.end())
	{
		(*ie)->clear_flag();
		ie++;
	}
	return 0;
}

int graph::clear_eFlag_l()
{
	std::list<adjListNode *>::iterator ia = this->G_adjList.begin();
	std::list<eNode *>::iterator ie;
	while (ia != this->G_adjList.end())
	{
		ie = (*ia)->eList().begin();
		while (ie != (*ia)->eList().end())
		{
			(*ie)->clear_flag();
			ie++;
		}
		ia++;
	}
	return 0;
}

int graph::coverGraph(const char * fileName)
{
	bool error = false;
	bool typeLine = false;
	bool nodeLine = false;
	bool eLine = false;
	int elen;
	int vID = 0;
	int eID = 0;
	char ch_a;
	char ch_b;
	char str[256];
	vNode *pv = NULL;
	eNode *pe = NULL;
	std::ifstream fra;
	int ia;
	int ib;
	this->delete_G();
	fra.open(fileName);
	if (!fra.good())
	{
		this->G_error = true;
		return -3;
	}
	while (fra.good())
	{
		fra >> str;
		//std::cout << eID << '-';
		//std::cout << str << std::endl;
		if (strlen(str) == 0)
		{
			continue;
		}
		if (strncmp(str, "//", 2) == 0)
		{
			fra.getline(str, 255);
			continue;
		}
		if (!typeLine && !nodeLine && !eLine)
		{
			if (strcmp(str, "Graph") == 0)
			{
				typeLine = true;
				continue;
			}
		}
		if (typeLine)
		{
			if (strcmp(str, "UDG") == 0)
			{
				this->G_U = true;
				this->G_N = false;
			}
			else
			{
				if (strcmp(str, "DG") == 0)
				{
					this->G_U = false;
					this->G_N = false;
				}
				else
				{
					if (strcmp(str, "UDN") == 0)
					{
						this->G_U = true;
						this->G_N = true;
					}
					else
					{
						if (strcmp(str, "DN") == 0)
						{
							this->G_U = false;
							this->G_N = true;
						}
						else
						{
							error = true;
							break;
						}
					}
				}
			}
			typeLine = false;
			nodeLine = true;
			continue;
		}
		if (nodeLine)
		{
			ch_a = str[0];
			this->G_vList[vID] = new vNode(vID, ch_a);
			if (G_vList[vID] == NULL)
			{
				error = true;
				break;
			}
			vID += 1;
			if (!fra.good())
			{
				error = true;
				break;
			}
			ch_a = fra.get();
			while (ch_a != '\n')
			{
				//std::cout << ch_a << ' ';
				if (!isspace(ch_a))
				{
					this->G_vList[vID] = new vNode(vID, ch_a);
					if (G_vList[vID] == NULL)
					{
						error = true;
						break;
					}
					vID += 1;
				}
				if (!fra.good())
				{
					error = true;
					break;
				}
				ch_a = fra.get();
			}
			//std::cout << std::endl;
			if (error)
			{
				break;
			}
			this->G_Vnum = vID;
			nodeLine = false;
			eLine = true;
			continue;
		}
		if (eLine)
		{
			ch_a = str[0];
			if (!fra.good())
			{
				error = true;
				break;
			}
			fra >> ch_b;
			if (this->G_N)
			{
				if (!fra.good())
				{
					error = true;
					break;
				}
				fra >> elen;
			}
			else
			{
				elen = 1;
			}
			//std::cout << ch_a << ' ' << ch_b << ' ' << elen << std::endl;
			ia = 0;
			while (ia < this->G_Vnum)
			{
				if (this->G_vList[ia]->data() == ch_a)
				{
					break;
				}
				ia++;
			}
			ib = 0;
			while (ib < this->G_Vnum)
			{
				if (this->G_vList[ib]->data() == ch_b)
				{
					break;
				}
				ib++;
			}
			if (ia >= G_Vnum || ib >= G_Vnum)
			{
				error = true;
				break;
			}
			//std::cout << eID << std::endl;
			pe = new eNode(eID, this->G_vList[ia], this->G_vList[ib], elen);
			eID += 1;
			if (pe != NULL)
			{
				this->G_adjMat[ia][ib] = pe;
				this->G_eList.push_back(pe);
			}
			else
			{
				error = true;
				break;
			}
		}
		str[0] = '\0';
	}
	fra.close();

	if (error)
	{
		this->G_error = true;
		return -4;
	}

	this->G_Enum = eID;
	if (this->G_U)
	{
		this->G_Enum /= 2;
	}

	if (this->init_list() != 0)
	{
		this->G_error = true;
		return -5;
	}

	this->G_empty = false;

	return 0;
}

int graph::delete_G(void)
{
	int i;
	int j;

	i = 0;
	while (i < MAX_V_NUM)
	{
		if (this->G_vList[i] != NULL)
		{
			delete this->G_vList[i];
			this->G_vList[i] = NULL;
		}
		i++;
	}

	while (!this->G_eList.empty())
	{
		delete this->G_eList.front();
		this->G_eList.pop_front();
	}

	while (!this->G_adjList.empty())
	{
		delete this->G_adjList.front();
		this->G_adjList.pop_front();
	}

	while (!this->G_i_adjList.empty())
	{
		delete this->G_i_adjList.front();
		this->G_i_adjList.pop_front();
	}

	i = 0;
	while (i < MAX_V_NUM)
	{
		j = 0;
		while (j < MAX_V_NUM)
		{
			this->G_adjMat[i][j] = NULL;
			j++;
		}
		i++;
	}

	this->G_empty = true;

	return 0;
}

graph::~graph()
{
	this->delete_G();
}

#undef MAX_V_NUM

#endif
