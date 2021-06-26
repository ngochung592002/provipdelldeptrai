#pragma once
void XuatMenu()
{
	cout << "\n========================= HE THONG CHUC NANG =========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao danh sach hoc vien";
	cout << "\n2. Xem lai danh sach hoc vien";
	cout << "\n3. sua so tin chi tich luy cua hoc vien Dl23452 thanh 35";
	cout << "\n4. xuat danh sach sinh vien lop ctk36";
	cout << "\n5. xoa tat ca hoc vien co nam sinh 1995 ra khoi danh sach ";
	cout << "\n======================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap 1 so trong khoang tu [0,..," << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int menu, LIST& list)
{
	char filename[15];
	int ketQua, x;
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("cls");
		cout << "\n1.Tao danh sach hoc vien\n";
		cout << "\nNhap vao ten tep tin de mo: ";
		cin >> filename;
		FileReader(filename, list);
		XuatDSNV(list);
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem lai danh sach hoc vien\n";
		XuatDSNV(list);
		break;
	case 3:
		system("cls");
		cout << "\n3. sua so tin chi tich luy cua hoc vien Dl23452 thanh 35";
		SuaHocVien(list);
		XuatDSNV(list);
		break;
	case 4:
		system("cls");
		cout << "\n4.xuat danh sach sinh vien lop ctk36";
		XuatHocVienCTK36(list);
		break;
	case 5:
		system("cls");
		cout << "\n5. xoa tat ca hoc vien co nam sinh 1995 ra khoi danh sach";
		XoaTatCa(list);
		XuatDSNV(list);
		break;
	}
	_getch();
}
