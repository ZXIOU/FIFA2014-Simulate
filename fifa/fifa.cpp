#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <windows.h>
using namespace std;

class Player
{
	public:
		Player()
		{
			position=100;	
			name="no";
			number=0;
			goals=0;
		}
		
		Player(string a,string b,int c)
		{
			position=a;	
			name=b;
			number=c;
			goals=0;
		}
		
		~Player()
		{};
		
		void goalsPlus()
		{
			goals++;
		} 
		
		string getName() const
		{
			return name;
		}
		
		string getPosition() const
		{
			return position;
		}
		
		int getNumber() const
		{
			return number;
		}
		
		int getGoals() const
		{
			return goals;	
		}
		
	private:
		string name;
		string position;
		int number;
		int goals;
};

class Country
{
	public:
		Country()
		{
			name="nothing";
			win=0;
			lose=0;
			goals=0;
			dogfall=0;
			gf=0;
			ga=0;
			gd=0;
			oldRow=-1;
			oldCol=-1; 
		}
		
		Country(string s)
		{
			name=s;
			win=0;
			lose=0;
			goals=0;
			dogfall=0;
			gf=0;
			ga=0;
			gd=0;
			oldRow=-1;
			oldCol=-1; 
		}
		
		Country(string s,int x,int y,vector<Player> ss)
		{
			name=s;
			win=0;
			lose=0;
			goals=0;
			dogfall=0;
			gf=0;
			ga=0;
			gd=0;
			oldRow=x;
			oldCol=y; 
			for(int i=0;i<23;i++)
			  player.push_back(ss[i]);
		}
	/*	Country & operator =(const Country & s)
		{
			name=s.getName();
			win=s.getWin();
			lose=s.getLose();
			dogfall=s.getDogfall();
			for(int i=0;i<s.getPlayer().size();i++)
			  player.push_back(s.getPlayer()[i]);
		}
		*/		
		~Country()
		{}
		
		void setName(const string & s)
		{
			name=s;
		}
		
		void winPlus()
		{
			win++;
		}

		void losePlus()
		{
			lose++;
		}
		
		void dogfallPlus()
		{
			dogfall++;
		}
		
		void gfPlus(int n)
		{
			gf+=n;
		}
		
		void gaPlus(int n)
		{
			ga+=n;
		}
		
		void setGd()
		{
			gd=gf-ga;
		}
		
		void setGoals()
		{
			goals=3*win+dogfall;
		}
		
		void setOld(int n,int m)
		{
			oldRow=n;
			oldCol=m;	
		}
		
		void playerPush(Player & s)
		{
			player.push_back(s); 
		}
		
		string getName() const
		{
			return name;
		}
		
		int getWin() const
		{
			return win;
		}
		
		int getLose() const
		{
			return lose;
		}
		
		int getDogfall() const
		{
			return dogfall;
		}
		
		int getGoals() const
		{
			return goals;
		}
		
		int getGf() const
		{
			return gf;
		}
		
		int getGa() const
		{
			return ga;
		}
		
		int getGd() const
		{
			return gd;
		}
		
		int getOldRow() const
		{
			return oldRow;
		}
		
		int getOldCol() const
		{
			return oldCol;
		}
		
		Player & getPlayer(int n)
		{
			return player[n];
		}
		
		vector<Player> & getPlayer() 
		{
			return player;
		}
		
		void setPlayer(vector<Player> s)
		{
			for(int i=0;i<23;i++)
			  player.push_back(s[i]);
		}
		
	private:
		string name;
		int win;                 //胜场 
		int lose;                //败场 
		int dogfall;             //平局 
		int goals;               //分数 
		int gf;					 //进球数
		int ga;					 //输球数
		int gd;					 //净胜球 
		vector<Player> player;   //球员数组 
		int oldRow; 			 //原先的行 
		int oldCol;              //原先的列 
};

class Fifa
{
	public:
		Fifa(int gradeRow,int gradeCol,int groupRow,int groupCol):grade(gradeRow),group(groupRow)
		{
			for(int i=0;i<gradeRow;i++)  
               grade[i].resize(gradeCol);
                
            for(int i=0;i<groupRow;i++)  
                group[i].resize(groupCol);
          	  
            int n=0;
			ifstream in,in2; 
		
			//初始化四档
			in.open("country32.txt");
			for(string str;in>>str;n++)
			{
				int k;
				string s1,s2;
				if(n<8)
				{
					grade[0][n].setName(str);
				//	cout<<grade[0][n].getName()<<endl;
					for(int i=0;i<23;i++)
					{
						in>>k>>s1>>s2;
						Player temp(s1,s2,k);
						grade[0][n].playerPush(temp);
					}
				}
				else if(n<15)
				{
					grade[1][n-8].setName(str);
				//	cout<<grade[1][n-8].getName()<<endl;
					for(int i=0;i<23;i++)
					{
						in>>k>>s1>>s2;
						Player temp(s1,s2,k);
						grade[1][n-8].playerPush(temp);
					}
				//	for(int i=0;i<23;i++)
				//		cout<<grade[1][n-8].getPlayer()[i].getName()<<endl;
				}
				else if(n<23)
				{
					grade[2][n-15].setName(str);
					for(int i=0;i<23;i++)
					{
						in>>k>>s1>>s2;
						Player temp(s1,s2,k);
						grade[2][n-15].playerPush(temp);
					}
				}
				else
				{
					grade[3][n-23].setName(str);
			  	    for(int i=0;i<23;i++)
					{
						in>>k>>s1>>s2;
						Player temp(s1,s2,k);
						grade[3][n-23].playerPush(temp);
					}
				}	
			}
			in.close();
			
			//初始化八组 
			for(int i=0;i<8;i++)
				for(int k=0;k<4;k++)
					group[i][k].setName("nothing");
					
			//初始化场馆 
			in2.open("venues.txt");
			for(string str;getline(in2,str);)
			  venues.push_back(str);
			in2.close();
		} 
		
		~Fifa()
		{}
		
		string swap_()
		{
			int random=rand()%9;
			Country temp=grade[3][random];
			grade[3][random]=grade[3][8];
			//swap(grade[3][random],grade[3][8]);
			grade[1][7]=temp;
			//grade[1].push_back(grade[3][8]);
			return temp.getName();
		}
		
		void setGroupVenues(string s)
		{
			groupVenues.push_back(s); 
		}
		
		void setFinals8(Country s)
		{
			finals8.push_back(s); 
		}
		
		void setFinals4(Country s)
		{
			finals4.push_back(s); 
		}
		
		void setFinals2(Country s)
		{
			finals2.push_back(s); 
		}
		
		void setFinals(Country s)
		{
			finals.push_back(s); 
		}
		
		void setFinals8Venues(string s)
		{
			finals8Venues.push_back(s);
		}
		
		void setFinals4Venues(string s)
		{
			finals4Venues.push_back(s);
		}
		
		void setFinals2Venues(string s)
		{
			finals2Venues.push_back(s);
		}
		
		void setFinalsVenues(string s)
		{
			finalsVenues.push_back(s);
		}
		
		vector<Country> & getFinals8()
		{
			return finals8; 
		}
		
		vector<Country> & getFinals4()
		{
			return finals4; 
		}
		
		vector<Country> & getFinals2()
		{
			return finals2; 
		}
		
		vector<Country> & getFinals()
		{
			return finals; 
		}
		
		string printGrade(int n,int m) const
		{
			return grade[n][m].getName();
		}
		
		string printGroup(int n,int m) const
		{
			return group[n][m].getName();
		}
		
		string printVenues(int n) const
		{
			return venues[n];
		}
		
		Country & getGroup(int i,int k) 
		{
			return group[i][k];
		}
		
		vector<Country> & getGroupOne(int i) 
		{
			return group[i];
		}
		
