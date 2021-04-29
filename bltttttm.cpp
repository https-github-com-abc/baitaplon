#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#define max 100
struct QUANLI
{
	char DoUong[50];
	int GiaSanPham;
	char size[5];
	int SoLuong;
};
typedef QUANLI QuanLi;
struct DANHSACH
{
	QuanLi a[max];
	int n;
};
typedef DANHSACH DanhSach;
void NhapSoLieu(QuanLi &QL)
{
	fflush(stdin);
	printf ("\n   Moi Khach Hang Muon Chon Do Uong : ");
	gets(QL.DoUong);
	printf("\n   Gia Cua Moi Do Uong La:");
	scanf("%d",&QL.GiaSanPham);
	printf("\n   Cua hang co size m: la nho , l: la lon");
	printf("\n   Chon kich co do uong ban muon: ");
    scanf("%s",&QL.size);
	printf ("\n   So Luong Do Uong Quy Khach Mong Muon la : ");
	scanf("%d",&QL.SoLuong);
}
void XuatSoLieu(QuanLi QL)
{
	printf ("\n   Loai Do Uong Quy Khach Da Chon : %s", QL.DoUong);	
	printf("\n    Gia Do Uong Quy khach Vua Chon La : %d",QL.GiaSanPham);
	printf("\n    Kich co ban chon: %s",QL.size);
    printf("\n    So Luong Quy Khach Da Chon : %d ",QL.SoLuong);
}
void NhapDS(DanhSach &ds)
{

	for (int i=0; i<ds.n; i++)
	{
		printf("\n***************************************************************");
		printf("\n\nMat Hang thu %d la:", i+1);
		NhapSoLieu(ds.a[i]);
	}
}
void XuatDS(DanhSach &ds)
{
	for (int i=0; i<ds.n ; i++)
	{
		XuatSoLieu(ds.a[i]);
	}
}
void ThemDoUong(DanhSach &ds,QuanLi x,int k)
{
	for(int i=ds.n;i>=k;i--)
		{
			ds.a[i]=ds.a[i-1];
		}
		ds.a[k]=x;
		ds.n++;
}
int TimDoUong(DanhSach ds, char *c)
{
	for(int i=0 ; i<ds.n ; i++)
	{
		if(strcmp(ds.a[i].DoUong,c)==0)
		{
			return i;
			break;
		}
	}
	return -1;
}
void XoaMotDoUong(DanhSach ds, char *c)
{
	int vt=TimDoUong(ds,c);
	if(vt==-1)
	printf("\nkhong tim thay Do Uong %s muon xoa.",c );
	else
		for (int i=vt ; i<=ds.n-2 ; i++)
		{
			ds.a[i]=ds.a[i+1];
			ds.n--;
		}
}
void SapXep(DanhSach ds)

{
	for(int i=0;i<ds.n-1;i++)
	{
		for(int j=i+1;j<ds.n;j++)
		{
			if(ds.a[i].SoLuong<ds.a[j].SoLuong)
			{
				float t=ds.a[i].SoLuong;
				ds.a[i].SoLuong=ds.a[j].SoLuong;
				ds.a[j].SoLuong=t;
			}
		}
	}
}
void HienThiBang() {
	printf("-----------------------------------------------------"
	"-----------------------------\n");
	printf("	||%-20s ||%-20s ||%-20s ||%-30s \n", "DO UONG", "GIA SAN PHAM", "SIZE", "SO LUONG" );
}
void ThongTinDoUong(QuanLi x){
	printf("	||%-20s ||%-20d ||%-20s ||%-30d \n",x.DoUong,x.GiaSanPham,x.size,x.SoLuong);
}//hien thi thong tin do uong
void Bang(DanhSach ds) {
	HienThiBang();
	int i;
	for(i = 0; i < ds.n; i++) {
		ThongTinDoUong(ds.a[i]);
	}
	printf("-----------------------------------------------------"
	"-----------------------------\n");
}
void ThanhToan(DanhSach ds, int Tong=0)
{
	SapXep(ds);
	int vt = 0;//vi tri bat dau dem;
	for(int i = vt; i<ds.n; i = vt)
	{
		int dem = 1;
		int Tong = ds.a[i].SoLuong*ds.a[i].GiaSanPham;
		for(int j = vt + 1; j < ds.n; j++)
		{
			if(ds.a[i].DoUong == ds.a[j].DoUong)
			{
				dem++;
				Tong = Tong + ds.a[j].SoLuong*ds.a[j].GiaSanPham;
			}
			else
			{
				break;
			}
		}
		if(dem>0)
		{
			printf("\nTien cua do uong %s la %d",ds.a[vt].DoUong,Tong);
			vt = vt + dem; //vi tri bat dau moi;
		}
	}
}
void ghiFile(DanhSach ds) {
	getchar();
	char fName[26];
	printf("	Nhap ten file: ");
	gets(fName);
	FILE* fOut = fopen(fName, "a");
	int i;
	fprintf(fOut,"	------------------------------------------------------------\n");
	fprintf(fOut,"	||TEN DO UONG   ||SO LUONG            ||SIZE            ||GIA SAN PHAM  \n");
	fprintf(fOut,"	------------------------------------------------------------\n");
	for(i = 0; i < ds.n; i++) {
		QuanLi x = ds.a[i];
		fprintf(fOut, "	||%-20s ||%-20d ||%-20s ||%-20d ||\n",x.DoUong,x.SoLuong,x.size,x.GiaSanPham	);
	}
	fprintf(fOut,"	------------------------------------------------------------\n");
	fclose(fOut);
}

