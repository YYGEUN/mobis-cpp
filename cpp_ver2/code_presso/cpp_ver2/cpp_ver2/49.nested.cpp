#include <iostream>

using namespace std;
template<typename T>
class Car 
{
private:
	T m_nAccel;
	T m_nBreak;
public:
	void setAccel(T t) { m_nAccel = t };
	void setBreak(T t) { m_nBreak = t };
	// nested Å¬·¡½º ----------------------
	class CarEngine
	{
	private:
		T m_nEngine;
	public:
		void setEngine(T t) { m_nEngine = t };
	};
};

//template<typename T>
//class CarEngine
//{
//private:
//	T m_nEngine;
//public:
//	void setEngine(T t) { m_nEngine = t };
//};


int main() 
{
	Car<int>::CarEngine CE;
	CE.setEngine(100);

	Car<int> car;
	car.setAccel(23);

	return 0;
}