		Country  getGrade(int i,int k) const
		{
			return grade[i][k];
		}
		
		string getGroupVenues(int m) const
		{
			return groupVenues[m];
		}
		
		string getVenues(int n) const
		{
			return venues[n];
		}
		
		string getFinals8Venues(int n)
		{
			return finals8Venues[n];
		}
		
		string getFinals4Venues(int n)
		{
			return finals4Venues[n];
		}
		
		string getFinals2Venues(int n)
		{
			return finals2Venues[n];
		}
		
		string getFinalsVenues(int n)
		{
			return finalsVenues[n];
		}
		void groupSeparate()
		{
			string s;
			//第一档分组 
			group[0][0]=grade[0][0];
			for(int i=1;i<8;i++)
			{
        	flag1:
				int random=rand()%8;
				if(group[random][0].getName()=="nothing")
			  	  group[random][0]=grade[0][i];
				else
			  	  goto flag1;
			}
			//第二档分组 
			flag2:
				int random1=rand()%8;
				s=group[random1][0].getName();
				if(s=="Brazil(hosts)"||s=="Argentina"||s=="Columbia"||s=="Uruguay")
		  	  	  group[random1][1]=grade[1][7];
		  		else
		  	  	  goto flag2;
			flag3:
				int random2=rand()%8;
				s=group[random2][0].getName(); 
				if(s=="Spain"||s=="Germany"||s=="Belgium"||s=="Switzerland")
		  		  group[random2][1]=grade[1][0];
		  		else
		 	 	  goto flag3;
			flag4:
				int random3=rand()%8;
				s=group[random3][0].getName();
				if((s=="Spain"||s=="Germany"||s=="Belgium"||s=="Switzerland")&&(group[random3][1].getName()=="nothing"))
				  group[random3][1]=grade[1][1];
			  	else
			  	  goto flag4;
			for(int i=2;i<7;i++)
			{
        	flag5:
				int random=rand()%8;
				if(group[random][1].getName()=="nothing")
				  group[random][1]=grade[1][i];
				else
				  goto flag5;
			}
			//第三档分组 
			for(int i=0;i<8;i++)
			{
        	flag6:
				int random=rand()%8;
				if(group[random][2].getName()=="nothing")
				  group[random][2]=grade[2][i];
				else
				  goto flag6;
			}
			//第四档分组 
			for(int i=0;i<8;i++)
			{
        	flag7:
				int random=rand()%8;
				if(group[random][3].getName()=="nothing")
				  group[random][3]=grade[3][i];
				else
				  goto flag7;
			}
		}	
		
		
	private:
		vector<vector<Country> > grade;
		vector<vector<Country> > group;
		vector<string> venues;
		vector<string> groupVenues;
		vector<string> finals8Venues;
		vector<string> finals4Venues;
		vector<string> finals2Venues;
		vector<string> finalsVenues;
		vector<Country> finals8;
		vector<Country> finals4;
		vector<Country> finals2;
		vector<Country> finals;
}; 

void groupShow(Fifa &fifa);
void groupGamePrintBySquads(Fifa & fifa);
void groupGamePrintByDate(Fifa & fifa);
void groupGame(Fifa & fifa);
void game1(Fifa & fifa,int x1,int y1,int x2,int y2);

void groupShow(Fifa &fifa)
{
	ofstream out("finalDraw.txt");
	out<<"First stage:"<<endl;	
	
	//原先的四档
	for(int i=0;i<4;i++)
	{
		out<<"pot"<<i+1<<endl;
		switch(i)
		{
			case 0:	for(int k=0;k<8;k++) out<<"  "<<fifa.printGrade(i,k)<<endl;break;
			case 1: for(int k=0;k<7;k++) out<<"  "<<fifa.printGrade(i,k)<<endl;break;
			case 2: for(int k=0;k<8;k++) out<<"  "<<fifa.printGrade(i,k)<<endl;break;
			case 3: for(int k=0;k<9;k++) out<<"  "<<fifa.printGrade(i,k)<<endl;break;
		}
	}
	
	//进行调整
	out<<endl;
	out<<"One European team was first randomly drawn from Pot 4 andplaced into Pot 2: ";
	out<<fifa.swap_()<<endl<<endl;
	//变成4*8的四档  
	out<<"After first draw:"<<endl;
	for(int i=0;i<4;i++)
	{
		out<<"pot"<<i+1<<endl;
		for(int k=0;k<8;k++)
		  out<<"  "<<fifa.printGrade(i,k)<<endl;
	}
	
	//进行分组 
	fifa.groupSeparate();
	out<<endl;
	out<<"The Final Draw:"<<endl;
	for(int i=0;i<8;i++)
	{
		out<<"group"<<i+1<<endl;
		for(int k=0;k<4;k++)
		  out<<"  "<<fifa.printGroup(i,k)<<endl;
	}
} 

void groupGamePrintBySquads(Fifa & fifa)
{
	ifstream in1,in2;
	in2.open("groupGamePrintBySquads.txt");
	ofstream out("schedule16.txt");
	out<<"Matches by squads"<<endl;
	for(int i=0;i<8;i++)
	{
		int x,y;
		out<<"Group"<<char(i+65)<<endl;
		in1.open("xunhuan.txt");
		for(int k=0;k<6;k++)
		{
			string str;
			int random=rand()%12; 
			fifa.setGroupVenues(fifa.printVenues(random));
			in1>>x>>y;
			getline(in2,str);
			out<<"·";
			out<<fifa.printGroup(i,x)<<" vs ";
			out<<fifa.printGroup(i,y)<<",";
			out<<fifa.printVenues(random)<<","<<str<<endl;
		}
		in1.close();
	}
}

void groupGamePrintByDate(Fifa & fifa)
{
	ifstream in("groupGamePrintByDate.txt");
	ofstream out("schedule16.txt",ios::app);
	out<<endl<<"Matches by date"<<endl;
	int n;
	while(in>>n)
	{
		out<<"June "<<n<<endl;
		int x1,y1,x2,y2,m;
		for(int i=0;i<4;i++)
		{
			in>>x1>>y1>>x2>>y2>>m;
			out<<"·";
			out<<fifa.printGroup(x1,y1)<<" vs ";
			out<<fifa.printGroup(x2,y2)<<",";
			out<<fifa.getGroupVenues(m)<<endl;
		}
	}
}

void groupGame(Fifa & fifa)
{
	ifstream in("groupGamePrintByDate.txt");
	ofstream out("schedule16.txt",ios::app);
	out<<endl<<"The match Live..."<<endl;
	int n;
	while(in>>n)
	{
		out<<endl<<"June "<<n<<endl;
		int x1,y1,x2,y2,m;
		for(int i=0;i<4;i++)
		{
			in>>x1>>y1>>x2>>y2>>m;
			if(i!=0)
			  out<<endl;
			out<<"Game "<<i+1<<endl;
			out<<"This game is playing in "<<fifa.getGroupVenues(m)<<endl;
			game1(fifa,x1,y1,x2,y2);
		}
	}
}

