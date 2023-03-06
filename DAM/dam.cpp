
#include "dam.h"
#include<cstring>
baseDMA::baseDMA(const char * l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA & rs)
{
	label = new char[std::strlen(rs.label) + 1];//分配内存
	std::strcpy(label, rs.label);//初始化
	rating = rs.rating;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
	if (&rs == this)
		return *this;
	else
	{
		delete[] label;
		label = new char[std::strlen(rs.label) + 1];
		rating = rs.rating;
		return *this;
	}
}

baseDMA::~baseDMA()
{
	delete[] label;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
	os << "lable: " << rs.label << endl;
	os << "rating: " << rs.rating << endl;
	return os;
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ld)
{
	os<< (const baseDMA &)ld;
	os << "color: " << ld.color << endl;
	return os;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & ho)
{
	os << (const baseDMA &)ho;
	os << "style: " << ho.style << endl;
	return os;
}



lacksDMA::lacksDMA(const char * c, const char * l, int r):baseDMA(l,r)
{
	std::strncpy(color, c,39);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & bs)
{
	std::strncpy(color, c, COL_LEN-1);
	color[COL_LEN - 1] = '\0';
}

//hasDMA method

hasDMA::hasDMA(const char * s, const char * bs, int r):baseDMA(bs,r)
{
	style = new char[std::strlen(s) +1];
	strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const baseDMA & bs):baseDMA(bs)
{
	style = new char[std::strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & ch):baseDMA(ch)
{
	style = new char[std::strlen(ch.style) + 1];
	strcpy(style, ch.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
}

hasDMA & hasDMA::operator=(const hasDMA & ph)
{
	if (&ph == this)
		return *this;
	delete[]style;
	style = new char[strlen(ph.style) + 1];
	strcpy(style, ph.style);
	return *this;
}