void docfile(DanhSach ds)
{
	QuanLi x;
	FILE* fOut = fopen("drink.txt", "r");
    for(int i=1;i<=ds.n;i++)
        fscanf(fOut,"%20s%20d%10s%20d\n",x.DoUong,x.SoLuong,x.size,x.GiaSanPham);
    fclose(fOut);
}
void menu()
{
	DanhSach ds;
	QuanLi x;
	int i,k;
	char *c;
	int Tong=0;
	int chon, flat=1;
	NhapDS(ds);
	XuatDS(ds);
	
		bool DaNhap = false;
	do{
		printf("\n	Nhap so luong do uong: ");
		scanf("%d",&ds.n);
	}
	while(ds.n<=0);
	while(true)
	{
		printf ("\n\t\t    ===============THAY_DOI===============");
		printf("\n\t\t** 1.Nhap thong tin do uong");
		printf("\n\t\t** 2.Them Mot Do Uong                       **");
		printf("\n\t\t** 3.Loai Bo Mot Loai Do uong               **");
		printf("\n\t\t** 4.Tim Do Uong Quy khach Da Chon          **");
		printf("\n\t\t** 5.Thong ke Mat Hang                      **");
		printf("\n\t\t** 6.Thanh Toan                             **");
		printf("\n\t\t** 7.Ket Thuc Cam On Quy Khach              **");
		printf("\n\t\t-------------------------------------");
		printf("\n\t\t HAY CHON THU BAN MUON");
		printf("\n\t\t        (bam so)");
		printf("\n\t\t SO BAN CHON LA :  ");
		scanf("%d",&chon);
		switch (chon)
		{
			case 1:
			{
				printf ("\n\t\tNhap Thong Tin Do Uong");
				NhapDS(ds);
				DaNhap = true;
				break;
			}
			case 2:
			{
				if(DaNhap)
				{
					printf("\n\tvi tri them: ");
					scanf("%d",&k);
					NhapSoLieu(x);
					ThemDoUong(ds,x,k);
					printf("\ndanh sach do uong sau khi them la :");
					XuatDS(ds);
				}
				else 
				{
					printf("	LUU Y: Quy Khach Nen Nhap thong tin cho do uong truoc!\n");
					printf("\t\t\t    MOI QUY KHACH CHON LAI\n");
				}
				break;
			}
			case 3:
			{
				if(DaNhap)
				{
					char *c;
					DanhSach ds;
					printf("\n\tDo uong can xoa la: ");
					scanf("%s",&c);
					XoaMotDoUong(ds,c);
					printf("\n\t\tdanh sach sau khi xoa");
					XuatDS(ds);
					break;
				}
				else
				{
					printf("	LUU Y: Quy Khach Nen Nhap thong tin cho do uong truoc!\n");
				}
					break;
			}
			case 4:
			{
				if (DaNhap)
				{
					char c[20];
					printf("\n\tnhap ten can tim: ");
					fflush(stdin);
					gets(c);
					int b=TimDoUong(ds,c);
					if(TimDoUong(ds,c)==-1)
						printf("\nKhong tim thay nhan vien: %s",c);
					else
					{
						printf("\nTim thay do uong thu %d",b+1);
					}				
				}
				else
				{
					printf("	LUU Y: Quy Khach Nen Nhap thong tin cho do uong truoc!\n");
				}
				break;
			}
			case 5:
			{
				if (DaNhap)
				{
			  	    SapXep(ds);
			  	    Bang(ds);
				}
				else
				{
					printf("	LUU Y: Quy Khach Nen Nhap thong tin cho do uong truoc!\n");
				}
				break;
			}
			case 6:
			{
				if (DaNhap)
				{
					ThanhToan(ds,Tong);
				}
				else
				{
					printf("	LUU Y: Quy Khach Nen Nhap thong tin cho do uong truoc!\n");
				}
				break;
			}
			case 7:{
				if (DaNhap)
				{
					ghiFile(ds);	
				}
				else
				{
					printf("	LUU Y: Quy Khach Nen Nhap thong tin cho do uong truoc!\n");
				}
				break;
			}
			case 8:
			{
				if (DaNhap)
				{
					docfile(ds);
				}
				else
				{
					printf("	LUU Y: Quy Khach Nen Nhap thong tin cho do uong truoc!\n");
				}
				break;
			}
			case 9:
			{
				flat=0;
				break;
			}	
			default: 
			{
				printf("\nkhong co chuc nang nay");
				break;
			}
		}
	}
}
int main()
{
	system("Color 72");
	printf ("\nCHAO MUNG QUY KHACH DEN VOI COFFEE IT CUA CHUNG TOI CHUC QUY KHACH NGON MIENG ! ");
	printf ("\n\t\t       =============MENU=============\n");
	printf("\n\t\t    1.CAfE DEN................15 000 VND");
	printf("\n\t\t    2.CAFE SUA................20 000 VND");
	printf("\n\t\t    3.TRA SUA.................20 000 VND");
	printf("\n\t\t    4.SINH TO.................25 000 VND");
	printf("\n\t\t------------------------------------------------");
	printf("\n HAY CHON THU BAN MUON");
	menu();
}
