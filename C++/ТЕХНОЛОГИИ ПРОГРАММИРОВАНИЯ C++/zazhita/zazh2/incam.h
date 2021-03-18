#ifndef INCAM_H_INCLUDED
#define INCAM_H_INCLUDED
#include <string>
using namespace std;
class Hospital
{
private:
    string type;
    int number;
    float valuation;
public:
    Hospital();
    Hospital(string, int, float);
    ~Hospital();

    void Set_Type(string);
    string Get_Type() const;
    void Set_Number(int);
    int Get_Number() const;
    void Set_Valuation(float);
    float Get_Valuation() const;

    void Input_Data();
    void Show_Data();
    Hospital Comparison_Type(const Hospital&);
    Hospital Comparison_Number(const Hospital&);
    Hospital Comparison_Valuation(const Hospital&);
};
/*
friend void Input_Data(Hospital&);
friend void Show_Data(const Hospital&);
friend Hospital Comparison_Type(const Hospital&, const Hospital&);
friend Hospital Comparison_Number(const Hospital&, const Hospital&);
friend Hospital Comparison_Valuation(const Hospital&, const Hospital&);
*/
#endif // INCAM_H_INCLUDED
