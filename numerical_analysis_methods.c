#include <stdio.h>
#include <math.h>
#include <conio.h>
#define max 100
#define ORDER 4

float f(float[],int,float );
float ft(float[],int ,float );
int factoriyel(int );
float determinant(float [][25], float);
void cofactor(float [][25], float);
void transpose(float [][25], float [][25], float);
void gaussEliminasyon(int , int , float [][25], float []);
void matrisgir(int , int , float matrix[][25]);
void matrisyazdir(int , int , float matrix[][25]);
void matriskopyala(int , int , float matrix1[][25], float matrix2[][25]);


int main(){
	int islem;
	int i,j,k,d,y=1,m,n,secim,flag,konum;
	float a1,b1,c,epsilon,hata,x0,x1,det,h,turev,b[max],p,s;
	float a[25][25],altlimit,ustlimit,sum1=0.0,sum2=0.0,sum=0.0,x,sonuc=0.0,max1,arr[max],bas[max],temp,t[max],kopya[max][max];
	float ax[max+1], ay[max+1],carpim=1.0,fark[max][max]={0};
	
	do{
		printf("\n>>Uygulamak istediginiz yontemi seciniz :\n(Secim yapmayi birakmak icin -1 giriniz.)\n");
		printf("-> 1.Bisection yontemi\n");
		printf("-> 2.Regula-Falsi yontemi\n");
		printf("-> 3.Newton-Rapshon yontemi\n");
		printf("-> 4.NxN'lik bir matrisin inversi\n");
		printf("-> 5.Gauus Eleminasyon\n");
		printf("-> 6.Gauss Seidal \n");
		printf("-> 7.Sayisal Turev (merkezi, ileri ve geri farklar opsiyonlu)\n");
		printf("-> 8.Simpson yontemi(1/3)\n");
		printf("-> 9.Simpson yontemi(3/8)\n");
		printf("-> 10.Trapez yontemi\n");
		printf("-> 11.Degisken donusumsuz Gregory newton Enterpolasyonu\n");
		scanf("%d",&islem);
	
	
	switch(islem){
		case 1:
			
	printf("\n\n");
	printf("   1.Bisection yontemi\n");
	printf(" - Polinomun derecesini giriniz:");
	scanf("%d",&d);
	for(j=d;j>=0;j--){
		printf(" > %d dereceli elemanin katsayisini giriniz:",j);
		scanf("%f",&b[j]);
	}
	
	printf("\n - Kokun hangi aralikta aranacagini giriniz.(a,b)\n");
	printf(" > a:"); 
	scanf("%f",&a1);
	printf(" > b:"); 
	scanf("%f",&b1);
	
	printf("\n - Hata payini giriniz:");
	scanf("%f",&epsilon);
	if(f(b,d,a1)==0 || f(b,d,b1)==0){
		if(f(b,d,a1)==0){
			printf("\n > kok = %f\n",a1);
		}
		if(f(b,d,b1)==0){
			printf("\n > kok = %f\n",b1);
		}
	}else{
			hata=(b1-a1)/exp2(y);		
	while(epsilon<hata){
		hata=(b1-a1)/exp2(y);
		c=(a1+b1)/2;
		if((f(b,d,c)*f(b,d,a1))<0){
			b1=c;
		}else if((f(b,d,c)*f(b,d,b1))<0){
			a1=c;
		}
		y++;
		printf("\n > %d. iterasyon : a1=%f    b1=%f    hata=%f    ",y-1,a1,b1,hata);
	}
	printf("\n\n -> yaklasik  kok = %f\n\n",c);	
	}
	
	break;
		case 2:
						
	printf("\n\n");
	printf("   2.Regula-Falsi yontemi\n");
	printf(" - Polinomun derecesini giriniz:");
	scanf("%d",&d);
	for(j=d;j>=0;j--){
		printf(" > %d dereceli elemanin katsayisini giriniz:",j);
		scanf("%f",&b[j]);
	}
	
	printf("\n - Kokun hangi aralikta aranacagini giriniz.(a,b)\n");
	printf(" > a:"); 
	scanf("%f",&a1);
	printf(" > b:"); 
	scanf("%f",&b1);
	
	printf("\n - Hata payini giriniz:");
	scanf("%f",&epsilon);
	
	if(f(b,d,a1)==0 || f(b,d,b1)==0){
		if(f(b,d,a1)==0){
			printf("\n > kok = %f\n",a1);
		}
		if(f(b,d,b1)==0){
			printf("\n > kok = %f\n",b1);
		}
	}else{
		hata=(b1-a1)/exp2(y);	
		while(epsilon<hata){
			hata=(b1-a1)/exp2(y);
			c=(b1*f(b,d,a1)-a1*f(b,d,b1))/(f(b,d,a1)-f(b,d,b1));
			if((f(b,d,c)*f(b,d,a1))<0){
				b1=c;
			}else if((f(b,d,c)*f(b,d,b1))<0){
				a1=c;
			}
			y++;
			printf("\n > %d. iterasyon : a1=%f    b1=%f    hata=%f    ",y-1,a1,b1,hata);
		}
		printf("\n\n -> yaklasik  kok= %f\n\n",c);
	}
	

	break;
		case 3:
									
	printf("\n\n");
	printf("   3.Newton-Rapshon yontemi\n");
	printf(" - Polinomun derecesini giriniz:");
	scanf("%d",&d);
	for(j=d;j>=0;j--){
		printf(" > %d dereceli elemanin katsayisini giriniz:",j);
		scanf("%f",&b[j]);
	}

	printf("\n - x0 giriniz:");
	scanf("%f",&x0);	
	
	printf("\n - Hata payini giriniz:");
	scanf("%f",&epsilon);
	if(f(b,d,x0)==0){
		printf("\n > kok = %f\n",x0);
	}else{
		hata=3.0;
		i=0;
		while(epsilon<hata){
			x1=x0-(f(b,d,x0)/ft(b,d,x0));
			hata=x1- x0;	
			printf("\n > %d. iterasyon : x%d=%f    x%d=%f    hata=%f    ",i+1,i,x0,i+1,x1,hata);
			i++;
			x0=x1;
		}
		printf("\n\n -> yaklasik  kok= %f\n\n",x1);
	}
		
	break;
		case 4:
			
	printf("\n\n");
	printf("   4.NxN'lik bir matrisin inversi\n");
	printf(" - Matrisin boyutunu giriniz : ");
  	scanf(" %d", &m);
  	printf(" - Matrisin elemanlarini giriniz : \n");
  	/*Matrisin elemanlarinin alinmasi */
  	for (i = 0;i < m; i++){
     	for (j=0;j<m;j++){
     		printf(" x[%d][%d] = ",i,j);
        	scanf(" %f",&a[i][j]);
    	}
	}
  	det = determinant(a,m);
  	if (det == 0){
  		 printf("\n -> Girilen matrisin tersi alinamaz. \n");
 	}else{
   		cofactor(a,m);
	}
	break;
		case 5:
						
	printf("\n\n");
	printf("   5.Gauus Eleminasyon\n");
	printf(" - Arttirilmis matrisin boyutunu girin:\n > satir sayisi (m):");
   scanf("%d",&m);
   printf(" > sutun sayisi (n):");
   scanf("%d",&n);


   printf("\n - Matrisin elemanlarini girin:\n");
   matrisgir(m,n,a);
   matriskopyala(m,n,a,kopya);  
   gaussEliminasyon(m,n,kopya,t);
   printf("\n - Ust ucgen matris:\n\n");
   matrisyazdir(m,n,kopya);
   printf("\n > Dogrusal denklemlerin cozumu:\n\n");
   for(i=0;i<n-1;i++){
      printf(" -> x[%d] = %f\n",i+1,t[i]);
   }
   break;
    	case 6:
   						
	printf("\n\n");
	printf("-> 6.Gauss Seidal \n"); 		
   printf(" - Matrisin satir sayisini giriniz:");
	scanf("%d",&m);
	printf(" - Matrisin sutun sayisini giriniz:");
	scanf("%d",&n);
	printf(" > Matrisin elemanlarini giriniz:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf(" > x[%d][%d] = ",i,j);
			scanf(" %f",&a[i][j]);
		}
	}
	for(i=0;i<m;i++){
		max1=fabs(a[0][i]);
		konum=i;
		for(j=0;j<m;j++){
			if(max1<fabs(a[j][i])){
				konum=j;
				max1=fabs(a[j][i]);	
			}
		}
		for(k=0;k<m;k++){
			for(j=0;j<n;j++){
				temp=a[konum][j];
				a[konum][j]=a[i][j];
				a[i][j]=temp;
			}	
		}
	}
	printf("\n > Mutlak degerce en buyuk elemanlarin kosegene alinmis hali: \n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf(" %5f  ",a[i][j]);
		}
		printf("\n");
	}
	printf(" - Baslangic degerlerini giriniz:\n");
	for(i=0;i<n-1;i++){
		printf(" > %d. bilinmeyenin baslangic degeri:",i+1);
		scanf("%f",&bas[i]);
	}

	printf(" - Hata payini giriniz: ");
	scanf("%f",&epsilon);
	do{
		for(i=0;i<m;i++){
			s=a[i][n-1];
			for(j=0;j<n-1;j++){
				if(j!=i){
					s = s - a[i][j]*bas[j];
				}
			}
			t[i]=s/a[i][i];
			flag=0;
			for(k=0;k<m;k++){
				if(fabs(t[k]-bas[k])>epsilon){
					flag++;
				}	
			}
				bas[i]=t[i];
		}
	}while(flag>0);
	for(i=0;i<m;i++){
		printf(" -> x[%d] = %f \n",i+1,t[i]);
	}
   break;
   	case 7:
    		  								
	printf("\n\n");		
   printf("   7.Sayisal Turev (merkezi, ileri ve geri farklar opsiyonlu)\n");
   printf("\n");
	printf("  -> SECINIZ\n");
	printf(" > 1.Geri farklar ile sayisal turev\n > 2.Ileri farklar ile sayisal turev\n > 3.Merkezi farklar ile sayisal turev\n");
	scanf("   %d",&secim);
   printf(" - Polinomun derecesini giriniz:");
	scanf("%d",&d);
	for(j=d;j>=0;j--){
		printf(" > %d dereceli elemanin katsayisini giriniz:",j);
		scanf("%f",&b[j]);
	}
	printf("\n - Hangi noktada turevin bulunacagini giriniz: ");
	scanf("%f",&x0);	
	
	printf(" - h degerini giriniz: ");
	scanf("%f",&h);
	
	if (secim==1){
		turev=(f(b,d,x0)-f(b,d,(x0-h)))/h;
	}else if(secim==2){
		turev=(f(b,d,(x0+h))-f(b,d,x0))/h;
	}else if(secim==3){
		turev=(f(b,d,(x0+h))-f(b,d,(x0-h)))/2*h;
	}
	printf(" -> Turevi : %f\n\n",turev);
   break;		
		case 8:	  
		  								
	printf("\n\n");
	printf("   8.Simpson yontemi(1/3)\n");
	printf(" - Polinomun derecesini giriniz:");
	scanf("%d",&d);
	for(i=d;i>=0;i--){
		printf(" > %d dereceli elemanin katsayisini giriniz:",i);
		scanf("%f",&b[i]);
	}
	
	printf(" - Integralin alt limitini giriniz: ");
	scanf("%f",&altlimit);
	printf(" - Integralin ust limitini giriniz: ");
	scanf("%f",&ustlimit);	
	
	printf(" - Alt araliklarin sayisini giriniz: ");
	scanf("%d",&n);
	
	h=fabs(ustlimit-altlimit)/n;
	
	
	for(i=0;i<=n;i++){
		x=altlimit+i*h;
		arr[i]=f(b,d,x);
	}
	for(i=1;i<n;i++){
		if(i%2==1){
			sum1=sum1+arr[i];
		}else{
			sum2=sum2+arr[i];
		}
	}
	
	sonuc=(h/3)*(arr[0]+arr[n]+(4*sum1)+(2*sum2));
	
	printf("  -> Yaklasik sonuc : %f\n",sonuc);
	break;
		case 9:
			  								
	printf("\n\n");
	printf("   9.Simpson yontemi(3/8)\n");
			
	printf(" - Polinomun derecesini giriniz:");
	scanf("%d",&d);
	for(i=d;i>=0;i--){
		printf(" > %d dereceli elemanin katsayisini giriniz:",i);
		scanf("%f",&b[i]);
	}
	
	printf(" - Integralin alt limitini giriniz: ");
	scanf("%f",&altlimit);
	printf(" - Integralin ust limitini giriniz: ");
	scanf("%f",&ustlimit);	
	
	printf(" - Alt araliklarin sayisini giriniz: ");
	scanf("%d",&n);
	
	h=fabs(ustlimit-altlimit)/n;
	
	for(i=0;i<=n;i++){
		x=altlimit+i*h;
		arr[i]=f(b,d,x);
	}
	
	for(i=1;i<n;i++){
		if(i%3==0){
			sum1=sum1+arr[i];
		}else{
			sum2=sum2+arr[i];
		}	
	}
	sonuc=((3*h)/8)*(arr[0]+arr[n]+2*sum1+3*sum2);
	
	printf("  -> Yaklasik sonuc: %f\n",sonuc);
	break;
		case 10:
						  								
	printf("\n\n");
	printf("  10.Trapez yontemi\n");
		printf(" - Polinomun derecesini giriniz:");
	scanf("%d",&d);
	for(i=d;i>=0;i--){
		printf(" > %d dereceli elemanin katsayisini giriniz:",i);
		scanf("%f",&b[i]);
	}
	
	printf(" - Integralin alt limitini giriniz: ");
	scanf("%f",&altlimit);
	printf(" - Integralin ust limitini giriniz: ");
	scanf("%f",&ustlimit);
	
	printf(" - Alt araliklarin sayisini giriniz: ");
	scanf("%d",&n);
	
	h=fabs(altlimit-ustlimit)/n;
	
	for(i=1;i<n;i++){
		x=altlimit+i*h;
		sum=sum+f(b,d,x);
	}
	
	sonuc=(h/2.0)*(f(b,d,altlimit)+f(b,d,ustlimit)+2.0*sum);
	
	printf("  -> Yaklasik sonuc: %f\n\n",sonuc);
	break;
		case 11:
								  								
	printf("\n\n");
	printf("   11.Degisken donusumsuz Gregory newton Enterpolasyonu\n");
	printf(" - n degeri giriniz:\n");
   scanf("%d",&n);
 
   printf("\n - Degerleri (x,y) biçiminde giriniz:\n");
   for (i=0;i<n;i++){
      scanf("%f %f",&ax[i],&ay[i]);
   }
   printf("\n - Hangi x degerine karsilik gelen y degerini bulmak istiyorsunuz? : \n");
   scanf("%f",&x);
   h=ax[1]-ax[0];
 	
 	
  	for(i=0;i<n-1;i++){
  		fark[i][0]=ay[i+1]-ay[i];
	}
	for(i=1;i<n;i++){
		for(j=1;j<n-i;j++)
		fark[j][i]=fark[j][i-1]-fark[j-1][i-1];
	}
	
	p=(x-ax[0])/h;
	
	for(i=0;i<n;i++){
		d=0;
		carpim=1.0;
		while(d<=i){
			carpim=carpim*(p-d);
			d++;
		}	
		arr[i]=((carpim*fark[i][i])/factoriyel(i+1));	
	}
	for(i=0;i<n;i++){
		sum += arr[i];	
	}
	sum += ay[0];


   printf("\n  -> x = %f iken, karsilik gelen y = %f\n",x,sum);
	break;
	

		
	}

	}while(islem != -1 || islem>11);	
}