void game1(Fifa & fifa,int x1,int y1,int x2,int y2)
{
	Country & a= fifa.getGroup(x1,y1);
	Country & b= fifa.getGroup(x2,y2);
	ofstream out("schedule16.txt",ios::app);
	out<<"Group stage:"<<endl;
	out<<a.getName()<<" vs "<<b.getName()<<endl;
	out<<a.getName()<<endl;
	for(int i=0;i<23;i++)
	{ 
	  	out<<"#"<<setw(8)<<setiosflags(ios::left)<<a.getPlayer(i).getNumber();
	  	out<<setw(8)<<setiosflags(ios::left)<<a.getPlayer(i).getPosition();
	  	out<<setw(8)<<setiosflags(ios::left)<<a.getPlayer(i).getName()<<endl;
	}
	out<<b.getName()<<endl;
	for(int i=0;i<23;i++)
	{
		out<<"#"<<setw(8)<<setiosflags(ios::left)<<b.getPlayer(i).getNumber();
	  	out<<setw(8)<<setiosflags(ios::left)<<b.getPlayer(i).getPosition();
	  	out<<setw(8)<<setiosflags(ios::left)<<b.getPlayer(i).getName()<<endl;
	}
	out<<"Playing..."<<endl;
	int random1=rand()%5;
	int random2=rand()%5;
	int m=0,n=0;
	for(int i=0;i<random1+random2;i++)
	{
		int random3=rand()%2;
		int random4=rand()%23;
		if(random3==0)
		{
			if(m!=random1)
			{
				a.getPlayer(random4).goalsPlus();
				//cout<<a.getPlayer()[random4].getGoals()<<endl;
				out<<a.getName()<<"did a goal, and it was "<<"#"<<random4<<a.getPlayer()[random4].getName()<<" did the goal."<<endl;
				m++;
			}  
			else
			{
				b.getPlayer(random4).goalsPlus();
				//cout<<b.getPlayer()[random4].getGoals()<<endl;
				out<<b.getName()<<"did a goal, and it was "<<"#"<<random4<<b.getPlayer()[random4].getName()<<" did the goal."<<endl;	
				n++;
			}	  
		}
		else
		{
			if(n!=random2)
			{
				b.getPlayer(random4).goalsPlus();
				//cout<<b.getPlayer()[random4].getGoals()<<endl;
				out<<b.getName()<<"did a goal, and it was "<<"#"<<random4<<b.getPlayer()[random4].getName()<<" did the goal."<<endl;
				n++;
			}  
			else
			{
				a.getPlayer(random4).goalsPlus();
				//cout<<a.getPlayer()[random4].getGoals()<<endl;
				out<<a.getName()<<"did a goal, and it was "<<"#"<<random4<<a.getPlayer()[random4].getName()<<" did the goal."<<endl;	
				m++;
			}	  
		}
		out<<"Now it is "<<m<<":"<<n<<endl;	  
	}
	if(m>n)
	{
		out<<a.getName()<<" wins with "<<m<<":"<<n<<endl;
		a.winPlus();
		b.losePlus();
	}
	else if(m<n)
	{
		out<<b.getName()<<" wins with "<<n<<":"<<m<<endl;
		b.winPlus();
		a.losePlus();
	}
	else
	{
		out<<"It is a draw with "<<m<<":"<<n<<endl;
		a.dogfallPlus();
		b.dogfallPlus();
	}
	a.gfPlus(m);
	a.gaPlus(n);
	b.gfPlus(n);
	b.gaPlus(m);
}

bool Comp(Country x,Country y)
{
	if(x.getGoals()!=y.getGoals())
	  return x.getGoals()>y.getGoals();
	else if(x.getGd()!=y.getGd())
	  return  x.getGd()>y.getGd();
	else if(x.getGf()!=y.getGf())
	  return  x.getGf()>y.getGf();
}

void groupResultShow(Fifa & fifa)
{
	ofstream out("Result16.txt");
	for(int i=0;i<8;i++)
	{
		for(int k=0;k<4;k++)
		{
			fifa.getGroup(i,k).setGoals();
			fifa.getGroup(i,k).setGd();
		}
		sort(fifa.getGroupOne(i).begin(),fifa.getGroupOne(i).end(),Comp);
		for(int k=0;k<4;k++)
		  fifa.getGroup(i,k).setOld(i,k);
		
		out<<"Final result for group "<<char(i+65)<<endl;
		out<<"Team                     W   D   L   GF  GA  GD  Pts"<<endl;
		for(int k=0;k<4;k++)
		{
			out<<setw(25)<<setiosflags(ios::left)<<fifa.printGroup(i,k);
			out<<setw(4)<<setiosflags(ios::left)<<fifa.getGroup(i,k).getWin();
			out<<setw(4)<<setiosflags(ios::left)<<fifa.getGroup(i,k).getDogfall();
			out<<setw(4)<<setiosflags(ios::left)<<fifa.getGroup(i,k).getLose();
			out<<setw(4)<<setiosflags(ios::left)<<fifa.getGroup(i,k).getGf();
			out<<setw(4)<<setiosflags(ios::left)<<fifa.getGroup(i,k).getGa();
			out<<setw(4)<<setiosflags(ios::left)<<fifa.getGroup(i,k).getGd();
			out<<setw(4)<<setiosflags(ios::left)<<fifa.getGroup(i,k).getGoals()<<endl;
		}
		out<<endl;
	}
}

void setFinal8(Fifa & fifa);
void fianls8GamePrintByDate(Fifa & fifa);
void finals8Game(Fifa & fifa);
void game2(Fifa & fifa,int x,int y);
void finals8ResultShow(Fifa & fifa);

void setFinal8(Fifa & fifa)
{
	ofstream out("team16.txt");
	out<<"Qualified for round of 16:"<<endl;
	for(int i=0;i<8;i++)
		for(int k=0;k<2;k++)
		{
			out<<"·"<<fifa.printGroup(i,k)<<endl;
			Country temp(fifa.getGroup(i,k).getName(),i,k,fifa.getGroup(i,k).getPlayer());
			fifa.setFinals8(temp);
		}
}

void fianls8GamePrintByDate(Fifa & fifa)
{
	ifstream in("finals8GamePrintByDate.txt");
	ofstream out("schedule8.txt");
	out<<"Matches by date"<<endl;
	int l;
	for(int k=0;k<4;k++)
	{
		in>>l;
		out<<"June "<<l<<endl;
		int x,y;
		for(int i=0;i<2;i++)
		{
			int random=rand()%12;
			fifa.setFinals8Venues(fifa.getVenues(random));
			in>>x>>y;
			out<<"·";
			out<<fifa.getFinals8()[x].getName()<<" vs ";
			out<<fifa.getFinals8()[y].getName()<<",";
			out<<fifa.getVenues(random)<<endl;
		}
	}
}

void finals8Game(Fifa & fifa)
{
	ifstream in("finals8GamePrintByDate.txt");
	ofstream out("schedule8.txt",ios::app);
	out<<endl<<"The match Live..."<<endl;
	int n,m=0;
	for(int k=0;k<4;k++)
	{
		in>>n;
		out<<endl<<"June "<<n<<endl;
		int x,y;
		for(int i=0;i<2;i++)
		{
			in>>x>>y;
			if(i!=0)
			  out<<endl;
			out<<"Game "<<i+1<<endl;
			out<<"This game is playing in "<<fifa.getFinals8Venues(m++)<<endl;
			game2(fifa,x,y);
		}
	}
	in.close();
}

