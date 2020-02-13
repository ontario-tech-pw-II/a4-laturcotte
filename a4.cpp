//Liam Turcotte, 100741376  
#include <iostream>
using namespace std;

class Circle {
  private:  
    int x,y;      // center of circle
    double r;    // radius of circle

  public:
   
    Circle(int =0,int=0, double =1.0);
    void print() const;
    double area() const;

    double operator+(const Circle &) const;

    Circle & operator++();
    Circle operator++(int);

  friend ostream & operator<<(ostream &out, const Circle &);
  friend istream & operator>>(istream &in, Circle &);
};

Circle::Circle(int nx,int ny, double nr)
{
  x = nx;
  y = ny; 
  r = nr; 
}

double Circle::area() const {
  return (3.14159 * r * r); 
}

double Circle::operator+(const Circle & c) const
{
   return (area() + c.area()); 

}

Circle & Circle::operator++()
{
  r++; 

  return *this;
}

Circle Circle::operator++(int)
{
  Circle temp = *this;
  
  r++; 

  return temp;
}

ostream & operator<<(ostream &out, const Circle &c)
{
  out << "\tCentered at (" << c.x << ", " << c.y << ")" << endl; 
  out << "\tRadius: " << c.r << endl; 
  return out;
}

istream & operator>>(istream &in, Circle &c)
{
 int tempx, tempy; 
 double tempr; 

 cout << "\tx: "; 
 in >> tempx; 

 cout << "\ty: "; 
 in >> tempy; 

 cout << "\tradius: "; 
 in >> tempr; 

 c = Circle(tempx, tempy, tempr); 

  return in;
}


void Circle::print() const
{
  cout << "Circle =(" << x << "," << y << "," << r << ")" << endl;
}



int main()
{
  Circle a;
  Circle b(2,3,3.0);

  a.print();
b.print();
  
  cout << "The area a + b is: " << a+b << endl;
++a;
  a.print();

  a++;
  a.print();

  cout << a;

  cin >> a;
  cout <<a;

  return 0;

}