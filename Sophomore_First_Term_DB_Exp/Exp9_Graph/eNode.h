#ifndef ENODE_H
#define ENODE_H

#include "vNode.cpp"

//#define INF 65535

class eNode
{
public:
	eNode(int r_id, vNode *v_begin, vNode *v_end, int r_len);
	int id();
	vNode *begin();
	vNode *end();
	int len();
	bool flag1();
	void T_flag1();
	void F_flag1();
	bool flag2();
	void T_flag2();
	void F_flag2();
	bool flag3();
	void T_flag3();
	void F_flag3();
	void clear_flag();
	~eNode();
private:
	int E_id;
	vNode *E_begin;
	vNode *E_end;
	int E_len;
	bool E_flag1;
	bool E_flag2;
	bool E_flag3;
};

#endif
