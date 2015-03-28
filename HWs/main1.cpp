#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int A=0,B=0,x=0,times=0,wins=0;
	int a[3],b[3];		//a-->the ranNums,b-->the player guess
	int ranNum[10]={0};	//ranNum[x]=1 means x is a random number.
	char c='Y';			//from the keyboard

	cout<<"需要玩游戏吗（Y/N）？"<<endl;
	cin>>c;
	while(c=='Y')
	{
		times++;

		srand((int)time(0));		//the system time as a seed

		for (int i=0;i<=2;i++)
		{
			x=rand()%10;
			while (ranNum[x]==1)	//make sure that the numbers won't repeat
				x=rand()%10;
			a[i]=x;
			ranNum[x]=1;			
		}

		for (int i=0;i<10;i++)
		{
			ranNum[i]=0;
		}

		for (int i=1;i<=7;i++)
		{
			A=0;B=0;
			cout<<"请输入你猜测的数字:"<<endl;
			cin>>b[0]>>b[1]>>b[2];

			for (int j=0;j<=2;j++)		//calculate A,B
			{
				for (int k=0;k<=2;k++)
				{
					if (a[k]==b[j])
					{
						if (j==k)
							A++;
						else
							B++;
					}
				
				}
			}

			if (A==3 && B==0)			//judge the result
			{
				cout<<"恭喜，你猜对了\n";
				wins++;
				break;
			}
			cout<<A<<"A"<<B<<"B\n";
			if (i==7 && A!=3)
			{
				cout<<"很遗憾，你没有在规定次数内猜对。答案是 "<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
			}

		}

		cout<<"需要玩游戏吗（Y/N）？"<<endl;
		cin>>c;
	}

	cout<<"你一共玩了"<<times<<"局，赢了"<<wins<<"局，输了"<<times-wins<<"局"<<endl;
	system("pause");
	return(0);
}