void game2(Fifa & fifa,int x,int y)
{
	//cout<<"1"<<endl;
	Country & a= fifa.getFinals8()[x];
	Country & b= fifa.getFinals8()[y];
	ofstream out("schedule8.txt",ios::app);
	out<<"Group stage:"<<endl;
	out<<a.getName()<<" vs "<<b.getName()<<endl;
	out<<a.getName()<<endl;
	for(int i=0;i<23;i++)
	{ 
	  	out<<"#"<<setw(8)<<setiosflags(ios::left)<<a.getPlayer(i).getNumber();
	  	out<<setw(8)<<setiosflags(ios::left)<<a.getPlayer(i).getPosition();
	  	out<<setw(8)<<setiosflags(ios::left)<<a.getPlayer(i).getName()<<endl;
	}
	out<<b.getName()<<endl;
	for(int i=0;i<23;i++)
	{
		out<<"#"<<setw(8)<<setiosflags(ios::left)<<b.getPlayer(i).getNumber();
	  	out<<setw(8)<<setiosflags(ios::left)<<b.getPlayer(i).getPosition();
	  	out<<setw(8)<<setiosflags(ios::left)<<b.getPlayer(i).getName()<<endl;
	}
	out<<"Playing..."<<endl;
	int random1=rand()%5;
	int random2=rand()%5;
	int m=0,n=0;
	for(int i=0;i<random1+random2;i++)
	{
		int random3=rand()%2;
		int random4=rand()%23;
		if(random3==0)
		{
			if(m!=random1)
			{
				fifa.getGroupOne(a.getOldRow())[a.getOldCol()].getPlayer()[random4].goalsPlus();
				out<<a.getName()<<"did a goal, and it was "<<"#"<<random4<<a.getPlayer()[random4].getName()<<" did the goal."<<endl;
				m++;
			}  
			else
			{
				fifa.getGroupOne(b.getOldRow())[b.getOldCol()].getPlayer()[random4].goalsPlus();
				out<<b.getName()<<"did a goal, and it was "<<"#"<<random4<<b.getPlayer()[random4].getName()<<" did the goal."<<endl;	
				n++;
			}	  
		}
		else
		{
			if(n!=random2)
			{
				fifa.getGroupOne(b.getOldRow())[b.getOldCol()].getPlayer()[random4].goalsPlus();
				out<<b.getName()<<"did a goal, and it was "<<"#"<<random4<<b.getPlayer()[random4].getName()<<" did the goal."<<endl;
				n++;
			}  
			else
			{
				fifa.getGroupOne(a.getOldRow())[a.getOldCol()].getPlayer()[random4].goalsPlus();
				out<<a.getName()<<"did a goal, and it was "<<"#"<<random4<<a.getPlayer()[random4].getName()<<" did the goal."<<endl;	
				m++;
			}	  
		}
		out<<"Now it is "<<m<<":"<<n<<endl;	  
	}
	
	
	if(random1==random2)
	{
		
		int random5=rand()%5;
	flag:
		int random6=rand()%5;
		if(random6==random5)
		  goto flag;
		out<<endl<<"because it is a draw,so later there will be a Penalty Shootout!"<<endl;
		out<<"Penalty Shootout is starting..."<<endl;
		for(int i=0;i<random5+random6;i++)
		{
			int random3=rand()%2;
			int random4=rand()%23;
			if(random3==0)
			{
				if(m!=random1+random5)
				{
					fifa.getGroupOne(a.getOldRow())[a.getOldCol()].getPlayer()[random4].goalsPlus();
					out<<a.getName()<<"did a goal, and it was "<<"#"<<random4<<a.getPlayer()[random4].getName()<<" did the goal."<<endl;
					m++;
				}  
				else
				{
					fifa.getGroupOne(b.getOldRow())[b.getOldCol()].getPlayer()[random4].goalsPlus();
					out<<b.getName()<<"did a goal, and it was "<<"#"<<random4<<b.getPlayer()[random4].getName()<<" did the goal."<<endl;	
					n++;
				}	  
			}
			else
			{
				if(n!=random2+random6)
				{
					fifa.getGroupOne(b.getOldRow())[b.getOldCol()].getPlayer()[random4].goalsPlus();
					out<<b.getName()<<"did a goal, and it was "<<"#"<<random4<<b.getPlayer()[random4].getName()<<" did the goal."<<endl;
					n++;
				}  
				else
				{
					fifa.getGroupOne(a.getOldRow())[a.getOldCol()].getPlayer()[random4].goalsPlus();
					out<<a.getName()<<"did a goal, and it was "<<"#"<<random4<<a.getPlayer()[random4].getName()<<" did the goal."<<endl;	
					m++;
				}	  
			}
			out<<"Now it is "<<m<<":"<<n<<endl;	
		}	
	}
	
	if(m>n)
	{
		out<<a.getName()<<" wins with "<<m<<":"<<n<<endl;
		a.winPlus();
		fifa.getGroup(a.getOldRow(),a.getOldCol()).winPlus();
		b.losePlus();
		fifa.getGroup(b.getOldRow(),b.getOldCol()).losePlus();
		
		Country temp(a.getName(),a.getOldRow(),a.getOldCol(),a.getPlayer());
		fifa.setFinals4(temp); 
	}
	else if(m<n)
	{
		out<<b.getName()<<" wins with "<<n<<":"<<m<<endl;
		b.winPlus();
		fifa.getGroup(b.getOldRow(),b.getOldCol()).winPlus();
		a.losePlus();
		fifa.getGroup(a.getOldRow(),a.getOldCol()).losePlus();
		
		Country temp(b.getName(),b.getOldRow(),b.getOldCol(),b.getPlayer());
		fifa.setFinals4(temp);  
	}
	a.gfPlus(m);
	fifa.getGroup(a.getOldRow(),a.getOldCol()).gfPlus(m);
	a.gaPlus(n);
	fifa.getGroup(a.getOldRow(),a.getOldCol()).gaPlus(n);
	b.gfPlus(n);
	fifa.getGroup(b.getOldRow(),b.getOldCol()).gfPlus(n);
	b.gaPlus(m);
	fifa.getGroup(b.getOldRow(),b.getOldCol()).gaPlus(m);
}

void finals8ResultShow(Fifa & fifa)
{
	//cout<<"2"<<endl;
	ofstream out("Result8.txt");
	for(int i=0;i<16;i++)
	{
		fifa.getFinals8()[i].setGoals();
		fifa.getFinals8()[i].setGd();
	}
	//cout<<"2"<<endl;
	sort(fifa.getFinals8().begin(),fifa.getFinals8().end(),Comp);
	out<<"Final result for Finals8 "<<endl;
	out<<"Team                     W   D   L   GF  GA  GD  Pts"<<endl;
	for(int i=0;i<16;i++)
	{
		out<<setw(25)<<setiosflags(ios::left)<<fifa.getFinals8()[i].getName();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals8()[i].getWin();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals8()[i].getDogfall();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals8()[i].getLose();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals8()[i].getGf();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals8()[i].getGa();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals8()[i].getGd();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals8()[i].getGoals()<<endl;
	}
	out<<endl;
}

void setFinal4(Fifa & fifa);
void fianls4GamePrintByDate(Fifa & fifa);
void finals4Game(Fifa & fifa);
void game3(Fifa & fifa,int x,int y); 
void finals4ResultShow(Fifa & fifa);

void setFinal4(Fifa & fifa)
{
	ofstream out("team8.txt");
	out<<"Qualified for round of 8:"<<endl;
	int n=0;
	for(int i=0;i<8;i++)
	  out<<"·"<<fifa.getFinals4()[i].getName()<<endl;
}

void fianls4GamePrintByDate(Fifa & fifa)
{
	ifstream in("finals4GamePrintByDate.txt");
	ofstream out("schedule4.txt");
	out<<"Matches by date"<<endl;
	int n;
	for(int k=0;k<2;k++)
	{
		in>>n;
		out<<"June "<<n<<endl;
		int x,y;
		for(int i=0;i<2;i++)
		{
			int random=rand()%12;
			fifa.setFinals4Venues(fifa.getVenues(random));
			in>>x>>y;
			out<<"·";
			out<<fifa.getFinals4()[x].getName()<<" vs ";
			out<<fifa.getFinals4()[y].getName()<<",";
			out<<fifa.getVenues(random)<<endl;
		}
	}
}

void finals4Game(Fifa & fifa)
{
	ifstream in("finals4GamePrintByDate.txt");
	ofstream out("schedule4.txt",ios::app);
	out<<endl<<"The match Live..."<<endl;
	int n,m=0;
	for(int k=0;k<2;k++)
	{
		in>>n;
		out<<endl<<"June "<<n<<endl;
		int x,y;
		for(int i=0;i<2;i++)
		{
			in>>x>>y;
			if(i!=0)
			  out<<endl;
			out<<"Game "<<i+1<<endl;
			out<<"This game is playing in "<<fifa.getFinals4Venues(m++)<<endl;
			game3(fifa,x,y);
		}
	}
	in.close();
}

