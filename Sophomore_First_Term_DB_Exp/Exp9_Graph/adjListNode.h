#ifndef ADJLISTNODE_H
#define ADJLISTNODE_H

#include "vNode.cpp"
#include "eNode.cpp"

class adjListNode
{
public:
	adjListNode(vNode *r_v);
	vNode *v();
	std::list<eNode *> &eList();
	void add_adj_e(eNode *r_e);
	eNode *get_first_adj_e();
	eNode *get_next_adj_e(eNode *e);
	void clear();
	~adjListNode();
private:
	vNode *N_v;
	std::list<eNode *> N_eList;
};

#endif
