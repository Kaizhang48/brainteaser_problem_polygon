//written by KAIZHANG
#include<vector>
#include<cmath>
#include<set>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Point {
	friend ostream& operator<<(ostream& os, const Point&);
private:
	double x;
	double y;
public:
	Point(const double & a = 0.0, const double & b = 0.0) :x(a), y(b) {}
	Point(const Point &a) :x(a.getX()), y(a.getY()) {}
	double getX() const {
		return x;
	}
	double getY() const {
		return y;
	}
	void setX(const double &a) {
		x = a;
	}
	void setY(const double &a) {
		y = a;
	}
	void operator=(const Point &a) {
		x = a.getX();
		y = a.getY();
	}
	double distanceFrom(const Point &a) const {
		double tempx = a.getX()-x;
		double tempy = a.getY()-y;
		tempx = tempx*tempx;
		tempy = tempy*tempy;
		double tempr= tempx + tempy;
		return pow(tempr, 0.5);
	}
	

};

Point operator-(Point A) {
	double x = A.getX();
	double y = A.getY();
	return std::move(Point(-x, -y));
}

ostream& operator<<(ostream& os, const Point& a) {
	os << "( " << a.getX() << ", " << a.getY() << " )";
	return os;
}
int operator == (const Point& a,const Point& b) {
	if (b.getX() == a.getX() && b.getY() == a.getY()) {
		return 1;
	}
	else {
		return 0;
	}
}

int operator <(const Point& a,const Point& b) {
	//Point temp;

	if (a.getX() < b.getY()) {
		return 1;
	}
	else {
		return 0;
	}
}
int numberofpoints(){
	set<Point> result;
	cout << "enter the point: " << endl;
	double c;
	double x;
	double y;

	int count = 0;
	while (cin >> c) {
		if (c > 0) {
			++count;
			if (count % 2 != 0) {
				x = c;
			}
			else {
				y = c;
				result.insert(Point(x, y));
			}
		}
		else {
			break;
		}
	}
	return result.size();
}


struct polygon{
	int num;
	vector<Point> vertex;
	vector<Point> vct;
	polygon(const int& a) :num(a) {
		vertex.resize(num);
		vct.resize(num);
		//cout << "enter the cordinate of vertex" << endl;
		int count = 0;
		double x;
		double y;
		double c;
		int n = 0;
		while (cin >> c) {
			if (n < num)
			{
				++count;
				if (count % 2 != 0) {
					x = c;
				}
				else {
					y = c;
					Point temp(x, y);
					vertex[n] = temp;
					++n;
					if (n == num) {
						break;
					}
				}
			}
		}

		for (int i = 0; i < num; ++i) {
			int next = ((i + 1) == num) ? 0 : i + 1;
			Point p = vertex[i];
			Point nextp = vertex[next];
			Point vv(p.getX() - nextp.getX(), p.getY() - nextp.getY());
			vct[i] = vv;
		}
	}
};

int operator ==(polygon& a, polygon& b) {
	int flag = 0;
	vector<Point> av= a.vct;
	vector<Point> bv = b.vct;
	int removetime = 0;
	if (a.num == b.num) {
		for (auto i = av.begin(); i != av.end(); ++i) {
			for (auto j = bv.begin(); j != bv.end(); ++j) {
				if ((*i == *j || *i == -(*j)))
				{
					j = bv.erase(j);
					flag = 1;
					++removetime;
					if (removetime == a.num) {
						return 1;
					}
					break;
				}
			}
			if (flag == 0) {
				break;
			}
			flag = 0;
		}
	}
	return flag;
}



int main()
{
	int c;
	vector<polygon> r ;
	int count = 0;
	while (cin >> c) {
		if (c > 2) {
			polygon temp(c);
			++count;
			if (count == 1) {
				r.push_back(temp);
			}
			else {
				int flag = 1;
				for (auto &c : r) {
					if (temp == c) {
						flag = 0;
						break;
					}
				}
				if (flag == 1) {
					r.push_back(temp);
				}
			}
		}
		else {
			break;
		}
	}
	cout << r.size() << endl;
	system("PAUSE");
    return 0;
}

