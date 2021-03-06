#include<iostream>
#include<conio.h>
#include<graphics.h>
#define round(a) ((int)(a+0.5))

using namespace std;

int k;
float xmin,ymin,xmax,ymax,arr[20],m;

class clipinitiate{

public:
void clipl(float x1,float y1,float x2,float y2){
    if(x2-x1)
        m=(y2-y1)/(x2-x1);
    if(x1>=xmin && x2>=xmin)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(x1<xmin && x2>=xmin)
    {
        arr[k]=xmin;
        arr[k+1]=y1+m*(xmin-x1);
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(x1>=xmin && x2<xmin)
    {
        arr[k]=xmin;
        arr[k+1]=y1+m*(xmin-x1);
        k+=2;
    }
}

void clipt(float x1,float y1,float x2,float y2){
    if(y2-y1)
        m=(x2-x1)/(y2-y1);
    if(y1<=ymax && y2<=ymax)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(y1>ymax && y2<=ymax)
    {
        arr[k]=x1+m*(ymax-y1);
        arr[k+1]=ymax;
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(y1<=ymax && y2>ymax)
    {
        arr[k]=x1+m*(ymax-y1);
        arr[k+1]=ymax;
        k+=2;
    }
}

void clipr(float x1,float y1,float x2,float y2){
    if(x2-x1)
        m=(y2-y1)/(x2-x1);
    if(x1<=xmax && x2<=xmax)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(x1>xmax && x2<=xmax)
    {
        arr[k]=xmax;
        arr[k+1]=y1+m*(xmax-x1);
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(x1<=xmax && x2>xmax)
    {
        arr[k]=xmax;
        arr[k+1]=y1+m*(xmax-x1);
        k+=2;
    }
}

void clipb(float x1,float y1,float x2,float y2){
    if(y2-y1)
    m=(x2-x1)/(y2-y1);
    if(y1>=ymin && y2>=ymin)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(y1<ymin && y2>=ymin)
    {
        arr[k]=x1+m*(ymin-y1);
        arr[k+1]=ymin;
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(y1>=ymin && y2<ymin)
    {
        arr[k]=x1+m*(ymin-y1);
        arr[k+1]=ymin;
        k+=2;
     }
}

};

int main(){
    clipinitiate obj1;
    int gd=DETECT,gm,n,poly[20],i;
    initgraph(&gd,&gm,"C://tc//bgi");
    float xi,yi,xf,yf,polyy[20];
    cout<<"Coordinates of rectangular clip window :\nxmin,ymin:"<<endl;
    cin>>xmin>>ymin;
    cout<<"Coordinates of rectangular clip window :\nxmax,ymax:"<<endl;
    cin>>xmax>>ymax;
    cout<<"Number of sides :"<<endl;
    cin>>n;
    cout<<"Enter the coordinates :"<<endl;

    for (i=0;i<2*n;i++)
        scanf("%f",&polyy[i]);
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];

    for(i=0;i<2*n+2;i++)
        poly[i]=round(polyy[i]);

    rectangle(xmin,ymax,xmax,ymin);
    cout<<"UNCLIPPED "<<endl;
    drawpoly(n+1,poly);
    getch();
    cleardevice();
    k=0;
    for(i=0;i<2*n;i+=2)
        obj1.clipl(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    n=k/2;

    for(i=0;i<k;i++)
        polyy[i]=arr[i];
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];

    k=0;
    for(i=0;i<2*n;i+=2)
        obj1.clipt(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    n=k/2;
    for(i=0;i<k;i++)
        polyy[i]=arr[i];
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];

    k=0;
    for(i=0;i<2*n;i+=2)
        obj1.clipr(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    n=k/2;
    for(i=0;i<k;i++)
    polyy[i]=arr[i];
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];

    k=0;
    for(i=0;i<2*n;i+=2)
        obj1.clipb(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    for(i=0;i<k;i++)
    poly[i]=round(arr[i]);
    //if(k)
    setfillstyle(SOLID_FILL, RED);
    fillpoly(k/2,poly);
    rectangle(xmin,ymax,xmax,ymin);

    cout<<"CLIPPED"<<endl;
    line(xmin,ymin,xmax,ymin);
    line(xmin,ymax,xmax,ymax);
    delay(100000);

    getch();
    closegraph();
    return 0;
}