int factoriyel(int x){
	int i,fak=1;
	if(x==0){
		return 1;
	}else if(x==1){
		return 1;
	}else {
		for(i=1;i<=x;i++){
			fak=fak*i;
		}
		return fak;
	}
}	

float f(float a[],int d,float x ){
	int i;
	float A=0;
	for(i=0;i<=d;i++){
		A=A+(a[i]*pow(x,i));
	}
	return A;
}

float ft(float a[],int d,float x){
	int i;
	float A=0;
	for(i=1;i<=d;i++){
		A=A+(a[i]*i*pow(x,(i-1)));
	}
	return A;
	
}

/*Matrisin determinantýnýn hesaplanmasý */
float determinant(float a[25][25],float k){  //k=matrisin boyutu
	float s=1,det=0,b[25][25];
  	int i,j,m,n,c;
  	if (k == 1){
     	return (a[0][0]);
   }else{
     	det=0;
     	for (c=0;c<k;c++){
        	m=0;
        	n=0;
        	for (i=0;i<k;i++){
            	for (j=0;j<k;j++){
                	b[i][j]=0;
                	if (i!=0 && j!=c){
                   		b[m][n]=a[i][j];
                   		if (n<(k - 2)){
                    		n++;
                   		}else{
                     		n=0;
                     		m++;
                     	}
                  }
               }
            }
          	det=det+s*(a[0][c]*determinant(b,k-1));
          	s=-1*s;
        }
    }
 
    return (det);
}

