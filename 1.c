#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fp,*fpj,*fps;//����3���ļ�
int i,xuan;
typedef struct book{//�鼮�ṹ��
	char name[10];//����
	char num[10];//���
	char writer[10];//����
	int date;//��������
	char press[10];//������
	float price;//�۸�
	int leibie[10];//���
	int kucun;//���
	int jiechu;//�����
}bo;
typedef struct student{//ѧ���ṹ��
	char name[10];//ѧ����
	char num[10];//ѧ��
	int jie;//�������
}st;
typedef struct jieyue{//���Ľṹ��
	char snum[10];
	char bnum[10];
}ji;
void menu()//�˵�����
{
	printf("\n\n");
	for(i=0;i<80;i++)
		printf("*");
	printf("\n\n");
	printf("\t\t1-----ͼ��¼��\t\t\t");
	printf("2-----ͼ�����\n\n");
	printf("\t\t3-----ͼ���ѯ\t\t\t");
	printf("4-----�޸�ɾ��ͼ��\n\n");
	printf("\t\t5-----����ͼ��\t\t\t");
	printf("6-----�黹ͼ��\n\n");
	printf("\t\t7-----���Ĳ�ѯ\t\t\t");
	printf("8-----ͼ���⳥\n\n");
	printf("\t\t9-----�˳�\t\t\t");
	printf("\n\n");
	for(i=0;i<80;i++)
		printf("*");
	printf("\n\n");
}
void end()//¼��ͼ��
{
	bo boo,booq;
	printf("������ͼ����(���ʮ���ַ�)��");
	scanf("%s",boo.name);
	do{
		i=1;
		printf("������ͼ����(���ʮ���ַ�)��");
		scanf("%s",boo.num);
		fread(&booq,sizeof(bo),1,fp);//��ȡ�ļ�����
		while(!feof(fp)){
			if(strcmp(booq.num,boo.num)==0){
				printf("\n�ñ���Ѵ�������������\n\n");
				i=0;
				break;
			}
			fread(&booq,sizeof(bo),1,fp);
		}
		rewind(fp);
	}while(i==0);
	printf("������ͼ������(���ʮ���ַ�)��");
	scanf("%s",boo.writer);
	printf("������ͼ��������ڣ�");
	scanf("%d",&boo.date);
	printf("������ͼ��۸�");
	scanf("%f",&boo.price);
	printf("������ͼ�������(���ʮ���ַ�)��");
	scanf("%s",boo.press);
	printf("������ͼ�����(���ʮ���ַ�)��");
	scanf("%s",boo.leibie);
	printf("������ͼ���������");
	scanf("%d",&boo.kucun);
	boo.jiechu=0;
	getchar();
	fseek(fp,0,2);
	fwrite(&boo,sizeof(bo),1,fp);//��ͼ����Ϣд���ļ�
	printf("\n¼��ɹ����ص����˵�");
	system("pause");
}
void print()//���ͼ��
{
	bo boo;
	printf("����      ���      ����      �۸�      ������    ���      ԭʼ���  ���\n");
	fread(&boo,sizeof(bo),1,fp);
	while(feof(fp)==0){
		printf("%-10s%-10s%-10s%-10.2f%-10s%-10s%-10d%-4d\n",boo.name,boo.num,boo.writer,boo.price,boo.press,boo.leibie,boo.kucun,boo.jiechu);
		fread(&boo,sizeof(bo),1,fp);
		}
	printf("\n���ͼ����ϣ��ص����˵�");
	system("pause");
}

