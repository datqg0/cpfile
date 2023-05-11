   while(n%2==0) {
   	n=n/2;
   }
   for(int i=3;i<=sqrt(n);i+=2) {
    	while(n%i==0) {
    		if(check==false) {
    			check=true;
    		}
    		else {
    			sum*=i;
    		}
    		n=n/i;
    	}
    }