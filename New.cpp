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
}x;
typedef QUANLI QuanLi;
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
void NhapDS(QuanLi QL[],int n)
{

	for (int i=0; i<n; i++)
	{
		printf("\n***************************************************************");
		printf("\n\nMat Hang thu %d la:", i+1);
		NhapSoLieu(QL[i]);
	}
}
void XuatDS(QuanLi QL[], int n)
{
	for (int i=0; i<n ; i++)
	{
		XuatSoLieu(QL[i]);
	}
}
void ThemDoUong(QuanLi QL[],int n,int k)
{
	QUANLI x;
	for(int i=n;i>=k;i--)
		{
			QL[i]=QL[i-1];
		}
		QL[k]=x;
		n++;
}
void XoaMotDoUong(QuanLi QL[], int n)
{
	char c[50];
	printf("\nCho biet ten do uong can xoa: ");
	fflush(stdin);
	gets(c);
	int bienLap,BienKT=0;
	for(int i=0 ; i<n ; i++)
	{
		if(strcmp(QL[i].DoUong,c)==0)
		{
			for (bienLap=i;bienLap<n;i++){
				QL[bienLap]=QL[bienLap+1];
				n=n-1;
			}
			printf("da xao somg");
			BienKT++;
		}
	}
	if(BienKT==0)
	{
		printf("thuc uong ko ton tai");
	}
}
void SapXep(QuanLi QL[], int n)

{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(QL[i].SoLuong<QL[j].SoLuong)
			{
				float t=QL[i].SoLuong;
				QL[i].SoLuong=QL[j].SoLuong;
				QL[j].SoLuong=t;
			}
		}
	}
}
void HienThiBang() {
	printf("-----------------------------------------------------"
	"-----------------------------\n");
	printf("	||%-20s ||%-20s ||%-20s ||%-30s \n", "DO UONG", "GIA SAN PHAM", "SIZE", "SO LUONG" );
}

void ThongTinDoUong(QuanLi QL){
	printf("	||%-20s ||%-20d ||%-20s ||%-30d \n",QL.DoUong,QL.GiaSanPham,QL.size,QL.SoLuong);
}//hien thi thong tin do uong
void Bang(QuanLi QL[],int n) {
	HienThiBang();
	int i;
	for(i = 0; i < n; i++) {
		ThongTinDoUong(QL[i]);
	}
	printf("-----------------------------------------------------"
	"-----------------------------\n");
}
void ThanhToan(QuanLi QL[], int n)
{
	int Tong=0;
	SapXep(QL,n);
	int vt = 0;//vi tri bat dau dem;
	for(int i = vt; i<n; i = vt)
	{
		int dem = 1;
		int Tong = QL[i].SoLuong * QL[i].GiaSanPham;
		for(int j = vt + 1; j < n; j++)
		{
			if(QL[i].DoUong == QL[j].DoUong)
			{
				dem++;
				Tong = Tong + QL[j].SoLuong * QL[j].GiaSanPham;
			}
			else
			{
				break;
			}
		}
		if(dem>0)
		{
			printf("\nTien cua do uong %s la %d",QL[vt].DoUong,Tong);
			vt = vt + dem; //vi tri bat dau moi;
		}
	}
}
void GhiFile(QuanLi QL[],int n) {
	getchar();
	char fName[26];
	printf("	Nhap ten file: ");
	gets(fName);
	FILE* fOut = fopen(fName, "a");
	int i;
	fprintf(fOut,"	------------------------------------------------------------\n");
	fprintf(fOut,"	||TEN DO UONG   ||SO LUONG            ||SIZE            ||GIA SAN PHAM  \n");
	fprintf(fOut,"	------------------------------------------------------------\n");
	for(i = 0; i < n; i++) {
		struct QUANLI x = QL[i];
		fprintf(fOut, "	||%-20s ||%-20d ||%-20s ||%-20d ||\n",x.DoUong,x.SoLuong,x.size,x.GiaSanPham	);
	}
	fprintf(fOut,"	------------------------------------------------------------\n");
	fclose(fOut);
}
void menu()
{
	QuanLi QL;
	int k,n;
	int chon, flat=1;
	bool DaNhap = false;
	do{
		printf("\n	Nhap so luong do uong: ");
		scanf("%d",&n);
	}
	while(n<=0);
	while(true && flat)
	{
		printf ("\n\t\t    ===============THAY_DOI===============");
		printf("\n\t\t** 1.Nhap thong tin do uong");
		printf("\n\t\t** 2.Them Mot Do Uong                       **");
		printf("\n\t\t** 3.Loai Bo Mot Loai Do uong               **");
		printf("\n\t\t** 4.Thong ke Mat Hang                      **");
		printf("\n\t\t** 5.Thanh Toan                             **");
		printf("\n\t\t** 6.Ghi file                               **");
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
				QuanLi QL[100];
     			printf ("\n\t\tNhap Thong Tin Do Uong");
				NhapDS(QL,n);
				XuatDS(QL,n);
				DaNhap = true;
				break;
			}
			case 2:
			{
				if(DaNhap)
				{	
					printf("\n\tvi tri them: ");
					scanf("%d",&k);
					NhapSoLieu(QL);
					QuanLi QL[100];
					ThemDoUong(QL,n,k);
					printf("\ndanh sach do uong sau khi them la :");
					XuatDS(QL,n);
					
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
					QuanLi QL[100];
					XoaMotDoUong(QL,n);
				//	printf("\n\t\tdanh sach sau khi xoa");
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
					QuanLi QL[100];
			  	    SapXep(QL,n);
			  	    Bang(QL,n);
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
					QuanLi QL[100];
					ThanhToan(QL,n);
				}
				else
				{
					printf("	LUU Y: Quy Khach Nen Nhap thong tin cho do uong truoc!\n");
				}
				break;
			}
			case 6:{
				if (DaNhap)
				{
					QuanLi QL[100];
					GhiFile(QL,n);	
				}
				else
				{
					printf("	LUU Y: Quy Khach Nen Nhap thong tin cho do uong truoc!\n");
				}
				break;
			}
			case 7:
			{
				flat = 0;
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
	menu();
}
