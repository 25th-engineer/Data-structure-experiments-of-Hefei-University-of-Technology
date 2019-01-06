#ifndef VNODE_H
#define VNODE_H

class vNode
{
public:
	vNode(int r_id, char r_data);
	int id();
	char data();
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
	~vNode();
private:
	int V_id;
	char V_data;
	bool V_flag1;
	bool V_flag2;
	bool V_flag3;
};

#endif
