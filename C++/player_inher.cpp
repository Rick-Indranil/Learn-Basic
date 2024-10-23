#include<iostream>
#include<string.h>
using namespace std;
class player
{
    private:
        int id;
        char name[20];
    public:
        void play_read();
        void play_disp();
};

class batsman : virtual public player
{
    private:
        int run;
    public:
        void bat_read();
        void bat_disp();
};

class bowler : virtual public player
{
    private:
        int wicket;
    public:
        void bowl_read();
        void bowl_disp();
};

class allrounder : public batsman,public bowler
{
    private:
        int bat_avg;
        int bowl_avg;
    public:
        void allround_read();
        void allround_disp();
};


void player::play_read()
{
    cout<<"\n Player id. : ";
    cin>>id;
    cout<<"\n Player Name : ";
    cin>>name;
}
void player::play_disp()
{
    cout<<"\n Player id. : "<<id;
    cout<<"\n Player Name : "<<name;
}

void batsman::bat_read()
{
    cout<<"\n Total run : ";
    cin>>run;
}
void batsman::bat_disp()
{
    cout<<"\n Total run : "<<run;
}

void bowler::bowl_read()
{
    cout<<"\n Total wicket : ";
    cin>>wicket;
}
void bowler::bowl_disp()
{
    cout<<"\n Total wicket : "<<wicket;
}

void allrounder::allround_read()
{
    cout<<"\n Batting average : ";
    cin>>bat_avg;
    cout<<"\n Bowling average : ";
    cin>>bowl_avg;
}
void allrounder::allround_disp()
{
    cout<<"\n Batting average : "<<bat_avg;
    cout<<"\n Bowling average : "<<bowl_avg;
}

int main()
{
    allrounder a;
    a.play_read();
    a.bat_read();
    a.bowl_read();
    a.allround_read();

    a.play_disp();
    a.bat_disp();
    a.bowl_disp();
    a.allround_disp();

    return 0;
}
