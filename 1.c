#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fp,*fpj,*fps;//定义3个文件
int i,xuan;
typedef struct book{//书籍结构体
	char name[10];//书名
	char num[10];//编号
	char writer[10];//作者
	int date;//出版日期
	char press[10];//出版社
	float price;//价格
	int leibie[10];//类别
	int kucun;//库存
	int jiechu;//借出数
}bo;
typedef struct student{//学生结构体
	char name[10];//学生名
	char num[10];//学号
	int jie;//借的数量
}st;
typedef struct jieyue{//借阅结构体
	char snum[10];
	char bnum[10];
}ji;
void menu()//菜单界面
{
	printf("\n\n");
	for(i=0;i<80;i++)
		printf("*");
	printf("\n\n");
	printf("\t\t1-----图书录入\t\t\t");
	printf("2-----图书浏览\n\n");
	printf("\t\t3-----图书查询\t\t\t");
	printf("4-----修改删除图书\n\n");
	printf("\t\t5-----借阅图书\t\t\t");
	printf("6-----归还图书\n\n");
	printf("\t\t7-----借阅查询\t\t\t");
	printf("8-----图书赔偿\n\n");
	printf("\t\t9-----退出\t\t\t");
	printf("\n\n");
	for(i=0;i<80;i++)
		printf("*");
	printf("\n\n");
}
void end()//录入图书
{
	bo boo,booq;
	printf("请输入图书名(最多十个字符)：");
	scanf("%s",boo.name);
	do{
		i=1;
		printf("请输入图书编号(最多十个字符)：");
		scanf("%s",boo.num);
		fread(&booq,sizeof(bo),1,fp);//读取文件内容
		while(!feof(fp)){
			if(strcmp(booq.num,boo.num)==0){
				printf("\n该编号已存在请重新输入\n\n");
				i=0;
				break;
			}
			fread(&booq,sizeof(bo),1,fp);
		}
		rewind(fp);
	}while(i==0);
	printf("请输入图书作者(最多十个字符)：");
	scanf("%s",boo.writer);
	printf("请输入图书出版日期：");
	scanf("%d",&boo.date);
	printf("请输入图书价格：");
	scanf("%f",&boo.price);
	printf("请输入图书出版社(最多十个字符)：");
	scanf("%s",boo.press);
	printf("请输入图书类别(最多十个字符)：");
	scanf("%s",boo.leibie);
	printf("请输入图书入库数：");
	scanf("%d",&boo.kucun);
	boo.jiechu=0;
	getchar();
	fseek(fp,0,2);
	fwrite(&boo,sizeof(bo),1,fp);//将图书信息写入文件
	printf("\n录入成功！回到主菜单");
	system("pause");
}
void print()//浏览图书
{
	bo boo;
	printf("书名      编号      作者      价格      出版社    类别      原始库存  借出\n");
	fread(&boo,sizeof(bo),1,fp);
	while(feof(fp)==0){
		printf("%-10s%-10s%-10s%-10.2f%-10s%-10s%-10d%-4d\n",boo.name,boo.num,boo.writer,boo.price,boo.press,boo.leibie,boo.kucun,boo.jiechu);
		fread(&boo,sizeof(bo),1,fp);
		}
	printf("\n浏览图书完毕！回到主菜单");
	system("pause");
}

