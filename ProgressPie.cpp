#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    //Facebook Hackercup 2017 Qualification Round Problem 1 (Progress Pie)
    //Made by - DEVESH SHYNGLE
    
    int T,X,Y,P=0;
    float arcP,len,cordangle;

    cin>>T;
    if ( (T == 0) || (T > 1000) )
    {
        exit(-1);
    }
    while(1 <= T <= 1000)
    {
        for(int i=1; i<=T; i++)
        {
            //input P,X,Y as three space-separated integers resp.
            int n = 3;
            vector<int> v(n);       //vector seperates inputs by spaces
            for (int j=0; j<n; ++j)
            {
                cin>>v[j];
            }
            P = v[0];
            X = v[1];
            Y = v[2];

            while( (0 <= P <= 100) && (0 <= X <= 100) && (0 <= Y <= 100) )
            {
                cout<<"Case #"<<i<<": "; 

                if (P == 0)     //Zero percent
                    {   
                        cout<<"white"<<endl;
                        break;
                    }
                if ( (X == 50) && (Y == 50) )       
                    {
                        cout<<"black"<<endl;
                        break;
                    }

                //Length of coordinates from origin 
                len = sqrt( pow((50 - X),2) + pow((50 - Y),2) );

                if (len > 50)       //Greater than radius(50)
                {
                    cout<<"white"<<endl;
                    break;
                }
                if ( (X > 50) && (Y == 50) && (P > 24) )        //Lies only on X axis but P>24
                {
                    cout<<"black"<<endl;
                    break;
                }
                if ( (X > 50) && (Y == 50) && (P <= 24) )        //Lies only on X axis but P<=24
                {
                    cout<<"white"<<endl;
                    break;
                }
                else
                {   if (Y == 50)
                    {
                        cordangle = 0;      //Cordangle is angle made by X,Y 
                    }
                    else
                    {
                        cordangle = atan( (X-50) / (Y-50) ) * (180/3.1415);
                        //minus50 to shift origin, invtan(X/Y)=cordangle, rad to deg
                    }
                    arcP = (float) P * 3.6;     //Calc Arc by given P
                    
                    if (X >= 50)
                        cordangle = cordangle;

                    else
                        cordangle = cordangle + 180;
                    
                    if(cordangle > arcP)
                    {
                        cout<<"white"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"black"<<endl;
                        break;
                    }
                }
            }
        }
    }
   return 0;
}
