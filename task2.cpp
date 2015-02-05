#include <iostream>

using namespace std;

class fraction
{
private:
  int _numerator, _divider;
public: 
  int numerator()const { return _numerator; }
  int divider()const { return _divider; }
  
  fraction(int n, int d)
  {
    _numerator = n;
    _divider = d;    
  }
  
  fraction(int r): _numerator(r),_divider(1){}
  
  fraction& operator*=(fraction a)
  {
    _numerator *= a.numerator();
    _divider *= a.divider();
    return *this;
  }
  
  fraction& operator/=(fraction a)
  {
    _numerator *= a.divider();
    _divider *= a.numerator();
    return *this;
  }
  
  fraction& operator+=(fraction a)
  {
    _numerator = _numerator*a.divider() + _divider*a.numerator();
    _divider *= a.divider();
    return *this;
  }
  
  fraction& operator-=(fraction a)
  {
    _numerator = _numerator*a.divider() - _divider*a.numerator();
    _divider *= a.divider();
    return *this;
  }
};

ostream& operator<<(ostream& s, fraction z)
{
  return s<<z.numerator()<<'/'<<z.divider();
}

fraction operator+(fraction a, fraction b)
{
  fraction result = a;
  return result+=b;
}

fraction operator-(fraction a, fraction b)
{
  fraction result = a;
  return result-=b;
}

fraction operator*(fraction a, fraction b)
{
  fraction result = a;
  return result*=b;
}

fraction operator/(fraction a, fraction b)
{
  fraction result = a;
  return result/=b;
}

bool operator<(fraction a, fraction b)
{
  double t1 = (double)a.numerator()/a.divider();
  double t2 = (double)b.numerator()/b.divider();
  return t1<t2;
}

bool operator>(fraction a, fraction b)
{
  double t1 = (double)a.numerator()/a.divider();
  double t2 = (double)b.numerator()/b.divider();
  return t1>t2;
}

bool operator>=(fraction a, fraction b)
{
  double t1 = (double)a.numerator()/a.divider();
  double t2 = (double)b.numerator()/b.divider();
  return t1>=t2;
}

bool operator<=(fraction a, fraction b)
{
  double t1 = (double)a.numerator()/a.divider();
  double t2 = (double)b.numerator()/b.divider();
  return t1<=t2;
}

bool operator==(fraction a, fraction b)
{
  double t1 = (double)a.numerator()/a.divider();
  double t2 = (double)b.numerator()/b.divider();
  return t1==t2;
}

bool operator!=(fraction a, fraction b)
{
  double t1 = (double)a.numerator()/a.divider();
  double t2 = (double)b.numerator()/b.divider();
  return t1!=t2;
}

int main()
{
  // 2. Реализуйте класс, который хранит 2 числа (типа int и должен описывать дробь).
  // Данный класс должен уметь храниться в контейнерах STL (list, deque, vector, stack, set и map (в обоих параметрах pair)) .
  // Необходимо так же реализовать поддержку вывода в поток, реализовать все математические операторы и операторы сравнения.
  
  fraction c(2,3);
  cout<<c<<endl;
  
  // *
  cout<<"умножение"<<endl;
  c = fraction(2,3);
  c*=fraction(3,4);
  cout<<c<<endl;
  cout<<fraction(2,3)*fraction(3,4)<<endl;
  
  // /
  cout<<"деление"<<endl;
  c = fraction(2,3);
  c/=fraction(3,9);
  cout<<c<<endl;
  cout<<fraction(2,3)/fraction(3,9)<<endl;
  
  // +
  cout<<"сложение"<<endl;
  c = fraction(2,3);
  c+=fraction(3,4);
  cout<<c<<endl;
  cout<<fraction(2,3)+fraction(3,4)<<endl;
    
  // -
  cout<<"вычитание"<<endl;
  c = fraction(2,3);
  c -= fraction(3,4);
  cout<<c<<endl;
  cout<<fraction(2,3)-fraction(3,4)<<endl;
  
  cout<<"привидение"<<endl;
  c = 3;
  cout<<c<<endl;
  cout<<c*3<<endl;
  cout<<3*c<<endl;
  
  cout<<"логические операции"<<endl;
  fraction a(2,3);
  fraction b(3,4);
  c = fraction(4,6);
  fraction d(6,8);
  bool l1 = a<b;
  bool l2 = a>b;
  bool l3 = c>=d;  
  bool l4 = a<=b;
  bool l5 = a>=c;
  bool l6 = a==c;
  bool l7 = a!=c;
  
  cout<<l1<<endl;
  cout<<l2<<endl;
  cout<<l3<<endl;
  cout<<l4<<endl;
  cout<<l5<<endl;
  cout<<l6<<endl;
  cout<<l7<<endl;
  return 0;
}


