#include "Func.hpp"

namespace Masiv
{

    int* FunInput(int &x, int &y, int Mess[10000])
        {
            int i=0, j=0;
            for (int g=0; g<100; g++)
            {
                for (int g1=0; g1<100; g1++)
                {
                    Mess[g*100+g1]=0;
                }
            }
            std::ifstream file("/Users/graf/Desktop/Lab_6/Lab_6/input.txt");
            
            file >> i >> j;
            
            
            for (int j1=0; j1<10000; j1++)
            {
                file >> Mess[j1];
            }
            
            
            file.close();
            
            x = i; y = j;
            
            return Mess;
        }
    

    void FunOutput(int a, int b, int Mass[])
    {
        std::ofstream file("/Users/graf/Desktop/Lab_6/Lab_6/output.txt", std::ios::out);
        
        for (int i=0; i<a; i++)
        {
            for (int j=0; j<b; j++)
            {
                file << Mass[i*(a+1)+j];
                file << " ";
            }
            file << std::endl;
        }
        
        file.close();
    }

    int* FunSmena(int x, int y, int Mess[10000])
    {
        int Op=0; int Op1=0; int Op2=0;
        int Arr[100]; int temp=0;
        
        for (int s=0; s<100; s++)
        {
            Arr[s]=0;
        }
        
        for (int i=0; i<10000; i++)
        {
            if ((Mess[i]!=0)&&(Mess[i]!=1)&&(Mess[i]>0))
            {
                for (int j=2; j<= sqrt(Mess[i]); j++)
                {
                    if (Mess[i]%j==0) Op=1;
                }
            }
            if ((Mess[i]!=0)&&(Mess[i]!=1)&&(Mess[i]<0))
            {
                for (int j=2; j<= sqrt(-Mess[i]); j++)
                {
                    if (-Mess[i]%j==0) Op=1;
                }
            }
        }
        
        if (Op==1)
        {
            for (int g=0; g<y; g++)
            {
                for (int h=0; h<y; h++)
                {
                    if (g!=h)
                    {
                        for (int k=0; k<x; k++)
                        {
                            if (Mess[k*(x+1)+g]!=Mess[k*(x+1)+h]) Op1=1;
                        }
                        if (Op1==0) Op2=1;
                        Op1=0;
                    }
                }
            }
        }
        
        if ((Op==1)&&(Op2==1))
        {
            for (int g=0; g<x; g++)
            {
                for (int h=0; h<y; h++)
                {
                    if (Mess[g*(x+1)+h]>0) Arr[g] = Arr[g] + Mess[g*(x+1)+h];
                    else Arr[g] = Arr[g] - Mess[g*(x+1)+h];
                }
            }
            
            for (int g=0; g<x; g++)
            {
                for (int h=0; h<x-1; h++)
                {
                    if (Arr[h]>Arr[h+1])
                    {
                        for (int s=0; s<y; s++)
                        {
                            temp = Mess[h*(x+1)+s];
                            Mess[h*(x+1)+s] = Mess[(h+1)*(x+1)+s];
                            Mess[(h+1)*(x+1)+s] = temp;
                        }
                        temp = Arr[h];
                        Arr[h] = Arr[h+1];
                        Arr[h+1] = temp;
                    }
                }
            }
        }
        
        
        return Mess;
    }

}
