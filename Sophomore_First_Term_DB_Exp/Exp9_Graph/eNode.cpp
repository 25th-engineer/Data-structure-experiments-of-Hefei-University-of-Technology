#include "pch.h"

#ifndef ENODE_CPP
#define ENODE_CPP

#include "eNode.h"

eNode::eNode(int r_id, vNode *v_begin, vNode *v_end, int r_len)
{
	this->E_id = r_id;
	this->E_begin = v_begin;
	this->E_end = v_end;
	this->E_len = r_len;
	this->E_flag1 = false;
	this->E_flag2 = false;
	this->E_flag3 = false;
}

int eNode::id()
{
	return this->E_id;
}

vNode * eNode::begin()
{
	return this->E_begin;
}

vNode * eNode::end()
{
	return this->E_end;
}

int eNode::len()
{
	return this->E_len;
}

bool eNode::flag1()
{
	return this->E_flag1;
}

void eNode::T_flag1()
{
	this->E_flag1 = true;
}

void eNode::F_flag1()
{
	this->E_flag1 = false;
}

bool eNode::flag2()
{
	return this->E_flag2;
}

void eNode::T_flag2()
{
	this->E_flag2 = true;
}

void eNode::F_flag2()
{
	this->E_flag2 = false;
}

bool eNode::flag3()
{
	return this->E_flag3;
}

void eNode::T_flag3()
{
	this->E_flag3 = true;
}

void eNode::F_flag3()
{
	this->E_flag3 = false;
}

void eNode::clear_flag()
{
	this->E_flag1 = false;
	this->E_flag2 = false;
	this->E_flag3 = false;
}


eNode::~eNode()
{
}

#endif