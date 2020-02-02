int thirdLargest(int a[], int n)
{
	/*
		Basic idea for minding nth largest/smallest number.
		Other method: (Automated process)
			I've another idea, for nth max and min, let us make an
			array in heap of size n-1; coz you can ignore max n-1 values.
			There we will store the previous round's 'max' values, stored 
			after each round. maxes[]
			We fill iterate(j) n time, 
				for each iteration(i) we will find max by usual 
				method but add the condition a[i] not in maxes[0:];
				This will ensure we skip/ignore already maxed values.
		Verdict: There's no time complexity difference but, method simple
		is NOT a true program, coz it has to be configured each time before use.
		Time and Space Complexity for both are the same.
		T.C = o(n)
		S.C = o(m) // m means mth minimum or maximum
	*/
    int b0 = INT32_MAX, b1 = b0;
    int max = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
            if(a[i]>max && a[i]!=b0 && a[i] != b1)
            max = a[i];
    }
    b0 = max;   // 1st maximum
    max = INT32_MIN;
    for(int i=0; i<n; i++){
            if(a[i]>max && a[i]!=b0 && a[i]!=b1)
            max = a[i];
    }
    b1 = max;   // second maximum
    max = INT32_MIN;
    for(int i=0; i<n; i++){
            if(a[i]>max && a[i]!=b0 && a[i]!=b1)
            max  = a[i];
    }   // 3rd maximum
    return max;
}