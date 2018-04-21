#include <iostream>
#include <fstream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef struct doibong
{	char tendoibong[25];
    char khoavien[25];
    char huanluyenvien[25];
}doibong;
doibong b[20];
typedef struct cauthu
{char cmt[12];
 char tencauthu[25];
 char quoctich[15];
 int  namsinh;
 float  chieucao;
 float cannang;
 char vitrithidau[20];
 char doibong[25];
}cauthu;
cauthu a[320];
typedef struct trandau
{int ngaythidau;
 int thangthidau;
 int namthidau;
 char santhi[25];
 char tendoi1[25];
 char tendoi2[25];
 int banthangdoi1;
  int banthangdoi2;
  int muagiai;
}trandau;
trandau c[300];
int i=0,d=0,t=0 ;
void menu();
void nhapdoibong();
void timcauthutrongdoibong();
void hienthicauthu();
void xoacauthu();
void suacauthu();
void nhaptrandau();
void nhapcauthu();
void hienthidoibong();
void hienthitrandau();
void xoadoibong();
void suadoibong();
void lietke();
void caonhat();
void thapnhat();
void trenhat();
void lietkeketqua();
void tinhdiem();
void docfilecauthu();
void docfiletrandau();
void docfiledoibong();
main()
{
      system("color 70");
      printf("\t************************************************\n");
      printf("\t*Chao mung den voi ung dung quan ly giai dau BKLEAGE2018*\n");
      printf("\t************************************************\n");
      getch();
      menu();
}
void menu()
{ int choice,chon;
     system("cls");
     printf("\t***********************************************************\n");
     printf("\t\t\t1.doibong.\n");
     printf("\t\t\t2.cauthu.\n");
     printf("\t\t\t3.trandau.\n");
     printf("\t\t\t4.doc file text.\n");
     printf("\t\t\tChon 1 or 2 or 3 or 4:\n");
     printf("\t***********************************************************\n");
     scanf("%d",&choice);
     if(choice==0)
     {
     system("cls");
     exit(0);
     }
     switch(choice)
     {
                   case 1:
                        system("cls");
                        printf("1.Thong tin doi bong\n");
                        printf("2.danh sach cau thu trong doi bong\n");
                        printf("3.them doi bong\n");
                        printf("4.xoa doi bong\n");
                        printf("5.cap nhat thong tin doi bong\n");
                         printf("6.tinh diem cho doi bong tai mot thoi diem\n");
                        printf("0.Tro ve menu chinh\n");
                        printf("Chon tu 1-6:\n");
                        scanf("%d",&chon);
                        if(chon>6)
                        {
                        system("cls");
                        main();
                        }
                        switch(chon)
                        {
                            case 1:hienthidoibong();menu();break;
                            case 2:timcauthutrongdoibong();menu();break;
                            case 3:nhapdoibong();menu();break;
                            case 4:xoadoibong();menu();break;
                            case 5: suadoibong();menu();break;
                            case 6: tinhdiem();menu();break;
                            case 0:system("cls");menu();break;
                        }
                   break;
                      case 2:
                           system("cls");
                           printf("1.thong tin cau thu\n");
                           printf("2.liet ke cau thu theo nam sinh vi tri thi dau \n");
                           printf("3.cau thu cao nhat giai \n");
                           printf("4.cau thu thap nhat giai \n");
                           printf("5.cau thu tre nhat giai \n");
                           printf("6.them cau thu\n");
                           printf("7.xoa cau thu\n");
                           printf("8.sua cau thu\n");
                           printf("0.Tro ve menu chinh\n");
                           printf("Chon tu 1-8:\n");
                           scanf("%d",&chon);
                           if(chon>8)
                           {
                            system("cls");
                            main();
                           }
                           switch(chon)
                           {
                             case 1:hienthicauthu();menu();break;
                             case 2:lietke();menu();break;
                             case 3:caonhat();menu();break;
                             case 4:thapnhat();menu();break;
                             case 5:trenhat();menu();break;
                             case 6:nhapcauthu();menu();break;
                             case 7:xoacauthu();menu();break;
                             case 8:suacauthu();menu();break;
                             case 0:system("cls");menu();break;
                           }
                           break;
                    case 3:
                    	   system("cls");
                           printf("1.them tran dau \n");
                           printf("2.danh sach tran dau \n");
                           printf("3.liet ke ket qua tran dau theo ngay or thang or mua giai\n");
                           printf("0.Tro ve menu chinh\n");
                           printf("Chon tu 1-2-3:\n");
                           scanf("%d",&chon);
                           if(chon>3)
                           {
                            system("cls");
                            main();
                           }
                           switch(chon)
                           {
                             case 1:nhaptrandau();menu();break;
                             case 2:hienthitrandau();menu();break;
                             case 3:lietkeketqua();menu();break;
                             case 0:system("cls");menu();break;
                           }
                           case 4:
                           	 system("cls");
                             printf("1.doc file cau thu \n");
                             printf("2.doc file tran dau \n");
                             printf("3.doc file doi bong\n");
                             printf("0.Tro ve menu chinh\n");
                             printf("Chon tu 1-2-3:\n");
                             scanf("%d",&chon);
                           if(chon>3)
                           {
                            system("cls");
                            main();
                           }
                           switch(chon)
                           {
                             case 1:docfilecauthu();menu();break;
                             case 2:docfiletrandau();menu();break;
                             case 3:docfiledoibong();menu();break;
                           }
                      case 0:system("cls");menu();break;
     }
}
void suacauthu()
{
	 char cmt[12],tencauthumoi[25],quoctichmoi[15],vttdm[20],doibongmoi[25];
     int j=0;
     int kt=1;
     char ch;
     char nh;
     system("cls");
     printf("nhap soCMT/MSSV/CCCD cua cau thu can sua:");
     scanf("%s",cmt);
     fflush(stdin);
     if(strlen(cmt)!=0);
     for(j=0;j<i&&strcmp(a[j].cmt,cmt)!=0;j++);
     if(strcmp(a[j].cmt,cmt)==0)
     {
      printf("\n soCMT/MSSV/CCCD : %s",a[j].cmt);
      printf("\n ten cau thu:%s",a[j].tencauthu);
      printf("\n ho quoc tich:%s",a[j].quoctich);
      printf("\n vi tri thi dau:%s",a[j].vitrithidau);
      printf("\n doi bong:%s",a[j].doibong);
      printf("\n can nang:%f",a[j].cannang);
       printf("\n chieu cao:%f",a[j].chieucao);
      printf("\n nam sinh:%d",a[j].namsinh);
      do
      {
          printf("\n Ban co muon sua? (Y/N):");
          nh=getchar();
          fflush(stdin);
      }while(nh!='y'&&nh!='Y'&&nh!='n'&&nh!='N');
            if(nh=='y'||nh=='Y')
            {
            system("cls");
            printf("\n Nhap ten cau thu moi:");
            scanf("%s",tencauthumoi);
            strcpy(a[j].tencauthu,tencauthumoi);
            fflush(stdin);
            strcpy(a[i].tencauthu,tencauthumoi);
            printf("\n Nhap soCMT/MSSV/CCCD  moi:");
            scanf("%s",cmt);
            strcpy(a[j].cmt,cmt);
            fflush(stdin);
            strcpy(a[i].cmt,cmt);
            printf("\n Nhap quoc tich moi:");
            scanf("%s",quoctichmoi);
            strcpy(a[j].quoctich,quoctichmoi);
            fflush(stdin);
            strcpy(a[i].quoctich,quoctichmoi);
            printf("\n Nhap vi tri thi dau moi:");
            scanf("%s",vttdm);
            strcpy(a[j].vitrithidau,vttdm);
            fflush(stdin);
            strcpy(a[i].vitrithidau,vttdm);
            printf("\n Nhap ten doi bong moi:");
            scanf("%s",doibongmoi);
            strcpy(a[j].doibong,doibongmoi);
            fflush(stdin);
            strcpy(a[i].doibong,doibongmoi);
            printf("\n Sua chieu cao:");
            scanf("%f",&a[j].chieucao);
            fflush(stdin);
            printf("\n Sua can nang:");
            scanf("%f",&a[j].cannang);
            fflush(stdin);
            printf("\n Sua nam sinh:");
            scanf("%d",&a[j].namsinh);
            fflush(stdin);
 
 
      do
               {
                   printf("Ban muon tiep tuc?(Y/N):");
                   ch=getchar();
                   fflush(stdin);
               }while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
                              if(ch=='y'||ch=='Y')
                              suacauthu();
                              else
                              kt=1;
            }
           else main();
     }
     else
      printf("khong tim thay cau thu can sua");
    getch();
    system("cls");
     main();
	
}
void suadoibong()
{
	char doibong[25],hlvm[25],tenkhoavienmoi[25];
     int j=0;
     int kt=1;
     char ch;
     char nh;
     system("cls");
     printf("nhap ten doi bong can sua:");
     scanf("%s",doibong);
     fflush(stdin);
     if(strlen(doibong)!=0);
     for(j=0;j<d&&strcmp(b[j].tendoibong,doibong)!=0;j++);
     if(strcmp(b[j].tendoibong,doibong)==0)
     {
      printf("\n ten doi bong : %s",b[j].tendoibong);
      printf("\n ten khoa vien:%s",b[j].khoavien);
      printf("\n huanluyenvien:%s",b[j].huanluyenvien);
      do
      {
          printf("\n Ban co muon sua? (Y/N):");
          nh=getchar();
          fflush(stdin);
      }while(nh!='y'&&nh!='Y'&&nh!='n'&&nh!='N');
            if(nh=='y'||nh=='Y')
            {
            system("cls");
            printf("\n Nhap ten doi bong moi:");
             scanf("%s",doibong);
             strcpy(b[j].tendoibong,doibong);
            fflush(stdin);
            strcpy(b[d].tendoibong,doibong);
            printf("\n Nhap ten khoa vien moi:");
            scanf("%s",tenkhoavienmoi);
             strcpy(b[j].khoavien,tenkhoavienmoi);
            fflush(stdin);
            strcpy(b[d].khoavien,tenkhoavienmoi);
            printf("\n Nhap ten huan luyen vien moi:");
            scanf("%s",hlvm);
             strcpy(b[j].huanluyenvien,hlvm);
            fflush(stdin);
            strcpy(b[d].huanluyenvien,hlvm);
      do
               {
                   printf("Ban muon tiep tuc?(Y/N):");
                   ch=getchar();
                   fflush(stdin);
               }while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
                              if(ch=='y'||ch=='Y')
                              suadoibong();
                              else
                              kt=1;
            }
            else main();
     }
      else
      printf("khong tim thay doi bong can sua");
     getch();
     system("cls");
     main();
}
void xoadoibong()
{
	system("cls");
     char doibong[25];
     int j=0;
     int n=0;
     char ch;
     printf("nhap ten doi bong can xoa:");
     scanf("%s",doibong);
     fflush(stdin);
     if(strlen(doibong)!=0);
     for(j=0;j<d&&strcmp(b[j].tendoibong,doibong)!=0;j++);
     if(strcmp(b[j].tendoibong,doibong)==0)
     {
      printf("\n doi bong : %s",b[j].tendoibong);
      printf("\n khoa(vien):%s",b[j].khoavien);
      printf("\n huan luyen vien:%s",b[j].huanluyenvien);
      do
      {
      printf("\n Ban co muon xoa thong tin?(Y/N):");
       ch=getchar();
       fflush(stdin);
      }while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
          if(ch=='y'||ch=='Y')
      {
	   for(n=j;n<d;n++)
       {
        b[j] = b[j+1];
       }
       d--;
      }
      
     }
     else
      printf("khong tim thay doi bong can xoa");
    getch();
    system("cls");
     main();
}
void xoacauthu()
{
     system("cls");
     char cmt[12];
     int j=0;
     int n=0;
     char ch;
     printf("nhap soCMT/MSSV/CCCD cau thu can tim :");
     scanf("%s",cmt);
     fflush(stdin);
     if(strlen(cmt)!=0);
     for(j=0;j<i&&strcmp(a[j].cmt,cmt)!=0;j++);
     if(strcmp(a[j].cmt,cmt)==0)
     {
      printf("\n soCMT/MSSV/CCCD : %s",a[j].cmt);
      printf("\n ho ten cauthu:%s",a[j].tencauthu);
      printf("\n quoc tich:%s",a[j].quoctich);
      printf("\n doi bong:%s",a[j].doibong);
      printf("\n vi tri thi dau:%s",a[j].vitrithidau);
      printf("\n nam sinh:%d",a[j].namsinh);
      printf("\n chieu cao:%f",a[j].chieucao);
      printf("\n can nang:%f",a[j].cannang);
      do
      {
      printf("\n Ban co muon xoa thong tin?(Y/N):");
       ch=getchar();
       fflush(stdin);
      }while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
          if(ch=='y'||ch=='Y')
     {for(n=j;n<i;n++)
      {
        a[j] = a[j+1];
      }
      i--;
     }
     }
     else
      printf("khong tim thay cau thu can xoa");
    getch();
    system("cls");
     main();
}
void nhapcauthu()
{
	 int done = 1;
          int kt=1;
          char ch;
          char cmt[12];
          char tencauthu[25];
          char quoctich[15];
          char vttd[20];
          char doibong[25];
          do
          {
              do
              {
                         fflush(stdin);
                         system("cls");
                         printf("Nhap soCMT/MSSV/CCCD:\n");
                          scanf("%s",&cmt );
                         if(strlen(cmt)==0)
                           done=0;
                         else
                         {
                             fflush(stdin);
                             strcpy(a[i].cmt,cmt);
                             printf("Nhap ten cau thu:\n");
                             gets(tencauthu);
                             fflush(stdin);
                         }
                         if(strlen(tencauthu)==0)
                           done=0;
                         else
                         {
                             fflush(stdin);
                             strcpy(a[i].tencauthu,tencauthu);
                             printf("Nhap quoc tich:\n");
                             gets(quoctich);
                             fflush(stdin);
 						 }
 						  if(strlen(tencauthu)==0)
                           done=0;
                         else
                         {
                             fflush(stdin);
                             strcpy(a[i].quoctich,quoctich);
                             printf("Nhap vi tri thi dau:\n");
                             gets(vttd);
                             fflush(stdin);
 						 }
 						  if(strlen(vttd)==0)
                           done=0;
                         else
                         {
                             fflush(stdin);
                             strcpy(a[i].vitrithidau,vttd);
                             printf("Nhap doi bong:\n");
                             gets(doibong);
                             fflush(stdin);
 						 }
 						 if(strlen(doibong)==0)
                           done=0;
                         else
                         {
                             fflush(stdin);
                             strcpy(a[i].doibong,doibong);
                             printf("Nhap nam sinh:\n");
                             scanf("%d",&a[i].namsinh);
                             fflush(stdin);
                         }
                         if(a[i].namsinh==0)
                           done=0;
                         else
                         {
                             fflush(stdin);
                             printf("Nhap chieu cao:\n");
                             scanf("%f",&a[i].chieucao);
                             fflush(stdin);
                         }
                         if(a[i].chieucao==0)
                           done=0;
                         else
                         {
                             fflush(stdin);
                             printf("Nhap can nang:\n");
                             scanf("%f",&a[i].cannang);
                             fflush(stdin);
                         }
                           i++;
              } while(!done);
               do
               {
                   printf("Ban muon tiep tuc?(Y/N):");
                   ch=getchar();
                   fflush(stdin);
               }while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
                              if(ch=='y'||ch=='Y')
                              kt=0;
                              else
                              kt=1;
          }while(kt==0);
}
void nhapdoibong()
{
	
          int done = 1;
          int kt=1;
          char ch;
          char doibong[25];
          char khoa[25];
          char hlv[25];
          do
          {
              do
              {
                         fflush(stdin);
                         system("cls");
                         printf("Nhap ten doi bong:\n");
                         gets(doibong);
                         if(strlen(doibong)==0)
                           done=0;
                         else
                         {
                             fflush(stdin);
                             strcpy(b[d].tendoibong,doibong);
                             printf("Nhap ten khoa (vien):\n");
                             gets(khoa);
                             fflush(stdin);
                         }
                         if(strlen(khoa)==0)
                           done=0;
                         else
                         {
                             fflush(stdin);
                             strcpy(b[d].khoavien,khoa);
                             printf("Nhap ten huan luyen vien:\n");
                             gets(hlv);
                             fflush(stdin);
       					 }
       					 if(strlen(hlv)==0)
                           done=0;
                         else
                         {
                             fflush(stdin);
                             strcpy(b[d].huanluyenvien,hlv);
                             fflush(stdin);
                         }
 
                           d++;
              } while(!done);
               do
               {
                   printf("Ban muon tiep tuc?(Y/N):");
                   ch=getchar();
                   fflush(stdin);
               }while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
                              if(ch=='y'||ch=='Y')
                              kt=0;
                              else
                              kt=1;
          }while(kt==0);
}
void nhaptrandau()
{
	int done = 1;
          int kt=1;
          char ch;
          char std[25];
          char doi1[25];
          char doi2[25];
          do
          {
              do
              {
                         fflush(stdin);
                         system("cls");
                         printf("Nhap san thi dau:\n");
                         gets(std);
                         if(strlen(std)==0)
                           done=0;
                         else
                         {
                             fflush(stdin);
                             strcpy(c[t].santhi,std);
                             printf("Nhap ten doi1:\n");
                             gets(doi1);
                             fflush(stdin);
                         }
                         if(strlen(doi1)==0)
                           done=0;
                         else
                         {
                             fflush(stdin);
                             strcpy(c[t].tendoi1,doi1);
                             printf("Nhap ten doi2:\n");
                             gets(doi2);
                             fflush(stdin);
                         }
                         if(strlen(doi2)==0)
                           done=0;
                         else
                         {
                             fflush(stdin);
                             strcpy(c[t].tendoi2,doi2);
                             printf("Nhap ngay thi dau:\n");
                             scanf("%d",&c[t].ngaythidau);
                             fflush(stdin);
                         }
                          if(c[t].ngaythidau==0)
                           done=0;
                         else
                         {
                             fflush(stdin);
                             printf("Nhap thang thi dau:\n");
                             scanf("%d",&c[t].thangthidau);
                             fflush(stdin);
                         }
                         if(c[t].thangthidau==0)
                           done=0;
                         else
                         {
                             fflush(stdin);
                             printf("Nhap nam thi dau:\n");
                             scanf("%d",&c[t].namthidau);
                             fflush(stdin);
                         }
                         if(c[t].namthidau==0)
                           done=0;
                         else
                         {
                             fflush(stdin);
                             printf("Nhap ban thang doi 1:\n");
                             scanf("%d",&c[t].banthangdoi1);
                             fflush(stdin);
                         }
                         if(c[t].banthangdoi1==0)
                           done=0;
                         else
                         {
                             fflush(stdin);
                             printf("Nhap ban thang doi 2:\n");
                             scanf("%d",&c[t].banthangdoi2);
                             fflush(stdin);
                         }
                         if(c[t].banthangdoi2==0)
                           done=0;
                         else
                         {
                             fflush(stdin);
                             printf("Nhap mua giai:\n");
                             scanf("%d",&c[t].muagiai);
                             fflush(stdin);
                         }
                           t++;
              } while(!done);
               do
               {
                   printf("Ban muon tiep tuc?(Y/N):");
                   ch=getchar();
                   fflush(stdin);
               }while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
                              if(ch=='y'||ch=='Y')
                              kt=0;
                              else
                              kt=1;
          }while(kt==0);
 
}
void hienthitrandau()
 {
 	int n;
 	if (t!=0)
 	{
 	  printf("\n|----------|-----------|---------|-------------|-----------------|------------------|------------|------------|--------|");
	  printf("\n|ngaythidau|thangthidau|namthidau|san thi dau  |ten doi 1        |ten doi 2         |banthangdoi1|banthangdoi2|mua giai|");	
	  printf("\n|----------|-----------|---------|-------------|-----------------|------------------|------------|------------|--------|");
 	  for(n=0;n<t;n++)
 	  {
 	   printf("\n|%-10d|%-9d  |%-8d |%-12s |%-16s |%-16s  |%-11d |%-10d  |%-6d  |",c[n].ngaythidau,c[n].thangthidau,c[n].namthidau,c[n].santhi,c[n].tendoi1,c[n].tendoi2,c[n].banthangdoi1,c[n].banthangdoi2,c[n].muagiai);
 	  }
 	  printf("\n|----------|-----------|---------|-------------|-----------------|------------------|------------|------------|--------|");
	 }
	 else
	          printf(" chua co tran dau nao trong danh sach");
              getch();
              system("cls");
              main();
 }
