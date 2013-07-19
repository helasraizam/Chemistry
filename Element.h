#pragma once

class Element
{
public:
	Element();
	//Element(const Element&);  // todo: finish copy constructor
	Element(string,char[3],int,float,int,int,int);

	string getGp();
    void testDisplay();

protected:
	string name;
	char symb[3];
	float amass;
	int anbr,gpnbr,pd,block;
	static const string gpnames[17];
};
