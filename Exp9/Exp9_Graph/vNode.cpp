#include "pch.h"

#ifndef VNODE_CPP
#define VNODE_CPP

#include "vNode.h"

vNode::vNode(int r_id, char r_data)
{
	this->V_id = r_id;
	this->V_data = r_data;
	this->V_flag1 = false;
	this->V_flag2 = false;
	this->V_flag3 = false;
}

int vNode::id()
{
	return this->V_id;
}

char vNode::data()
{
	return this->V_data;
}

bool vNode::flag1()
{
	return this->V_flag1;
}

void vNode::T_flag1()
{
	this->V_flag1 = true;
}

void vNode::F_flag1()
{
	this->V_flag1 = false;
}

bool vNode::flag2()
{
	return this->V_flag2;
}

void vNode::T_flag2()
{
	this->V_flag2 = true;
}

void vNode::F_flag2()
{
	this->V_flag2 = false;
}

bool vNode::flag3()
{
	return this->V_flag3;
}

void vNode::T_flag3()
{
	this->V_flag3 = true;
}

void vNode::F_flag3()
{
	this->V_flag3 = false;
}

void vNode::clear_flag()
{
	this->V_flag1 = false;
	this->V_flag2 = false;
	this->V_flag3 = false;
}


vNode::~vNode()
{
}

#endif
