#ifndef CLINC_H_INCLUDED
#define CLINC_H_INCLUDED
#include<iostream>
class Tank
{
private:
    static int Count;
    char *model;
    int year;
public:
    Tank();
    Tank(const char *, int);
    ~Tank();
    void set_model(const char*);
    char* get_model();
    void set_year(int);
    int get_year();
    void show();
};
#endif // CLINC_H_INCLUDED
