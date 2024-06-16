time_t t;char*p,*e;extern char*i;x,y,h,m,s,c,d[8],f[]={31599,19812,14479,31207,
23524,29411,29679,30866,31727,31719,1040};o(c){d[0]=h/10;d[3]=m/10;d[7]=s%10;d[
4]=m%10;d[1]=h%10;d[6]=s/10;d[2]=d[5]=10;printf((x<80&&y<=10&&x%10<6&&f[d[x/10]
]>>((x/2)%5+15-3*(y/2))&1)?"\e[41m%c\e[0m":"%c",c);x++;if(c==10){x=0;y++;}}main
(){for(;;){p=e=i;time(&t);s=t%86400;h=s/3600;m=(s%3600)/60;s%=60;x=0;y=0;while(
*p){if(*p!=64)o(*p);else while(*e){c=*e;switch(c){case 10:c='n';case 92:case 34
:o(92);}o(c);if(x>77){o(92);o(10);}e++;}p++;}sleep(1);printf("\033[%dA\033[%dD"
,y,x);}}char*i="time_t t;char*p,*e;extern char*i;x,y,h,m,s,c,d[8],f[]={31599,1\
9812,14479,31207,\n23524,29411,29679,30866,31727,31719,1040};o(c){d[0]=h/10;d[\
3]=m/10;d[7]=s%10;d[\n4]=m%10;d[1]=h%10;d[6]=s/10;d[2]=d[5]=10;printf((x<80&&y\
<=10&&x%10<6&&f[d[x/10]\n]>>((x/2)%5+15-3*(y/2))&1)?\"\\e[41m%c\\e[0m\":\"%c\"\
,c);x++;if(c==10){x=0;y++;}}main\n(){for(;;){p=e=i;time(&t);s=t%86400;h=s/3600\
;m=(s%3600)/60;s%=60;x=0;y=0;while(\n*p){if(*p!=64)o(*p);else while(*e){c=*e;s\
witch(c){case 10:c='n';case 92:case 34\n:o(92);}o(c);if(x>77){o(92);o(10);}e++\
;}p++;}sleep(1);printf(\"\\033[%dA\\033[%dD\"\n,y,x);}}char*i=\"@\";//AS\n";//AS

