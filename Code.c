#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>


pthread_mutex_t lockt=PTHREAD_MUTEX_INITIALIZER;
int s0[3];
int s1[3];
int s2[3];

void exit1()
{
	sleep(2);
	exit(0);
}	
int assign(int x,int y)
{
	int i=1;
	if(y==0)
	{
		if(s1[x]==1 || s2[x]==1)
		{
			printf("\n 2 student have different resource.");
			exit1();
		}
	}
	if(y==1)
	{
		if(s0[x]==1 || s2[x]==1)
		{
			printf("\n 2 student have different resource.");
			exit1();
		}
	}
	if(y==2)
	{
		if(s0[x]==1 || s1[x]==1)
		{
			printf("\n 2 student have different resource.");
			exit1();
		}
	}
	return i;
}
void *student0()
{
	printf("\nPress(1/2/3) for items are (pen/paper/question paper)\n");
	printf("choose items from the above for student 1: ");
	int a;
	pthread_mutex_lock(&lockt);	
	scanf("%d",&a);
	if(a==1)
	{
		s0[0]=assign(0,0);
	}
	else
		{ if(a==2)
			{
				s0[1]=assign(1,0);
			}
		else
			{ if(a==3)
				{
					s0[2]=assign(2,0);
				}
			else
				{
			printf(" A student isn't configured to contain this.\n");
		}}
	}
	pthread_mutex_unlock(&lockt);
}
void *student1()
{

	printf("choose items for student 2: ");
	int a;
	pthread_mutex_lock(&lockt);	
	scanf("%d",&a);
	if(a==1)
	{
		s1[0]=assign(0,1);
	}
	else{ if(a==2)
	{
		s1[1]=assign(1,1);
	}
	else{ if(a==3)
	{
		s1[2]=assign(2,1);
	}
	else
	{
		printf(" A student isn't configured to contain this.\n");
	}}}
	pthread_mutex_unlock(&lockt);
}
void *student2()
{
	printf("choose items for student 3: ");
	int a;
	pthread_mutex_lock(&lockt);	
	scanf("%d",&a);
	if(a==1)
	{
		s2[0]=assign(0,2);
	}
	else{ if(a==2)
		{
			s2[1]=assign(1,2);
		}
		else{ if(a==3)
			{
				s2[2]=assign(2,2);
			}
		    else
			{
			printf("A student isn't configured to contain this.\n");
			}
		  }
	}
	pthread_mutex_unlock(&lockt);
}
int checking(int a,int b)
{   	int c=0;
	if (a==1 && b==2 || a==2 && b==1)
		{ 										
			c=3;
		}
	else{ if (a==1 && b==3 || a==3 && b==1)
		{
			c=2;
		}
		else{ if (a==2 && b==3 || a==3 && b==2)
			{
				c=1;
			}
			else
			{
				printf("\nPlease choose correct input!\n");
				exit1();
			}
		   }
	}
	return c;
}
void checking1(int c)
{
if(s0[c-1]==1)
		{		
		 	printf("1st Student has the end item and he completes the task\n\n");
			sleep(1.5);
		}
		else{ if(s1[c-1]==1)
		{
			printf("2nd Student has the end item and he completes the task \n");
			sleep(1.5);
		}
		else{ if(s2[c-1]==1)
		{
			printf("3rd Student has the end item and he completes the task \n");
			sleep(1.5);
		}
		else { printf("\n Student have end item has either complete task.\n");
			}
		}
	}
	return;
}
void *table()
{
	int i,a,b,c,d,e,f;
		pthread_mutex_lock(&lockt);		
		a=1,b=2;
		printf("\nTeacher places Pen and Paper on the table\n");
		sleep(2);
		c=checking(a,b);
		checking1(c);
		pthread_mutex_unlock(&lockt);
		pthread_mutex_lock(&lockt);		
		a=2,b=3;
		printf("\nTeacher places Question Paper and Paper on the table\n");
		sleep(2);
		c=checking(a,b);
		checking1(c);
		pthread_mutex_unlock(&lockt);
		pthread_mutex_lock(&lockt);		
		a=1,b=3;
		printf("\nTeacher places Pen and Question Paper on the table\n");
		sleep(2);
		c=checking(a,b);
		checking1(c);
		pthread_mutex_unlock(&lockt);
}