void hienthidoibong()
 {
  int n; 
   if(d!=0)
   {
 	  printf("\n|-----------------|--------------------|--------------------|");
	  printf("\n|Ten doi bong     |KHoa(vien)          |huan luyen vien     |");
	  printf("\n|-----------------|--------------------|--------------------|");
	  for(n=0;n<d;n++)
	  {
	  	printf("\n|%-17s|%-20s|%-20s|",b[n].tendoibong,b[n].khoavien,b[n].huanluyenvien);
	  }
	  printf("\n|-----------------|--------------------|--------------------|");
   }
   else
              printf(" chua co doi bong trong danh sach");
              getch();
              system("cls");
              main();
 }
 void hienthicauthu()
 {  int n;
    if(i!=0)
    { printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
      printf("\n|soCMT/MSSV/CCCD |Ten cau thu	      |Quoc tich   |Nam sinh  |Chieu cao|Can nang |Vitrithidau|doi bong         |");
      printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
      for(n=0;n<i;n++)
      { 
	   printf("\n|%-16s|%-20s|%-12s|%-10d|%-9f|%-8f|%-11s|%-17s|",a[n].cmt,a[n].tencauthu,a[n].quoctich,a[n].namsinh,a[n].chieucao,a[n].cannang,a[n].vitrithidau,a[n].doibong);
      }
      printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
    }
    else
              printf(" chua co cau thu nao trong danh sach");
              getch();
              system("cls");
              main();
}
void lietkeketqua()
{
 int j,ng,th,n,da=0,g=0,ta=0;  
 char ch;
 int k;
 system("cls");
 printf("1.liet ke theo ngay \n");
 printf("2.liet ke theo thang \n");
 printf("3.liet ke theo mua giai thi dau \n");
 printf("0.Tro ve menu chinh\n");
 printf("chon 1 or 2 or 3:\n");
 scanf("%d",&k);
 if(k>3)
 {
  system("cls");
  main();
 }
 switch(k)
 {
 	
 	case 1:
	 system("cls");
 	 printf ("nhap ngay:");
 	 scanf("%d",&ng);
 	 printf ("nhap thang:");
 	 scanf("%d",&th);
 	 printf ("nhap nam:");
 	 scanf("%d",&n);
 	 fflush(stdin);
 	  printf("\n|----------|-----------|---------|-------------|-----------------|------------------|------------|------------|--------|");
	  printf("\n|ngaythidau|thangthidau|namthidau|san thi dau  |ten doi 1        |ten doi 2         |banthangdoi1|banthangdoi2|mua giai|");	
	  printf("\n|----------|-----------|---------|-------------|-----------------|------------------|------------|------------|--------|");
     for(j=0;j<t;j++)
	  if(c[j].ngaythidau==ng&&c[j].thangthidau==th&&c[j].namthidau==n)
     {da++;
    
 	  {
 	   printf("\n|%-10d|%-9d  |%-8d |%-12s |%-16s |%-16s  |%-11d |%-10d  |%-6d  |",c[j].ngaythidau,c[j].thangthidau,c[j].namthidau,c[j].santhi,c[j].tendoi1,c[j].tendoi2,c[j].banthangdoi1,c[j].banthangdoi2,c[j].muagiai);
 	  }
 	  printf("\n|----------|-----------|---------|-------------|-----------------|------------------|------------|------------|--------|");
      continue;
     }
     if(da==0)
     {system("cls");
	 fflush(stdin);
	 printf("\n khong co ngay day moi nhap lai");
     }
	  do
                       {
                  
				        printf("\n Ban co muon tim kiem tiep khong ?(Y/N):");
                         ch=getchar();
                         fflush(stdin);
                       }while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
                        if(ch=='y'||ch=='Y')
                        lietkeketqua();
     getch();
     system("cls");
     lietkeketqua();
     break;
    case 2:
	 system("cls");
 	 printf ("nhap thang:");
 	 scanf("%d",&th);
 	 printf ("nhap nam:");
 	 scanf("%d",&n);
 	 fflush(stdin);
 	  printf("\n|----------|-----------|---------|-------------|-----------------|------------------|------------|------------|--------|");
	  printf("\n|ngaythidau|thangthidau|namthidau|san thi dau  |ten doi 1        |ten doi 2         |banthangdoi1|banthangdoi2|mua giai|");	
	  printf("\n|----------|-----------|---------|-------------|-----------------|------------------|------------|------------|--------|");
     for(j=0;j<t;j++)
     if(c[j].thangthidau==th&&c[j].namthidau==n)
     {ta++;
 	  {
 	   printf("\n|%-10d|%-9d  |%-8d |%-12s |%-16s |%-16s  |%-11d |%-10d  |%-6d  |",c[j].ngaythidau,c[j].thangthidau,c[j].namthidau,c[j].santhi,c[j].tendoi1,c[j].tendoi2,c[j].banthangdoi1,c[j].banthangdoi2,c[j].muagiai);
 	  }
 	  printf("\n|----------|-----------|---------|-------------|-----------------|------------------|------------|------------|--------|");
     continue;
	 }
     if(ta==0)
     {system("cls");
        fflush(stdin);
      printf("\n khong co thang day moi nhap lai");
     }
	  do
                       {
                        printf("\n Ban co muon tim kiem tiep khong ?(Y/N):");
                         ch=getchar();
                         fflush(stdin);
                       }while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
                        if(ch=='y'||ch=='Y')
                        lietkeketqua();
 
     getch();
     system("cls");
     lietkeketqua();
     break;
    case 3:
	 system("cls");
 	 int m;
 	 printf ("nhap mua giai:");
 	 scanf("%d",&m);
 	 fflush(stdin);
 	  printf("\n|----------|-----------|---------|-------------|-----------------|------------------|------------|------------|--------|");
	  printf("\n|ngaythidau|thangthidau|namthidau|san thi dau  |ten doi 1        |ten doi 2         |banthangdoi1|banthangdoi2|mua giai|");	
	  printf("\n|----------|-----------|---------|-------------|-----------------|------------------|------------|------------|--------|");
     for(j=0;j<t;j++)
     if(c[j].muagiai==m)
      {g++;
 	  {
 	   printf("\n|%-10d|%-9d  |%-8d |%-12s |%-16s |%-16s  |%-11d |%-10d  |%-6d  |",c[j].ngaythidau,c[j].thangthidau,c[j].namthidau,c[j].santhi,c[j].tendoi1,c[j].tendoi2,c[j].banthangdoi1,c[j].banthangdoi2,c[j].muagiai);
 	  }
 	  printf("\n|----------|-----------|---------|-------------|-----------------|------------------|------------|------------|--------|");
      continue;
     }
     if(g==0)
      {system("cls");
        fflush(stdin);
       printf("\n khong co mua giai do moi nhap lai");
      }	 
	  do
                       {
                        printf("\n Ban co muon tim kiem tiep khong ?(Y/N):");
                         ch=getchar();
                         fflush(stdin);
                       }while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
                        if(ch=='y'||ch=='Y')
                        lietkeketqua();
     getch();
     system("cls");
     lietkeketqua();
     break;
    case 0:system("cls");menu();break;
 }
}

