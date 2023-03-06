#pragma once
#ifndef DAM_H
#define DAM_H
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::ios_base;

class baseDMA
{
public:
	baseDMA(const char* l="null",int r=0);
	baseDMA(const baseDMA &rs);
	baseDMA & operator=(const baseDMA &rs);

	virtual ~baseDMA();
	friend std::ostream & operator<<(std::ostream &os, const baseDMA &rs);
private:
	char* label;
	int rating;
};
//derive calss without DAM
class lacksDMA :public baseDMA
{
public:
	lacksDMA(const char* c="blank",const char* l="null",int r=0);
	lacksDMA(const char* c,const baseDMA &bs);
	friend std::ostream & operator<<(std::ostream &os, const lacksDMA &ld);

private:
	enum 
	{
		COL_LEN=40
	};
	char color[COL_LEN];
};
//derived class from DAM
class hasDMA :public baseDMA
{
public:
	hasDMA(const char* s = "null", const char* bs = "null", int r = 0);
	hasDMA(const char* s, const baseDMA &bs);
	hasDMA(const hasDMA &ch);//复制构造函数
	~hasDMA();
	hasDMA & operator=(const hasDMA &ph);//重载负值运算符
	friend std::ostream & operator<<(std::ostream &os, const hasDMA &ho);
private:
	char* style;
};

#endif // !DAM_H
