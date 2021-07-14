#include<graphics.h>
void drawbucket() 
{
	setcolor(RED);
	delay(100);  
	line(0,100,0,200);
	delay(100);   		  // Bucket 1
	line(0,200,80,200);
	delay(100);  
	line(80,200,80,100);
	//outtextxy(40,210,"0");

	setcolor(GREEN);
	delay(100);  
	line(130,100,130,200);  
	delay(100);  	 // Bucket 2
	line(130,200,210,200);
	delay(100);  
	line(210,200,210,100);

	setcolor(MAGENTA);
	delay(100);  
	line(260,100,260,200);  
	delay(100);   	 //Bucket 3
	line(260,200,340,200);
	delay(100);  
	line(340,200,340,100);

	setcolor(LIGHTBLUE);
	delay(100);  
	line(390,100,390,200);
	delay(100);  
	line(390,200,470,200); 
	delay(100);        	//Bucket 4
	line(470,200,470,100);

	setcolor(YELLOW);
	delay(100);  
	line(520,100,520,200);
	delay(100);      	//Bucket 5
	line(520,200,600,200);
	delay(100);  
	line(600,200,600,100);


	setcolor(17);
	delay(100);  
	line(0,280,0,380);  
	delay(100);   		  // Bucket 6
	line(0,380,80,380);
	delay(100);  
	line(80,280,80,380);


	setcolor(12);
	delay(100);  
	line(130,280,130,380);  
	delay(100);  	 // Bucket 7
	line(130,380,210,380);
	delay(100);  
	line(210,280,210,380);


	setcolor(3);
	delay(100);  
	line(260,280,260,380); 
	delay(100);    	 //Bucket 8
	line(260,380,340,380);
	delay(100);  
	line(340,280,340,380);


	setcolor(8);
	delay(100);  
	line(390,280,390,380);
	delay(100);  
	line(390,380,470,380);
	delay(100);         	//Bucket 9
	line(470,280,470,380);

	setcolor(15);
	delay(100);  
	line(520,280,520,380);  
	delay(100);    	//Bucket 10
	line(520,380,600,380);
	delay(100);  
	line(600,280,600,380);
}
void findbucketlocation(int rem,int buckets[],int arr[])
{
    int x,y;
    char buffer[50];
    if(rem==0 || rem==5)
			x=20;
		else if(rem==1||rem==6)
			x=150;
		else if(rem==2 || rem==7)
			x=280;
		else if(rem==3 || rem==8)
			x=430;
		else if(rem==4 || rem==9)
			x=540;
		if(rem>=0&&rem<=4)
			y = 180 - (20*buckets[rem]);
		else if(rem>=5&&rem<=9)
			y = 360 - (20*buckets[rem]);
	arr[0]=x;
	arr[1]=y;
	//sprintf(buffer,"x = %d y = %d",arr[0],arr[1]);
	//outtextxy(300,400,buffer);
}
void movetext(int x0,int y0,int x1,int y1,char buffer[50])
{
	float x, y,dx,dy,steps,m,xinc,yinc;
	int j;
	dx = (float)(x1 - x0);
		dy = (float)(y1 - y0);
		if(abs(dx)>=abs(dy))
		{
			steps = dx;
		}
		else
		{
		    steps = dy;
		}
		m = dy/dx;
		x = x0;
		y = y0;
		j = 1;
        if(dx<=0)
        {
            if(m<=1)
            {
                xinc = -1;
                yinc = -m;
            }
            else
            {
                xinc = -1/m;
                yinc = -1;
            }
            while(x>=x1)
		    {
		        //	putpixel(x, y, RED);
                if(x>=x1 && y<=y1)
                {
                    x += (xinc*5);
                    y += (yinc*5);
                    setcolor(WHITE);
                    outtextxy(x,y,buffer);
                    delay(50);
                    setcolor(BLACK);
                    outtextxy(x,y,buffer);
                }
                else
                    break;
		    }
        }
        else
        {
            if(m<=1)
            {
            xinc = 1;
            yinc = m;
            }
            else
            {
            xinc = 1/m;
            yinc = 1;
            }
            while(x<=x1 && y<=y1)
		{
		//	putpixel(x, y, RED);
            if(x<=x1 && y<=y1)
            {
                x += (xinc*5);
                y += (yinc*5);
                setcolor(WHITE);
                outtextxy(x,y,buffer);
                delay(300);
                setcolor(BLACK);
                outtextxy(x,y,buffer);
            }
	        j=j+1;
		}
        }
		
		setcolor(WHITE);
		outtextxy(x1,y1,buffer);
		drawbucket() ;
}
// Function to find largest element
int max(int a[], int n)
{
      int max = a[0], i;
      for(i = 1; i < n; i++)
      {
	    if(max < a[i])
	    max = a[i];
      }
      return max;
}
int findNOP(int lar)
{
    int nop=0;
    while(lar > 0)
    {
        nop++;
	    lar/=10;
    }
    return nop;
}
// Function to perform sorting
void RadixSort(int a[], int n,int NOP)
{
      int bucket[10][10], bucket_cnt[10];
      int i, j, k, r, divisor=1, lar, pass;
      lar=max(a, n);
      /*Initialize the buckets*/
      for(pass = 0; pass < NOP; pass++)
      {
	    for(i = 0; i < 10; i++)
	    {
		  bucket_cnt[i] = 0;
	    }
	    //sort the numbers according to the digit & place it into specified bucket
	    for(i = 0; i < n; i++)
	    {
		  r = (a[i] / divisor) % 10;
		  bucket[r][bucket_cnt[r]] = a[i];
		  bucket_cnt[r] += 1;
	    }
	    //Collect the numbers after completed each pass
	    i = 0;
	    for(k = 0; k < 10; k++)
	    {
		  for(j = 0; j < bucket_cnt[k]; j++)
		  {
			a[i] = bucket[k][j];
			i++;
		  }
	    }
	    divisor *= 10;
	    printf("\n Numbers after completing pass %d :\n",pass+1);
	    for(i = 0; i < n; i++)
		  printf("  %d",a[i]);
	    printf("\n");
      }
}
void main()
{
	int gd=DETECT,gm,i,j,rem,divisor=1,num[20];
	int x0,y0,x1,y1;
	int arr[3],buckets[10],bucket[10][10];
	int n,k,NOP,pass,i2;
	char buffer[100];
	printf(" How many numbers you want to sort?: ");
	scanf("%d",&n);
	printf("\n Enter %d numbers:\n",n);
    for(i = 0; i < n; i++)
    {
	    scanf("%d",&num[i]);
    }

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    outtextxy(200,200,"RADIX SORT");
	delay(2000);
	cleardevice();
	//outtextxy(200,200,"PASS I");
	delay(2000);
	cleardevice();
	//drawbucket();
	for(i=0;i<n;i++)
	{
		sprintf(buffer,"%d",num[i]);
		outtextxy(200+(20*i),20,buffer);
	}
    NOP = findNOP(max(num,n));
    for(pass=0;pass<NOP;pass++)
    {
        cleardevice();
        setcolor(WHITE);
        sprintf(buffer,"PASS %d",pass+1);
        outtextxy(200,200,buffer);
        delay(2000);
        cleardevice();
        drawbucket();
        //outtextxy(200,200,buffer);
        for(j=0;j<n;j++)
	    {
            sprintf(buffer,"%d",num[j]);
            outtextxy(200+(40*j),20,buffer);
	    }
        for(j=0;j<10;j++)
        {
            buckets[j]=0;
        }
        delay(2000);
	//cleardevice();
        for(i=0;i<n;i++)
        {
            rem = (num[i] / divisor) % 10;
            bucket[rem][buckets[rem]] = num[i];
            findbucketlocation(rem,buckets,arr);
            x0=200+(40*i);
            y0=30;
            x1= arr[0];
            y1= arr[1];
            sprintf(buffer,"%d",num[i]);
            movetext(x0,y0,x1,y1,buffer);
            buckets[rem]=buckets[rem]+1;
        }
        divisor *= 10;
        i2=0;
        for(k = 0; k < 10; k++)
        {
            for(j = 0; j < buckets[k]; j++)
            {
                num[i2] = bucket[k][j];
                i2++;
            }
        }
        cleardevice();
        setcolor(WHITE);
        sprintf(buffer,"Numbers after pass %d",pass+1);
        outtextxy(200,200,buffer);
        for(j=0;j<n;j++)
        {
            sprintf(buffer,"%d",num[j]);
            outtextxy(200+(40*j),250,buffer);
        }
        delay(6000);
    }
    cleardevice();
    sprintf(buffer,"Sorted numbers are");
    outtextxy(200,200,buffer);
    for(j=0;j<n;j++)
    {
	    sprintf(buffer,"%d",num[j]);
	    outtextxy(200+(40*j),250,buffer);
    }
    delay(6000);
    getch();
}
//Entry point of program