void game3(Fifa & fifa,int x,int y)
{
	//cout<<"1"<<endl;
	Country & a= fifa.getFinals4()[x];
	Country & b= fifa.getFinals4()[y];
	ofstream out("schedule4.txt",ios::app);
	out<<"Group stage:"<<endl;
	out<<a.getName()<<" vs "<<b.getName()<<endl;
	out<<a.getName()<<endl;
	for(int i=0;i<23;i++)
	{ 
	  	out<<"#"<<setw(8)<<setiosflags(ios::left)<<a.getPlayer(i).getNumber();
	  	out<<setw(8)<<setiosflags(ios::left)<<a.getPlayer(i).getPosition();
	  	out<<setw(8)<<setiosflags(ios::left)<<a.getPlayer(i).getName()<<endl;
	}
	out<<b.getName()<<endl;
	for(int i=0;i<23;i++)
	{
		out<<"#"<<setw(8)<<setiosflags(ios::left)<<b.getPlayer(i).getNumber();
	  	out<<setw(8)<<setiosflags(ios::left)<<b.getPlayer(i).getPosition();
	  	out<<setw(8)<<setiosflags(ios::left)<<b.getPlayer(i).getName()<<endl;
	}
	out<<"Playing..."<<endl;
	int random1=rand()%5;
	int random2=rand()%5;
	int m=0,n=0;
	for(int i=0;i<random1+random2;i++)
	{
		int random3=rand()%2;
		int random4=rand()%23;
		if(random3==0)
		{
			if(m!=random1)
			{
				fifa.getGroupOne(a.getOldRow())[a.getOldCol()].getPlayer()[random4].goalsPlus();
				out<<a.getName()<<"did a goal, and it was "<<"#"<<random4<<a.getPlayer()[random4].getName()<<" did the goal."<<endl;
				m++;
			}  
			else
			{
				fifa.getGroupOne(b.getOldRow())[b.getOldCol()].getPlayer()[random4].goalsPlus();
				out<<b.getName()<<"did a goal, and it was "<<"#"<<random4<<b.getPlayer()[random4].getName()<<" did the goal."<<endl;	
				n++;
			}	  
		}
		else
		{
			if(n!=random2)
			{
				fifa.getGroupOne(b.getOldRow())[b.getOldCol()].getPlayer()[random4].goalsPlus();
				out<<b.getName()<<"did a goal, and it was "<<"#"<<random4<<b.getPlayer()[random4].getName()<<" did the goal."<<endl;
				n++;
			}  
			else
			{
				fifa.getGroupOne(a.getOldRow())[a.getOldCol()].getPlayer()[random4].goalsPlus();
				out<<a.getName()<<"did a goal, and it was "<<"#"<<random4<<a.getPlayer()[random4].getName()<<" did the goal."<<endl;	
				m++;
			}	  
		}
		out<<"Now it is "<<m<<":"<<n<<endl;	  
	}
	
	
	if(random1==random2)
	{
		
		int random5=rand()%5;
	flag:
		int random6=rand()%5;
		if(random6==random5)
		  goto flag;
		out<<endl<<"because it is a draw,so later there will be a Penalty Shootout!"<<endl;
		out<<"Penalty Shootout is starting..."<<endl;
		for(int i=0;i<random5+random6;i++)
		{
			int random3=rand()%2;
			int random4=rand()%23;
			if(random3==0)
			{
				if(m!=random1+random5)
				{
					fifa.getGroupOne(a.getOldRow())[a.getOldCol()].getPlayer()[random4].goalsPlus();
					out<<a.getName()<<"did a goal, and it was "<<"#"<<random4<<a.getPlayer()[random4].getName()<<" did the goal."<<endl;
					m++;
				}  
				else
				{	fifa.getGroupOne(b.getOldRow())[b.getOldCol()].getPlayer()[random4].goalsPlus();
					out<<b.getName()<<"did a goal, and it was "<<"#"<<random4<<b.getPlayer()[random4].getName()<<" did the goal."<<endl;	
					n++;
				}	  
			}
			else
			{
				if(n!=random2+random6)
				{
					fifa.getGroupOne(b.getOldRow())[b.getOldCol()].getPlayer()[random4].goalsPlus();
					out<<b.getName()<<"did a goal, and it was "<<"#"<<random4<<b.getPlayer()[random4].getName()<<" did the goal."<<endl;
					n++;
				}  
				else
				{
					fifa.getGroupOne(a.getOldRow())[a.getOldCol()].getPlayer()[random4].goalsPlus();
					out<<a.getName()<<"did a goal, and it was "<<"#"<<random4<<a.getPlayer()[random4].getName()<<" did the goal."<<endl;	
					m++;
				}	  
			}
			out<<"Now it is "<<m<<":"<<n<<endl;	
		}	
	}
	
	if(m>n)
	{
		out<<a.getName()<<" wins with "<<m<<":"<<n<<endl;
		a.winPlus();
		fifa.getGroup(a.getOldRow(),a.getOldCol()).winPlus();
		b.losePlus();
		fifa.getGroup(b.getOldRow(),b.getOldCol()).losePlus();
		
		Country temp(a.getName(),a.getOldRow(),a.getOldCol(),a.getPlayer());
		fifa.setFinals2(temp);
	}
	else if(m<n)
	{
		out<<b.getName()<<" wins with "<<n<<":"<<m<<endl;
		b.winPlus();
		fifa.getGroup(b.getOldRow(),b.getOldCol()).winPlus();
		a.losePlus();
		fifa.getGroup(a.getOldRow(),a.getOldCol()).losePlus();
		
		Country temp(b.getName(),b.getOldRow(),b.getOldCol(),b.getPlayer());
		fifa.setFinals2(temp); 
	}
	a.gfPlus(m);
	fifa.getGroup(a.getOldRow(),a.getOldCol()).gfPlus(m);
	a.gaPlus(n);
	fifa.getGroup(a.getOldRow(),a.getOldCol()).gaPlus(n);
	b.gfPlus(n);
	fifa.getGroup(b.getOldRow(),b.getOldCol()).gfPlus(n);
	b.gaPlus(m);
	fifa.getGroup(b.getOldRow(),b.getOldCol()).gaPlus(m);
}

void finals4ResultShow(Fifa & fifa)
{
	//cout<<"2"<<endl;
	ofstream out("Result4.txt");
	for(int i=0;i<8;i++)
	{
		fifa.getFinals4()[i].setGoals();
		fifa.getFinals4()[i].setGd();
	}
	//cout<<"2"<<endl;
	sort(fifa.getFinals4().begin(),fifa.getFinals4().end(),Comp);
	out<<"Final result for Finals4 "<<endl;
	out<<"Team                     W   D   L   GF  GA  GD  Pts"<<endl;
	for(int i=0;i<8;i++)
	{
		out<<setw(25)<<setiosflags(ios::left)<<fifa.getFinals4()[i].getName();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals4()[i].getWin();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals4()[i].getDogfall();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals4()[i].getLose();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals4()[i].getGf();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals4()[i].getGa();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals4()[i].getGd();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals4()[i].getGoals()<<endl;
	}
	out<<endl;
}

void setFinal2(Fifa & fifa);
void fianls2GamePrintByDate(Fifa & fifa);
void finals2Game(Fifa & fifa);
void game4(Fifa & fifa,int x,int y); 
void finals2ResultShow(Fifa & fifa);

