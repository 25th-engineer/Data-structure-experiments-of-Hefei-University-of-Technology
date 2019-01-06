#include "pch.h"

#ifndef ADJLISTNODE_CPP
#define ADJLISTNODE_CPP

#include "adjListNode.h"

adjListNode::adjListNode(vNode *r_v)
{
	this->N_v = r_v;
}

vNode * adjListNode::v()
{
	return this->N_v;
}

std::list<eNode*>& adjListNode::eList()
{
	// TODO: 在此处插入 return 语句
	return this->N_eList;
}

void adjListNode::add_adj_e(eNode * r_e)
{
	this->N_eList.push_back(r_e);
}

eNode * adjListNode::get_first_adj_e()
{
	if (!this->N_eList.empty())
	{
		return this->N_eList.front();
	}
	return NULL;
}

eNode * adjListNode::get_next_adj_e(eNode * e)
{
	std::list <eNode *>::iterator i = this->N_eList.begin();
	while (i != this->N_eList.end())
	{
		if (*i == e)
		{
			++i;
			break;
		}
		i++;
	}
	if (i != this->N_eList.end())
	{
		return *i;
	}
	return NULL;
}

void adjListNode::clear()
{
	this->N_eList.clear();
}


adjListNode::~adjListNode()
{
}

#endif