void lietke()
{
 int j;  
 char ch;
 int c,vk=0,y=0;
 system("cls");
 printf("1.liet ke theo nam sinh \n");
 printf("2.liet ke theo vi tri thi dau \n");
 printf("0.Tro ve menu chinh\n");
 printf("chon 1 or 2:\n");
 scanf("%d",&c);
 if(c>2)
 {
  system("cls");
  main();
 }
 switch(c)
 {
 	case 1:
	 system("cls");
 	 int ns;
 	 printf ("nhap nam sinh:");
 	 scanf("%d",&ns);
 	 fflush(stdin);
 	  printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
      printf("\n|soCMT/MSSV/CCCD |Ten cau thu	      |Quoc tich   |Nam sinh  |Chieu cao|Can nang |Vitrithidau|doi bong         |");
      printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
     for(j=0;j<i;j++)
	 if(a[j].namsinh==ns)
     {y++;
      { 
	   printf("\n|%-16s|%-20s|%-12s|%-10d|%-9f|%-8f|%-11s|%-17s|",a[j].cmt,a[j].tencauthu,a[j].quoctich,a[j].namsinh,a[j].chieucao,a[j].cannang,a[j].vitrithidau,a[j].doibong);
      }
      printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
       continue;
     }
     if(y==0)
     {
     	 system("cls");
        fflush(stdin);
      printf("\n khong co cau thu co nam sinh can tim");
	 }
      do
                       {
                        printf("\n Ban co muon tim kiem tiep khong ?(Y/N):");
                         ch=getchar();
                         fflush(stdin);
                       }while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
                        if(ch=='y'||ch=='Y')
                        lietke();
 
     getch();
     system("cls");
     main();
     break;
    case 2:
     system("cls");
 	 char vttd[20];
 	 printf ("nhap vi tri thi dau can tim:");
 	 scanf("%s",vttd);
 	 fflush(stdin);
 	 if(strlen(vttd)!=0);
 	  printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
      printf("\n|soCMT/MSSV/CCCD |Ten cau thu	      |Quoc tich   |Nam sinh  |Chieu cao|Can nang |Vitrithidau|doi bong         |");
      printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
     for(j=0;j<i;j++)
	 if(strcmp(a[j].vitrithidau,vttd)==0)
     {
      vk++;
      { 
	   printf("\n|%-16s|%-20s|%-12s|%-10d|%-9f|%-8f|%-11s|%-17s|",a[j].cmt,a[j].tencauthu,a[j].quoctich,a[j].namsinh,a[j].chieucao,a[j].cannang,a[j].vitrithidau,a[j].doibong);
      }
      printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
      continue;
     }
     if(vk==0) 
	  {  system("cls");
        fflush(stdin);
        printf("\n khong co cau thu o vi tri thi dau can tim");
      }
      do
                       {
                        printf("\n Ban co muon tim kiem tiep khong ?(Y/N):");
                         ch=getchar();
                         fflush(stdin);
                       }while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
                        if(ch=='y'||ch=='Y')
                        lietke();
 
     getch();
     system("cls");
     main();
     break;
  case 0:system("cls");menu();break;
 }
}
 void timcauthutrongdoibong()
{    system("cls");
     char tendoibong[25];
     int j=0,db=0;
     char ch;
 	printf ("nhap ten doi bong can tim:");
 	scanf("%s",tendoibong);
 	 fflush(stdin);
 	 printf("\n danh sach cac cau thu cua doi bong %s",tendoibong);
 	 if(strlen(tendoibong)!=0);
 	   printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
       printf("\n|soCMT/MSSV/CCCD |Ten cau thu	       |Quoc tich   |Nam sinh  |Chieu cao|Can nang |Vitrithidau|doi bong         |");
       printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
     for(j=0;j<i;j++)
     if(strcmp(a[j].doibong,tendoibong)==0)
      {db++;
       { 
	    printf("\n|%-16s|%-20s|%-12s|%-10d|%-9f|%-8f|%-11s|%-17s|",a[j].cmt,a[j].tencauthu,a[j].quoctich,a[j].namsinh,a[j].chieucao,a[j].cannang,a[j].vitrithidau,a[j].doibong);
       }
       printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
       continue;
      }
      if(db==0)
      { system("cls");
        fflush(stdin);
	  printf("\n khong co cau thu trong doi bong can tim");
	  }
      do
                       {
                        printf("\n Ban co muon tim kiem tiep khong ?(Y/N):");
                         ch=getchar();
                         fflush(stdin);
                       }while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
                        if(ch=='y'||ch=='Y')
                        timcauthutrongdoibong();	
                      getch();
                     system("cls");
                      main();

}
 void caonhat()
{
	system("cls");
     char cmt[12];
     int j;
	 float max=0;
     for(j=0;j<i;j++)
     {
     if(a[j].chieucao>=max)max=a[j].chieucao;}
     for(j=0;j<i;j++)
     if(a[j].chieucao==max){
      printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
      printf("\n|soCMT/MSSV/CCCD |Ten cau thu	      |Quoc tich   |Nam sinh  |Chieu cao|Can nang |Vitrithidau|doi bong         |");
      printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
      {
	   printf("\n|%-16s|%-20s|%-12s|%-10d|%-9f|%-8f|%-11s|%-17s|",a[j].cmt,a[j].tencauthu,a[j].quoctich,a[j].namsinh,a[j].chieucao,a[j].cannang,a[j].vitrithidau,a[j].doibong);
      }
      printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
     }
     getch();
 }
 void thapnhat()
{
	system("cls");
     int j;
     float min=2.5;
     for(j=0;j<i;j++)
     {
     if(a[j].chieucao<=min)min=a[j].chieucao;}
     for(j=0;j<i;j++)
     if(a[j].chieucao==min){
      printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
      printf("\n|soCMT/MSSV/CCCD |Ten cau thu	      |Quoc tich   |Nam sinh  |Chieu cao|Can nang |Vitrithidau|doi bong         |");
      printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
      { 
	   printf("\n|%-16s|%-20s|%-12s|%-10d|%-9f|%-8f|%-11s|%-17s|",a[j].cmt,a[j].tencauthu,a[j].quoctich,a[j].namsinh,a[j].chieucao,a[j].cannang,a[j].vitrithidau,a[j].doibong);
      }
      printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
     }
     getch();
 }
 void trenhat()
 {
	system("cls");
     int j;
     int min=1950;
     for(j=0;j<i;j++)
     {
     if(a[j].namsinh>=min)min=a[j].namsinh;}
     for(j=0;j<i;j++)
     if(a[j].namsinh==min){
      printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
      printf("\n|soCMT/MSSV/CCCD |Ten cau thu	      |Quoc tich   |Nam sinh  |Chieu cao|Can nang |Vitrithidau|doi bong         |");
      printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
      { 
	   printf("\n|%-16s|%-20s|%-12s|%-10d|%-9f|%-8f|%-11s|%-17s|",a[j].cmt,a[j].tencauthu,a[j].quoctich,a[j].namsinh,a[j].chieucao,a[j].cannang,a[j].vitrithidau,a[j].doibong);
      }
      printf("\n|----------------|--------------------|------------|----------|---------|---------|-----------|-----------------|");
     }
     getch();
 }
 void tinhdiem()
 {  system("cls");
 	char doibong[25]; 
 	int ng ,th, n,j,dem=0,flag=0,mua;
 	printf("\n nhap ten doi bong can tim:");
 	scanf("%s",&doibong);
 		 fflush(stdin);
 		 printf("\n nhap mua giai:");
 		 scanf("%d",&mua);
 	printf("\n nhap ngay:");
 	scanf("%d",&ng);
 	printf("\n nhap thang :");
 	scanf("%d",&th);
 	printf("\n nhap nam:");
	scanf("%d",&n);
	for(j=0;j<t;j++)
	{
		if((mua==c[i].muagiai)&&(strcmp(c[j].tendoi1,doibong)==0)&&(((c[j].ngaythidau<=ng)&&(c[j].namthidau==n)&&(c[j].thangthidau==th))||((c[j].thangthidau<th)&&(c[j].namthidau==n))||(c[j].namthidau<n)))
	{flag++;	(c[j].banthangdoi1>c[j].banthangdoi2)?dem=dem+3:((c[j].banthangdoi1==c[j].banthangdoi2)?dem++:dem);}
		
		if((mua==c[i].muagiai)&&(strcmp(c[j].tendoi2,doibong)==0)&&(((c[j].ngaythidau<=ng)&&(c[j].namthidau==n)&&(c[j].thangthidau==th))||((c[j].thangthidau<th)&&(c[j].namthidau==n))||(c[j].namthidau<n)))
		{flag++;(c[j].banthangdoi1<c[j].banthangdoi2)?dem=dem+3:((c[j].banthangdoi1==c[j].banthangdoi2)?dem++:dem);}
	}
	 system("cls");
	 fflush(stdin);
	 if(flag!=0)
      {printf("\n|-----------------|------------|");
	   printf("\n|%-17s|%-12d|",doibong,dem);
	  }
	 else
	 printf("\n khong co thong tin can tim");
	 getch();
 }
  void docfiledoibong()
 { 
    ifstream DB ("doibong.txt");
    if(! DB.is_open())
    {
        cout << "Khong the mo file.\n";
    }
    else
	 {
    	  DB >> d;
        for(int j = 0; j < d; j++)
        {
            DB >> b[j].tendoibong;
            DB >>b[j].khoavien;
            DB >>b[j].huanluyenvien;
        }
     }
      DB.close();
    
}
void docfilecauthu()
 { 
    ifstream CT ("cauthu.txt");
    if(! CT.is_open())
    {
        cout << "Khong the mo file.\n";
    }
    else {
    		CT >> i;
        for(int j = 0; j < i; j++)
        {
           CT >> a[j].cmt;
           CT >>a[j].tencauthu;
           CT >>a[j].quoctich;
           CT >>a[j].namsinh;
           CT >>a[j].chieucao;
           CT >>a[j].cannang;
           CT >>a[j].vitrithidau;
           CT >>a[j].doibong;
            
        }
    }
     CT.close();
}
void docfiletrandau()
 { 
    ifstream TD ("trandau.txt");
    if(! TD.is_open())
    {
        cout << "Khong the mo file.\n";
    }
    else 
	{
    	  TD >> t;
        for(int j = 0; j <= t; j++)
        {  
		   TD >> c[j].ngaythidau;
           TD >>c[j].thangthidau;
           TD >>c[j].namthidau;
           TD >>c[j].santhi;
           TD >>c[j].tendoi1;
           TD >>c[j].tendoi2;
           TD >>c[j].banthangdoi1;
           TD >>c[j].banthangdoi2;
           TD >>c[j].muagiai;
        }
    }
    TD.close();
}
 
 