void find()//��ѯͼ��
{
	char hao[10];
	int fan=1;
	int bian=1;
	bo boo;
	printf("                \n\t\t1-��ͼ���ž�ȷ��ѯ     2-��ͼ������ȷ��ѯ\n\n���룺");
	scanf("%d",&xuan);

	 if(xuan==2){
		printf("������ͼ����(���ʮ���ַ�)��");
		scanf("%s",hao);
		printf("��� ����      ���      ����      �۸�      ������    ���      ԭʼ���  ���\n");
		while(!feof(fp)){
			if(strcmp(hao,boo.name)==0)
				printf("%-5d%-10s%-10s%-10s%-10.2f%-10s%-10s%-10d%-4d\n",bian,boo.name,boo.num,boo.writer,boo.price,boo.press,boo.leibie,boo.kucun,boo.jiechu);
			fread(&boo,sizeof(bo),1,fp);
		}

	}
	else if(xuan==1){
		printf("������ͼ����(���ʮ���ַ�)��");
		scanf("%s",hao);
		printf("��� ����      ���      ����      �۸�      ������    ���      ԭʼ���  ���\n");
		while(!feof(fp)){
			if(strcmp(hao,boo.num)==0)
				printf("%-5d%-10s%-10s%-10s%-10.2f%-10s%-10s%-10d%-4d\n",bian,boo.name,boo.num,boo.writer,boo.price,boo.press,boo.leibie,boo.kucun,boo.jiechu);
			fread(&boo,sizeof(bo),1,fp);
		}

	}
	else{
		printf("������������˳���");
		system("pause");
		return;
	}
	printf("\n��ѯͼ����ϣ� ");
	system("pause");
}
void del()//�޸�ɾ��ͼ��
{
	FILE *p;
	ji jie;
	int j=0;
	char num[10];
	bo boo,booq;
	int xu;
	char or;
	char cha[10];
	printf("\nɾ���޸�ͼ��ֻ��ͨ��ͼ��������ɣ�\n�Ƿ����ͼ���ѯ����ѯ��Ҫ������ͼ���ţ�Y/N��\n");
	getchar();
	scanf("%c",&or);
	if(or=='Y'||or=='y'){
		find();
		rewind(fp);}
	printf("\n��������Ҫ������ͼ��ı�ţ�����������ı�ţ��������κβ�������");
	scanf("%s",cha);
	fread(&jie,sizeof(ji),1,fpj);
	while(!feof(fpj)){
		if(strcmp(jie.bnum,cha)==0){
			printf("\n�Ȿ�������˽��ģ����ܲ�����\n�����˳� ");
			system("pause");
			return;
		}
		fread(&jie,sizeof(ji),1,fpj);
	}
	printf("\n\n1-ɾ��ͼ��   2-�޸�ͼ��\n\n");
	printf("��ѡ��������ͣ�");
	scanf("%d",&xuan);
	fread(&boo,sizeof(bo),1,fp);
	p=fopen("c:\\books1.txt","wb+");
	while(!feof(fp)){
		j++;
		if(strcmp(boo.num,cha)==0){
			if(xuan==2){
				printf("\n\n1-����    2-���    3-����    4-�۸�    5-������   6-���    7-���\n\n");
				printf("��ѡ��Ҫ�޸ĵ���Ŀ:");
				scanf("%d",&xu);
				if(xu==1){
					printf("��Ҫ��%s��Ϊ��",boo.name);
					scanf("%s",boo.name);}
				else if(xu==2){
					do{
						i=1;
						printf("��Ҫ��%s��Ϊ��",boo.num);
						scanf("%s",num);
						rewind(fp);
						fread(&booq,sizeof(bo),1,fp);
						while(!feof(fp)){
							if(strcmp(booq.num,num)==0){
								printf("\n�ñ���Ѵ�������������\n\n");
								i=0;
								break;
							}
							fread(&booq,sizeof(bo),1,fp);
						}
					}while(i==0);
						rewind(fp);
					for(i=0;i<j;i++){
						fread(&boo,sizeof(bo),1,fp);
						strcpy(boo.num,num);
					}
				}
				else if(xu==3){
					printf("��Ҫ��%s��Ϊ��",boo.writer);
					scanf("%s",boo.writer);}
				else if(xu==4){
					printf("��Ҫ��%.2f��Ϊ��",boo.price);
					scanf("%f",&boo.price);}
				else if(xu==5){
					printf("��Ҫ��%s��Ϊ��",boo.press);
					scanf("%s",boo.press);}
				else if(xu==6){
					printf("��Ҫ��%s��Ϊ��",boo.leibie);
					scanf("%s",boo.leibie);}
				else if(xu==7){
					printf("��Ҫ��%d��Ϊ��",&boo.kucun);
					scanf("%d",&boo.kucun);}
				fwrite(&boo,sizeof(bo),1,p);
			}
		}
		else
			fwrite(&boo,sizeof(bo),1,p);
		fread(&boo,sizeof(bo),1,fp);
	}
	fclose(p);
	p=fopen("c:\\books1.txt","rb+");
	fclose(fp);
	fp=fopen("c:\\book.txt","wb+");
	fread(&boo,sizeof(bo),1,p);
	while(!feof(p)){
		fwrite(&boo,sizeof(bo),1,fp);
		fread(&boo,sizeof(bo),1,p);
	}
	fclose(fp);
	printf("�����ɹ�   �ص����˵�");
	system("pause");
}
void lend()//����ͼ��
{
	bo boo;
	FILE *p;
	st stu;
	ji jie;
	int j=0;
	char or,num[10],xnum[10];
	printf("\n����ͼ��ֻ��ͨ��ͼ������ɣ�\n�Ƿ����ͼ���ѯ����ѯ��Ҫ������ͼ���ţ�Y/N��\n");
	getchar();
	scanf("%c",&or);
	if(or=='Y'||or=='y')
		find();
	printf("\n��������Ҫ���ĵ�ͼ��ı�ţ�");
	scanf("%s",num);
	fread(&boo,sizeof(bo),1,fp);
	while(!feof(fp)){
		if(strcmp(num,boo.num)==0){
			j=1;
			break;
		}
		fread(&boo,sizeof(bo),1,fp);
	}
	if(j==0){
		printf("\n���û�и�ͼ�� �����˳�\n");
		system("pause");
		return;
	}
	printf("\n����Ҫ���ĵ�ͼ���ǣ�\n");
	printf("����      ���      ����      �۸�      ������    ���      ԭʼ���  ���\n");
	printf("%-10s%-10s%-10s%-10.2f%-10s%-10s%-10d%-4d\n",boo.name,boo.num,boo.writer,boo.price,boo.press,boo.leibie,boo.kucun,boo.jiechu);
	if(boo.kucun==boo.jiechu){
		printf("\n�ò�ͼ����ȫ������������˳�\n");
		system("pause");
		return;
	}
	printf("\n���������ѧ�ţ�");
	scanf("%s",xnum);
	j=0;
	fread(&jie,sizeof(ji),1,fpj);
	while(!feof(fpj)){
		if((strcmp(jie.bnum,num)==0)&&(strcmp(jie.snum,xnum)==0)){
			j=1;
			break;
		}
		fread(&jie,sizeof(ji),1,fpj);
	}
	if(j==1){
		printf("\n���Ѿ����Ĺ�����  �����˳�\n");
		system("pause");
		return;
	}
	fread(&stu,sizeof(st),1,fps);
	j=0;
	while(!feof(fps)){
		if(strcmp(xnum,stu.num)==0){
			j=1;
			break;
		}
		fread(&stu,sizeof(st),1,fps);
	}
	if(j==0){
		printf("\n���ǵ�һ�ν���ͼ�飬Ϊ�˷���������������������");
		scanf("%s",stu.name);
		strcpy(stu.num,xnum);
		stu.jie=1;
		fseek(fps,0,2);
		fwrite(&stu,sizeof(st),1,fps);
	}
	else{
		if(stu.jie==5){//������Կ���ÿ��ѧ�����輸����
			printf("\n���Ѿ�����5���飬�����ٽ�\n");
			system("pause");
			return;}
		p=fopen("c:\\jie.txt","wb+");
		rewind(fps);
		fread(&stu,sizeof(st),1,fps);
		while(!feof(fps)){
			if(strcmp(xnum,stu.num)==0)
				stu.jie++;
		fwrite(&stu,sizeof(st),1,p);
		fread(&stu,sizeof(st),1,fps);
		}
		fclose(p);
		fclose(fps);
		p=fopen("c:\\jie.txt","rb+");
		fps=fopen("c:\\student.txt","wb+");
		fread(&stu,sizeof(st),1,p);
		while(!feof(p)){
			fwrite(&stu,sizeof(st),1,fps);
			fread(&stu,sizeof(st),1,p);
		}
	}
	strcpy(jie.bnum,num);
	strcpy(jie.snum,xnum);
	fseek(fpj,0,2);
	fwrite(&jie,sizeof(ji),1,fpj);
	rewind(fp);
	p=fopen("c:\\jie.txt","wb+");
	fread(&boo,sizeof(bo),1,fp);
	while(!feof(fp)){
		if(strcmp(num,boo.num)==0)
			boo.jiechu++;
		fwrite(&boo,sizeof(bo),1,p);
		fread(&boo,sizeof(bo),1,fp);
	}
	fclose(p);
	p=fopen("c:\\jie.txt","rb+");
	fclose(fp);
	fp=fopen("c:\\book.txt","wb+");
	fread(&boo,sizeof(bo),1,p);
	while(!feof(p)){
		fwrite(&boo,sizeof(bo),1,fp);
		fread(&boo,sizeof(bo),1,p);
	}
	printf("\n���ĳɹ����ص����˵�");
	system("pause");
}
void pei(){//��ʧͼ���⳥
	FILE *p;
	bo boo;
	ji jie;
	st stu;
	int j=0;
	char snum[10],bnum[10];
	i=0;
	printf("\n���������ѧ�ţ�");
	scanf("%s",snum);
	printf("\n�����������ͼ��\n");
	fread(&jie,sizeof(ji),1,fpj);
	printf("����      ���      ����      �۸�      ������    ���      ԭʼ���  ���\n");
	while(!feof(fpj)){
		if(strcmp(jie.snum,snum)==0){
			fread(&boo,sizeof(bo),1,fp);
			while(!feof(fp)){
				if(strcmp(jie.bnum,boo.num)==0){
					printf("%-10s%-10s%-10s%-10.2f%-10s%-10s%-10d%-4d\n",boo.name,boo.num,boo.writer,boo.price,boo.press,boo.leibie,boo.kucun,boo.jiechu);
					j=1;
				}
				fread(&boo,sizeof(bo),1,fp);
			}
		}
		fread(&jie,sizeof(ji),1,fpj);
	}
	if(j==0){
		printf("\n��û�н����κ�ͼ�飡\n\n�����˳�");
		system("pause");
		return;
	}
	rewind(fp);
	rewind(fpj);
	printf("\n�������㶪ʧ��ͼ��ı�ţ�");
	scanf("%s",bnum);
	fread(&jie,sizeof(jie),1,fpj);//�ı�jieyue.txt�������
	p=fopen("c:\\jie.txt","wb+");
	while(!feof(fpj)){
		if((strcmp(jie.bnum,bnum)==0)&&(strcmp(jie.snum,snum)==0))
			i=1;
		else
			fwrite(&jie,sizeof(jie),1,p);
		fread(&jie,sizeof(jie),1,fpj);
	}
	if(i==0){
		printf("\n��û�н����ͼ��\n�����˳�");
		system("pause");
		return;
	}
	fclose(p);
	fclose(fpj);
	p=fopen("c:\\jie.txt","rb+");
	fpj=fopen("c:\\jieyue.txt","wb+");
	fread(&jie,sizeof(ji),1,p);
	while(!feof(p)){
		fwrite(&jie,sizeof(ji),1,fpj);
		fread(&jie,sizeof(ji),1,p);
	}
	fclose(p);//�ı�book.txt�������
	p=fopen("c:\\jie.txt","wb+");
	fread(&boo,sizeof(bo),1,fp);
	while(!feof(fp)){
		if(strcmp(bnum,boo.num)==0)
			boo.jiechu--;
		fwrite(&boo,sizeof(bo),1,p);
		fread(&boo,sizeof(bo),1,fp);
	}
	fclose(p);
	p=fopen("c:\\jie.txt","rb+");
	fclose(fp);
	fp=fopen("c:\\book.txt","wb+");
	fread(&boo,sizeof(bo),1,p);
	while(!feof(p)){
		fwrite(&boo,sizeof(bo),1,fp);
		fread(&boo,sizeof(bo),1,p);
	}
	fclose(p);//�ı�student.txt�������
	p=fopen("c:\\jie.txt","wb+");
	rewind(fps);
	fread(&stu,sizeof(st),1,fps);
	while(!feof(fps)){
		if(strcmp(snum,stu.num)==0)
			stu.jie--;
		fwrite(&stu,sizeof(st),1,p);
		fread(&stu,sizeof(st),1,fps);
	}
	fclose(p);
	fclose(fps);
	p=fopen("c:\\jie.txt","rb+");
	fps=fopen("c:\\student.txt","wb+");
	fread(&stu,sizeof(st),1,p);
	while(!feof(p)){
		fwrite(&stu,sizeof(st),1,fps);
		fread(&stu,sizeof(st),1,p);
	}
    printf("\n�밴�鼮�۸�ɨ���⳥,�⳥����ڹ���ͼ��");
	printf("\n�⳥�ɹ����ص����˵�");
	system("pause");
}
void huan(){//�黹ͼ��
	FILE *p;
	bo boo;
	ji jie;
	st stu;
	int j=0;
	char snum[10],bnum[10];
	i=0;
	printf("\n���������ѧ�ţ�");
	scanf("%s",snum);
	printf("\n�����������ͼ��\n");
	fread(&jie,sizeof(ji),1,fpj);
	printf("����      ���      ����      �۸�      ������    ���      ԭʼ���  ���\n");
	while(!feof(fpj)){
		if(strcmp(jie.snum,snum)==0){
			fread(&boo,sizeof(bo),1,fp);
			while(!feof(fp)){
				if(strcmp(jie.bnum,boo.num)==0){
					printf("%-10s%-10s%-10s%-10.2f%-10s%-10s%-10d%-4d\n",boo.name,boo.num,boo.writer,boo.price,boo.press,boo.leibie,boo.kucun,boo.jiechu);
					j=1;
				}
				fread(&boo,sizeof(bo),1,fp);
			}
		}
		fread(&jie,sizeof(ji),1,fpj);
	}
	if(j==0){
		printf("\n��û�н����κ�ͼ�飡\n\n�����˳�");
		system("pause");
		return;
	}
	rewind(fp);
	rewind(fpj);
	printf("\n��������黹��ͼ��ı�ţ�");
	scanf("%s",bnum);
	fread(&jie,sizeof(jie),1,fpj);//�ı�jieyue.txt�������
	p=fopen("c:\\jie.txt","wb+");
	while(!feof(fpj)){
		if((strcmp(jie.bnum,bnum)==0)&&(strcmp(jie.snum,snum)==0))
			i=1;
		else
			fwrite(&jie,sizeof(jie),1,p);
		fread(&jie,sizeof(jie),1,fpj);
	}
	if(i==0){
		printf("\n��û�н����ͼ��\n�����˳�");
		system("pause");
		return;
	}
	fclose(p);
	fclose(fpj);
	p=fopen("c:\\jie.txt","rb+");
	fpj=fopen("c:\\jieyue.txt","wb+");
	fread(&jie,sizeof(ji),1,p);
	while(!feof(p)){
		fwrite(&jie,sizeof(ji),1,fpj);
		fread(&jie,sizeof(ji),1,p);
	}
	fclose(p);//�ı�book.txt�������
	p=fopen("c:\\jie.txt","wb+");
	fread(&boo,sizeof(bo),1,fp);
	while(!feof(fp)){
		if(strcmp(bnum,boo.num)==0)
			boo.jiechu--;
		fwrite(&boo,sizeof(bo),1,p);
		fread(&boo,sizeof(bo),1,fp);
	}
	fclose(p);
	p=fopen("c:\\jie.txt","rb+");
	fclose(fp);
	fp=fopen("c:\\book.txt","wb+");
	fread(&boo,sizeof(bo),1,p);
	while(!feof(p)){
		fwrite(&boo,sizeof(bo),1,fp);
		fread(&boo,sizeof(bo),1,p);
	}
	fclose(p);//�ı�student.txt�������
	p=fopen("c:\\jie.txt","wb+");
	rewind(fps);
	fread(&stu,sizeof(st),1,fps);
	while(!feof(fps)){
		if(strcmp(snum,stu.num)==0)
			stu.jie--;
		fwrite(&stu,sizeof(st),1,p);
		fread(&stu,sizeof(st),1,fps);
	}
	fclose(p);
	fclose(fps);
	p=fopen("c:\\jie.txt","rb+");
	fps=fopen("c:\\student.txt","wb+");
	fread(&stu,sizeof(st),1,p);
	while(!feof(p)){
		fwrite(&stu,sizeof(st),1,fps);
		fread(&stu,sizeof(st),1,p);
	}
	printf("\n�黹�ɹ����ص����˵�");
	system("pause");
}
void cha(){//���Ĳ�ѯ
	char num[10];
	bo boo;
	ji jie;
	printf("\n���������ѧ�ţ�");
	scanf("%s",num);
	fread(&jie,sizeof(ji),1,fpj);
	printf("����      ���      ����      �۸�      ������    ���      ԭʼ���  ���\n");
	while(!feof(fpj)){
		if(strcmp(jie.snum,num)==0){
			fread(&boo,sizeof(bo),1,fp);
			while(!feof(fp)){
				if(strcmp(jie.bnum,boo.num)==0)
					printf("%-10s%-10s%-10s%-10.2f%-10s%-10s%-10d%-4d\n",boo.name,boo.num,boo.writer,boo.price,boo.press,boo.leibie,boo.kucun,boo.jiechu);
				fread(&boo,sizeof(bo),1,fp);
			}
		}
		fread(&jie,sizeof(ji),1,fpj);
	}
	printf("\n��ѯ��ϣ��ص����˵�");
	system("pause");
}
main(){
	if((fp=fopen("c:\\book.txt","rb+"))==NULL){

		if((fp=fopen("c:\\book.txt","wb+"))!=NULL)
				   printf("���ݴ����ļ�1�����ɹ�\n");
	}
	if((fpj=fopen("c:\\jieyue.txt","rb+"))==NULL){
		if((fpj=fopen("c:\\jieyue.txt","wb+"))!=NULL)
				   printf("���ݴ����ļ�2�����ɹ�\n");
	}
	if((fps=fopen("c:\\student.txt","rb+"))==NULL){
		if((fps=fopen("c:\\student.txt","wb+"))!=NULL)
				   printf("���ݴ����ļ�3�����ɹ�\n");
	}
int o = 0;
char admin[10] = { 0 };
char password[10] = { 0 };
printf("****************************��ӭʹ��ͼ����Ϣ����ϵͳ!*************************");
int  i, j, k, l, m;//�������
char c=3;
for (i=1; i<=3; i++)    printf("\n");
for (i=1; i<=3; i++) {
for (j=1; j<=32-2*i; j++)  printf(" ");
for (k=1; k<=4*i+1; k++)  printf("%c", c);
for (l=1; l<=13-4*i; l++)  printf(" ");
for (m=1; m<=4*i+1; m++)  printf("%c", c);
printf("\n");
}
for (i=1; i<=3; i++) {
for (j=1; j<=24+1; j++)   printf(" ");
for (k=1; k<=29; k++)   printf("%c", c);
printf("\n");
}
for (i=7; i>=1; i--) {
for (j=1; j<=40-2*i; j++)  printf(" ");
for (k=1; k<=4*i-1; k++)  printf("%c", c);
printf("\n");
}
for (i=1; i<=39; i++)    printf(" ");
printf("%c\n", c);
printf("\n");
printf("�������û���:");
printf("\n");
printf("����������:\n");
while (o < 3)
{
scanf("%s", admin);
scanf("%s", password);
printf("\n");
if (strcmp(password, "666666") == 0&&strcmp(admin, "liu") == 0)
{
printf("��¼�ɹ�\n");
break;
}
else
{
o++;
if (o != 3)
printf("������һ���û���������");
printf("\n");
}
}
if (o == 3)
{
printf("������������˳���¼����\n");
exit(0);
system("pause");}
	menu();
	printf("\n  ѡ��:");
	scanf("%d",&xuan);
	while(xuan==1||xuan==2||xuan==3||xuan==4||xuan==5||xuan==6||xuan==7||xuan==8){
		fp=fopen("c:\\book.txt","rb+");
		fps=fopen("c:\\student.txt","rb+");
		fpj=fopen("c:\\jieyue.txt","rb+");
		switch(xuan){
		case 0:break;
		case 1:end();break;
		case 2:print();break;
		case 3:find();break;
		case 4:del();break;
		case 5:lend();break;
		case 6:huan();break;
		case 7:cha();break;
		case 8:pei();break;
		}
		fclose(fp);
		fclose(fpj);
		fclose(fps);
		menu();
	printf("\n  ѡ��:");
	scanf("%d",&xuan);
	}
}