void find()//查询图书
{
	char hao[10];
	int fan=1;
	int bian=1;
	bo boo;
	printf("                \n\t\t1-按图书编号精确查询     2-按图书名精确查询\n\n代码：");
	scanf("%d",&xuan);

	 if(xuan==2){
		printf("请输入图书名(最多十个字符)：");
		scanf("%s",hao);
		printf("序号 书名      编号      作者      价格      出版社    类别      原始库存  借出\n");
		while(!feof(fp)){
			if(strcmp(hao,boo.name)==0)
				printf("%-5d%-10s%-10s%-10s%-10.2f%-10s%-10s%-10d%-4d\n",bian,boo.name,boo.num,boo.writer,boo.price,boo.press,boo.leibie,boo.kucun,boo.jiechu);
			fread(&boo,sizeof(bo),1,fp);
		}

	}
	else if(xuan==1){
		printf("请输入图书编号(最多十个字符)：");
		scanf("%s",hao);
		printf("序号 书名      编号      作者      价格      出版社    类别      原始库存  借出\n");
		while(!feof(fp)){
			if(strcmp(hao,boo.num)==0)
				printf("%-5d%-10s%-10s%-10s%-10.2f%-10s%-10s%-10d%-4d\n",bian,boo.name,boo.num,boo.writer,boo.price,boo.press,boo.leibie,boo.kucun,boo.jiechu);
			fread(&boo,sizeof(bo),1,fp);
		}

	}
	else{
		printf("输入错误，正在退出！");
		system("pause");
		return;
	}
	printf("\n查询图书完毕！ ");
	system("pause");
}
void del()//修改删除图书
{
	FILE *p;
	ji jie;
	int j=0;
	char num[10];
	bo boo,booq;
	int xu;
	char or;
	char cha[10];
	printf("\n删除修改图书只能通过图书编号来完成！\n是否调用图书查询来查询你要操作的图书编号（Y/N）\n");
	getchar();
	scanf("%c",&or);
	if(or=='Y'||or=='y'){
		find();
		rewind(fp);}
	printf("\n请输入你要操作的图书的编号（如果输入错误的编号，将不做任何操作）：");
	scanf("%s",cha);
	fread(&jie,sizeof(ji),1,fpj);
	while(!feof(fpj)){
		if(strcmp(jie.bnum,cha)==0){
			printf("\n这本书已有人借阅，不能操作！\n正在退出 ");
			system("pause");
			return;
		}
		fread(&jie,sizeof(ji),1,fpj);
	}
	printf("\n\n1-删除图书   2-修改图书\n\n");
	printf("请选择操作类型：");
	scanf("%d",&xuan);
	fread(&boo,sizeof(bo),1,fp);
	p=fopen("c:\\books1.txt","wb+");
	while(!feof(fp)){
		j++;
		if(strcmp(boo.num,cha)==0){
			if(xuan==2){
				printf("\n\n1-书名    2-编号    3-作者    4-价格    5-出版社   6-类别    7-库存\n\n");
				printf("请选择要修改的项目:");
				scanf("%d",&xu);
				if(xu==1){
					printf("你要把%s改为：",boo.name);
					scanf("%s",boo.name);}
				else if(xu==2){
					do{
						i=1;
						printf("你要把%s改为：",boo.num);
						scanf("%s",num);
						rewind(fp);
						fread(&booq,sizeof(bo),1,fp);
						while(!feof(fp)){
							if(strcmp(booq.num,num)==0){
								printf("\n该编号已存在请重新输入\n\n");
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
					printf("你要把%s改为：",boo.writer);
					scanf("%s",boo.writer);}
				else if(xu==4){
					printf("你要把%.2f改为：",boo.price);
					scanf("%f",&boo.price);}
				else if(xu==5){
					printf("你要把%s改为：",boo.press);
					scanf("%s",boo.press);}
				else if(xu==6){
					printf("你要把%s改为：",boo.leibie);
					scanf("%s",boo.leibie);}
				else if(xu==7){
					printf("你要把%d改为：",&boo.kucun);
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
	printf("操作成功   回到主菜单");
	system("pause");
}
void lend()//借阅图书
{
	bo boo;
	FILE *p;
	st stu;
	ji jie;
	int j=0;
	char or,num[10],xnum[10];
	printf("\n借阅图书只能通过图书编号完成！\n是否调用图书查询来查询你要操作的图书编号（Y/N）\n");
	getchar();
	scanf("%c",&or);
	if(or=='Y'||or=='y')
		find();
	printf("\n请输入你要借阅的图书的编号：");
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
		printf("\n书库没有该图书 正在退出\n");
		system("pause");
		return;
	}
	printf("\n你需要借阅的图书是：\n");
	printf("书名      编号      作者      价格      出版社    类别      原始库存  借出\n");
	printf("%-10s%-10s%-10s%-10.2f%-10s%-10s%-10d%-4d\n",boo.name,boo.num,boo.writer,boo.price,boo.press,boo.leibie,boo.kucun,boo.jiechu);
	if(boo.kucun==boo.jiechu){
		printf("\n该册图书已全部借出！正在退出\n");
		system("pause");
		return;
	}
	printf("\n请输入你的学号：");
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
		printf("\n你已经借阅过该书  正在退出\n");
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
		printf("\n你是第一次借阅图书，为了方便管理请输入你的姓名：");
		scanf("%s",stu.name);
		strcpy(stu.num,xnum);
		stu.jie=1;
		fseek(fps,0,2);
		fwrite(&stu,sizeof(st),1,fps);
	}
	else{
		if(stu.jie==5){//这里可以控制每个学生最多借几本书
			printf("\n你已经借了5本书，不能再借\n");
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
	printf("\n借阅成功！回到主菜单");
	system("pause");
}
void pei(){//丢失图书赔偿
	FILE *p;
	bo boo;
	ji jie;
	st stu;
	int j=0;
	char snum[10],bnum[10];
	i=0;
	printf("\n请输入你的学号：");
	scanf("%s",snum);
	printf("\n你借阅了以下图书\n");
	fread(&jie,sizeof(ji),1,fpj);
	printf("书名      编号      作者      价格      出版社    类别      原始库存  借出\n");
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
		printf("\n你没有借阅任何图书！\n\n正在退出");
		system("pause");
		return;
	}
	rewind(fp);
	rewind(fpj);
	printf("\n请输入你丢失的图书的编号：");
	scanf("%s",bnum);
	fread(&jie,sizeof(jie),1,fpj);//改变jieyue.txt里的数据
	p=fopen("c:\\jie.txt","wb+");
	while(!feof(fpj)){
		if((strcmp(jie.bnum,bnum)==0)&&(strcmp(jie.snum,snum)==0))
			i=1;
		else
			fwrite(&jie,sizeof(jie),1,p);
		fread(&jie,sizeof(jie),1,fpj);
	}
	if(i==0){
		printf("\n你没有借过该图书\n正在退出");
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
	fclose(p);//改变book.txt里的数据
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
	fclose(p);//改变student.txt里的数据
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
    printf("\n请按书籍价格扫码赔偿,赔偿款将用于购买图书");
	printf("\n赔偿成功！回到主菜单");
	system("pause");
}
void huan(){//归还图书
	FILE *p;
	bo boo;
	ji jie;
	st stu;
	int j=0;
	char snum[10],bnum[10];
	i=0;
	printf("\n请输入你的学号：");
	scanf("%s",snum);
	printf("\n你借阅了以下图书\n");
	fread(&jie,sizeof(ji),1,fpj);
	printf("书名      编号      作者      价格      出版社    类别      原始库存  借出\n");
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
		printf("\n你没有借阅任何图书！\n\n正在退出");
		system("pause");
		return;
	}
	rewind(fp);
	rewind(fpj);
	printf("\n请输入你归还的图书的编号：");
	scanf("%s",bnum);
	fread(&jie,sizeof(jie),1,fpj);//改变jieyue.txt里的数据
	p=fopen("c:\\jie.txt","wb+");
	while(!feof(fpj)){
		if((strcmp(jie.bnum,bnum)==0)&&(strcmp(jie.snum,snum)==0))
			i=1;
		else
			fwrite(&jie,sizeof(jie),1,p);
		fread(&jie,sizeof(jie),1,fpj);
	}
	if(i==0){
		printf("\n你没有借过该图书\n正在退出");
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
	fclose(p);//改变book.txt里的数据
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
	fclose(p);//改变student.txt里的数据
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
	printf("\n归还成功！回到主菜单");
	system("pause");
}
void cha(){//借阅查询
	char num[10];
	bo boo;
	ji jie;
	printf("\n请输入你的学号：");
	scanf("%s",num);
	fread(&jie,sizeof(ji),1,fpj);
	printf("书名      编号      作者      价格      出版社    类别      原始库存  借出\n");
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
	printf("\n查询完毕！回到主菜单");
	system("pause");
}
main(){
	if((fp=fopen("c:\\book.txt","rb+"))==NULL){

		if((fp=fopen("c:\\book.txt","wb+"))!=NULL)
				   printf("数据储存文件1创建成功\n");
	}
	if((fpj=fopen("c:\\jieyue.txt","rb+"))==NULL){
		if((fpj=fopen("c:\\jieyue.txt","wb+"))!=NULL)
				   printf("数据储存文件2创建成功\n");
	}
	if((fps=fopen("c:\\student.txt","rb+"))==NULL){
		if((fps=fopen("c:\\student.txt","wb+"))!=NULL)
				   printf("数据储存文件3创建成功\n");
	}
int o = 0;
char admin[10] = { 0 };
char password[10] = { 0 };
printf("****************************欢迎使用图书信息管理系统!*************************");
int  i, j, k, l, m;//界面设计
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
printf("请输入用户名:");
printf("\n");
printf("请输入密码:\n");
while (o < 3)
{
scanf("%s", admin);
scanf("%s", password);
printf("\n");
if (strcmp(password, "666666") == 0&&strcmp(admin, "liu") == 0)
{
printf("登录成功\n");
break;
}
else
{
o++;
if (o != 3)
printf("再输入一次用户名和密码");
printf("\n");
}
}
if (o == 3)
{
printf("密码错误三次退出登录界面\n");
exit(0);
system("pause");}
	menu();
	printf("\n  选项:");
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
	printf("\n  选项:");
	scanf("%d",&xuan);
	}
}
