#include <iostream>
#include <vector>

using namespace std;

class OutOfRangeException : public exception
{
private:
    char *message;
public:
    OutOfRangeException(char *c)
    {
        message = c;
    }
    virtual const char* what()
    {
        return message;
    }
};

template<class T>
class Stos
{
private:
    vector <T> stos;
public:
    void push(T t)
    {
        stos.push_back(t);
    }
    T pop()
    {
        if(stos.size()==0)
        {
            exception *ex = new OutOfRangeException("kulawy");
            throw ex;
        }

        T t = stos.back();
        stos.pop_back();
        return t;
    }
    T peek()
    {
        if(stos.size()==0)
            throw OutOfRangeException("panie, ale zeby tak poza indeks wychodzic?");
        return stos.back();
    }
    Stos& operator+(T t)
    {
        push(t);
    }
    Stos& operator-()
    {
        pop();
    }
    Stos& operator--(int)
    {
        pop();
    }
    friend operator+(int,Stos<int>&);
};

operator+(int i,Stos<int>& s)
{
    s.stos.push_back(i);
}

int main()
{
    try
    {
        Stos<int> stos;
        //stos.push(1);
        //stos+1;
        1+stos;
        cout << stos.peek() << endl;
        //stos.pop();
        //stos.pop();
        //-stos;
        //-stos;
        stos--;
        stos--;
    }
    catch(exception* e)
    {
        cout << e->what();
    }

    return 0;
}