void setFinal2(Fifa & fifa)
{
	ofstream out("team4.txt");
	out<<"Qualified for round of 4:"<<endl;
	int n=0;
	for(int i=0;i<4;i++)
	  out<<"·"<<fifa.getFinals2()[i].getName()<<endl;
}

void fianls2GamePrintByDate(Fifa & fifa)
{
	ifstream in("finals2GamePrintByDate.txt");
	ofstream out("schedule2.txt");
	out<<"Matches by date"<<endl;
	int n;
	for(int k=0;k<2;k++)
	{
		in>>n;
		out<<"July "<<n<<endl;
		int x,y;
		int random=rand()%12;
		fifa.setFinals2Venues(fifa.getVenues(random));
		in>>x>>y;
		out<<"·";
		out<<fifa.getFinals4()[x].getName()<<" vs ";
		out<<fifa.getFinals4()[y].getName()<<",";
		out<<fifa.getVenues(random)<<endl;
	}
}

void finals2Game(Fifa & fifa)
{
	ifstream in("finals2GamePrintByDate.txt");
	ofstream out("schedule2.txt",ios::app);
	out<<endl<<"The match Live..."<<endl;
	int n,m=0;
	for(int k=0;k<2;k++)
	{
		in>>n;
		out<<endl<<"July "<<n<<endl;
		int x,y;
		in>>x>>y;
		out<<"This game is playing in "<<fifa.getFinals2Venues(m++)<<endl;
		game4(fifa,x,y);
	}
	in.close();
}

void game4(Fifa & fifa,int x,int y)
{
	//cout<<"1"<<endl;
	Country & a= fifa.getFinals2()[x];
	Country & b= fifa.getFinals2()[y];
	ofstream out("schedule2.txt",ios::app);
	out<<"Group stage:"<<endl;
	out<<a.getName()<<" vs "<<b.getName()<<endl;
	out<<a.getName()<<endl;
	for(int i=0;i<23;i++)
	{ 
	  	out<<"#"<<setw(8)<<setiosflags(ios::left)<<a.getPlayer(i).getNumber();
	  	out<<setw(8)<<setiosflags(ios::left)<<a.getPlayer(i).getPosition();
	  	out<<setw(8)<<setiosflags(ios::left)<<a.getPlayer(i).getName()<<endl;
	}
	out<<b.getName()<<endl;
	for(int i=0;i<23;i++)
	{
		out<<"#"<<setw(8)<<setiosflags(ios::left)<<b.getPlayer(i).getNumber();
	  	out<<setw(8)<<setiosflags(ios::left)<<b.getPlayer(i).getPosition();
	  	out<<setw(8)<<setiosflags(ios::left)<<b.getPlayer(i).getName()<<endl;
	}
	out<<"Playing..."<<endl;
	int random1=rand()%5;
	int random2=rand()%5;
	int m=0,n=0;
	for(int i=0;i<random1+random2;i++)
	{
		int random3=rand()%2;
		int random4=rand()%23;
		if(random3==0)
		{
			if(m!=random1)
			{
				fifa.getGroupOne(a.getOldRow())[a.getOldCol()].getPlayer()[random4].goalsPlus();
				out<<a.getName()<<"did a goal, and it was "<<"#"<<random4<<a.getPlayer()[random4].getName()<<" did the goal."<<endl;
				m++;
			}  
			else
			{
				fifa.getGroupOne(b.getOldRow())[b.getOldCol()].getPlayer()[random4].goalsPlus();
				out<<b.getName()<<"did a goal, and it was "<<"#"<<random4<<b.getPlayer()[random4].getName()<<" did the goal."<<endl;	
				n++;
			}	  
		}
		else
		{
			if(n!=random2)
			{
				fifa.getGroupOne(b.getOldRow())[b.getOldCol()].getPlayer()[random4].goalsPlus();
				out<<b.getName()<<"did a goal, and it was "<<"#"<<random4<<b.getPlayer()[random4].getName()<<" did the goal."<<endl;
				n++;
			}  
			else
			{
				fifa.getGroupOne(a.getOldRow())[a.getOldCol()].getPlayer()[random4].goalsPlus();
				out<<a.getName()<<"did a goal, and it was "<<"#"<<random4<<a.getPlayer()[random4].getName()<<" did the goal."<<endl;	
				m++;
			}	  
		}
		out<<"Now it is "<<m<<":"<<n<<endl;	  
	}
	
	
	if(random1==random2)
	{
		
		int random5=rand()%5;
	flag:
		int random6=rand()%5;
		if(random6==random5)
		  goto flag;
		out<<endl<<"because it is a draw,so later there will be a Penalty Shootout!"<<endl;
		out<<"Penalty Shootout is starting..."<<endl;
		for(int i=0;i<random5+random6;i++)
		{
			int random3=rand()%2;
			int random4=rand()%23;
			if(random3==0)
			{
				if(m!=random1+random5)
				{
					fifa.getGroupOne(a.getOldRow())[a.getOldCol()].getPlayer()[random4].goalsPlus();
					out<<a.getName()<<"did a goal, and it was "<<"#"<<random4<<a.getPlayer()[random4].getName()<<" did the goal."<<endl;
					m++;
				}  
				else
				{
					fifa.getGroupOne(b.getOldRow())[b.getOldCol()].getPlayer()[random4].goalsPlus();
					out<<b.getName()<<"did a goal, and it was "<<"#"<<random4<<b.getPlayer()[random4].getName()<<" did the goal."<<endl;	
					n++;
				}	  
			}
			else
			{
				if(n!=random2+random6)
				{
					fifa.getGroupOne(b.getOldRow())[b.getOldCol()].getPlayer()[random4].goalsPlus();
					out<<b.getName()<<"did a goal, and it was "<<"#"<<random4<<b.getPlayer()[random4].getName()<<" did the goal."<<endl;
					n++;
				}  
				else
				{
					fifa.getGroupOne(a.getOldRow())[a.getOldCol()].getPlayer()[random4].goalsPlus();
					out<<a.getName()<<"did a goal, and it was "<<"#"<<random4<<a.getPlayer()[random4].getName()<<" did the goal."<<endl;	
					m++;
				}	  
			}
			out<<"Now it is "<<m<<":"<<n<<endl;	
		}	
	}
	
	if(m>n)
	{
		out<<a.getName()<<" wins with "<<m<<":"<<n<<endl;
		a.winPlus();
		fifa.getGroup(a.getOldRow(),a.getOldCol()).winPlus();
		b.losePlus();
		fifa.getGroup(b.getOldRow(),b.getOldCol()).losePlus();
		
		Country temp(a.getName(),a.getOldRow(),a.getOldCol(),a.getPlayer());
		fifa.setFinals(temp);
		
		Country temp1(b.getName(),b.getOldRow(),b.getOldCol(),b.getPlayer());
		fifa.setFinals(temp1);
	}
	else if(m<n)
	{
		out<<b.getName()<<" wins with "<<n<<":"<<m<<endl;
		b.winPlus();
		fifa.getGroup(b.getOldRow(),b.getOldCol()).winPlus();
		a.losePlus();
		fifa.getGroup(a.getOldRow(),a.getOldCol()).losePlus();
		
		Country temp(b.getName(),b.getOldRow(),b.getOldCol(),b.getPlayer());
		fifa.setFinals(temp);
		
		Country temp1(a.getName(),a.getOldRow(),a.getOldCol(),a.getPlayer());
		fifa.setFinals(temp1); 
	}
	a.gfPlus(m);
	fifa.getGroup(a.getOldRow(),a.getOldCol()).gfPlus(m);
	a.gaPlus(n);
	fifa.getGroup(a.getOldRow(),a.getOldCol()).gaPlus(n);
	b.gfPlus(n);
	fifa.getGroup(b.getOldRow(),b.getOldCol()).gfPlus(n);
	b.gaPlus(m);
	fifa.getGroup(b.getOldRow(),b.getOldCol()).gaPlus(m);
}

