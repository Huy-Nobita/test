#include <iostream>
using namespace std;
class Nhanvien{
	string ma;
	double luong;
	virtual double tinhluong() const = 0;
public:
	Nhanvien(){}
	void setInfo(string m){
		ma = m;
		luong = tinhluong();
	}
	double getluong() const {
		return luong;
	}
	virtual void print() const {
		cout<<"ma: "<<ma<<endl<<"luong: "<<luong<<endl;
	}
};
class NhanVienSanXuat: public Nhanvien{
	int sosp;
	double tiencong;
	double tinhluong() const {
		return sosp * tiencong;
	}
public:
	void setInfo(string n, int s, double t){
		sosp = s;
		tiencong = t;
		Nhanvien::setInfo(n);
	}
	NhanVienSanXuat(){};
	NhanVienSanXuat(string n = "", int sosp = 0, double tiencong = 0){
		setInfo(n, sosp, tiencong);
	}
	void print() const{
		Nhanvien::print();
		cout<<"so san pham: "<<sosp<<endl<<"tien cong 1 san pham: "<<tiencong<<endl;
	}
};
class NhanVienVanPhong: public Nhanvien{
	int ngay;
	double luongcb;
	double tinhluong() const {
		return (ngay * luongcb)/30;
	}
public:
	void setInfo(string n, int m, double l){
		ngay = m;
		luongcb = l;
		Nhanvien::setInfo(n);
	}
	NhanVienVanPhong(){};
	NhanVienVanPhong(string n, int ngay, double luongcb){
		setInfo(n, ngay, luongcb);
	}
	void print() const {
		Nhanvien::print();
		cout<<"so ngay: "<<ngay<<endl<<"luong co ban: "<<luongcb<<endl;
	}
};
int main()
{
	Nhanvien *a[10] = {
			new NhanVienSanXuat("A", 10, 20),
			new NhanVienSanXuat("B", 30, 40),
			new NhanVienVanPhong("C", 50, 60),
			new NhanVienVanPhong("D", 70, 80),
			new NhanVienVanPhong("E", 90, 100),
			new NhanVienSanXuat("F", 110, 120),
			new NhanVienSanXuat("G", 130, 140),
			new NhanVienSanXuat("H", 150, 160),
			new NhanVienSanXuat("I", 180, 170),
			new NhanVienVanPhong("K", 168, 190)
	};
	for (int i = 0; i <10; i++)
	{
		a[i]->print();
	};
	return 0;
}
