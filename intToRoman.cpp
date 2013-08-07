class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int i,v,x,l,c,d,m,liv,lix,lxl,lxc,lcd,lcm;
        i=v=x=l=c=d=m=liv=lix=lxl=lxc=lcd=lcm=0;
        int j;
        if(num >= 1000)
        {
        	m = num/1000;
        	num %= 1000;
        }
        if(num >= 900)
        {
        	lcm = 1;
        	num-=900;
        }
        else if(num >= 500)
        {
        	d = 1;
        	num -= 500;
        }
        else if(num >= 400)
        {
        	lcd = 1;
        	num -= 400;
        }

        if(num >= 100)
    	{
    		c = num/100;
    		num %= 100;
    	}
    	if(num >= 90)
        {
        	lxc = 1;
        	num-=90;
        }
        else if(num >= 50)
        {
        	l = 1;
        	num -= 50;
        }
        else if(num >= 40)
        {
        	lxl = 1;
        	num -= 40;
        }

        if(num >= 10)
    	{
    		x = num/10;
    		num %= 10;
    	}
    	if(num >= 9)
        {
        	lix = 1;
        	num-=9;
        }
        else if(num >= 5)
        {
        	v = 1;
        	num -= 5;
        }
        else if(num >= 4)
        {
        	liv = 1;
        	num -= 4;
        }

        i = num;

        string res(50,' ');
      	int pos = 0;
      	for(j = 0;j < m;j++)
      	{
      		res[pos++] = 'M';
      	}
      	if(lcm == 1)
      	{
      		res[pos++] = 'C';
      		res[pos++] = 'M';
      	}
      	else if(d == 1)
      	{
      		res[pos++] = 'D';
      	}
      	else if(lcd == 1)
      	{
      		res[pos++] = 'C';
      		res[pos++] = 'D';
      	}

		for(j = 0;j < c;j++)
      	{
      		res[pos++] = 'C';
      	}
      	if(lxc == 1)
      	{
      		res[pos++] = 'X';
      		res[pos++] = 'C';
      	}
      	else if(l == 1)
      	{
      		res[pos++] = 'L';
      	}
      	else if(lxl == 1)
      	{
      		res[pos++] = 'X';
      		res[pos++] = 'L';
      	} 

      	for(j = 0;j < x;j++)
      	{
      		res[pos++] = 'X';
      	}
      	if(lix == 1)
      	{
      		res[pos++] = 'I';
      		res[pos++] = 'X';
      	}
      	else if(v == 1)
      	{
      		res[pos++] = 'V';
      	}
      	else if(liv == 1)
      	{
      		res[pos++] = 'I';
      		res[pos++] = 'V';
      	} 

      	for(j = 0;j < i;j++)
      	{
      		res[pos++] = 'I';
      	} 

      	return res.substr(0,pos);
    }
};