void finals2ResultShow(Fifa & fifa)
{
	//cout<<"2"<<endl;
	ofstream out("Result2.txt");
	for(int i=0;i<4;i++)
	{
		fifa.getFinals2()[i].setGoals();
		fifa.getFinals2()[i].setGd();
	}
	//cout<<"2"<<endl;
	sort(fifa.getFinals2().begin(),fifa.getFinals2().end(),Comp);
	out<<"Final result for Finals2 "<<endl;
	out<<"Team                     W   D   L   GF  GA  GD  Pts"<<endl;
	for(int i=0;i<4;i++)
	{
		out<<setw(25)<<setiosflags(ios::left)<<fifa.getFinals2()[i].getName();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals2()[i].getWin();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals2()[i].getDogfall();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals2()[i].getLose();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals2()[i].getGf();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals2()[i].getGa();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals2()[i].getGd();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals2()[i].getGoals()<<endl;
	}
	out<<endl;
}

void setFinals(Fifa & fifa);
void fianlsGamePrintByDate(Fifa & fifa);
void finalsGame(Fifa & fifa);
void game5(Fifa & fifa,int x,int y); 
void finalsResultShow(Fifa & fifa);

void setFinals(Fifa & fifa)
{
	ofstream out("team(finals).txt");
	out<<"Qualified for finals :"<<endl;
	int n=0;
	out<<"The two teams will win the championship!"<<endl; 
	out<<"·"<<fifa.getFinals2()[0].getName()<<endl;
	out<<"·"<<fifa.getFinals2()[2].getName()<<endl;
	out<<"The two teams will won the second runner up!"<<endl;
	out<<"·"<<fifa.getFinals2()[1].getName()<<endl;
	out<<"·"<<fifa.getFinals2()[3].getName()<<endl;
}

void fianlsGamePrintByDate(Fifa & fifa)
{
	ifstream in("finalsGamePrintByDate.txt");
	ofstream out("schedule(finals).txt");
	out<<"Matches by date"<<endl;
	int n;
	for(int k=0;k<2;k++)
	{
		in>>n;
		out<<"July "<<n<<endl;
		int x,y;
		//int random=rand()%12;
		if(k==1)
		  fifa.setFinalsVenues("Maracan");
		else
		  fifa.setFinalsVenues("Estádio Nacional de Brasilia");
		in>>x>>y;
		out<<"·";
		out<<fifa.getFinals4()[x].getName()<<" vs ";
		out<<fifa.getFinals4()[y].getName()<<",";
		if(k==1)
		  out<<"Maracan"<<endl;
		else
		  out<<"Estádio Nacional de Brasilia"<<endl;
	}
}

vector<string> s;
void finalsGame(Fifa & fifa)
{
	ifstream in("finalsGamePrintByDate.txt");
	ofstream out("schedule(finals).txt",ios::app);
	out<<endl<<"The match Live..."<<endl;
	int n,m=0;
	for(int k=0;k<2;k++)
	{
		in>>n;
		out<<endl<<"July "<<n<<endl;
		int x,y;
		in>>x>>y;
		out<<"This game is playing in "<<fifa.getFinalsVenues(m++)<<endl;
		game5(fifa,x,y);
	}
	in.close();
}

int t=0;
void game5(Fifa & fifa,int x,int y)
{
	//cout<<"1"<<endl;
	t++;
	Country & a= fifa.getFinals()[x];
	Country & b= fifa.getFinals()[y];
	ofstream out("schedule(finals).txt",ios::app);
	//ofstream out1("Result(finals).txt");
	out<<"Group stage:"<<endl;
	out<<a.getName()<<" vs "<<b.getName()<<endl;
	out<<a.getName()<<endl;
	for(int i=0;i<23;i++)
	{ 
	  	out<<"#"<<setw(8)<<setiosflags(ios::left)<<a.getPlayer(i).getNumber();
	  	out<<setw(8)<<setiosflags(ios::left)<<a.getPlayer(i).getPosition();
	  	out<<setw(8)<<setiosflags(ios::left)<<a.getPlayer(i).getName()<<endl;
	}
	out<<b.getName()<<endl;
	for(int i=0;i<23;i++)
	{
		out<<"#"<<setw(8)<<setiosflags(ios::left)<<b.getPlayer(i).getNumber();
	  	out<<setw(8)<<setiosflags(ios::left)<<b.getPlayer(i).getPosition();
	  	out<<setw(8)<<setiosflags(ios::left)<<b.getPlayer(i).getName()<<endl;
	}
	out<<"Playing..."<<endl;
	int random1=rand()%5;
	int random2=rand()%5;
	int m=0,n=0;
	for(int i=0;i<random1+random2;i++)
	{
		int random3=rand()%2;
		int random4=rand()%23;
		if(random3==0)
		{
			if(m!=random1)
			{
				fifa.getGroupOne(a.getOldRow())[a.getOldCol()].getPlayer()[random4].goalsPlus();
				out<<a.getName()<<"did a goal, and it was "<<"#"<<random4<<a.getPlayer()[random4].getName()<<" did the goal."<<endl;
				m++;
			}  
			else
			{
				fifa.getGroupOne(b.getOldRow())[b.getOldCol()].getPlayer()[random4].goalsPlus();
				out<<b.getName()<<"did a goal, and it was "<<"#"<<random4<<b.getPlayer()[random4].getName()<<" did the goal."<<endl;	
				n++;
			}	  
		}
		else
		{
			if(n!=random2)
			{
				fifa.getGroupOne(b.getOldRow())[b.getOldCol()].getPlayer()[random4].goalsPlus();
				out<<b.getName()<<"did a goal, and it was "<<"#"<<random4<<b.getPlayer()[random4].getName()<<" did the goal."<<endl;
				n++;
			}  
			else
			{
				fifa.getGroupOne(a.getOldRow())[a.getOldCol()].getPlayer()[random4].goalsPlus();
				out<<a.getName()<<"did a goal, and it was "<<"#"<<random4<<a.getPlayer()[random4].getName()<<" did the goal."<<endl;	
				m++;
			}	  
		}
		out<<"Now it is "<<m<<":"<<n<<endl;	  
	}
	
	
	if(random1==random2)
	{
		
		int random5=rand()%5;
	flag:
		int random6=rand()%5;
		if(random6==random5)
		  goto flag;
		out<<endl<<"because it is a draw,so later there will be a Penalty Shootout!"<<endl;
		out<<"Penalty Shootout is starting..."<<endl;
		for(int i=0;i<random5+random6;i++)
		{
			int random3=rand()%2;
			int random4=rand()%23;
			if(random3==0)
			{
				if(m!=random1+random5)
				{
					fifa.getGroupOne(a.getOldRow())[a.getOldCol()].getPlayer()[random4].goalsPlus();
					out<<a.getName()<<"did a goal, and it was "<<"#"<<random4<<a.getPlayer()[random4].getName()<<" did the goal."<<endl;
					m++;
				}  
				else
				{
					fifa.getGroupOne(b.getOldRow())[b.getOldCol()].getPlayer()[random4].goalsPlus();
					out<<b.getName()<<"did a goal, and it was "<<"#"<<random4<<b.getPlayer()[random4].getName()<<" did the goal."<<endl;	
					n++;
				}	  
			}
			else
			{
				if(n!=random2+random6)
				{
					fifa.getGroupOne(b.getOldRow())[b.getOldCol()].getPlayer()[random4].goalsPlus();
					out<<b.getName()<<"did a goal, and it was "<<"#"<<random4<<b.getPlayer()[random4].getName()<<" did the goal."<<endl;
					n++;
				}  
				else
				{
					fifa.getGroupOne(a.getOldRow())[a.getOldCol()].getPlayer()[random4].goalsPlus();
					out<<a.getName()<<"did a goal, and it was "<<"#"<<random4<<a.getPlayer()[random4].getName()<<" did the goal."<<endl;	
					m++;
				}	  
			}
			out<<"Now it is "<<m<<":"<<n<<endl;	
		}	
	}
	
	if(m>n)
	{
		out<<a.getName()<<" wins with "<<m<<":"<<n<<endl;
		a.winPlus();
		fifa.getGroup(a.getOldRow(),a.getOldCol()).winPlus();
		b.losePlus();
		fifa.getGroup(b.getOldRow(),b.getOldCol()).losePlus();
		
		if(t==1)
		{
			out<<endl<<"The second runner up is "<<a.getName()<<endl;
			//s.push_back(a.getName());
		}
		else
		{
			out<<endl<<"Champion is "<<a.getName()<<endl;
			//s.push_back(a.getName());
			out<<"Runner-up is "<<b.getName()<<endl;
			//s.push_back(b.getName());
		}
	}
	else if(m<n)
	{
		out<<b.getName()<<" wins with "<<n<<":"<<m<<endl;
		b.winPlus();
		fifa.getGroup(b.getOldRow(),b.getOldCol()).winPlus();
		a.losePlus();
		fifa.getGroup(a.getOldRow(),a.getOldCol()).losePlus();
		
		if(t==1)
		{
			out<<endl<<"The second runner up is "<<b.getName()<<endl;
			//s.push_back(b.getName());
		}
		else
		{
			out<<endl<<"Champion is "<<b.getName()<<endl;
			//s.push_back(b.getName());
			out<<"Runner-up is "<<a.getName()<<endl;
			//s.push_back(a.getName());
		}
	}
	a.gfPlus(m);
	fifa.getGroup(a.getOldRow(),a.getOldCol()).gfPlus(m);
	a.gaPlus(n);
	fifa.getGroup(a.getOldRow(),a.getOldCol()).gaPlus(n);
	b.gfPlus(n);
	fifa.getGroup(b.getOldRow(),b.getOldCol()).gfPlus(n);
	b.gaPlus(m);
	fifa.getGroup(b.getOldRow(),b.getOldCol()).gaPlus(m);
}

