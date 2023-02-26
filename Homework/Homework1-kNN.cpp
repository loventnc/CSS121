#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Friend {
	float ne, ni, te, ti, se, si, fe, fi;
	string type, nickname, name, number; 
	float distance = 0;
};

int main()
{
    struct Friend friends[64];
    struct Friend me;
    
    string number, name, sex, ne, ni, te, ti, se, si, fe, fi, type, enneagram , nickname;
    int count = 0;

	ifstream myFile;
    myFile.open("MBTI65.csv", ios::in);
    

    while (myFile.good())
    {

        getline(myFile, number, ',');
        getline(myFile, name, ',');
        getline(myFile, sex, ',');
        getline(myFile, ne, ',');		
		getline(myFile, ni, ',');		
		getline(myFile, te, ',');		
		getline(myFile, ti, ',');		
		getline(myFile, se, ',');		
		getline(myFile, si, ',');		
		getline(myFile, fe, ',');		
		getline(myFile, fi, ',');		
		getline(myFile, type, ',');		
		getline(myFile, enneagram, ',');
        getline(myFile, nickname, '\n');

        if(nickname == "Love")
        {
            me.number = number;
            me.name = name;
            me.ne = stof(ne);
            me.ni = stof(ni);
            me.te = stof(te);
            me.ti = stof(ti);
            me.se = stof(se);
            me.si = stof(si);
            me.fe = stof(fe);
            me.fi = stof(fi);
            me.type = type;
            me.nickname = nickname;
            me.distance = sqrt(pow((me.ne),2) + 
                                pow((me.ni),2) + 
                                pow((me.te),2) + 
                                pow((me.ti),2) + 
                                pow((me.se),2) + 
                                pow((me.si),2) + 
                                pow((me.fe),2) + 
                                pow((me.fi),2));
            count--;

        }
        else
        {
            friends[count].number = number;
            friends[count].name = name;
            friends[count].ne = stof(ne);
            friends[count].ni = stof(ni);
            friends[count].te = stof(te);
            friends[count].ti = stof(ti);
            friends[count].se = stof(se);
            friends[count].si = stof(si);
            friends[count].fe = stof(fe);
            friends[count].fi = stof(fi);
            friends[count].type = type;
            friends[count].nickname = nickname;
            
        }
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        friends[i].distance = sqrt(pow((me.ne -  friends[i].ne),2) + 
                                        pow((me.ni - friends[i].ni),2) + 
                                        pow((me.te - friends[i].te),2) + 
                                        pow((me.ti - friends[i].ti),2) + 
                                        pow((me.se - friends[i].se),2) + 
                                        pow((me.si - friends[i].si),2) + 
                                        pow((me.fe - friends[i].fe),2) + 
                                        pow((me.fi - friends[i].fi),2));
    }
    
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (friends[i].distance < friends[j].distance)
            {
                struct Friend temp = friends[i];
                friends[i] = friends[j];
                friends[j] = temp;
            }
        }
    }

    int mincount = 0;
    int maxcount = 0;
    string minType[5];
    string maxType[5];
    
    for (int i = 0; i < count; i++)
    {
        if (friends[i].distance == friends[0].distance)
        {
            minType[mincount] = friends[i].type;
            mincount++;
        }
        else if (friends[i].distance == friends[1].distance)
        {
            maxType[maxcount] = friends[i].type;
            maxcount++;
        }
        else
        {
            break;
        }
    }
    
    //output
    cout << me.nickname << " : " << me.type << endl;
    cout << "--------------------" << endl;
    cout << "My Type" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i+1 << " : "<< friends[i].nickname << " : " << friends[i].type << endl;
    }
   
    return 0;
}