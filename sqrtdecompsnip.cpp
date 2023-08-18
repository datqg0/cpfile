void sqrtdecomposition (int l,int r,vector<int>&decomp,vector<int>&mcomp) {
	int n=decomp.size()-1;
	ll c1=l/n;
	if(l%n!=0) {
		c1++;
	}
	ll c2=r/n;
	if(r%n!=0) {
		c2++;
	}
	if (c1==c2) {
		decomp[c1]=-1;
		for (int i=l;i<=r;i++) {
			//query
		}
	}
	else {
		//breakdecomp;
		decomp[c1]=-1;
		for (int i=l;i<=c1*n;i++) {
			//query
		}
		for (int i=c1+1;i<=c2-1;i++) {
			//query
		}
		//breakdecomp;
		decomp[c2]=-1;
		for (int i=(c2-1)*n+1;i<=r;i++) {
			//query
		}
	}
}