void finalsResultShow(Fifa & fifa)
{
	//cout<<"2"<<endl;
	ofstream out("Result(finals).txt");
	for(int i=0;i<4;i++)
	{
		fifa.getFinals()[i].setGoals();
		fifa.getFinals()[i].setGd();
	}
	//cout<<"2"<<endl;
	sort(fifa.getFinals().begin(),fifa.getFinals().end(),Comp);
	out<<"Final result for Finals "<<endl;
	out<<"Team                     W   D   L   GF  GA  GD  Pts"<<endl;
	for(int i=0;i<4;i++)
	{
		out<<setw(25)<<setiosflags(ios::left)<<fifa.getFinals()[i].getName();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals()[i].getWin();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals()[i].getDogfall();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals()[i].getLose();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals()[i].getGf();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals()[i].getGa();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals()[i].getGd();
		out<<setw(4)<<setiosflags(ios::left)<<fifa.getFinals()[i].getGoals()<<endl;
	}
	out<<endl;
}

void topteam(Fifa & fifa)
{
	ofstream out("topTenTeam.txt");
	vector<Country> topTeam;
	for(int i=0;i<8;i++)
	{
		for(int k=0;k<4;k++)
		{
			fifa.getGroup(i,k).setGoals();
			fifa.getGroup(i,k).setGd();
			topTeam.push_back(fifa.getGroup(i,k));
		} 
	}
	sort(topTeam.begin(),topTeam.end(),Comp);
	out<<"Top ten teams: "<<endl;
	out<<"    Team                     W   D   L   GF  GA  GD  Pts"<<endl;
	for(int i=0;i<10;i++)
	{
		out<<setw(4)<<setiosflags(ios::left)<<i+1;
		out<<setw(25)<<setiosflags(ios::left)<<topTeam[i].getName();
		out<<setw(4)<<setiosflags(ios::left)<<topTeam[i].getWin();
		out<<setw(4)<<setiosflags(ios::left)<<topTeam[i].getDogfall();
		out<<setw(4)<<setiosflags(ios::left)<<topTeam[i].getLose();
		out<<setw(4)<<setiosflags(ios::left)<<topTeam[i].getGf();
		out<<setw(4)<<setiosflags(ios::left)<<topTeam[i].getGa();
		out<<setw(4)<<setiosflags(ios::left)<<topTeam[i].getGd();
		out<<setw(4)<<setiosflags(ios::left)<<topTeam[i].getGoals()<<endl;
	}
	out<<endl;
} 

bool comp(int x,int y)
{
	return x>y;
}

void goalScorers(Fifa & fifa)
{
	ofstream out("finalStastics.txt");
	out<<"Goalscorers"<<endl;
	vector<int> s; 
	for(int i=0;i<8;i++)
		for(int k=0;k<4;k++)
			for(int j=0;j<23;j++)
			{
				bool p=true;
				//cout<<fifa.getGroup(i,k).getPlayer()[j].getGoals()<<" ";
				//vector<int>::iterator result=find(s.begin(),s.end(),fifa.getGroup(i,k).getPlayer()[j].getGoals());
				for(int l=0;l<s.size();l++)
				{
					if(s[l]==fifa.getGroup(i,k).getPlayer()[j].getGoals())
					{
						p=false;
						break;
					}
				}
				if(p)
				  s.push_back(fifa.getGroup(i,k).getPlayer()[j].getGoals());
			}
			  
	sort(s.begin(),s.end(),comp);
	//cout<<s.size()<<endl; 
	for(int i=0;i<s.size();i++)
	{
		out<<endl<<s[i]<<"goals"<<endl<<endl;
		for(int i=0;i<8;i++)
			for(int k=0;k<4;k++)
			 	for(int j=0;j<23;j++)
			 	{
			 		if(fifa.getGroup(i,k).getPlayer()[j].getGoals()==s[i])
			 		{
			 			out<<setw(27)<<setiosflags(ios::left)<<fifa.getGroup(i,k).getPlayer(j).getName();
						out<<setw(6)<<setiosflags(ios::left)<<fifa.getGroup(i,k).getPlayer(j).getPosition();
						out<<setw(25)<<setiosflags(ios::left)<<fifa.getGroup(i,k).getName()<<endl;
			 		} 
			 	}
	}
}

int main()
{
	Fifa fifa(4,10,8,4);
	srand((unsigned)time(NULL));
	//show();
	groupShow(fifa);
	groupGamePrintBySquads(fifa);
	groupGamePrintByDate(fifa);
	groupGame(fifa);
	groupResultShow(fifa);
	
	setFinal8(fifa);
	fianls8GamePrintByDate(fifa);
	finals8Game(fifa);
	finals8ResultShow(fifa);
	
	setFinal4(fifa);
	fianls4GamePrintByDate(fifa);
	finals4Game(fifa); 
	finals4ResultShow(fifa);
	
	setFinal2(fifa);
	fianls2GamePrintByDate(fifa);
	finals2Game(fifa); 
	finals2ResultShow(fifa);
	
	setFinals(fifa);
	fianlsGamePrintByDate(fifa);
	finalsGame(fifa); 
//	cout<<"3"<<endl;
//	ofstream out("Result(finals).txt");
//	out<<"Champion is "<<s[1]<<endl;
//	out<<"Runner-up is "<<s[2]<<endl;
//	out<<"The second runner up is "<<s[0]<<endl;
	finalsResultShow(fifa);	
	topteam(fifa);
	goalScorers(fifa);
	//cout<<"success"<<endl;
	return 0;
}
