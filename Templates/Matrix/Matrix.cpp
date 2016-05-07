const int cc=0x7FFFFFFF;//模数 
struct Matrix
{
    int r,c,w[100][100];//r是行数，c是列数，下标从1开始 
};
Matrix operator+(const Matrix &A,const Matrix &B)//加法，减法对此复制即可 
{
    Matrix C;
    C.c=A.c;
    C.r=A.r;
    for (int i=1;i<=C.r;i++)
     for (int j=1;j<=C.c;j++)
      C.w[i][j]=(A.w[i][j]+B.w[i][j])%cc;
    return C;
};
Matrix operator*(const Matrix &A,const Matrix &B)//乘法 
{
	Matrix C;
	C.r=A.r;
	C.c=B.c;
	for (int i=1;i<=A.r;i++)
	 for (int j=1;j<=B.c;j++)
	 {
	 	C.w[i][j]=0;
	    for (int k=1;k<=A.c;k++)
	     C.w[i][j]=((A.w[i][k]*B.w[k][j])%cc+C.w[i][j])%cc;
	 }
	return C;
}
Matrix pow(Matrix A,int k)//快速幂 
{
	Matrix C;
	C.c=A.c;
	C.r=A.r;
	for (int i=1;i<=C.r;i++) 
	 for (int j=1;j<=C.r;j++)
	  if (i==j) C.w[i][j]=1;
	  else C.w[i][j]=0;
	while (k>0)
	{
		if (k&1) C=C*A;
		A=A*A;
		k>>=1;
	}
	return C;
}
int tr(Matrix A)//迹 
{
	int tr=0;
	for (int i=1;i<=A.r;i++) tr=(A.w[i][i]+tr)%cc;
	return tr;
}
