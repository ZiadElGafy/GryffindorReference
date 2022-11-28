#define matrix vector<vector<double> >
matrix inverse(matrix mat)
{
	int n=mat.size();
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		mat[i].push_back(i==j);
		mat[i].push_back(i);
	}
	for (int i=n-1;i>0;i--)
	{
		if (mat[i-1][0]<mat[i][0])
		swap(mat[i],mat[i-1]);
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (i!=j)
			{
				double tmp=mat[j][i]/mat[i][i];
				for (int k=0;k<2*n;k++)
				mat[j][k]-=mat[i][k]*tmp;
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		double tmp=mat[i][i];
		for (int j=0;j<2*n;j++)
		mat[i][j]/=tmp;
	}
	for (int i=0;i<n;i++)
	swap(mat[i],mat[mat[i].back()]);
	return mat;
}
