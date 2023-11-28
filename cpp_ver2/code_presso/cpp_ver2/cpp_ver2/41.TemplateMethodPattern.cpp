#include <iostream>
#include <cstring>
using namespace std;

class ¹ä
{
public:
	void ºº´Â´Ù()
	{
		cout << "¹äÀ» ºº´Â´Ù" << endl;
	}
	void ¿ä¸®ÁøÇà()
	{
		¹äÃ·°¡¹°³Ö±â(); // º¯È­µÇ´Â ºÎºĞ¸¸ ¹Ù²Ü¼öÀÖµµ·Ï
		ºº´Â´Ù();
	}
	virtual void ¹äÃ·°¡¹°³Ö±â() = 0;
};

class ±èÄ¡ººÀ½¹ä : public ¹ä
{
public:
	virtual void ¹äÃ·°¡¹°³Ö±â()
	{
		cout << "±èÄ¡¸¦ ³Ö´Â´Ù" << endl;
	}
};
class »õ¿ìººÀ½¹ä : public ¹ä
{
public:
	virtual void ¹äÃ·°¡¹°³Ö±â()
	{
		cout << "»õ¿ì¸¦ ³Ö´Â´Ù" << endl;
	}
};

class ¾ßÃ¤ººÀ½¹ä : public ¹ä
{
public:
	virtual void ¹äÃ·°¡¹°³Ö±â()
	{
		cout << "¾ßÃ¤¸¦ ³Ö´Â´Ù" << endl;
	}
};

int  main()
{
	¹ä* p_rice = new ±èÄ¡ººÀ½¹ä;
	p_rice->¿ä¸®ÁøÇà();
	return 0;
}
