#ifndef ZZH_H_INCLUDED
#define ZZH_H_INCLUDED

#include <iostream>
using namespace std;
class Emploee
{
private:
	float senioriy;
	int wages;
protected:
	static int count;
public:
	Emploee();
	Emploee(float, int);
	~Emploee();
	void setSeniority(float);
	void setWages(int);
	int getWages() const;
	float getSeniority() const;
	void show();
	void input();
	Emploee cmpSen(const Emploee&);
	Emploee cmpWag(const Emploee&);
};
class GosSluzhazhi : public Emploee
{
private:
	int rang;
	float seniorityGos;
public:
	GosSluzhazhi();
	GosSluzhazhi(float, int, int, float);
	~GosSluzhazhi();
	void setRang(int);
	void setSenGos(float);
	float getSenGos() const;
	int getRang() const;
	void input();
	void show();
	GosSluzhazhi cmpRang(const GosSluzhazhi&);
	GosSluzhazhi cmpSenGos(const GosSluzhazhi&);
};
class Ministr : public GosSluzhazhi
{
private:
	int oborotDeneg;
	string kategoriya;
public:
	Ministr();
	Ministr(float, int, int, float, string, int);
	~Ministr();
	void setObDen(int);
	void setKateg(string);
	int getObDen() const;
	string getKateg() const;
	void input();
	void show();
	Ministr cmpObDen(const Ministr&);
	Ministr cmpKat(const Ministr&);
};
#endif // ZZH_H_INCLUDED
