#include "Element.h"

//Element::Element(const Element&);
Element::Element(string nname,char nsymb[3],int nanbr,float namass,int ngpnbr,int npd,int nblock)
{
	name=nname;
	symb=nsymb;
	anbr=nanbr;
	amass=namass;
	gpnbr=ngpnbr;
	pd=npd;
	block=nblock;

	gpnames={"Alkali Metals/Lithium","Alkaline Eart Metals/Beryllium","Scandium (Rare Earth Elements and Actinides","Titanium","Vanadium","Chromium","Manganese","Iron","Cobalt","Nickel","Coinage Metals/Copper","Zinc","Triels/Boron Group/Boron","Tetrels/Carbon Group/Carbon","Pnictogens/Nitrogen","Chalcogens/Oxygen","Halogens/Fluorine","Noble Gase/Helium Family/Neon"};
}

string Element::getGp()
{
	return gpnames[gpnbr-1]+" Family";
}

void Element::testDisplay()
{
    cout<<"\n\n"<<name<<":\n\n\tSymbol: "<<symb<<"\n\tAtomic Number: "<<anbr<<"\n\tAtomic Mass: "<<amass<<"\n\tLocation: ("<<gpnbr<<","<<pd<<")\n\n";
}