void main()
{
	int a;pthread_t Std0;
	pthread_t Std1;
	pthread_t Std2;
	pthread_t Tea1;
	printf("OS ASSIGNMENT\n");
	system("clear");	
printf("This contain 3 cases: Case 1:Exam Hall, Case 2: Library, Case 3: Served book\n");
	scanf("%d",&a);
switch(a)
{
	case 1:
		printf("\nCAse 1: Exam Hall\n");
		pthread_create(&Std0,NULL,student0,NULL);
		pthread_join(Std0,NULL);
		pthread_create(&Std1,NULL,student1,NULL);
		pthread_join(Std1,NULL);	
		pthread_create(&Std2,NULL,student2,NULL);
		pthread_join(Std2,NULL);
		pthread_create(&Tea1,NULL,table,NULL);
		pthread_join(Tea1,NULL);
		printf("\n\nCase 1 Exam Hall is done.\n");
		int a;
		printf("\npress 0 to other case ,press any key to exit :  ");
		scanf("%d",&a);
		if (a==0)
		{
			main();
		}
		else {exit1();}
		break;
	case 2:
		{printf("\ncase 2: Library\n");
		int p[30],pr[30],bt[30],temp,max,wt[30],ta[30],sum=0,i,j,n;
		int c=0,d=0;
		wt[0]=0;
		printf("Enter the number of persons=");
		scanf("%d",&n);
		printf("choose (0/1)for (teacher/student)\n");
		for(i=0;i<n;i++)
		{
			p[i]=i+1;
			bt[i]=1;
			printf("Who arrived %d? =",i+1);
			scanf("%d",&pr[i]);
		}
		for(i=0;i<n;i++)
		{
		   	max=i;
			for(j=i+1;j<n;j++)
			{
				if(pr[j] <pr[max])
				max=j;
			}
			temp=pr[max];
			pr[max]=pr[i];
			pr[i]=temp;
			temp=bt[max];
			bt[max]=bt[i];
			bt[i]=temp;
			temp=p[max];
			p[max]=p[i];
			p[i]=temp;
		}

		for(i=0;i<n;i++)
		{     
			wt[i+1]=bt[i]+wt[i];
			ta[i]=bt[i]+wt[i];
			sum+=ta[i];
		}
		for(i=0;i<n;i++)
		{
			printf("\nWaiting time for %d person is =%d",p[i],wt[i]);
		}
		printf("\n\nCase 2 Library is done\n");
		int a;
		printf("\npress 0 to other case ,press any key to exit :  ");
		scanf("%d",&a);
		if (a==0)
		{
			main();
		}
		else {exit1();}
		break;
		}
	case 3:
		{printf("\nCase 3:Served book\n");
		int p[30],pr[30],bt[30],temp,max,wt[30],ta[30],sum=0,i,j,n;
		int c=0,d=0;
		wt[0]=0;
		printf("Enter the number of persons=");
		scanf("%d",&n);
		printf("choose (0/1)for (teacher/student)\n");
		for(i=0;i<n;i++)
		{
			p[i]=i+1;
			bt[i]=1;
			printf("\t Who arrived %d? =",i+1);
			scanf("%d",&pr[i]);
			if(pr[i]==0)
			{
				c=c+1;
				
			}
			if(pr[i]==0 && d==1)
			{
				
				pr[i]=pr[i]+1;
				d=0;
			}
			if(c==3)
			{
				c=0;
				d=1;
				continue;
			}
		}
		for(i=0;i<n;i++)
		{
	   		max=i;
			for(j=i+1;j<n;j++)
			{
				if(pr[j] <pr[max])
				max=j;
			}
			temp=pr[max];
			pr[max]=pr[i];
			pr[i]=temp;
			temp=bt[max];
			bt[max]=bt[i];
			bt[i]=temp;
			temp=p[max];
			p[max]=p[i];
			p[i]=temp;
		}

		for(i=0;i<n;i++)
		{     
			wt[i+1]=bt[i]+wt[i];
			ta[i]=bt[i]+wt[i];
			sum+=ta[i];
		}
		for(i=0;i<n;i++)
		{
			printf("\nWaiting time for person %d is =%d",p[i],wt[i]);
			
		}
	
		printf("\n\nCase 3 Served Book is done.\n");
		int a;
		printf("\npress 0 to other case ,press any key to exit : ");
		scanf("%d",&a);
		if (a==0)
		{
			main();
		}
		else {exit1();}
		break;
	}

default:
	printf("You choose incorrect case");exit1();
}
}