void cofactor(float num[25][25], float f){ //f=matrisin boyutu
 	float b[25][25],fac[25][25];
 	int p,q,m,n,i,j;
 	for (q=0;q<f;q++){
   		for (p=0;p<f;p++){
    		m=0;
    		n=0;
     		for(i=0;i<f;i++){
       			for(j=0;j<f;j++){
          			if (i!=q && j!=p){
            			b[m][n]=num[i][j];
            			if (n<(f-2)){
             				n++;
             			}else{
              				n=0;
               			m++;
               		}
            		}
        			}	
      		}
      		fac[q][p]=pow(-1,q+p)*determinant(b,f-1);   //kofaktör=(-1)^(q+p)*determinant
   		}
  	}
  	transpose(num,fac,f);
}

/*Matrisin transpozesini bulma*/ 
void transpose(float num[25][25],float fac[25][25],float r){
  	int i, j;
  	float b[25][25],inverse[25][25],d;
 
  	for (i=0;i<r;i++){
     	for (j=0;j<r;j++){
         	b[i][j]=fac[j][i];  // satir ve sutun degerlerini birbiriyle degistiriyoruz
      }
   }
  	d=determinant(num,r);
  	for(i=0;i<r;i++){
    	for(j=0;j<r;j++){
        	inverse[i][j]=b[i][j]/d;   // matrisin transpozesini determinanta böluyoruz
      }
   }
  	printf("\n\n     -> Matrisin inversi : \n");
 
   for (i=0;i<r;i++){
     	for (j = 0;j<r;j++){
         	printf(" \t%f",inverse[i][j]);
      }
    printf("\n");
   }
}

void gaussEliminasyon(int m, int n, float a[m][n], float x[n-1]){
    int i,j,k;
    float temp,s;
    for(i=0;i<m-1;i++){
        for(k=i+1;k<m;k++){
            if(fabs(a[i][i])<fabs(a[k][i])){
                for(j=0;j<n;j++){                
                    temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
            		}
            }
        }
        for(k=i+1;k<m;k++){
            s=a[k][i]/ a[i][i];
            for(j=0;j<n;j++){
                a[k][j]=a[k][j]-s *a[i][j];
            }
        }
         
    }
    for(i=m-1;i>=0;i--){
        x[i]=a[i][n-1];
        for(j=i+1;j<n-1;j++){
            x[i]=x[i]-a[i][j]*x[j];
        }
        x[i]=x[i]/a[i][i];
    }
             
}
void matrisgir(int m, int n, float a[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
        	printf(" > x[%d][%d] = ",i,j);
         scanf("%f",&a[i][j]);
        }
    } 
}

void matrisyazdir(int m, int n, float a[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%f\t",a[i][j]);
        }
        printf("\n");
    } 
}

void matriskopyala(int m, int n, float a[m][n], float b[m][n]){
    int i,j; 
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            b[i][j]=a[i][j];
        }
    } 
}
 

