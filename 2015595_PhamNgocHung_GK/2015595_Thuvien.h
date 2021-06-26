#pragma once

struct HocVien
{
	char maSV[8];
	char ho[15];
	char tenLot[15];
	char ten[10];
	char lop[15];
	int namSinh;
	double diemTrungBinh;
	int soTinChi;
};
typedef struct HocVien DATA;

struct NODE
{
	DATA data;
	NODE* pNext;
};

struct LIST
{
	NODE* pHead;
	NODE* pTail;
};

void CreatList(LIST& list)
{
	list.pHead = list.pTail = NULL;
}

NODE* GetNode(DATA x)
{
	NODE* pNode = new NODE;
	if (pNode == NULL)
		return NULL;
	pNode->data = x;
	pNode->pNext = NULL;
}

int IsEmpty(LIST list)
{
	if (list.pHead == NULL)
		return 1;
	return 0;
}

void InsertHead(LIST& list, DATA x)
{
	NODE* pNode = GetNode(x);
	if (pNode == NULL)
		return;
	if (IsEmpty(list))
		list.pHead = list.pTail = pNode;
	else
	{
		pNode->pNext = list.pHead;
		list.pHead = pNode;
	}
}

void InsertTail(LIST& list, DATA x)
{
	NODE* pNode = GetNode(x);
	if (pNode == NULL)
		return;
	if (IsEmpty(list))
		list.pHead = list.pTail = pNode;
	list.pTail->pNext = pNode;
	list.pTail = pNode;
}

void  FileReader(char* filename, LIST& list)
{
	DATA x;
	ifstream in(filename);
	CreatList(list);
	while (!in.eof())
	{
		in >> x.maSV;
		in >> x.ho;
		in >> x.tenLot;
		in >> x.ten;
		in >> x.lop;
		in >> x.namSinh;
		in >> x.diemTrungBinh;
		in >> x.soTinChi;
		InsertTail(list, x);
	}
	in.close();
}

void XuatTieuDe()
{
	cout << "\n";
	for (int i = 0; i <= 150; i++)
		cout << '=';
	cout << "\n";
	cout << setiosflags(ios::left) << " "
		<< setw(15) << "Ma NV"
		<< setw(15) << "Ho"
		<< setw(15) << "Ho Lot"
		<< setw(15) << "Ten"
		<< setw(15) << "lop"
		<< setw(15) << "Nam sinh"
		<< setw(30) << "Diem Trung Binh"
	<< setw(20) << "So Tin Chi";
	cout << "\n";
	for (int i = 0; i <= 150; i++)
		cout << '=';
}

void XuatNhanVien(DATA a)
{
	cout << setiosflags(ios::left) << " ";
	cout << setw(15) << a.maSV
		<< setw(15) << a.ho
		<< setw(15) << a.tenLot
		<< setw(15) << a.ten
		<< setw(15) << a.lop
		<< setw(15) << a.namSinh
		<< setw(30) << a.diemTrungBinh
		<< setiosflags(ios::fixed) << setprecision(2) << setw(20) << a.soTinChi << '|';
	cout << "\n";
}

void XuatDSNV(LIST& list)
{
	XuatTieuDe();
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
	{
		cout << "\n\n";
		XuatNhanVien(i->data);
	}
	cout << "\n";
	for (int i = 0; i <= 150; i++)
		cout << '=';
}
void SuaHocVien(LIST& list)
{
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
	{
		if (strcmp(i->data.maSV, "DL23452")==0)
		{
			i->data.soTinChi = 35;
		}
	}
}
void XuatHocVienCTK36(LIST& list)
{
	LIST list1;
	CreatList(list1);
	for (NODE* i = list.pHead; i != NULL; i = i->pNext)
	{
		if (strcmp(i->data.lop,"CTK36")==0)
		{
			InsertTail(list1, i->data);
		}
	}
	XuatDSNV(list1);
}
int XoaNut1995(LIST &l)
{
	NODE* p = l.pHead;
	NODE* q = NULL;
	while (p != NULL)
	{
		if (p->data.namSinh == 1995)
			break;
		q = p; p = p->pNext;
	}
	if (p == NULL)
		return 0;
	//xoa nut sau q
	if (q != NULL)
	{
		if (p == l.pTail)
			l.pTail = q; //xoa nut cuoi
		q->pNext = p->pNext;
	}
	else //xoa nut dau
	{
		l.pHead = p->pNext;
		if (l.pHead == NULL)
			l.pTail = NULL;
	}
	delete p;
	return 1;
}
void XoaTatCa1995(LIST& l)
{
	while (XoaNut1995(l));
}
int XoaNut(LIST& l,int x)
{
	NODE* p = l.pHead;
	NODE* q = NULL;
	while (p != NULL)
	{
		if (p->data.namSinh == x)
			break;
		q = p; p = p->pNext;
	}
	if (p == NULL)
		return 0;
	//xoa nut sau q
	if (q != NULL)
	{
		if (p == l.pTail)
			l.pTail = q; //xoa nut cuoi
		q->pNext = p->pNext;
	}
	else //xoa nut dau
	{
		l.pHead = p->pNext;
		if (l.pHead == NULL)
			l.pTail = NULL;
	}
	delete p;
	return 1;
}
void locmang(int x, int a[],LIST l,int &f)
{
	
	NODE* p = l.pHead;
	while (p!=NULL)
	{
		if (p->data.namSinh>x)
		{
			a[f++] = p->data.namSinh;
		}
		p = p->pNext;
	}
 }
void XoaTatCa(LIST& l)
{
	static int a[100];
	int f = 0;
	locmang(1993, a, l, f);
	for (size_t i = 0; i < f; i++)
	{
		while (XoaNut(l,a[i]))
		{

		}
	}
}








